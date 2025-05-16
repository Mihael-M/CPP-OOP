//
//  Player.cpp
//  MMORPG
//
//  Created by Mishoni Mihaylov on 16.05.25.
//

#include <stdio.h>
#include "Player.h"
#include <iostream>
#include <cstring>

Player::Player() : Player(1,"unknown",0,Weapon::Staff,Point()) {}

Player::Player(int health, const char* name,unsigned attack_damage,Weapon weapon,const Point& position) : health(health), attack_damage(attack_damage), weapon(weapon) ,position(position)
{
    this->name = new char[std::strlen(name) + 1];
    std::strcpy(this->name, name);
}

Player::Player(const Player& other) : health(other.health),attack_damage(other.attack_damage),weapon(other.weapon),position(other.position)
{
    copyDynamic(other);
}

//operators:
Player& Player::operator=(const Player& other)
{
    if(this != &other)
    {
        attack_damage = other.attack_damage;
        health = other.health;
        weapon = other.weapon;
        position = other.position;
        freeDynamic();
        copyDynamic(other);
    }
    return *this;
}


//functionality:

const Point& Player::get_position() const
{
    return position;
}

const char* Player::get_name()const
{
    return name;
}


void Player::move(const Point& position)
{
    this->position = position;
}
void Player::move(unsigned x,unsigned y)
{
    position.x = x;
    position.y = y;
}

bool Player::is_dead() const
{
    return health <= 0;
}

bool Player::are_close(const Player& other) const
{
    return abs(position.x - other.position.x) == 1 || abs(position.y - other.position.y) == 1;
}

void Player::take_damage(unsigned damage)
{
    health -= damage;
}

unsigned Player::get_attack_power() const
{
    return attack_damage;
}

unsigned Player::get_health() const
{
    return health;
}

void Player::print_player(std::ostream& os) const
{
    if(os.good())
    {
        os<<"Player name: " << name<<std::endl;
        os<<"Player health: " << health<<std::endl;
        os<<"Player attack damage: " << get_attack_power()<<std::endl;
        os<<"Player position: " << position.x << " " << position.y <<std::endl;
        os<<"Player weapon: " ;
        print_weapon(os);
        os<<std::endl;
    }

}

unsigned Player::abs(int num) const
{
    return num < 0 ? num * -1 : num;
}


void Player::print_weapon(std::ostream& os) const
{
    switch (weapon) {
        case Weapon::Staff:
            os<<"Staff";
            break;
        case Weapon::Wand:
            os<<"Wand";
            break;
        case Weapon::Sword:
            os<<"Sword";
            break;
        case Weapon::Axe:
            os<<"Axe";
            break;
        default:
            os<<"Weapon Error";
    }
}



void Player::copyDynamic(const Player& other)
{
    this->name = new char[std::strlen(other.name) + 1];
    std::strcpy(this->name, other.name);
}
void Player::freeDynamic()
{
    delete[] name;
}

Player::~Player()
{
    freeDynamic();
}


bool operator==(const Player& ls,const Player& rs)
{
    return std::strcmp(ls.name, rs.name) == 0;
}
bool operator!=(const Player& ls,const Player& rs)
{
    return !(ls == rs);
}
