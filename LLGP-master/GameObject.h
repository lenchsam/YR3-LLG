#pragma once
#include "Object.h"
#include "Component.h"
#include "ComponentConcepts.h"
#include "Transform.h"
#include <vector>
#include <memory>

namespace LLGP {
	class Spawner;
	class GameObject : public Object
	{
	public:
		GameObject();
		GameObject(const GameObject&) = default;
		Transform* transform;
		inline void SetName(std::string newName) { m_Name = newName; }
		inline std::string GetName() { return m_Name; }

		void SetActive(bool newActive);
		inline bool GetActive() { return m_Active; }

		inline void SetTag(std::string newTag) { m_Tag = newTag; }
		inline bool CompareTag(std::string comp) { return m_Tag == comp; }

		static inline LLGP::Event<> OnWorldFixedUpdate;
		static inline LLGP::Event<> OnWorldEndFrame;

		template<class T> requires isComponent<T> T* GetComponent() {
			T* returnComp = nullptr;
			for (int i = 0; i < m_Components.size(); i++) {

				returnComp = dynamic_cast<T*>(m_Components[i].get());
				if (returnComp != nullptr) {
					break;
				}
			}

			return returnComp;
		}
		template<class T> requires isComponent<T> T* AddComponent() {
			std::unique_ptr<Component> newComp = std::make_unique<T>(this);
			m_Components.push_back(std::move(newComp));
			return static_cast<T*>(m_Components[m_Components.size() - 1].get());
		}
		template<class T> requires isComponent<T> bool RemoveComponent(T* comp) {
			T* castedType = nullptr;
			for (int i = 0; i < m_Components.size(); i++)
			{
				if (castedType = dynamic_cast<T>(m_Components[i].get()))
				{
					if (*castedType == *comp)
					{
						m_Components[i].reset();
						m_Components.erase(std::next(m_Components.begin(), i));
						return true;
					}
				}
			}
			return false;
		}

		virtual void OnCollision(GameObject* other);

		virtual void DestroyThis(Spawner* spawner = nullptr);


		bool isDestroyed = false;
	private:
		std::string m_Name;
		bool m_Active;
		std::string m_Tag;
		std::vector<std::unique_ptr<Component>> m_Components;
		
		void OnEndFrame();
	public:
		inline bool operator==(const GameObject& other) { return this->uuid == other.uuid; }
		inline bool operator!=(const GameObject& other) { return !(*this == other); }
	};
}


