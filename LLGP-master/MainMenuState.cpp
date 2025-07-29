#include "MainMenuState.h"
#include "UI.h"
#include "Button.h"
#include "GameplayState.h"
#include <fstream>
#include <iostream>
#include <string>

namespace LLGP {
	void MainMenuState::OnEnter(StateManager* manager) {
		UI::AddText("Play", { 500.f, 500.f }, 30, sf::Color::White, true);
		playButton = new Button(sf::FloatRect({ 475.f, 490.f }, { 50.f, 25.f }));
		quitButton = new Button(sf::FloatRect({ 475.f, 550.f }, { 50.f, 25.f }));
		UI::AddText("Quit", { 500.f, 560.f }, 30, sf::Color::White, true);

		//high score text
		std::vector<std::string> scores;
		std::ifstream file("highscores.txt");
		if (file.is_open()) {
			std::string line;
			while (std::getline(file, line)) {
				scores.push_back(line);
			}
			file.close();
		}

		UI::AddText("High Scores", {200.f, 300.f}, 30, sf::Color::White, true);

		for (int i = 0; i < scores.size(); i++) {
			UI::AddText(scores[i], {200.f, (300.f + (i * 25.f))}, 30, sf::Color::White, true);
		}
	}
	void MainMenuState::OnExit() {
		UI::ClearText();
	}
	void MainMenuState::HandleInput() {
		if (sf::Mouse::isButtonPressed(sf::Mouse::Button::Left)) {
			if (playButton->ClickCheck(window) == true)
			{
				std::cout << "changed state\n";
				stateManager->ChangeState(std::make_unique<GameplayState>(window, stateManager));
				return;
			}
			if (quitButton->ClickCheck(window) == true) {
				std::cout << "Clicked Quit Button\n";
				window->close();
				return;
			}
		}
	}
	void MainMenuState::Update(float deltaTime) {

	}
	void MainMenuState::FixedUpdate() {

	}
	void MainMenuState::Render(sf::RenderWindow* window)
	{
		window->setView(*view);
		window->draw(playButton->GetBox());
		window->draw(quitButton->GetBox());
		UI::RenderAllText(window);
		//Render main menu here
	}
}
