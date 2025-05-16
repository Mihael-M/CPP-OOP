//
//  Warrior.cpp
//  MMORPG
//
//  Created by Mishoni Mihaylov on 16.05.25.
//

#include <stdio.h>
#include "Warrior.h"


Warrior::Warrior(int armor,int health, const char* name,unsigned attack_damage,Weapon weapon,const Point& position) :Player(health, name, attack_damage, weapon, position), armor(armor) {}

void Warrior::take_damage(unsigned damage)
{
    if(armor >= damage)
        armor -= damage;
    
    else{
        unsigned remaining = get_attack_power() - armor;
        this->armor = 0;
        return Player::take_damage(remaining);
    }
}


void Warrior::print_player(std::ostream& os) const
{
    Player::print_player(os);
    os<<"Player class: Warrior" <<std::endl;
    os<<"Player armor: " <<armor<<std::endl;
}

Player* Warrior::clone() const
{
    return new Warrior(*this);
}
