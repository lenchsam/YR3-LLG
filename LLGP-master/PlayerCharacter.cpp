#include "PlayerCharacter.h"
#include <SFML/Graphics.hpp>
#include <vector>
#include "GameObject.h"
namespace LLGP {
	PlayerCharacter::PlayerCharacter(GameObject* owner) {
		_speed = 3.20f;
		_GameObject = owner;
		_GameObject->SetTag("Player");

		bounds = new sf::FloatRect({ -1000.f, -1000.f }, { 2000.f, 2000.f });

	}
	void PlayerCharacter::Input(Player* player) {
		sf::Vector2f currentPos = _GameObject->GetComponent<SpriteRenderer>()->GetSprite()->getPosition();
		player->SetCameraPosition(currentPos);
		//if player will be out of bounds
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::W))
		{
			//if player will be out of bounds return;
			if (!bounds->contains({currentPos.x, currentPos.y - 1 * _speed })) {return;}
			_GameObject->transform->ChangePosition({ 0, -1 * _speed });
			player->MoveCamera({ 0, -1 * _speed });
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::A))
		{
			if (!bounds->contains({ currentPos.x - 1 * _speed, currentPos.y })) { return; }
			_GameObject->transform->ChangePosition({-1 * _speed, 0  });
			player->MoveCamera({ -1 * _speed , 0 });
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::S))
		{
			if (!bounds->contains({ currentPos.x, currentPos.y + 1 * _speed })) { return; }
			_GameObject->transform->ChangePosition({ 0, 1 * _speed });
			player->MoveCamera({ 0, 1 * _speed });
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::D))
		{
			if (!bounds->contains({ currentPos.x + 1 * _speed, currentPos.y })) { return; }
			_GameObject->transform->ChangePosition({ 1 * _speed, 0  });
			player->MoveCamera({ 1 * _speed, 0 });
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::F))
		{
			//throw bomb
			std::cout << "threw bomb" << std::endl;
		}
	}
}
