#include <iostream>
#include <fstream>
#include "MultiSet.h"

int main() {
    MultiSet set1(30, 3);

    set1.add(1);
    set1.add(13);
    set1.add(2);
    set1.add(2);
    set1.add(1);
    set1.add(14);

    set1.add(15);
    set1.add(13);
    set1.add(14);
    set1.add(24);
    set1.add(30);

    MultiSet set2(20, 4);

    set1.add(3);
    set2.add(20);
    set1.add(10);
    set1.add(5);
    set1.add(20);
    set1.add(10);  
    set1.add(5);
    set1.printMultiSet();

    set1.contains(10);
    set2.printLikeInMemory();

    MultiSet intersection(30, 3);
    intersection = intersectionOfSets(set1, set2);
    MultiSet difference(30, 3);
    difference = differenceOfSets(set1, set2);
    std::ofstream ofs("set.dat", std::ios::binary);
    set1.serialize(ofs);

    std::ifstream ifs("set.dat", std::ios::binary);
    set1.deserialize(ifs)
}
