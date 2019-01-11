#include <iostream>
#include<bits/stdc++.h>
#include "dice.h"

int main(int argc, char *argv[])
{
    // see example at: https://en.wikipedia.org/wiki/S%C3%B8rensen%E2%80%93Dice_coefficient
    float sim = dice_comp("night", "nacht");
    float expected = 0.25f;

    if (sim == expected)
    {
        std::cout << "Test passed with value: " << sim << std::endl;
        return 0;
    }

    std::cerr << "Test failed with value: " << sim << ", expected: " << expected << std::endl;
    return 1;
}