#include <SFML/Graphics.hpp>
#include "KryptologySplash.hpp"
#include "MainMenu.hpp"
#include "ResourcePath.hpp"
#include "GamePlay.hpp"

SplashState::SplashState(std::shared_ptr<Context>&  context)
:m_context(context){}

SplashState::~SplashState(){}

void SplashState::Init()
{
    //Title
    typeWriter.loadFromFile(filepath + "Typewriter.ttf");
    m_splash.setFont(typeWriter);
    m_splash.setString("Kryptology");
    m_splash.setCharacterSize(130);
    m_splash.setOrigin(m_splash.getLocalBounds().width/2, m_splash.getLocalBounds().height/2);
    m_splash.setPosition(m_context->m_window->getSize().x/2, m_context->m_window->getSize().y - 760);
    
}
void SplashState::ProcessInput()
{
    
    sf::Event event;
    while(m_context->m_window->pollEvent(event))
    {
        if(event.type == sf::Event::Closed)
        {
            m_context->m_window->close();
        }
        
    }
}
void SplashState::Update(sf::Time deltaTime)
{
    duration = clock.getElapsedTime().asSeconds();
    
    if(duration > 4.0f)
    {
        m_context->m_states->Add(std::make_unique<MainMenu>(m_context), true);
    }
    
}
void SplashState::Draw()
{
    m_context->m_window->clear();
    m_context->m_window->draw(m_splash);
    m_context->m_window->display();
}
