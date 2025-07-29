#pragma once
#include "Component.h"
#include "SpriteRenderer.h"
#include "Player.h"
namespace LLGP {
	class PlayerCharacter : public Component
	{
	public:
		PlayerCharacter(GameObject* owner);
		PlayerCharacter(const PlayerCharacter&) = default;

		void Input(Player* player);
	private:
		sf::Rect<float>* bounds;
		float _speed = 2.f;
		GameObject* _GameObject;

		float _bombCooldown = 2.f;
		float _timeSinceLastBomb = 0.f;
	};
}

