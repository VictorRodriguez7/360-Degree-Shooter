#pragma once
#include <SFML/Graphics.hpp>
class State
{
public:
    State(){};
    virtual ~State(){};
    
    //initializes variables for state
    virtual void Init() = 0;
    
    //handles input such as keypress
    virtual void ProcessInput() = 0;
    
    //updates after input
    virtual void Update(sf::Time deltaTime) = 0;
    
    //draws everything
    virtual void Draw() = 0;
    
    //Pause and start
    virtual void Pause(){};
    virtual void Start(){};
};
