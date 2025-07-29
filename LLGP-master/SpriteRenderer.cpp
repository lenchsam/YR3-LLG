#include "SpriteRenderer.h"

namespace LLGP {
	SpriteRenderer::SpriteRenderer(GameObject* owner)
	{
		_GameObject = owner;
	}

	SpriteRenderer::~SpriteRenderer()
	{
		delete m_sprite;
	}

	void SpriteRenderer::SetSprite(sf::Sprite* sprite) 
	{
		m_sprite = sprite;
	}

	void SpriteRenderer::LoadTexture(std::string filename) 
	{
		if (!m_texture.loadFromFile(filename)) 
		{ 
			std::cout << "no texture found" << std::endl;
			return;
		}

		m_sprite = new sf::Sprite(m_texture);
		if (m_sprite != nullptr)
		{
			m_sprite->setScale({ 2.0f, 2.0f }); // absolute scale factor
			m_sprite->setPosition({ 500.f, 500.f }); // absolute position
			sf::FloatRect bounds = m_sprite->getLocalBounds();
			m_sprite->setOrigin(bounds.getCenter());
		}

	}
	sf::Sprite* SpriteRenderer::GetSprite() 
	{
		return m_sprite;
	}
	void SpriteRenderer::Draw(sf::RenderWindow* window) 
	{
		if (m_sprite != nullptr && isActive == true)
		{
			window->draw(*m_sprite);
		}
	}
}
