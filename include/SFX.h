#pragma once

#include <filesystem>
#include <SDL_mixer.h>

namespace ccm
{
	/*
	 * Small sound effects
	 * For longer durations use ccm::Music
	 * Supported & tested formats: WAV
	 */
	class SFX
	{
	private:
		Mix_Chunk* m_chunk{};
	public:
		SFX(const std::filesystem::path& filepath);
		SFX(const SFX&) = delete;
		SFX& operator=(const SFX&) = delete;
		SFX(SFX&& other);
		SFX& operator=(SFX&& other);
		~SFX();

		/*
		 * Play sound effect
		 */
		void play() const;

		/*
		 * Sets volume for all sound effects
		 * @param pct - Percent sound effect volume [0, 100]
		 */
		static void setVolume(int pct);
	};
}
