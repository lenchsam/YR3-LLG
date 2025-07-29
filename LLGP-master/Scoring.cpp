#include "Scoring.h"
#include <fstream>
#include <iostream>
#include <filesystem>
#include <string>
namespace LLGP {
	Scoring::Scoring() {
		Scoring::OnDeath += std::bind(&Scoring::SetScore, this, std::placeholders::_1);
		if (!std::filesystem::exists("highscores.txt")) {
			std::ofstream MyFile("highscores.txt");

			if (MyFile.is_open()) {
				MyFile << "0\n";
				MyFile << "0\n";
				MyFile << "0\n";
				MyFile << "0\n";
				MyFile << "0\n";
				MyFile.close();
			}
		}
	}
	void Scoring::SetScore(enum ScoreGivers scoreToAdd) {
		currentScore += scores[scoreToAdd];
		std::cout << "new score is " << currentScore << std::endl;
		ScoreChanged(currentScore);
	}
	void Scoring::ResetScore() {
		currentScore = 0;
	}
	void Scoring::CheckScore() {
		std::vector<int> HighScores = GetHighScores();
		for (int i = 0; i < HighScores.size(); i++) {
			if (currentScore > HighScores[i]) {
				std::cout << "NEW HIGH SCORE: " << i << std::endl;
				std::vector<std::string> smallerScores;//list of all scores after the new high score

				HighScores[i] = currentScore;

				std::ifstream File("highscores.txt");

				if (!File.is_open()) {
					std::cout << "error, file not open" << std::endl;
					return;
				}

				std::ofstream file("highscores.txt", std::ios::trunc); //clear the file

				for (int score : HighScores) {
					file << score << "\n";
				}

				return;
			}
		}

		currentScore = 0;
	}
	std::vector<int> Scoring::GetHighScores() {
		std::ifstream File("highscores.txt");
		std::vector<int> HighScores;

		if (!File.is_open()) {
			std::cout << "error, file not open" << std::endl;
			return HighScores;
		}	

		std::string line;
		int result;

		while (std::getline(File, line)) {
			result = std::stoi(line);
			HighScores.push_back(result);
		}

		File.clear();
		File.seekg(0);

		File.close();
		
		return HighScores;
	}
}

