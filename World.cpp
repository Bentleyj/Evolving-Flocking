//
//  World.cpp
//  flocking
//
//  Created by James Bentley on 9/30/14.
//
//

#include "World.h"

World::World()
{
    doves = vector<Dove>();
    foods = vector<Food>();
    hawks = vector<Hawk>();
}

void World::run()
{
    for(int i = 0; i < doves.size(); i++)
    {
        doves[i].run(doves);
        doves[i].eat(foods);
        if(doves[i].isDead())
        {
            foods.push_back(Food(doves[i].getLocation().x, doves[i].getLocation().y));
            doves.erase(doves.begin() + i);
        }
        
        Dove child = doves[i].reproduce();
        
        if((child.getLocation().x < ofGetWidth()) && (child.getLocation().y < ofGetHeight()))
        {
            addDove(child);
        }
    }
    
    for(int i = 0; i < hawks.size(); i++)
    {
        hawks[i].run(hawks);
        hawks[i].eat(doves);
        if(hawks[i].isDead())
        {
            foods.push_back(Food(hawks[i].getLocation().x, hawks[i].getLocation().y));
            hawks.erase(hawks.begin() + i);
        }
        
        Hawk child = hawks[i].reproduce();
        
        if((child.getLocation().x < ofGetWidth()) && (child.getLocation().y < ofGetHeight()))
        {
            addHawk(child);
        }
    }
}

void World::display()
{
    for(int i = 0; i < doves.size(); i++)
    {
        doves[i].display();
    }
    
    for(int i = 0; i < foods.size(); i++)
    {
        foods[i].display();
    }
    
    for(int i = 0; i < hawks.size(); i++)
    {
        hawks[i].display();
    }
}

void World::addDove(Dove dove)
{
    doves.push_back(dove);
}

void World::addFood(Food food)
{
    foods.push_back(food);
}

void World::addHawk(Hawk hawk)
{
    hawks.push_back(hawk);
}

