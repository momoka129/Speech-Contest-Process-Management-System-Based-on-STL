//
// Created by 24101 on 24-8-21.
//

#ifndef SPEECH_CONTEST_PROCESS_MANAGEMENT_SYSTEM_BASED_ON_STL_SPEECHMANAGER_H
#define SPEECH_CONTEST_PROCESS_MANAGEMENT_SYSTEM_BASED_ON_STL_SPEECHMANAGER_H

#include <iostream>
using namespace std;


class speechManager {
public:

    //constructor
    speechManager();

    //system interact menu
    void show_Menu();

    //exit the system
    void exitSystem();

    //distructor
    ~speechManager();
};


#endif //SPEECH_CONTEST_PROCESS_MANAGEMENT_SYSTEM_BASED_ON_STL_SPEECHMANAGER_H
