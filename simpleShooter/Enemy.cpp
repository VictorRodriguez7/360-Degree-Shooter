#include <iostream>
#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>
#include <cstdlib>
#include <ctime>
#include <vector>
#include <random>
#include "ResourcePath.hpp"
#include "Enemy.hpp"
#include "Player.hpp"

#define SCREEN_HEIGHT 1400
#define SCREEN_WIDTH 1400

Enemy::Enemy(sf::Texture &enemyTexture)
{

    srand(std::chrono::steady_clock::now().time_since_epoch().count());
    
    bodyrect.width = 1200;
    bodyrect.height = 1200;
    bodyrect.left = 100;
    bodyrect.top = 100;
    enemyTexture.loadFromFile(filepath + "bat.png");
    body.setTexture(&enemyTexture);
    body.setSize(sf::Vector2<float>(80,80));
    
    body.setPosition(sf::Vector2f(float(rand() % (int(bodyrect.width)))+bodyrect.left,(float(rand() % (int(bodyrect.height)))+bodyrect.top)));

}
void Enemy::draw(std::unique_ptr<sf::RenderWindow>& window)
{
    window->draw(body);
}
sf::FloatRect Enemy::getGlobalBounds()
{
    return body.getGlobalBounds();
}



