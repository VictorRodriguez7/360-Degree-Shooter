#pragma once
#include <memory>
#include <SFML/Graphics.hpp>
#include "State.hpp"
#include "Game.hpp"

class SplashState : public State
{
public:
    SplashState(std::shared_ptr<Context>&  context);
    ~SplashState();
    
    void Init() override;
    void ProcessInput() override;
    void Update(sf::Time deltaTime) override;
    void Draw() override;
    
private:
    std::shared_ptr<Context> m_context;
    sf::Text m_splash;
    sf::Font typeWriter;
    sf::Clock clock;
    float duration;
};
