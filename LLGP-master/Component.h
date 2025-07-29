#pragma once
#include "Object.h"

namespace LLGP {
    class GameObject;

    class Component : public Object
    {
    public:
        Component() {}
        Component(GameObject* owner) : _GameObject(owner) {}
        virtual ~Component() {}

        GameObject* GetGameObjects() { return _GameObject; }

        void OwnerActiveChange(bool newActive) { isActive = newActive; }
        bool isActive = true;

    protected:
        GameObject* _GameObject;
    };
}


