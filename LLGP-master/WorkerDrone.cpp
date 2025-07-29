#include "WorkerDrone.h"
#include "Spawner.h"
#include "Scoring.h"
#include <iostream>

namespace LLGP {
	WorkerDrone::WorkerDrone() {
		m_speed = 5.f;
	}
	void WorkerDrone::Init() {
		GetComponent<SpriteRenderer>()->GetSprite()->setColor(sf::Color::Blue);
	}
	void WorkerDrone::DestroyThis(Spawner* spawner) {
		std::cout << "Worker Drone is destroyed" << std::endl;
		spawner->DestroyWorkerDroneFromList(this);

		Scoring::OnDeath(WORKER);

		SetActive(false);
	}

	void WorkerDrone::GoToTarget(GameObject* player, sf::Vector2f target) {

		//TODO:: Change this to be going towards crystals, then to sinstar boss. repeat
		//get euclidian distance between two points
		//if distance between drone and player is set distance
		//if true stop
		//if false, move towards player.
		Enemy::GoToTarget(player, player->GetComponent<SpriteRenderer>()->GetSprite()->getPosition());
	}

}
