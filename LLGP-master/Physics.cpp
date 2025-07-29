#include "Physics.h"
#include "CircleCollider.h"
namespace LLGP {

	void Physics::GetCollisionInfo() {

	}
	void Physics::DispatchCollisions() {

	}
	void Physics::AddCollider(CircleCollider* col) {
		_Colliders.push_back(col);
		//std::cout << "added collider" << std::endl;
	}
	void Physics::RemoveCollider(CircleCollider* col) {
		std::vector<CircleCollider*>::iterator position = std::find(_Colliders.begin(), _Colliders.end(), col);
		if (position != _Colliders.end()) {}

		_Colliders.erase(position);
		//std::cout << "Removed Collider" << std::endl;
	}

	bool Physics::CheckCircleCollision(CircleCollider* a, CircleCollider* b) {
		//get difference in position
		//get radius of both colliders
		//if radius added together is < difference in position
		sf::Vector2f posDifference = b->GetPosition() - a->GetPosition(); 
		float radiusCombined = a->GetRadius() + b->GetRadius();

		float distanceSquared = posDifference.x * posDifference.x + posDifference.y * posDifference.y;

		if (radiusCombined * radiusCombined > distanceSquared) {
			return true;
		}
		return false;
	}

	void Physics::CheckCollisions() {
		for (size_t i = 0; i < _Colliders.size(); ++i) {

			for (size_t j = i + 1; j < _Colliders.size(); ++j) {

				if (CheckCircleCollision(_Colliders[i], _Colliders[j]) && _Colliders[i]->isActive && _Colliders[j]->isActive) {
					//collision detected between Colliders[i], _Colliders[j]
					//std::cout << "collission detected" << std::endl;
					_Colliders[i]->_GameObject->OnCollision(_Colliders[j]->_GameObject);
					_Colliders[j]->_GameObject->OnCollision(_Colliders[i]->_GameObject);

				}
			}
		}
		//std::cout << "no collission detected" << std::endl;
		//no collision detected
	}

	void Physics::StepPhysics() {
		OnStepPhysics();
	}
}
