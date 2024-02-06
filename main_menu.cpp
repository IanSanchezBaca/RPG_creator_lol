#include<iostream>
#include "main_menu.h"

MainMenu::MainMenu(){}

void MainMenu::print(std::string &test){
    test = "Hello world!\n";
}

bool MainMenu::initalize(){
    bool succ = false;
    // already initialized sdl so dont need to initialize it again.
    
    return succ;
}
