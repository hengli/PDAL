/******************************************************************************
* Copyright (c) 2017, Hobu Inc.
*
* All rights reserved.
*
* Redistribution and use in source and binary forms, with or without
* modification, are permitted provided that the following
* conditions are met:
*
*     * Redistributions of source code must retain the above copyright
*       notice, this list of conditions and the following disclaimer.
*     * Redistributions in binary form must reproduce the above copyright
*       notice, this list of conditions and the following disclaimer in
*       the documentation and/or other materials provided
*       with the distribution.
*     * Neither the name of Hobu, Inc. or Flaxen Geo Consulting nor the
*       names of its contributors may be used to endorse or promote
*       products derived from this software without specific prior
*       written permission.
*
* THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS
* "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT
* LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS
* FOR A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE
* COPYRIGHT OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT,
* INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING,
* BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS
* OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED
* AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY,
* OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT
* OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY
* OF SUCH DAMAGE.
****************************************************************************/

#pragma once

#include <deque>

namespace pdal
{

class Triangle
{
public:
    Triangle(PointId a, PointId b, PointId c) : m_a(a), m_b(b), m_c(c)
    {}

    PointId m_a;
    PointId m_b;
    PointId m_c;
};

/**
  A mesh is a way to represent a set of points connected by edges.  Point
  indices are into a point view.
*/
class PDAL_DLL Mesh
{};


/**
  A mesh where the faces are triangles.
*/
class PDAL_DLL TriangularMesh : public Mesh
{
public:
    TriangularMesh()
    {}

    size_t size() const
        { return m_index.size(); }
    void add(PointId a, PointId b, PointId c)
        { m_index.emplace_back(a, b, c); }
    const Triangle& operator[](PointId id) const
        { return m_index[id]; }
protected:
    std::deque<Triangle> m_index;
};

} // namespace pdal
