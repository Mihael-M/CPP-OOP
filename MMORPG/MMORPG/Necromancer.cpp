//
//  Necromancer.cpp
//  MMORPG
//
//  Created by Mishoni Mihaylov on 16.05.25.
//

#include <stdio.h>
#include "Necromancer.h"



Necromancer::Necromancer(const char* spell,double coefficient,int health, const char* name,unsigned attack_damage,Weapon weapon,const Point& position)
: Mage(spell, coefficient, health, name, attack_damage, weapon, position) , size(0),capacity(4)
{
    this->soldiers = new Player*[capacity];
}

void Necromancer::resize(size_t newCap)
{
    Player** temp = new Player*[newCap];
    for(int i = 0;i<size;i++)
        temp[i] = soldiers[i];
    delete[] soldiers;
    soldiers = temp;
    temp = nullptr;
}

void Necromancer::add_soldier(Player& soldier)
{
    if(size == capacity)
        resize(capacity * 2);
    
    soldiers[size++] = &soldier;
}

Necromancer::Necromancer(const Necromancer& other): Mage(other),size(other.size), capacity(other.capacity)
{
    copyDynamic(other);
}
Necromancer& Necromancer::operator=(const Necromancer& other)
{
    if(this != &other)
    {
        Mage::operator=(other);
        size = other.size;
        capacity = other.capacity;
        freeDynamic();
        copyDynamic(other);
    }
    return *this;
}

Necromancer::~Necromancer()
{
    freeDynamic();
}

void Necromancer::copyDynamic(const Necromancer& other)
{
    this->soldiers = new Player*[other.capacity];
    for(int i = 0;i < other.size;i++)
        soldiers[i] = other.soldiers[i]->clone();
}
void Necromancer::freeDynamic()
{
    delete[] soldiers;
}

bool Necromancer::no_soldiers() const
{
    return size == 0;
}

unsigned Necromancer::get_attack_power() const
{
    return no_soldiers() ? Player::get_attack_power() : Player::get_attack_power() + soldiers[0]->get_attack_power();
}

void Necromancer::print_player(std::ostream& os) const
{
    Player::print_player(os);
    os<<"Player class Necromancer: ";
    os<<"Soldiers:  ->"<<std::endl;
    for(int i = 0;i<size;i++)
    {
        soldiers[i]->print_player(os);
        os<<std::endl;
    }
    
}

Player* Necromancer::clone() const
{
    return new Necromancer(*this);
}
