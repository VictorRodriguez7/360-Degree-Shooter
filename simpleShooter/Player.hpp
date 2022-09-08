#pragma once

#include <iostream>
#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>
#include "Enemy.hpp"
#include "Bullet.hpp"

class Player
{
public:
    bool isIntersectingWithEnemy(Enemy en);
    Player(sf::Texture &playerTexture);
    void draw(std::unique_ptr<sf::RenderWindow>& window);
    void update();
    float getRotationAngle();
private:
    float movement = 0.0f;
    sf::RectangleShape body;
    sf::Rect<float> bodyrect;
    float speed;
};
