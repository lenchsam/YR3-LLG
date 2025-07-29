#include "Sinistar.h"
#include "iostream"

namespace LLGP {
	Sinistar::Sinistar() {
		m_minDistnaceFromPlayer = 0;
		currentStarLocation = 0;
		m_target = { 0, 0 };
	}
	Sinistar::~Sinistar() {

	}
	void Sinistar::Init() {

	}
	void Sinistar::DestroyThis(Spawner* spawner) {

	}
	void Sinistar::GoToTarget(GameObject* player, sf::Vector2f /*target*/) {
		m_target = ChooseTarget(player->GetComponent<SpriteRenderer>()->GetSprite()->getPosition());
		Enemy::GoToTarget(player, m_target);
	}
	sf::Vector2f Sinistar::ChooseTarget(sf::Vector2f playerPosition) {
		//TODO: add multiple attack sequences for variety when fighting the boss
		
		if (targetPositions.empty()) {
			for (sf::Vector2f point : starLocations) {
				targetPositions.push_back(playerPosition + point);
			}

			currentStarLocation = 0;
			m_target = targetPositions[currentStarLocation];
			return m_target;
		}
		
		//gets distance between target and current position
		sf::Vector2f start = GetComponent<SpriteRenderer>()->GetSprite()->getPosition();

		sf::Vector2f dist = { start.x - m_target.x, start.y - m_target.y };

		float distSquared = (dist.x * dist.x) + (dist.y * dist.y);
		float distance = sqrt(distSquared);

		if (distance >= 2) {
			//std::cout << "has not reached position" << std::endl;
			return m_target;
		}
		else if(currentStarLocation != targetPositions.size() - 1){
			currentStarLocation++;
			return targetPositions[currentStarLocation];
		}

		targetPositions.clear();
		for (sf::Vector2f point : starLocations) {
			targetPositions.push_back(playerPosition + point);
		}

		std::cout << "finished all in list" << std::endl;

		currentStarLocation = 0;
		m_target = targetPositions[0];
		return m_target;
	}
	void Sinistar::OnCollision(GameObject* other) {
		if (other->CompareTag("Player")) {
			std::cout << "Sinistar collided with player" << std::endl;
			other->GetComponent<Health>()->DealDamage(10.f);
		}
	}
}
