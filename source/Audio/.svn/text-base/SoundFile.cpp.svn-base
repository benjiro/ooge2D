/*
This file is apart of ooge(object-oriented 2D game engine)

-------------------------------------------------------------------
Copyright (c) 2010 Benjamin Evenson

Permission is hereby granted, free of charge, to any person
obtaining a copy of this software and associated documentation
files (the "Software"), to deal in the Software without
restriction, including without limitation the rights to use,
copy, modify, merge, publish, distribute, sublicense, and/or sell
copies of the Software, and to permit persons to whom the
Software is furnished to do so, subject to the following
conditions:

The above copyright notice and this permission notice shall be
included in all copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND,
EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES
OF MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND
NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT
HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY,
WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING
FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR
OTHER DEALINGS IN THE SOFTWARE.
-------------------------------------------------------------------
*/

#include <Soundfile.hpp>
#include <iostream>
#include <StringUtil.hpp>

using namespace ooge;

SoundFile::SoundFile()
{
}

SoundFile::~SoundFile()
{
	if(mFile)
		sf_close(mFile);
}

bool SoundFile::OpenRead(const std::string &filename, ooge::UInt32 *channels, ooge::UInt32 *samplerate, ooge::UInt32 *samples)
{
	SF_INFO info;
	mFile = sf_open(filename.c_str(), SFM_READ, &info);

	if(mFile)
	{
		*channels = info.channels;
		*samplerate = info.samplerate;
		*samples = info.frames * *channels;

		return true;
	}

	std::cerr << "Failed to Open " << filename << " sound file into memory" << std::endl;
	return false;
}

bool SoundFile::OpenRead(UInt8 *data, const std::size_t size, UInt32 *channels, UInt32 *samplerate, UInt32 *samples)
{
	if(mFile)
		sf_close(mFile);

	SF_VIRTUAL_IO virtualio;
	virtualio.get_filelen = &SoundFile::MemoryLength;
	virtualio.read = &SoundFile::MemoryRead;
	virtualio.seek = &SoundFile::MemorySeek;
	virtualio.tell = &SoundFile::MemoryTell;
	virtualio.write = &SoundFile::MemoryWrite;

	mMemoryData.Offset = 0;
	mMemoryData.Length = 0;
	mMemoryData.Data = data;

	SF_INFO info;
	mFile = sf_open_virtual(&virtualio, SFM_READ, &info, &mMemoryData);

	if(mFile)
	{
		*channels = info.channels;
		*samplerate = info.samplerate;
		*samples = info.frames * *channels;
		return true;
	}

	return false;
}

bool SoundFile::OpenWrite(const std::string &filename, ooge::UInt32 channels, ooge::UInt32 samplerate)
{
	if(mFile)
		sf_close(mFile);

	int format = IsFileSupport(filename);
	if(format == -1)
		return false;

	SF_INFO info;
	info.channels = channels;
	info.samplerate = samplerate;
	info.format = format | SF_FORMAT_PCM_16;

	mFile = sf_open(filename.c_str(), SFM_WRITE, &info);

	if(mFile)
		return true;
	return false;
}

Int32 SoundFile::IsFileSupport(const std::string &filename)
{
	std::size_t pos = filename.find_last_of(".");
	std::string ext = filename.substr(pos + 1); 
	StringUtil::ToLower(ext);

	if(ext == "wav") return SF_FORMAT_WAV;
	if(ext == "aiff" || ext == "aifc" || ext == "aif") return SF_FORMAT_AIFF;
	if(ext == "au" || ext == "snd") return SF_FORMAT_AU;
	if(ext == "raw") return SF_FORMAT_RAW;
	if(ext == "paf") return SF_FORMAT_PAF;
	if(ext == "iff" || ext == "svx") return SF_FORMAT_SVX;
	if(ext == "sf") return SF_FORMAT_IRCAM;
	if(ext == "voc") return SF_FORMAT_VOC;
	if(ext == "w64") return SF_FORMAT_W64;
	if(ext == "mat4") return SF_FORMAT_MAT4;
	if(ext == "mat5") return SF_FORMAT_MAT5;
	if(ext == "pvf") return SF_FORMAT_PVF;
	if(ext == "htk") return SF_FORMAT_HTK;
	if(ext == "caf") return SF_FORMAT_CAF;
	if(ext == "sd2") return SF_FORMAT_SD2;
	if(ext == "sds") return SF_FORMAT_SDS;
	if(ext == "flac") return SF_FORMAT_FLAC;
	if(ext == "ogg") return SF_FORMAT_OGG;

	return -1;
}

std::size_t SoundFile::Read(ooge::Int16 *buffer, const ooge::UInt32 samples)
{
	return mFile ? static_cast<std::size_t>(sf_read_short(mFile, buffer, samples)) : 0;
}

std::size_t SoundFile::Write(const ooge::Int16 *buffer, const ooge::UInt32 samples)
{
	return mFile ? static_cast<std::size_t>(sf_write_short(mFile, buffer, samples)) : 0;
}

sf_count_t SoundFile::MemoryLength(void *userData)
{
	MemoryData *data = static_cast<MemoryData*>(userData);
	return data->Length;
}

sf_count_t SoundFile::MemorySeek(sf_count_t offset, Int32 whence, void *userData)
{
	MemoryData *data = static_cast<MemoryData*>(userData);

	switch(whence)
	{
	case SEEK_SET:
		data->Offset = offset;
		break;
	case SEEK_CUR:
		data->Offset = data->Offset + offset;
		break;
	case SEEK_END:
		data->Offset = data->Length + offset;
		break;
	};

	return data->Offset;
}

sf_count_t SoundFile::MemoryRead(void *ptr, sf_count_t count, void *userData)
{
	MemoryData *data = static_cast<MemoryData*>(userData);

	if(data->Offset + count > data->Length)
		count = data->Length + data->Offset;

	memcpy(ptr, data->Data, count);
	data->Offset += count;
	
	return count;
}

sf_count_t SoundFile::MemoryWrite(const void *ptr, sf_count_t count, void *userData)
{
	MemoryData *data = static_cast<MemoryData*>(userData);

	if(data->Offset >= sizeof(data->Data))
		return 0;

	if(data->Offset + count > sizeof(data->Data))
		count = sizeof(data->Data) - data->Offset;

	memcpy(data->Data + data->Offset, ptr, static_cast<std::size_t>(count));
	data->Offset += count;

	if(data->Offset > data->Length)
		data->Length = data->Offset;

	return count;
}

sf_count_t SoundFile::MemoryTell(void *userData)
{
	MemoryData *data = static_cast<MemoryData*>(userData);
	return data->Offset;
}