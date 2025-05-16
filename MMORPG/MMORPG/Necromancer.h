//
//  Necromancer.h
//  MMORPG
//
//  Created by Mishoni Mihaylov on 16.05.25.
//

#ifndef Necromancer_h
#define Necromancer_h
#include "Mage.h"

class Necromancer : public Mage{
public:
    //constructors:
    Necromancer() = default;
    
    Necromancer(const char* spell,double coefficient,int health, const char* name,unsigned attack_damage,Weapon weapon,const Point& position);
    
    Necromancer(const Necromancer& other);
    Necromancer& operator=(const Necromancer& other);
    
    //functionality:
    void add_soldier(Player& soldier);
    
    unsigned get_attack_power() const override;
    
    bool no_soldiers() const;
    
    void print_player(std::ostream& os) const override;
    
    Player* clone() const override;

    //destructor:
    ~Necromancer();
    
private:
    void resize(size_t newCap);
    
    void copyDynamic(const Necromancer& other);
    
    void freeDynamic();
    
    Player** soldiers = nullptr;
    
    size_t size = 0;
    
    size_t capacity = 4;
    
};

#endif /* Necromancer_h */
