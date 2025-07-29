#include "MakeSound.h"
#include <iostream>
#include <filesystem>
#include <SFML/System/Sleep.hpp>



namespace LLGP {
	std::map<std::string, sf::SoundBuffer> MakeSound::buffers;
	std::vector<sf::Sound> MakeSound::sounds; //holds the list of sounds that are currently playing

	void MakeSound::PlaySound(std::string soundName)
	{
		CleanUpFinishedSounds();

		sounds.emplace_back(buffers[soundName]);
		sf::Sound sound(buffers[soundName]);
		sounds.back().play();
	}

	void MakeSound::LoadAllSounds(std::string path) {
		//got from https://stackoverflow.com/questions/612097/how-can-i-get-the-list-of-files-in-a-directory-using-c-or-c
		for (const auto& entry : std::filesystem::directory_iterator(path)) {
			sf::SoundBuffer buffer(entry.path().string());
			sf::Sound sound(buffer);

			sounds.push_back(sound);
			buffers.insert({ entry.path().filename().string(), buffer });
		}
	}

	//removes sounds that have finished playing from the list of sounds
	void MakeSound::CleanUpFinishedSounds() {
		for (std::vector<sf::Sound>::iterator it = sounds.begin(); it != sounds.end();) {
			if (it->getStatus() == sf::Sound::Status::Stopped) {
				it = sounds.erase(it);
                
			}
			else {
				it++;
			}
		}
	}

}
