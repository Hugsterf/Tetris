#pragma once
#include <vector>

class Rand {
private:
    static std::vector<char> bag;

public:
    static void initializ();
    static void mix();
    static void resetBag();
    static char getNext();
    static void createRandomShape();
};
