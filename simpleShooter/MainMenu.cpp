#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include "MainMenu.hpp"
#include "ResourcePath.hpp"
#include "GamePlay.hpp"

MainMenu::MainMenu(std::shared_ptr<Context>&  context)
:m_context(context), m_isPlayButtonSelected(true),m_isExitButtonSelected(false),m_isPlayButtonPressed(false),m_isExitButtonPressed(false){}

MainMenu::~MainMenu(){}
void MainMenu::Init()
{
    //Title
    sfCompact.loadFromFile(filepath + "SFCompact.ttf");
    m_gameTitle.setFont(sfCompact);
    m_gameTitle.setString("One Shot");
    m_gameTitle.setCharacterSize(200);
    m_gameTitle.setFillColor(sf::Color::Black);
    m_gameTitle.setOutlineThickness(10);
    m_gameTitle.setOutlineColor(sf::Color::White);
    m_gameTitle.setOrigin(m_gameTitle.getLocalBounds().width/2, m_gameTitle.getLocalBounds().height/2);
    m_gameTitle.setPosition(m_context->m_window->getSize().x/2, m_context->m_window->getSize().y - 1200);
    
    //instructions
    sfCompact.loadFromFile(filepath + "SFCompact.ttf");
    m_intructions.setFont(sfCompact);
    m_intructions.setString("Destroy The Enemies Before Time Runs Out");
    m_intructions.setCharacterSize(40);
    m_intructions.setOrigin(m_intructions.getLocalBounds().width/2, m_intructions.getLocalBounds().height/2);
    m_intructions.setPosition(m_context->m_window->getSize().x/2, m_context->m_window->getSize().y - 990);
    
    //logo
    logotex.loadFromFile(filepath + "bat.png");
    logo.setSize(sf::Vector2f(350,350));
    logo.setTexture(&logotex);
    logo.setOrigin(logo.getSize().x/2, logo.getSize().y/2);
    logo.setPosition((m_context->m_window->getSize().x/2)+10, m_context->m_window->getSize().y - 720);
    
    //peBox
    peBox.setSize(sf::Vector2f(200,230));
    peBox.setFillColor(sf::Color::Black);
    peBox.setOutlineThickness(5);
    peBox.setOutlineColor(sf::Color::White);
    peBox.setOrigin(peBox.getSize().x/2, peBox.getSize().y/2);
    peBox.setPosition(m_context->m_window->getSize().x/2, m_context->m_window->getSize().y - 345);
    
    //Play
    sfCompact.loadFromFile(filepath + "SFCompact.ttf");
    m_playButton.setFont(sfCompact);
    m_playButton.setString("Play");
    m_playButton.setCharacterSize(50);
    m_playButton.setOrigin(m_playButton.getLocalBounds().width/2, m_playButton.getLocalBounds().height/2);
    m_playButton.setPosition(m_context->m_window->getSize().x/2, m_context->m_window->getSize().y - 410);
    
    //Exit
    sfCompact.loadFromFile(filepath + "SFCompact.ttf");
    m_exitButton.setFont(sfCompact);
    m_exitButton.setString("Exit");
    m_exitButton.setCharacterSize(50);
    m_exitButton.setOrigin(m_exitButton.getLocalBounds().width/2, m_exitButton.getLocalBounds().height/2);
    m_exitButton.setPosition(m_context->m_window->getSize().x/2, m_context->m_window->getSize().y - 310);
    }
void MainMenu::ProcessInput()
{
    sf::Event event;
    while(m_context->m_window->pollEvent(event))
    {
        if(event.type == sf::Event::Closed)
        {
            m_context->m_window->close();
        }
        else if(event.type == sf::Event::KeyPressed)
        {
            switch(event.key.code)
            {
                case sf::Keyboard::Up:
                {
                    if(!m_isPlayButtonSelected)
                    {
                        m_isPlayButtonSelected = true;
                        m_isExitButtonSelected = false;
                    }
                    break;
                }
                case sf::Keyboard::Down:
                {
                    if(!m_isExitButtonSelected)
                    {
                        m_isExitButtonSelected = true;
                        m_isPlayButtonSelected = false;
                    }
                    break;
                }
                case sf::Keyboard::Return:
                {
                    m_isPlayButtonPressed=false;
                    m_isExitButtonPressed = false;
                    if(m_isPlayButtonSelected)
                    {
                        m_isPlayButtonPressed = true;
                    }
                    else
                    {
                        m_isExitButtonPressed = true;
                    }
                    break;
                }
                default:
                    break;
            }
        }
    }
}
void MainMenu::Update(sf::Time deltaTime)
{
    
    if(m_isPlayButtonSelected)
    {
        m_playButton.setFillColor(sf::Color::Yellow);
        m_exitButton.setFillColor(sf::Color::White);
    }
    else
    {
        m_exitButton.setFillColor(sf::Color::Yellow);
        m_playButton.setFillColor(sf::Color::White);
    }
    if(m_isPlayButtonPressed)
    {
        //lobbyMusic.stop();
        m_context->m_states->Add(std::make_unique<Gameplay>(m_context));
    }
    else if(m_isExitButtonPressed)
    {
        m_context->m_window->close();
    }
}
void MainMenu::Draw()
{
    m_context->m_window->clear();
    m_context->m_window->draw(m_gameTitle);
    m_context->m_window->draw(m_intructions);
    m_context->m_window->draw(logo);
    m_context->m_window->draw(peBox);
    m_context->m_window->draw(m_playButton);
    m_context->m_window->draw(m_exitButton);
    m_context->m_window->display();
}
