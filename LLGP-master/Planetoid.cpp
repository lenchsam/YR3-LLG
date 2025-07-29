#include "Planetoid.h"
#include "CircleCollider.h"
#include "Bullet.h"
#include "Spawner.h"
#include "Crystal.h"
#include "SpriteRenderer.h"
#include "Scoring.h"

namespace LLGP {
	Planetoid::Planetoid() {
		circleCollider->SetRadius(25.f);

		//TODO: SET RANDOM NUMBER OF CRYSTALS BETWEEN 1 AND 10

		//SpriteRenderer::RenderSprite += std::bind(&Planetoid::Drawing, this, std::placeholders::_1);
	}
	Planetoid::~Planetoid() {

	}

	void Planetoid::OnCollision(GameObject* other) {

		Bullet* bullet = dynamic_cast<Bullet*>(other);

		if (bullet) {
			//if other object is a bullet
			//std::cout << "other is bullet - from enemy" << std::endl;
			health->DealDamage(bullet->m_Damage);
			//bullet->Destroy();
		}
		else {
			//std::cout << "other is NOT bullet - from enemy" << std::endl;
		}
	}
	void Planetoid::RandomMovements() {
		
	}
	void Planetoid::Init() {

	}
	void Planetoid::GoToTarget(GameObject* player, sf::Vector2f target){
		Enemy::GoToTarget(player, target);
	}
	void Planetoid::DestroyThis(Spawner* spawner) {
		// explode into crystals
		SpawnCrystals();

		spawner->DestroyPlanetoidFromList(this);

		Scoring::OnDeath(PLANETOID);

		SetActive(false);
	}
	void Planetoid::SpawnCrystals() {
		for (int i = 0; i <= m_crystals - 1; i++) {
			new Crystal(GetComponent<SpriteRenderer>()->GetSprite()->getPosition());
		}
	}
	int Planetoid::GetCrystalNumber() {
		return m_crystals;
	}
}
