//
// Created by 24101 on 24-8-21.
//

#include "speechManager.h"

speechManager::speechManager() {

    //init container and rounds
    this->initSpeech();
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

void speechManager::initSpeech() {

    //all set to empty
    this->v1.clear();
    this->v2.clear();
    this->victory.clear();
    this->m_Speaker.clear();

    //init rounds
    this->index = 1;
}

speechManager::~speechManager() {

}
