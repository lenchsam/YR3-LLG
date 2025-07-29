#pragma once
#include "Collider.h"
#include "Physics.h"
#include "GameObject.h"
namespace LLGP {
    class CircleCollider :
        public Collider
    {
    public:
        CircleCollider(GameObject* owner);
        ~CircleCollider() = default;

        void SetRadius(float radius);
        float GetRadius();
        sf::Vector2f GetPosition();
        GameObject* _GameObject;
    private:
        float m_Radius;
    };
}

