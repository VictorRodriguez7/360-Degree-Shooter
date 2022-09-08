#include <iostream>
#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>
#include "Player.hpp"
#include "Enemy.hpp"
#include <cmath>
#include "Bullet.hpp"
#include "ResourcePath.hpp"
#define SCREEN_HEIGHT 1400
#define SCREEN_WIDTH 1400

Player::Player(sf::Texture &playerTexture)
{
    playerTexture.loadFromFile(filepath + "wand.png");
    body.setTexture(&playerTexture);
    body.setSize(sf::Vector2<float>(240.0f,240.f));
    body.setPosition((SCREEN_WIDTH/2), (SCREEN_HEIGHT/2));
    body.setOrigin((body.getSize().x/2), (body.getSize().y/2));
}
void Player::draw(std::unique_ptr<sf::RenderWindow>& window)
{
    window->draw(body);
}
void Player::update()
{
    movement = 0.0f;
    speed = 2.8f;

    movement = movement + speed;
    
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
        body.rotate(movement);
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
        body.rotate(movement * -1);
}
float Player::getRotationAngle()
{
    return (body.getRotation() * -1);
}
bool Player::isIntersectingWithEnemy(Enemy en)
{
    if(body.getGlobalBounds().intersects(en.getGlobalBounds()))
    {
        return true;
    }
    else
        return false;;
}
