#pragma once
#include <iostream>
#include "vector.h"
#include <iterator>

template <typename Thing>
class Bag {
public:
    typedef typename vector<Thing>::iterator iterator;
    typedef typename vector<Thing>::const_iterator const_iterator;
    iterator begin() { return bagContents.begin(); }
    iterator end() { return bagContents.end(); }
    const_iterator cbegin() const { return bagContents.cbegin(); }
    const_iterator cend() const { return bagContents.cend(); }
    
    void insert(Thing aThing) {
        bagContents.push_back(aThing);
        bagSize++;
    }
    Thing &pop() {
        Thing aThing;
        if (bagContents.size() > 0) {
            aThing = bagContents[bagSize];
            bagSize--;
        }
        else {
            std::cerr << "Can't pop out of an empty bag" << std::endl;
        }
        return aThing;
    }
    int size() {
        return bagSize;
    }
    int count(Thing aThing) {
        int bagCount = 0;
        for (int i = 0 ; i < bagSize; i++) {
            if (bagContents[i] == aThing) {
                bagCount++;
            }
        }
        return bagCount;
    }
    
private:
    vector<Thing> bagContents;
    int bagSize = 0;
};