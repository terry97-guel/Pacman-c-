#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>


class UserState{
    public:
        sf::Vector2i pos {0,0};
        int score = 0;
        int life = 10;
        void PrintInfo();
        
};

void UserState::PrintInfo(){
    std::cout<< "--------------------- User State ------------------" << std::endl;
    std::cout<< "Score:" << score << std::endl;
    std::cout<< "Life:" << life << std::endl;
    std::cout<< "Pos: (" << pos.x << "," << pos.y << ")" << std::endl;
}




class EnemyState{
    public:
        sf::Vector2i pos {0,0};
        void PrintInfo(int EnemyIdx);
        EnemyState();
        EnemyState(int pos_x, int pos_y);
};

EnemyState::EnemyState(){

}

EnemyState::EnemyState(int pos_x, int pos_y){
    pos = {pos_x,pos_y}; 
}

void EnemyState::PrintInfo(int EnemyIdx){
    std::cout<< "--------------------- Enemy" << EnemyIdx <<" State ------------------" << std::endl;
    std::cout<< "Pos (" << pos.x << "," << pos.y << ")" << std::endl;
}




class Env{
    public:
        // GUI* gui;
        UserState* userState;
        EnemyState* enemyStates;
        int numEnemy;
        Env(int numEnemy);
        void PrintInfo();
};

Env::Env(int numEnemy):numEnemy(numEnemy){
    userState = new UserState();
    enemyStates = new EnemyState[numEnemy];

    for (int i=0; i<numEnemy; i++){
        enemyStates[i] = EnemyState(i, i);
    }
}

void Env::PrintInfo(){
    this->userState->PrintInfo();
    int enemyIdx = 0;
    for (int enemyIdx=0; enemyIdx<numEnemy; enemyIdx++){    
        (this->enemyStates)[enemyIdx].PrintInfo(enemyIdx);
    }
}

