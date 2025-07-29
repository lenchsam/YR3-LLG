#pragma once
#include <memory>
#include <SFML/Graphics.hpp>
#include "IGameState.h"

namespace LLGP {
	class StateManager
	{
	public:
		StateManager() = default;
		void InitialiseStateMachine(std::unique_ptr<IGameState> initialState);

		void ChangeState(std::unique_ptr<IGameState> newState);
		void HandleInput();
		void Update(float deltaTime);
		void FixedUpdate();
		void Render(sf::RenderWindow* window);
	private:
		std::unique_ptr<IGameState> currentState = nullptr;
		std::unique_ptr<IGameState> nextState = nullptr;
	};

}

