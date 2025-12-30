#include "random.h"
#include "forms.h"
#include <cstdlib>
#include <ctime>
#include <iostream>

std::vector<char> Rand::bag{ 'I', 'J', 'L', 'O', 'S', 'T', 'Z' };

bool Rand::initialized = false;

void Rand::initialize() {
    if (!initialized) {
        std::srand(static_cast<unsigned int>(time(NULL)));
        resetBag();
        initialized = true;
    }
}

void Rand::resetBag() {
    bag.clear();
    bag = { 'I', 'J', 'L', 'O', 'S', 'T', 'Z' }; 
    mix(); 
}

void Rand::mix() 
{
    for (int i = bag.size() - 1; i > 0; i--) 
    {
        int j = std::rand() % (i + 1);
        std::swap(bag[i], bag[j]);
    }
}

char Rand::getNext() 
{
    if (bag.empty()) 
    {
        resetBag();
        mix();
    }

    char next = bag.back();
    bag.pop_back();
    return next;
}

void Rand::createRandomShape() 
{
    char shape = getNext();

    switch (shape) 
    {
    case 'I': CREATE_SHAPE(I); break;
    case 'J': CREATE_SHAPE(J); break;
    case 'L': CREATE_SHAPE(L); break;
    case 'O': CREATE_SHAPE(O); break;
    case 'S': CREATE_SHAPE(S); break;
    case 'T': CREATE_SHAPE(T); break;
    case 'Z': CREATE_SHAPE(Z); break;
    }
}