#pragma once
#include <memory>
#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>
#include <vector>
#include <sstream>
#include <string>

#include "ResourcePath.hpp"
#include "Enemy.hpp"
#include "Player.hpp"
#include "Bullet.hpp"
#include "Game.hpp"
#include "State.hpp"

class Gameplay : public State
{
public:
    Gameplay(std::shared_ptr<Context> &context);
    ~Gameplay();
    
    void Init() override;
    void ProcessInput() override;
    void Update(sf::Time deltaTime) override;
    void Draw() override;
    void Pause() override;
    void Start() override;
private:
    std::shared_ptr<Context> m_context;

    //Player
    sf::Texture playerTexture;
    Player player;

    //Enemy
    std::vector<Enemy> enemies = {};
    sf::Texture enemyTexture;
    int max_enemy = 1;

    //Bullets
    sf::Texture bulletTexture;
    std::vector<Bullet> bullets = {};
    int max_bullets = 1;

    //score
    sf::Font sfCompact;
    std::ostringstream ssScore;
    sf::Text lblscore;
    int score = 0;
    
    //time limit
    sf::Clock m_clock;
    float shootingDuration;
    float shootingDurationMax = 1.8;
    
    //timer text
    std::ostringstream ssTimer;
    sf::Text lblTimer;
    
    //contatiner
    sf::RectangleShape container;
    sf::RectangleShape clock;
    sf::Texture clock_tex;
};
//int Gameplay::score = 0;
