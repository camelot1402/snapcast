#include "sampleFormat.h"
#include <vector>
#include <boost/algorithm/string.hpp>
#include <boost/lexical_cast.hpp>
#include <iostream>


SampleFormat::SampleFormat(const std::string& format) : rate(rate_), bits(bits_), channels(channels_), sampleSize(bytes_), frameSize(frameSize_)
{
	setFormat(format);
}


SampleFormat::SampleFormat(uint16_t sampleRate, uint16_t bitsPerSample, uint16_t channelCount) : rate(rate_), bits(bits_), channels(channels_), sampleSize(bytes_), frameSize(frameSize_)
{
	setFormat(sampleRate, bitsPerSample, channelCount);
}


void SampleFormat::setFormat(const std::string& format)
{
	std::vector<std::string> strs;
	boost::split(strs, format, boost::is_any_of(":"));
	if (strs.size() == 3)
		setFormat(
			boost::lexical_cast<uint16_t>(strs[0]), 
			boost::lexical_cast<uint16_t>(strs[1]),
			boost::lexical_cast<uint16_t>(strs[2]));
}


void SampleFormat::setFormat(uint16_t rate, uint16_t bits, uint16_t channels)
{
	rate_ = rate;	
	bits_ = bits;
	bytes_ = bits / 8;
	channels_ = channels;
	if (bits_ == 24)
		bytes_ = 4;
	frameSize_ = channels_*bytes_;
}



