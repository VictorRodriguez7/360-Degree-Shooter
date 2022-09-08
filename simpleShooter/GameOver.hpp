#pragma once
#include <memory>
#include <SFML/Graphics.hpp>
#include "State.hpp"
#include "Game.hpp"
#include "GamePlay.hpp"
#include<string>
#include <sstream>

class GameOver : public State
{
public:
    GameOver(std::shared_ptr<Context>&  context,int score);
    GameOver(int score);
    ~GameOver();
    
    void Init() override;
    void ProcessInput() override;
    void Update(sf::Time deltaTime) override;
    void Draw() override;
    
private:
    
    std::shared_ptr<Context> m_context;
    sf::Text m_gameOverTitle;
    sf::Text m_retryButton;
    sf::Text m_exitButton;
    sf::Font sfCompact;
    
    sf::RectangleShape reBox;
    std::ostringstream gameover_ssScore;
    sf::Text gameover_lblscore;
    int gameover_score;
    
    bool m_isRetryButtonSelected;
    bool m_isExitButtonSelected;
    
    bool m_isRetryButtonPressed;
    bool m_isExitButtonPressed;
};
