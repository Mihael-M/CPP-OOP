//
//  Player.h
//  MMORPG
//
//  Created by Mishoni Mihaylov on 16.05.25.
//

#ifndef Player_h
#define Player_h
#include <ostream>

struct Point{
    unsigned x;
    unsigned y;
};

enum class Weapon{
    Sword,
    Wand,
    Staff,
    Axe
};

class Player{
public:
    //constructors:
    Player();
    
    Player(int health, const char* name,unsigned attack_damage,Weapon weapon,const Point& position);
    
    Player(const Player& other);
    
    //operators:
    Player& operator=(const Player& other);
    
    
    //functionality:
    
    void move(const Point& position);
    
    void move(unsigned x,unsigned y);
    
    virtual unsigned get_attack_power() const;
    
    virtual void take_damage(unsigned damage);
    
    unsigned get_health() const;
    
    virtual void print_player(std::ostream& os) const;
    
    bool are_close(const Player& other) const;
    
    bool is_dead() const;
    
    const char* get_name()const;
    
    const Point& get_position() const;
    
    virtual Player* clone() const = 0;
    
    //destructor:
    
    virtual ~Player();
    
    friend bool operator==(const Player& ls,const Player& rs);
    friend bool operator!=(const Player& ls,const Player& rs);
    
private:
    void copyDynamic(const Player& other);
    
    void freeDynamic();
    
    void print_weapon(std::ostream& os) const;
    
  
    
    unsigned abs(int num) const;
    
    // the player has:
    
    int health;
    char* name;
    unsigned attack_damage;
    Weapon weapon;
    Point position;
    
    
    
};


#endif /* Player_h */
