#pragma once
#include <SFML/Graphics.hpp>

namespace Shapes
{
    constexpr int SHAPE_I[4][4] =
    {
        {5,6,7,8},
        {0,0,0,0},  
        {0,0,0,0},
        {0,0,0,0}
    };

    constexpr int SHAPE_J[3][3] =
    {
        {5,0,0},   
        {5,6,7},    
        {0,0,0}
    };

    constexpr int SHAPE_L[3][3] =
    {
        {0,0,7},   
        {5,6,7},    
        {0,0,0}
    };

    constexpr int SHAPE_O[2][2] =
    {
        {5,6},      
        {5,6}       
    };

    constexpr int SHAPE_S[3][3] =
    {
        {0,6,7},    
        {5,6,0},   
        {0,0,0}
    };

    constexpr int SHAPE_T[3][3] =
    {
        {0,6,0},    
        {5,6,7},    
        {0,0,0}
    };

    constexpr int SHAPE_Z[3][3] =
    {
        {5,6,0},    
        {0,6,7},    
        {0,0,0}
    };
}

namespace ShapeColors 
{
    static const sf::Color T = sf::Color::Magenta;
    static const sf::Color J = sf::Color::Blue;
    static const sf::Color L = sf::Color(255, 165, 0);
    static const sf::Color I = sf::Color::Cyan;
    static const sf::Color O = sf::Color::Yellow;
    static const sf::Color S = sf::Color::Green;
    static const sf::Color Z = sf::Color::Red;
}

#define CREATE_SHAPE(shapeName) \
    Forms::createShape(Shapes::SHAPE_##shapeName, ShapeColors::shapeName)
