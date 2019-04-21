#include "Music.h"

#include <iostream>
#include <algorithm>
#include <cmath>

namespace ccm
{
	Music::Music(const std::filesystem::path& filepath, int loops)
		: m_loops{ loops }
	{
		if (!std::filesystem::exists(filepath))
		{
			std::cerr << "Could not find: " << filepath << '\n';
			return;
		}

		m_music = Mix_LoadMUS(filepath.string().c_str());

		if (m_music == nullptr)
		{
			std::cerr << Mix_GetError() << '\n';
			return;
		}
	}

	Music::Music(Music&& other)
	{
		m_music = std::exchange(other.m_music, nullptr);
	}

	Music& Music::operator=(Music&& other)
	{
		m_music = std::exchange(other.m_music, nullptr);
		return *this;
	}

	Music::~Music()
	{
		if (m_music)
		{
			Mix_FreeMusic(m_music);
		}
	}

	void Music::play() const
	{
		if (m_music)
		{
			Mix_FadeInMusic(m_music, m_loops, 1000);
		}
	}

	void Music::stop() const
	{
		Mix_FadeOutMusic(1000);
	}

	void Music::pause() const
	{
		Mix_PauseMusic();
	}

	void Music::setVolume(int pct) const
	{
		pct = std::clamp(pct, 0, 100);
		Mix_VolumeMusic(std::lroundf(pct * 128.0f / 100.f));
	}
}
