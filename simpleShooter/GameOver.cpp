#include "GameOver.hpp"
#include <SFML/Graphics.hpp>
#include "MainMenu.hpp"
#include "ResourcePath.hpp"


GameOver::GameOver(std::shared_ptr<Context>&  context,int score)
:m_context(context), m_isRetryButtonSelected(true),m_isExitButtonSelected(false),m_isRetryButtonPressed(false),m_isExitButtonPressed(false),gameover_score(score){}


GameOver::~GameOver(){}

void GameOver::Init()
{
    //Title
    sfCompact.loadFromFile(filepath + "SFCompact.ttf");
    m_gameOverTitle.setFont(sfCompact);
    m_gameOverTitle.setFillColor(sf::Color::Black);
    m_gameOverTitle.setString("Game Over");
    m_gameOverTitle.setOutlineThickness(8);
    m_gameOverTitle.setOutlineColor(sf::Color::Red);
    m_gameOverTitle.setCharacterSize(200);
    m_gameOverTitle.setOrigin(m_gameOverTitle.getLocalBounds().width/2, m_gameOverTitle.getLocalBounds().height/2);
    m_gameOverTitle.setPosition(m_context->m_window->getSize().x/2, m_context->m_window->getSize().y - 1050);
    
    //Play
    sfCompact.loadFromFile(filepath + "SFCompact.ttf");
    m_retryButton.setFont(sfCompact);
    m_retryButton.setString("Retry");
    m_retryButton.setCharacterSize(50);
    m_retryButton.setOrigin(m_retryButton.getLocalBounds().width/2, m_retryButton.getLocalBounds().height/2);
    m_retryButton.setPosition(m_context->m_window->getSize().x/2, m_context->m_window->getSize().y - 610);
    
    //Exit
    sfCompact.loadFromFile(filepath + "SFCompact.ttf");
    m_exitButton.setFont(sfCompact);
    m_exitButton.setString("Exit");
    m_exitButton.setCharacterSize(50);
    m_exitButton.setOrigin(m_exitButton.getLocalBounds().width/2, m_exitButton.getLocalBounds().height/2);
    m_exitButton.setPosition(m_context->m_window->getSize().x/2, m_context->m_window->getSize().y - 510);
    
    //Best Score
    gameover_ssScore << "Your Score Was: " << gameover_score;
    gameover_lblscore.setCharacterSize(70);
    gameover_lblscore.setOrigin(gameover_lblscore.getLocalBounds().width/2,gameover_lblscore.getLocalBounds().height/2);
    gameover_lblscore.setPosition(m_context->m_window->getSize().x/2 - 305, m_context->m_window->getSize().y - 840);
    gameover_lblscore.setString(gameover_ssScore.str());
    gameover_lblscore.setFont(sfCompact);
    
    reBox.setSize(sf::Vector2f(200,230));
    reBox.setFillColor(sf::Color::Black);
    reBox.setOutlineThickness(5);
    reBox.setOutlineColor(sf::Color::White);
    reBox.setOrigin(reBox.getSize().x/2, reBox.getSize().y/2);
    reBox.setPosition(m_context->m_window->getSize().x/2, m_context->m_window->getSize().y - 545);
}
void GameOver::ProcessInput()
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
                    if(!m_isRetryButtonSelected)
                    {
                        m_isRetryButtonSelected = true;
                        m_isExitButtonSelected = false;
                    }
                    break;
                }
                case sf::Keyboard::Down:
                {
                    if(!m_isExitButtonSelected)
                    {
                        m_isExitButtonSelected = true;
                        m_isRetryButtonSelected= false;
                    }
                    break;
                }
                case sf::Keyboard::Return:
                {
                    m_isRetryButtonPressed=false;
                    m_isExitButtonPressed = false;
                    if(m_isRetryButtonSelected)
                    {
                        m_isRetryButtonPressed = true;
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
void GameOver::Update(sf::Time deltaTime)
{
    if(m_isRetryButtonSelected)
    {
        m_retryButton.setFillColor(sf::Color::Yellow);
        m_exitButton.setFillColor(sf::Color::White);
    }
    else
    {
        m_exitButton.setFillColor(sf::Color::Yellow);
        m_retryButton.setFillColor(sf::Color::White);
    }
    if(m_isRetryButtonPressed)
    {
        m_context->m_states->Add(std::make_unique<Gameplay>(m_context));
    }
    else if(m_isExitButtonPressed)
    {
        m_context->m_window->close();
    }
}
void GameOver::Draw()
{
    m_context->m_window->clear();
    m_context->m_window->draw(m_gameOverTitle);
    m_context->m_window->draw(reBox);
    m_context->m_window->draw(m_retryButton);
    m_context->m_window->draw(m_exitButton);
    m_context->m_window->draw(gameover_lblscore);
    m_context->m_window->display();
}
