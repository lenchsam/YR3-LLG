#include "UI.h"
#include <SFML/Graphics.hpp>
#include <iostream>

sf::Font UI::font;
std::vector<sf::Text> UI::texts;

void UI::LoadFont() {
    if (!font.openFromFile("assets/CutePixel.ttf")) {
        // Handle error
    }
}

void UI::ClearText() {
    texts.clear();
}
int UI::AddText(std::string text, sf::Vector2f position, int size, sf::Color color, bool centreOrigin) {
    sf::Text textObj(font);
    textObj.setString(text);
    if (centreOrigin) { textObj.setOrigin({ textObj.getLocalBounds().size.x / 2.0f, textObj.getLocalBounds().size.x / 2.0f }); }
    textObj.setCharacterSize(size);
    textObj.setFillColor(color);
    textObj.setPosition(position);

    texts.push_back(textObj);

    return texts.size() - 1;

}
void UI::UpdateText(int index, std::string newText) {
	if (index < 0 || index >= texts.size()) {
		//index out of bounds
	    std::cout << "index out of bounds" << std::endl;
		return;
	}

	sf::Text* textToUpdate = &texts[index];
    textToUpdate->setString(newText);
}
void UI::RenderAllText(sf::RenderWindow* window) {
    for (const auto& text : texts) {
        window->draw(text);
    }
}
