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
        // HandlerGUI* gui;
        UserState* userState;
        EnemyState* enemyStates;
        int numEnemy;
        Env(int numEnemy);
        ~Env();
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

Env::~Env(){
    delete userState;
    delete[] enemyStates;
}


class HandlerGUI{
    public:
        sf::RenderWindow* window;
    	sf::Sprite mapSprite;
        sf::Texture mapTexture;
        float aspectRatio;

        Env* env;
        HandlerGUI(Env* env);
        ~HandlerGUI();
        void Draw();

    private:
        void LoadTextures();
};

HandlerGUI::HandlerGUI(Env* env): env(env){
    window = new sf::RenderWindow(sf::VideoMode(200, 200), "SFML works!");
    // window->create(sf::VideoMode(1000, 1100), "Pacman", sf::Style::Fullscreen);
    // aspectRatio = float(window->getSize().x) / float(window->getSize().y);
    // sf::View v(sf::Vector2f(400, 450), sf::Vector2f(800 * aspectRatio, 900));
    // window->setView(v);

    LoadTextures();
    
}

HandlerGUI::~HandlerGUI(){
    delete window;
}

void HandlerGUI::LoadTextures(){

    if (mapTexture.loadFromFile("Resources/PacManSprites.png", sf::IntRect(0, 0, 226, 248)))
    {
        mapTexture.setSmooth(false);
        mapSprite.setTexture(mapTexture);
        // mapSprite.setScale((window->getView().getSize().x) / (mapSprite.getLocalBounds().width * aspectRatio), (window->getView().getSize().y - 100) / mapSprite.getLocalBounds().height);
        mapSprite.move(0, 1);
    }
    else
    {
        std::cout << "texture not loaded correctly" << std::endl;
    }

}

void HandlerGUI::Draw(){
    window->clear();
    window->draw(mapSprite);
    window->display();
}


class GameManager{
    public:
        Env* env;
        HandlerGUI* handlerGUI;
        GameManager();
        ~GameManager();
        void Run();

    private:
        sf::Clock clock;
};


GameManager::GameManager(){
    int enemyNum = 10;
    env = new Env(enemyNum);
    handlerGUI = new HandlerGUI(env);
}

GameManager::~GameManager(){
    delete env;
    delete handlerGUI;
}

void GameManager::Run(){
    while (handlerGUI->window->isOpen()){
        handlerGUI->Draw();
    }
}