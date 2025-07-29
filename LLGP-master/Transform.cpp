#include "Transform.h"
#include "GameObject.h"
#include <numbers>
#include "PlayerCharacter.h"

namespace LLGP {
	Transform::Transform(GameObject* owner) {
		_GameObject = owner;
		sf::Vector2f* m_Position = new sf::Vector2f(0, 0);
	}

	sf::Vector2f Transform::GetPosition() {
		return m_Position;
	}

	void Transform::ChangePosition(sf::Vector2f distance) {
		m_Position += distance;
		_GameObject->GetComponent<SpriteRenderer>()->GetSprite()->move(distance);

		//std::cout << "m_Position" << std::endl;
	}
	void Transform::SetPosition(sf::Vector2f newPosition){
		m_Position = newPosition;

		SpriteRenderer* renderer = _GameObject->GetComponent<SpriteRenderer>();
		if (renderer && renderer->GetSprite()) {
			renderer->GetSprite()->setPosition(m_Position);
		}
	}
	void Transform::RotateTowardsMouse(sf::RenderWindow* window) {
		sf::Vector2i cursorPosition = sf::Mouse::getPosition(*window);
		sf::Vector2f worldPos = window->mapPixelToCoords(cursorPosition);
		sf::Vector2f spritePosition = _GameObject->GetComponent<SpriteRenderer>()->GetSprite()->getPosition();

		float a = spritePosition.x - worldPos.x;
		float b = spritePosition.y - worldPos.y;

		float rotation = (atan2(b, a)) * 180 / std::numbers::pi;

		_GameObject->GetComponent<SpriteRenderer>()->GetSprite()->setRotation(sf::degrees(rotation - 90));
	}
}
