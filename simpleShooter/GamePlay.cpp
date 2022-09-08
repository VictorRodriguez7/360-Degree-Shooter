#include "GamePlay.hpp"
#include "Game.hpp"
#include "ResourcePath.hpp"
#include "GameOver.hpp"
#include <vector>
#include <SFML/Graphics.hpp>
#include <iomanip>

Gameplay::Gameplay(std::shared_ptr<Context> &context) :m_context(context),player(playerTexture){}

Gameplay::~Gameplay(){}

void Gameplay::Init()
{
    //score
    sfCompact.loadFromFile(filepath + "SFCompact.ttf");
    ssScore << "Score: " << score;
    lblscore.setOutlineThickness(4);
    lblscore.setOutlineColor(sf::Color::Black);
    lblscore.setCharacterSize(70);
    lblscore.setPosition(25, 10);
    lblscore.setString(ssScore.str());
    lblscore.setFont(sfCompact);

    //timer
    ssTimer << std::fixed <<std::setprecision(1) << shootingDuration << "/1.8";
    lblTimer.setOutlineThickness(4);
    lblTimer.setOutlineColor(sf::Color::Black);
    lblTimer.setCharacterSize(70);
    lblTimer.setPosition(100, 80);
    lblTimer.setString(ssTimer.str());
    lblTimer.setFont(sfCompact);
    
    //clock
    clock.setFillColor(sf::Color::White);
    clock.setSize(sf::Vector2f(80,80));
    clock.setPosition(15, 85);
    clock_tex.loadFromFile(filepath + "clock.png");
    clock.setTexture(&clock_tex);
    
    //container
    container.setFillColor(sf::Color(113, 121, 126));
    container.setOutlineColor(sf::Color::Black);
    container.setSize(sf::Vector2f(350,150));
    container.setOutlineThickness(10);
    container.setPosition(15, 20);
}
void Gameplay::ProcessInput()
{
    sf::Event event;
    while(m_context->m_window->pollEvent(event))
    {
        if(event.type == sf::Event::Closed)
        {
            m_context->m_window->close();
        }
        if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Key::Space  && bullets.size() < max_bullets)
        {
            bullets.push_back(Bullet(bulletTexture));
        }
    }
}
void Gameplay::Update(sf::Time deltaTime)
{
    
    player.update();
    if(enemies.size() < max_enemy)
    {
        enemies.push_back(Enemy(enemyTexture));
    }
    shootingDuration = m_clock.getElapsedTime().asSeconds();
    ssTimer.str("");
    ssTimer << std::fixed <<std::setprecision(1)<< shootingDuration << "/1.8";
    lblTimer.setString(ssTimer.str());
    if(!bullets.empty())
    {
        m_clock.restart();
    }
    if (shootingDuration >= shootingDurationMax)
    {
        m_context->m_states->Add(std::make_unique<GameOver>(m_context,score), true);
    }
}
void Gameplay::Draw()
{
    m_context->m_window->clear(sf::Color(113, 121, 126));

    for(Enemy& e : enemies)
        {
            while(e.getGlobalBounds().intersects(container.getGlobalBounds()))
            {
                enemies.pop_back();
                enemies.push_back(Enemy(enemyTexture));
            }
            while(player.isIntersectingWithEnemy(e))
                {
                    enemies.pop_back();
                    enemies.push_back(Enemy(enemyTexture));
                }
    
                e.draw(m_context->m_window);
        
    
                for(Bullet& b : bullets)
                {

                    b.update(player.getRotationAngle());

                    if (b.isIntersectingWithEnemy(e))
                    {
                        enemies.pop_back();
                        bullets.pop_back();
                        

                        //updates score
                        score++;
                        ssScore.str("");
                        ssScore << "Score: " << score;
                        lblscore.setString(ssScore.str());
                    }
                    if(b.getPos().x < 0 || b.getPos().x > 1400||b.getPos().y < 0 || b.getPos().y > 1400)
                    {
                        m_context->m_states->Add(std::make_unique<GameOver>(m_context,score), true);
                    }
                    b.draw(m_context->m_window);
                }
            
            
        }
    m_context->m_window->draw(container);
    m_context->m_window->draw(lblscore);
    m_context->m_window->draw(lblTimer);
    m_context->m_window->draw(clock);
    player.draw(m_context->m_window);
    m_context->m_window->display();
}
void Gameplay::Pause()
{
    
}
void Gameplay::Start()
{
    
}

