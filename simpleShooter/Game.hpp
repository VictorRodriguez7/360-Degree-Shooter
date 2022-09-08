#pragma once
#include <SFML/Graphics.hpp>
#include <memory>
#include "StateManager.hpp"


struct Context
{
    std::unique_ptr<StateManager> m_states;
    std::unique_ptr<sf::RenderWindow> m_window;
    
    Context()
    {
        m_states = std::make_unique<StateManager>();
        m_window = std::make_unique<sf::RenderWindow>();
    }
};

class Game
{
public:
    Game();
    ~Game();
    void run();
private:
    std::shared_ptr<Context> m_context;
    const sf::Time TIME_PER_FRAME = sf::seconds(1.f/60.f);
};
