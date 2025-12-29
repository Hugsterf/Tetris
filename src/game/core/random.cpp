#include "random.h"
#include "forms.h"
#include <cstdlib>
#include <ctime>
#include <iostream>

std::vector<char> Rand::bag{ 'I', 'J', 'L', 'O', 'S', 'T', 'Z' };

void Rand::initializ()
{
    std::srand(time(NULL));
}

void Rand::resetBag() 
{
    bag.clear();
    bag.push_back('I');
    bag.push_back('J');
    bag.push_back('L');
    bag.push_back('O');
    bag.push_back('S');
    bag.push_back('T');
    bag.push_back('Z');
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