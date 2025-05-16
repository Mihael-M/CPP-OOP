//
//  PlayerCollection.cpp
//  MMORPG
//
//  Created by Mishoni Mihaylov on 16.05.25.
//

#include <stdio.h>
#include "PlayerCollection.h"


PlayerCollection::PlayerCollection() : capacity(4),size(0)
{
    players = new Player*[capacity];
}


PlayerCollection::PlayerCollection(const PlayerCollection& other) : size(other.size),capacity(other.capacity)
{
    copyDynamic(other);
}
PlayerCollection& PlayerCollection::operator=(const PlayerCollection& other)
{
    if(this != &other)
    {
        size = other.size;
        capacity = other.capacity;
        freeDynamic();
        copyDynamic(other);
    }
    return *this;
}


void PlayerCollection::add_player(const Player& player)
{
    if(size == capacity)
        resize(capacity * 2);
    
        for(int i = 0;i<size;i++)
        {
            if(players[i] != nullptr && *players[i] == player)
                throw ("already exists");
        }
    
    for(int i = 0;i<capacity;i++)
    {
        if(players[i] == nullptr)
        {
            players[i] = player.clone();
            size++;
            break;
        }
    }
}

Player& PlayerCollection::operator[](size_t idx) const
{
    if(idx > size)
        throw ("index out of bounds");
    
        return *players[idx];
}


size_t PlayerCollection::get_player_count() const
{
    return size;
}

void PlayerCollection::remove_player(const char* name)
{
    for(int i = 0;i<size;i++){
        
        if(players[i]!=nullptr && std::strcmp(players[i]->get_name(),name) == 0)
        {
            delete players[i];
            for (int j = i; j < size - 1; ++j) {
                players[j] = players[j + 1];
            }
            players[size - 1] = nullptr;
            size--;
            break;
        }
    }
}

void PlayerCollection::resize(size_t newCap)
{
    Player** temp = new Player*[newCap];
    for(int i = 0;i<size;i++)
    {
        temp[i] = players[i];
        
    }
    delete[] players;
    players = temp;
    capacity = newCap;
}

PlayerCollection::~PlayerCollection()
{
    freeDynamic();
}

void PlayerCollection::copyDynamic(const PlayerCollection& other)
{
    players = new Player*[other.capacity];
    for(int i = 0;i<other.get_player_count();i++)
        players[i] = other.players[i]->clone();
}
void PlayerCollection::freeDynamic()
{
    for(int i = 0; i< size; i++)
    {
            delete players[i];
    }
    delete[] players;
}
