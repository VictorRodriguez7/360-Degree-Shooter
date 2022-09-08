#pragma once
#include <stack>
#include <memory>

#include "State.hpp"

class StateManager
{
public:
    StateManager();
    ~StateManager();
    
    //adds a new state or replaces
    void Add(std::unique_ptr<State> toAdd, bool replace = false);
    
    //removes state
    void PopCurrent();
    
    //where actual state change occurs
    void ProcessStateChanges();
    
    //gets currentState
    std::unique_ptr<State>& GetCurrent();
    
private:
    std::stack<std::unique_ptr<State>> m_stateStack;
    std::unique_ptr<State> m_newState;
    
    bool m_add;
    bool m_replace;
    bool m_remove;
    
    
};
