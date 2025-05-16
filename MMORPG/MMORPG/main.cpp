//
//  main.cpp
//  MMORPG
//
//  Created by Mishoni Mihaylov on 16.05.25.
//

#include <iostream>
#include "PlayerCollection.h"
#include "Warrior.h"
#include "Mage.h"
#include "Necromancer.h"

int main() {
    PlayerCollection collection;

    
    // Create and add players
    collection.add_player(Warrior(100,100,"War",100,Weapon::Sword,{0, 0}));
    collection.add_player(Mage("Fireball",0.2, 80, "Elrion", 10, Weapon::Wand, {1, 0}));
    collection.add_player(Necromancer("Soul Drain",0.3, 90,"Morgul", 10, Weapon::Staff, {2, 0} ));
    collection.add_player(Warrior(110,40, "Krag",10, Weapon::Sword, {3, 0}));
    collection.add_player(Warrior(1000,5,"Petur",30,Weapon::Staff,{1, 0}));
    
    size_t i = 0;
    while (i < collection.get_player_count()) {
        Player& attacker = collection[i];
        size_t j = i + 1;
        while (j < collection.get_player_count()) {
            Player& defender = collection[j];
           

            Point newPos = defender.get_position();
            newPos.x += 1;
            attacker.move(newPos);
            
            defender.take_damage(attacker.get_attack_power());

            if (defender.is_dead()) {
                std::cout << defender.get_name() << " has died.\n";
                collection.remove_player(defender.get_name());
                
            }
            ++j;
        }
        ++i;
    }
    std::cout << "\n--- Surviving Players ---\n";
    for (size_t k = 0; k < collection.get_player_count(); ++k) {
            collection[k].print_player(std::cout);
        std::cout << "------------------------\n";
    }

    return 0;
}
