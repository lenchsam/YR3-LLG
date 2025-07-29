#pragma once
#include "IGameState.h"
#include <SFML/Graphics.hpp>
#include "StateManager.h"

namespace LLGP {
    class Button;
    class MainMenuState :
        public IGameState
    {
    public:
        MainMenuState(sf::RenderWindow* _window, StateManager* manager) : window(_window), stateManager(manager) {
            std::cout << "MainMenuState constructed" << std::endl;
            view = new sf::View(sf::FloatRect({ 0.f, 0.f }, { 1000.f, 1000.f }));
        }

        ~MainMenuState() override {
            std::cout << "MainMenuState destroyed" << std::endl;
        }

        void OnEnter(StateManager* manager) override;
        void OnExit() override;
        void HandleInput() override;
        void Update(float deltaTime) override;
        void FixedUpdate() override;
        void Render(sf::RenderWindow* window) override;

    private:
        sf::RenderWindow* window;
        sf::View* view;

        StateManager* stateManager = nullptr;
        Button* playButton;
        Button* quitButton;
    };
}

