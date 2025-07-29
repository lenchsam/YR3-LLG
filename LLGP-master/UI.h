#pragma once
#include <SFML/Graphics.hpp>
class UI
{
public:
	static int AddText(std::string text, sf::Vector2f position, int size, sf::Color color, bool centreOrigin);
	static void UpdateText(int index, std::string newText);
	static void LoadFont();
	static void RenderAllText(sf::RenderWindow* window);
	static void ClearText();

private:
	static sf::Font font;
	static std::vector<sf::Text> texts;
};

