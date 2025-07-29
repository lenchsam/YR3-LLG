#pragma once
#include "IGameState.h"
#include <SFML/Graphics.hpp>
#include "SpriteRenderer.h"
#include "StateManager.h"

namespace LLGP {
    class StateManager;
    class Player;
    class CrystalManager;
    class Spawner;

    class GameplayState :
        public IGameState
    {
    public:
        GameplayState(sf::RenderWindow* _window, StateManager* _stateManager) :
            window(_window),
            stateManager(_stateManager)
        {
            std::cout << "GameplayState constructed" << std::endl;

            view = new sf::View(sf::FloatRect({ 0.f, 0.f }, { 1000.f, 1000.f }));
            UIView = new sf::View(sf::FloatRect({ 0.f, 0.f }, { 1000.f, 1000.f }));
            minimapView = new sf::View(sf::FloatRect({ 0.f, 0.f }, { 2000.f, 2000.f }));
            minimapView->setViewport(sf::FloatRect({ 0.75f, 0.75f }, { 0.25f, 0.25f }));

            minimapBorder.setFillColor(sf::Color::Transparent);
            minimapBorder.setOutlineColor(sf::Color::Blue);
            minimapBorder.setOutlineThickness(5.f);


            playerViewBorder.setFillColor(sf::Color::Transparent);
            playerViewBorder.setOutlineColor(sf::Color::Blue);
            playerViewBorder.setOutlineThickness(10.f);

        }

        ~GameplayState() override {
            std::cout << "gameplaystate destroyed" << std::endl;

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
        sf::View* UIView;
        sf::View* minimapView;
        StateManager* stateManager;

        Player* player;
        Spawner* spawner;
        CrystalManager* crystalManager;

        void SwitchState();
        bool switchingStates = false;

		void UpdateScoreText(int currentScore);
		void UpdateBombText();
		void UpdateCrystalText();
        //index of ui text that will need to be updated
		//needed to call UI::UpdateText
        int scoreTextIndex;
        int bombTextIndex;
        int crystalTextIndex;

        sf::Font font;

        sf::RectangleShape minimapBorder;
        sf::RectangleShape playerViewBorder;
    };

}

