#include "StateManager.h"
#include "IGameState.h"

namespace LLGP {
    void StateManager::InitialiseStateMachine(std::unique_ptr<IGameState> initialState) {
        currentState = std::move(initialState);
        if (currentState) {
            currentState->OnEnter(this);
        }
    }

    void StateManager::ChangeState(std::unique_ptr<IGameState> newState) {
        if (newState) {
            nextState = std::move(newState);
            std::cout << "moved state\n";
        }

        //clean up current state
        if (currentState) {
            currentState->OnExit();
        }

        currentState = std::move(nextState); 
        nextState.reset(); 

        //initialise new state
        if (currentState) {
            currentState->OnEnter(this); 
        }
    }

    void StateManager::HandleInput() {
        if (currentState) { 
            currentState->HandleInput();
        }
    }

    void StateManager::Update(float deltaTime) {
        if (currentState) {
            currentState->Update(deltaTime);
        }
    }

    void StateManager::FixedUpdate() {
        if (currentState) {
            
            currentState->FixedUpdate();
        }
    }

    void StateManager::Render(sf::RenderWindow* window) {
        if (currentState) {
            currentState->Render(window);
        }
    }

}
