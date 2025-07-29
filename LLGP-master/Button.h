#pragma once
#include <SFML/Graphics.hpp>
#include "iostream"
#include "Event.h"

namespace LLGP {
	class Button
	{
	public:
		Button(sf::FloatRect _bounds) : bounds(_bounds){
			box.setPosition(bounds.position);
			box.setSize(bounds.size);
			box.setFillColor(sf::Color::Transparent); // No fill
			box.setOutlineColor(sf::Color::Red);      // Outline color
			box.setOutlineThickness(2.f);
		};
		~Button() {};
		std::string text;

		sf::RectangleShape GetBox();
		bool ClickCheck(sf::RenderWindow* window);

	private:
		sf::FloatRect bounds;
		sf::RectangleShape box;
	};

}

