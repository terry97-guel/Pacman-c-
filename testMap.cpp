#include <iostream>
#include <SFML/Graphics.hpp>

#include "GameManager.h"



int main()
{
    // int enemyNum = 10;
    // Env* env = new Env(enemyNum);
    // HandlerGUI* handlerGUI = new HandlerGUI(env);    
    // bool open = handlerGUI->window->isOpen();

    GameManager* gameManager = new GameManager();
    gameManager->Run();
    bool open = gameManager->handlerGUI->window->isOpen();

    std::cout << open;


}


