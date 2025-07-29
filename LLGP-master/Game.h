#pragma once
#include <SFML/Graphics.hpp>
#include "StateManager.h"

namespace LLGP {
	class Scoring;
	class Game
	{
	public:
		Game();
		void run();

	private:
		sf::RenderWindow window;
		sf::FloatRect mapBounds;
		sf::View* view;

		float timeSincePhsicsStep = 0.0f;
		float time = 0;

		void Render();

		StateManager stateManager;

		Scoring* scoring;
	};
}

