#pragma once
#include <map>
#include <iostream>
#include "Event.h"
enum ScoreGivers {
	PLANETOID,
	WORKER,
	CRYSTAL,
	WARRIOR,
	SINISTARPIECE,
	SINISTAR
};
namespace LLGP {
	class Scoring
	{
	public:
		Scoring();
		void ResetScore();

		void CheckScore();
		std::vector<int> GetHighScores();

		static inline LLGP::Event<ScoreGivers> OnDeath;
		static inline LLGP::Event<int> ScoreChanged;
	private:
		std::map <ScoreGivers, int> scores = { {PLANETOID, 5}, {WORKER, 150}, {CRYSTAL, 200}, {WARRIOR, 500}, {SINISTARPIECE, 500}, {SINISTAR, 15000 }};

		void SetScore(enum ScoreGivers scoreToAdd);

		int currentScore = 0;
	};

}


