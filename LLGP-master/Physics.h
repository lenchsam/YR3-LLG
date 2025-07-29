#pragma once
#include <SFML/Graphics.hpp>
#include <vector>
#include "Event.h"

namespace LLGP {
	class Collider;
	class CircleCollider;
	class BoxCollider;

	class Physics
	{
	public:
		Physics(){}
		//static because this isnt going to be a gameobject, allows it to be called in main
		static void GetCollisionInfo();
		static void DispatchCollisions();
		static void AddCollider(CircleCollider* c);
		static void RemoveCollider(CircleCollider* col);
		static void CheckCollisions();
		static void StepPhysics();

		static inline LLGP::Event<> OnStepPhysics;


	private:
		static bool CheckCircleCollision(CircleCollider* a, CircleCollider* b);
		static inline std::vector<CircleCollider*> _Colliders;
	};
}

