#pragma once
#include "Component.h"
#include <SFML/Graphics.hpp>
namespace LLGP {
    class AnimationController :
        public Component
    {
    public:
        AnimationController();
        ~AnimationController();

        void AddAnimation(std::string path, sf::Vector2i* _frameSize, sf::Vector2i* _spriteSize);
        void UpdateAnimation();

    private:
        sf::Texture* animationSheet;
        sf::Vector2i* spriteSize;
        sf::Vector2i* frameSize;//number of frames on the x and y axis.
        sf::Vector2i currentFrame;

    };
}

