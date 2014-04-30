/******************************************************************************
* Copyright (c) 2014, Andrew Bell
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

#include <pdal/IStream.hpp>
#include <pdal/Reader.hpp>
#include <pdal/ReaderIterator.hpp>

#include "BpfHeader.hpp"

namespace pdal
{

class PDAL_DLL BpfReader : public Reader
{
public:
    SET_STAGE_NAME("drivers.bpf.reader", "Bpf Reader")
    SET_STAGE_LINK("http://pdal.io/stages/drivers.bpf.reader.html")
    SET_STAGE_ENABLED(true)

    BpfReader(const Options&);
    BpfReader(const std::string&);

    virtual void initialize();
    virtual boost::uint64_t getNumPoints() const
        {  return m_header.m_numPts; }

    StageSequentialIterator*
        createSequentialIterator(PointBuffer& buffer) const;
    StageRandomIterator* createRandomIterator(PointBuffer& buffer) const;

private:
    ILeStream m_stream;
    BpfHeader m_header;
    std::vector<BpfDimension> m_dims;
    BpfUlemHeader m_ulemHeader;
    std::vector<BpfUlemFrame> m_ulemFrames;
    BpfPolarHeader m_polarHeader;
    std::vector<BpfPolarFrame> m_polarFrames;

    bool readUlemData();
    bool readPolarData();
};

} // namespace
