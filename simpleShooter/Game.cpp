#include "Game.hpp"
#include "MainMenu.hpp"
#include "KryptologySplash.hpp"
Game::Game() :m_context(std::make_shared<Context>())
{
    m_context->m_window->create(sf::VideoMode(1400,1400), "Simple Shooter",sf::Style::Close);
    
    m_context->m_states->Add(std::make_unique<SplashState>(m_context));
}
Game::~Game(){}
void Game::run()
{
    
    sf::Clock clock;
    sf::Time timeSinceLastFrame = sf::Time::Zero;
    
    while(m_context->m_window->isOpen())
    {
        timeSinceLastFrame += clock.restart();
        
        while(timeSinceLastFrame > TIME_PER_FRAME)
        {
            timeSinceLastFrame -= TIME_PER_FRAME;
            
            m_context->m_states->ProcessStateChanges();
            m_context->m_states->GetCurrent()->ProcessInput();
            m_context->m_states->GetCurrent()->Update(TIME_PER_FRAME);
            m_context->m_states->GetCurrent()->Draw();
            
        }
        
    }
}
