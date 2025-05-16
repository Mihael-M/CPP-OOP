//
//  Warrior.h
//  MMORPG
//
//  Created by Mishoni Mihaylov on 16.05.25.
//

#ifndef Warrior_h
#define Warrior_h
#include "Player.h"

class Warrior : public Player{
public:
    //constructor:
    Warrior() = default;
    Warrior(int armor,int health, const char* name,unsigned attack_damage,Weapon weapon,const Point& position);
    
    //functionality:
    
    void take_damage(unsigned damage) override;
    
    Player* clone() const override;
    
    void print_player(std::ostream& os) const override;
    
    
private:
    
    int armor = 100;
};

#endif /* Warrior_h */
