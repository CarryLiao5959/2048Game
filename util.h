#ifndef UTIL_H
#define UTIL_H

#pragma once

#include <random>

using namespace std;

#define ROW_NUM 4
#define DOUBLE_TRYS 3

inline int getTowOrFour()
{
    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<> dis(0, 9);
    int random_number2 = dis(gen);
    if (random_number2 >= 0 && random_number2 <= 7)
    {
        return 2;
    }
    else
    {
        return 4;
    }
}

inline int getRand16()
{
    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<> dis(0, 15);
    return dis(gen);
}

#endif // !UTIL_H