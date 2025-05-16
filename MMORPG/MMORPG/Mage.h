//
//  Mage.h
//  MMORPG
//
//  Created by Mishoni Mihaylov on 16.05.25.
//

#ifndef Mage_h
#define Mage_h
#include "Player.h"

class Mage : public Player{
public:
    //constructors
    Mage();
    
    Mage(const char* spell,double coefficient,int health, const char* name,unsigned attack_damage,Weapon weapon,const Point& position);
    
    Mage(const Mage& other);
    
    Mage& operator=(const Mage& other);
    
    //functionality:
    
    unsigned int get_attack_power() const override;
    
    void print_player(std::ostream& os) const override;
    
    Player* clone() const override;

    
    //destructor:
    
    ~Mage();
private:
    void set_coef(double coef);
    void copyDynamic(const Mage& other);
    void freeDynamic();
    
    char* spell;
    double coefficient;
};


#endif /* Mage_h */
