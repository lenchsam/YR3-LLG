#include "CircleCollider.h"
#include "GameObject.h"

namespace LLGP {

	CircleCollider::CircleCollider(GameObject* owner) : m_Radius(10.f), _GameObject(owner) {
		Physics::AddCollider(this);
	};
	void CircleCollider::SetRadius(float radius) {
		m_Radius = radius;
	}
	float CircleCollider::GetRadius() {
		return m_Radius;
	}
	sf::Vector2f CircleCollider::GetPosition() {
		return _GameObject->GetComponent<SpriteRenderer>()->GetSprite()->getPosition();
	}
}