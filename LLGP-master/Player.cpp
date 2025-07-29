#include "Player.h"
#include "Bullet.h"
#include "CircleCollider.h"
#include "PlayerCharacter.h"
#include "Physics.h"
#include "SpriteRenderer.h"
#include "MakeSound.h"
#include "Health.h"

namespace LLGP {
	Player::Player(sf::View* view) {
		SetTag("Player");
		playerSpriteRenderer = AddComponent<LLGP::SpriteRenderer>();
		playerSpriteRenderer->LoadTexture("assets/sprites/PLAYER.png");
		AddComponent<PlayerCharacter>();
		AddComponent<CircleCollider>();
		playerHealth = AddComponent<Health>();
		playerHealth->Init(100.f, 2, {0.f, 0.f});
		m_view = view;

		Physics::OnStepPhysics += std::bind(&Player::MoveAllBullets, this);
		SpriteRenderer::RenderSprite += std::bind(&Player::DrawAll, this, std::placeholders::_1);
		
	}
	Player::~Player() {
		delete m_view;
		delete playerSpriteRenderer;
		delete playerHealth;
	}
	void Player::MoveCamera(sf::Vector2f movement) {
		m_view->move(movement);
	}
	void Player::SetCameraPosition(sf::Vector2f newPosition) {
		m_view->setCenter(newPosition);
	}
	void Player::Shoot(float deltaTime, sf::RenderWindow *window) {
		m_time += deltaTime;


		if (sf::Mouse::isButtonPressed(sf::Mouse::Button::Left)) {
			if (m_time >= m_shootingSpeed) {
				MakeSound::PlaySound("Gun.wav");
				Bullet* bullet = new Bullet(true);
				bullet->Fire(this, window);

				_Bullets.push_back(bullet);

				m_time = 0.f;
			}
		}
	}

	void Player::DrawAllBullets(sf::RenderWindow* window) {
		for (auto bullet : _Bullets) {
			bullet->GetComponent<SpriteRenderer>()->Draw(window);
		}
	}

	void Player::DrawAll(sf::RenderWindow* window) {
		DrawAllBullets(window);
		playerSpriteRenderer->Draw(window);
	}

	void Player::MoveAllBullets() {
		for (auto bullet : _Bullets) {
			bullet->MoveBullet();
		}
	}
	void Player::DestroyThis(Spawner* spawnerd) {
		PlayerDead();
		std::cout << "DEEEEDDDDD\n";
	}
}
