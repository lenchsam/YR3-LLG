#pragma once
#include <SFML/Audio.hpp>
#include <map>

namespace LLGP{
	class MakeSound
	{
	public:
		static void PlaySound(std::string soundName);

		static void CleanUpFinishedSounds();

		static void LoadAllSounds(std::string path);
	private:
		static std::map<std::string ,sf::SoundBuffer> buffers;
		static std::vector<sf::Sound> sounds;
	};
}

