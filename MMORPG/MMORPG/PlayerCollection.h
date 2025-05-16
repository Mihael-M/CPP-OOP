//
//  PlayerCollection.h
//  MMORPG
//
//  Created by Mishoni Mihaylov on 16.05.25.
//

#ifndef PlayerCollection_h
#define PlayerCollection_h
#include "Player.h"

class PlayerCollection{
public:
    PlayerCollection();
    PlayerCollection(const PlayerCollection& other);
    PlayerCollection& operator=(const PlayerCollection& other);
    //functionality:
    void add_player(const Player& player);
    
    Player& operator[](size_t idx) const;

    size_t get_player_count() const;
    
    void remove_player(const char* name);
    
    
    ~PlayerCollection();
private:
    void copyDynamic(const PlayerCollection& other);
    void freeDynamic();
    void resize(size_t newCap);

    Player** players;
    size_t size;
    size_t capacity;
    
};

#endif /* PlayerCollection_h */
