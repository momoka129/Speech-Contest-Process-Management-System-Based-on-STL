//
// Created by 24101 on 24-8-21.
//

#include "speechManager.h"

speechManager::speechManager() {
    //init container and rounds
    this->initSpeech();

    //create 12 player
    this->createSpeaker();
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

void speechManager::createSpeaker() {
    string nameSeed = "ABCDEFGHIJKL";
    for(int i = 0; i < nameSeed.size(); i++){
        string name = "Player";
        name += nameSeed[i];

        //create specific player
        Speaker sp;

        sp.name = name;
        for(int j = 0; j < 2; j++){
            sp.score[j] = 0;
        }

        //Create a player number and put it in the v1 container
        this->v1.push_back(i + 10001);

        //The player number and the corresponding player are placed in the map container
        this->m_Speaker.insert(make_pair(i+10001, sp));
    }
}

speechManager::~speechManager() {

}
