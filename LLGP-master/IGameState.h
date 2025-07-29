#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>

namespace LLGP {
	class StateManager;
	//interface for the state machine. all states inherit from this
	class IGameState
	{
	public:
		virtual ~IGameState() = default;
		virtual void OnEnter(StateManager* manager) = 0;
		virtual void OnExit() = 0;
		virtual void HandleInput() = 0;
		virtual void Update(float deltaTime) = 0;
		virtual void FixedUpdate() = 0;
		virtual void Render(sf::RenderWindow* window) = 0;

	};

}

