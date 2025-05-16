//
//  Mage.cpp
//  MMORPG
//
//  Created by Mishoni Mihaylov on 16.05.25.
//

#include <stdio.h>
#include "Mage.h"

Mage::Mage() : Mage("Fireball",0,1,"Unknown",0,Weapon::Staff,Point()) {}

Mage::Mage(const char* spell,double coefficient,int health, const char* name,unsigned attack_damage,Weapon weapon,const Point& position) : Player(health,name,attack_damage,weapon,position)
{
    this->spell = new char[std::strlen(spell) + 1];
    std::strcpy(this->spell, spell);
    set_coef(coefficient);
}

Mage::Mage(const Mage& other) : Player(other)
{
    copyDynamic(other);
    
}
void Mage::set_coef(double coef){
    if(coef > 1 || coef < 0)
        throw std::invalid_argument("Error setting the coefficient");
    this->coefficient = coef;
}

Mage& Mage::operator=(const Mage& other)
{
    if(this != &other)
    {
        Player::operator=(other);
        this->coefficient = other.coefficient;
        freeDynamic();
        copyDynamic(other);
        
    }
    return *this;
}


void Mage::copyDynamic(const Mage& other)
{
    this->spell = new char[std::strlen(other.spell) + 1];
    std::strcpy(this->spell, other.spell);
}
void Mage::freeDynamic()
{
    delete[] spell;
}

Mage::~Mage()
{
    freeDynamic();
}


unsigned int Mage::get_attack_power() const
{
    double attack_bonus = Player::get_health() * coefficient;
    return Player::get_attack_power() + attack_bonus;
}

void Mage::print_player(std::ostream& os) const
{
    Player::print_player(os);
    os<<"Player class Mage" << std::endl;
    os<<"Mage spell" << spell <<std::endl;
    os<<"Damage coef" << coefficient<<std::endl;
}

Player* Mage::clone() const
{
    return new Mage(*this);
}
