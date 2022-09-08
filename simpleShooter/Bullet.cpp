#include "Bullet.hpp"
#include <iostream>
#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>
#include <cmath>
#include "Player.hpp"
#include "ResourcePath.hpp"

const float pi = 3.14;

Bullet::Bullet(sf::Texture &bulletTexture)
{
    bulletTexture.loadFromFile(filepath + "bullet1.png");
    body.setTexture(&bulletTexture);
    body.setSize(sf::Vector2<float>(35.0,73.0));
}

void Bullet::draw(std::unique_ptr<sf::RenderWindow>& window)
{
    window->draw(body);
}

void Bullet::update(float rotationAngle)
{
    
    body.setOrigin(17.5,25);
    if(!fired)
    {
        velocity.x = sin((pi/180)*rotationAngle)*speed;
        velocity.y = cos((pi/180)*rotationAngle)*speed;
        body.rotate(rotationAngle * (-1));
        fired = true;
    }

    x -= velocity.x;
    y -= velocity.y;

    body.setPosition((x),(y));
}
bool Bullet::isIntersectingWithEnemy(Enemy en)
{
    if(body.getGlobalBounds().intersects(en.getGlobalBounds()))
    {
        return true;
    }
    else
        return false;
}
sf::Vector2f Bullet::getPos()
{
    return body.getPosition();
}
