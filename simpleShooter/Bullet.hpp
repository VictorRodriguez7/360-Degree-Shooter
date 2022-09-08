#pragma once
#include <iostream>
#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>
#include "Enemy.hpp"

class Bullet
{
public:
    Bullet(sf::Texture &enemyTexture);
    bool isIntersectingWithEnemy(Enemy en);
    void draw(std::unique_ptr<sf::RenderWindow>& window);
    void update(float rotationAngle);
    sf::Vector2f getPos();
    
    
private:
    float timeElapsed;
    sf::RectangleShape body;
    float speed = 22.f;
    sf::Vector2f velocity;
    float x = 700;
    float y = 700;
    bool fired = false;
};
