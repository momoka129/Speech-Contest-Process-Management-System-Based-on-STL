//
// Created by 24101 on 24-8-21.
//

#ifndef SPEECH_CONTEST_PROCESS_MANAGEMENT_SYSTEM_BASED_ON_STL_SPEECHMANAGER_H
#define SPEECH_CONTEST_PROCESS_MANAGEMENT_SYSTEM_BASED_ON_STL_SPEECHMANAGER_H

#include <iostream>
using namespace std;
#include <vector>
#include <map>
#include "speaker.h"
#include <algorithm>
#include <deque>
#include <numeric>
#include <fstream>

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

    //init the attributes
    void initSpeech();

    //create player
    void createSpeaker();

    //start the contest!
    void Process_contest();

    //draw
    void speech_draw();

    //contest
    void speech_contest();

    //show the score
    void speech_showScore();

    //save every contest data
    void save_Record();

    //read the record
    void load_Record();

    //tell if the file is empty
    bool file_empty;

    //storage each contest record
    map<int, vector<string>> m_Record;

    //show record
    void show_Record();

    //member attributes
    //save the first round player numbers container
    vector<int> v1;

    //save the first round qualifiers
    vector<int> v2;

    //Top three players
    vector<int> victory;

    //save the numbers and the corresponding player name
    map<int, Speaker> m_Speaker;

    //indicate the rounds
    int index;

    //clear the file
    void clear_Record();
};


#endif //SPEECH_CONTEST_PROCESS_MANAGEMENT_SYSTEM_BASED_ON_STL_SPEECHMANAGER_H
