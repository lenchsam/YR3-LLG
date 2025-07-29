#include "Bullet.h"
#include "CircleCollider.h"
namespace LLGP {
	Bullet::Bullet(bool firedByPlayer) {
		transform = AddComponent<Transform>();
		spriteRenderer = AddComponent<SpriteRenderer>();
		AddComponent<CircleCollider>()->SetRadius(7);
		spriteRenderer->LoadTexture("assets/sprites/BULLET.png");
		spriteRenderer->GetSprite()->setScale({2.f, 2.f});

		m_Speed = 10.f;
		m_Damage = 5.f;
	}
	void Bullet::Fire(GameObject* player, sf::RenderWindow* window) {
		sf::Vector2f playerPosition = player->GetComponent<SpriteRenderer>()->GetSprite()->getPosition();
		spriteRenderer->GetSprite()->setPosition(playerPosition);

		spriteRenderer->GetSprite()->setRotation(player->GetComponent<SpriteRenderer>()->GetSprite()->getRotation());

		sf::Vector2i cursorPosition = sf::Mouse::getPosition(*window);
		sf::Vector2f worldPos = window->mapPixelToCoords(cursorPosition);

		m_directionToFire = (worldPos - playerPosition).normalized();
	}
	void Bullet::SetPlayer(Player* player) {
		m_player = player;
	}
	void Bullet::MoveBullet() {
		spriteRenderer->GetSprite()->move(m_directionToFire * m_Speed);
	}
}
