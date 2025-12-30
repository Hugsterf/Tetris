#pragma once
#include <vector>

class Rand 
{
public:
    static void initialize();
    static void resetBag();
    static void mix();
    static char getNext();
    static void createRandomShape();

private:
    static std::vector<char> bag;
    static bool initialized; 
};