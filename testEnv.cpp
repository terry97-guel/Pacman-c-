#include <iostream>
#include <SFML/Graphics.hpp>

#include "GameManager.h"

int main()
{
    int enemyNum = 10;
    Env* env = new Env(enemyNum);
    env->PrintInfo();
    // Env env = Env(enemyNum);
    // env.PrintInfo();
    
    std::cout << "Exiting..!! \n\n" << std::endl;
}


