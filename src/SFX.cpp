#include "SFX.h"

#include <iostream>
#include <algorithm>
#include <cmath>

namespace ccm
{
	SFX::SFX(const std::filesystem::path& filepath)
	{
		if (!std::filesystem::exists(filepath))
		{
			std::cerr << "Could not find: " << filepath << '\n';
			return;
		}

		m_chunk = Mix_LoadWAV(filepath.string().c_str());

		if (m_chunk == nullptr)
		{
			std::cerr << Mix_GetError() << '\n';
			return;
		}
	}
	SFX::SFX(SFX&& other)
	{
		m_chunk = std::exchange(other.m_chunk, nullptr);
	}
	SFX& SFX::operator=(SFX&& other)
	{
		m_chunk = std::exchange(other.m_chunk, nullptr);
		return *this;
	}
	SFX::~SFX()
	{
		Mix_FreeChunk(m_chunk);
	}
	void SFX::play() const
	{
		Mix_PlayChannel(-1, m_chunk, 0);
	}
	void SFX::setVolume(int pct)
	{
		pct = std::clamp(pct, 0, 100);
		Mix_Volume(-1, std::lroundf(pct * 128.0f / 100.f));
	}
}
