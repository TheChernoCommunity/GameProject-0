#pragma once

#include <filesystem>
#include <SDL_mixer.h>

namespace ccm
{
	/*
	 * Music (for relatively long streaming)
	 * For small sound effects use ccm::SFX
	 * Supported & tested formats: OGG
	 */
	class Music
	{
	private:
		Mix_Music* m_music{};
		int m_loops{};
	public:
		Music(const std::filesystem::path& filepath, int loops = -1);
		Music(const Music&) = delete;
		Music& operator=(const Music&) = delete;
		Music(Music&& other);
		Music& operator=(Music&& other);
		~Music();

		/*
		 * Plays music
		 */
		void play() const;

		/*
		 * Stops any music current playing
		 */
		void stop() const;

		/*
		 * Pauses any current playing music.
		 */
		void pause() const;

		/*
		 * Sets music volume
		 * @param pct - Percent music volume [0, 100]
		 */
		void setVolume(int pct) const;
	};
}
