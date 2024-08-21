//
// Created by 24101 on 24-8-21.
//

#include "speechManager.h"

speechManager::speechManager() {

}

void speechManager::show_Menu() {
    cout<<"*************************************************"<<endl;
    cout<<"welcome to the speech contest"<<endl;
    cout<<"1. Start a Speech Contest"<<endl;
    cout<<"2. View previous records"<<endl;
    cout<<"3. Clear contest records"<<endl;
    cout<<"4. exit the program"<<endl;
    cout<<"*************************************************"<<endl;
}

void speechManager::exitSystem() {
    cout<<"Welcome next use..."<<endl;
    system("pause");
    exit(0);
}

speechManager::~speechManager() {

}
