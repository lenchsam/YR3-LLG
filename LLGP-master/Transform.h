#pragma once
#include "Component.h"
#include <SFML/System/Vector2.hpp>
#include "SpriteRenderer.h"

namespace LLGP {
	class Transform : public Component
	{
	public:
		Transform(GameObject* owner);

		void SetPosition(sf::Vector2f newPosition);
		sf::Vector2f GetPosition();
		void ChangePosition(sf::Vector2f distance);
		void RotateTowardsMouse(sf::RenderWindow* window);

	private:
		sf::Vector2f m_Position;
		GameObject* _GameObject;
	};
}

