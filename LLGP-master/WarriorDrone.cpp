#include "WarriorDrone.h"
#include "Spawner.h"
#include "Scoring.h"

namespace LLGP {
	WarriorDrone::WarriorDrone() {
		m_speed = 5.f;
	}
	WarriorDrone::~WarriorDrone() {

	}
	void WarriorDrone::Init() {
		GetComponent<SpriteRenderer>()->GetSprite()->setColor(sf::Color(128, 128, 128));
	}
	void WarriorDrone::GoToTarget(GameObject* player, sf::Vector2f target) {

		//get euclidian distance between two points
		//if distance between drone and player is set distance
		//if true stop
		//if false, move towards player.
		Enemy::GoToTarget(player, player->GetComponent<SpriteRenderer>()->GetSprite()->getPosition());
	}

	void WarriorDrone::DestroyThis(Spawner* spawner) {
		std::cout << "Warrior Drone is destroyed" << std::endl;
		spawner->DestroyWarriorDroneFromList(this);

		Scoring::OnDeath(WARRIOR);

		SetActive(false);
	}
}
