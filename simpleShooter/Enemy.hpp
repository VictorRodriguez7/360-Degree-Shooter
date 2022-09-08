#pragma once
#include <iostream>
#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>

class Enemy
{
public:
    Enemy(sf::Texture &enemyTexture);
    void draw(std::unique_ptr<sf::RenderWindow>& window);
    void update();
    sf::FloatRect getGlobalBounds();
private:
    sf::RectangleShape body;
    sf::Rect<float> bodyrect;
};
