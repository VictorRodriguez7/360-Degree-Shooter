#pragma once
#include <memory>
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include "State.hpp"
#include "Game.hpp"

class MainMenu : public State
{
public:
    MainMenu(std::shared_ptr<Context>&  context);
    ~MainMenu();
    
    void Init() override;
    void ProcessInput() override;
    void Update(sf::Time deltaTime) override;
    void Draw() override;
    
private:
    std::shared_ptr<Context> m_context;
    sf::Text m_gameTitle;
    sf::Text m_playButton;
    sf::Text m_exitButton;
    sf::Text m_intructions;
    sf::Font sfCompact;
    
    sf::RectangleShape peBox;
    sf::RectangleShape logo;
    sf::Texture logotex;
    sf::Music lobbyMusic;
    sf::Sound lobby;
    bool m_isPlayButtonSelected;
    bool m_isExitButtonSelected;
    
    bool m_isPlayButtonPressed;
    bool m_isExitButtonPressed;
};
