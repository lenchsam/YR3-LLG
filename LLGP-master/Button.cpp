#include "Button.h"
#include "iostream"

namespace LLGP {

	bool Button::ClickCheck(sf::RenderWindow* window) {
		sf::Vector2i cursorPosition = sf::Mouse::getPosition(*window);
		sf::Vector2f worldPos = window->mapPixelToCoords(cursorPosition);

		if (bounds.contains(worldPos)) {
			return true;
		}
		return false;
	}
	sf::RectangleShape Button::GetBox() {
		return box;
	}
}
