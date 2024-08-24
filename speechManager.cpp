//
// Created by 24101 on 24-8-21.
//

#include "speechManager.h"

speechManager::speechManager() {
    //init container and rounds
    this->initSpeech();

    //create 12 player
    this->createSpeaker();

    //load previous record
    this->load_Record();
}

void speechManager::show_Menu() {
    cout<<"*************************************************"<<endl;
    cout<<"welcome to the speech contest"<<endl;
    cout<<"1. Start a Speech Contest"<<endl;
    cout<<"2. View previous records"<<endl;
    cout<<"3. Clear contest records"<<endl;
    cout<<"0. exit the program"<<endl;
    cout<<"*************************************************"<<endl;
}

void speechManager::exitSystem() {
    cout<<"Welcome next use..."<<endl;
    //system("pause");
    //exit(0);
    exit(EXIT_SUCCESS);
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

void speechManager::Process_contest() {
    //first round
    //1. draw
    cout<<"#####################################################################"<<endl;
    this->speech_draw();
    cout<<endl;

    //2. speech
    this->speech_contest();
    cout<<endl;

    //3. announce the qualifiers
    this->speech_showScore();
    cout<<"#####################################################################"<<endl;

    cout<<endl;cout<<endl;

    //final round
    this->index++;
    //1. draw
    cout<<"#####################################################################"<<endl;
    this->speech_draw();
    cout<<endl;

    //2.speech
    this->speech_contest();
    cout<<endl;

    //3.show the final result
    this->speech_showScore();
    cout<<"#####################################################################"<<endl;

    //4. record the score
    cout<<endl;
    this->save_Record();

    cout<<"The contest process is over!"<<endl;
}

void speechManager::speech_draw() {
    cout<<"The == "<<this->index<<" == "<<"round draw: "<<endl;
    cout<<"The results of the draw are as follows:"<<endl;
    if(this->index ==1){
        //first round
        random_shuffle(v1.begin(), v1.end());
        for(vector<int>::iterator it = v1.begin(); it != v1.end(); it++){
            cout<<*it<<" ";
        }
        cout<<endl;
    } else{
        //final round
        random_shuffle(v2.begin(), v2.end());
        for(vector<int>::iterator it = v2.begin(); it != v2.end(); it++){
            cout<<*it<<" ";
        }
        cout<<endl;
    }
    //system("pause");
    //cout<<endl;
}

void speechManager::speech_contest() {

    //prepare a temperate container to storage the group scores
    multimap<double, int, greater<double>> groupScore;

    int num = 0;    //record the number of players      6 people one group

    cout<<"The --- "<< this->index<<" --- round contest starts!"<<endl;

    vector<int> v_src;  //player container
    if(this->index == 1){
        v_src = v1;
    } else{
        v_src = v2;
    }

    //traverse all player to contest
    for(vector<int>::iterator it = v_src.begin(); it != v_src.end(); it++){
        //add one player
        num++;
        //judges' Ratings
        //cout<<"\nThe 10 judges' ratings: "<<endl;
        deque<double> d;
        for(int i = 0; i < 10; i++){
            double score = (rand()%401 + 600) / 10.0;   //60~100
            //cout<<score<<" ";
            d.push_back(score);
        }
        //cout<<endl;

        //sort
        sort(d.begin(), d.end(), greater<double>());

        //cout<<"Remove the highest score <"<<d.front()<<"> and the lowest scores <"<<d.back()<<">"<<endl;
        //remove highest and lowest
        d.pop_back();
        d.pop_front();

        double sum = accumulate(d.begin(), d.end(), 0.0);
        double avg = sum / (double)d.size();

        //print average score
        //cout<<"Serial number: "<<*it<<"\tName: "<<this->m_Speaker[*it].name<<"\tAverage score: "<<avg<<endl;

        //put the average score into the map container
        this->m_Speaker[*it].score[this->index - 1] = avg;

        //put average score into the temperate container
        groupScore.insert(make_pair(avg, *it));     //key: score;  value: serial number

        //The top three players are selected from every six players of one group
        if(num % 6 == 0){
            cout<<"\nThe (( "<< num/6<<" )) group contest ranking: "<<endl;
            for(multimap<double, int, greater<double>>::iterator temp = groupScore.begin(); temp != groupScore.end(); temp++){
                cout<<"The serial number: "<<temp->second<<"\tName: "<<this->m_Speaker[temp->second].name
                <<"\tScore: "<<this->m_Speaker[temp->second].score[this->index-1]<<endl;
            }

            //take top three
            int count = 0;
            for(multimap<double, int, greater<double>>::iterator temp = groupScore.begin(); temp != groupScore.end(); temp++){
                if(count < 3){
                    if(this->index == 1){
                        this->v2.push_back(temp->second);
                        count++;
                    } else{
                        this->victory.push_back(temp->second);
                        count++;
                    }
                } else{
                    break;
                }
            }

            //clear temp container
            groupScore.clear();
        }
        //cout<<endl;
    }
    cout<<endl;
    cout<<"The --- "<< this->index<<" --- round contest over!"<<endl;
    //system("pause");
}

void speechManager::speech_showScore() {
    cout<<"The <"<<this->index<<"> round qualified player info: "<<endl;

    vector<int> v;

    if(this->index == 1){
        v = this->v2;
    } else{
        v = this->victory;
    }
    for(vector<int>::iterator it = v.begin(); it != v.end(); it++){
        cout<<"The player serial number: "<<*it<<"\tName: "<<this->m_Speaker[*it].name
        <<"\tScore: "<<this->m_Speaker[*it].score[this->index-1]<<endl;
    }
    //cout<<endl;

    //this->show_Menu();
}

void speechManager::save_Record() {
    ofstream ofs;

    ofs.open("speech.csv", ios::out | ios::app);    //append way to write file

    for(vector<int>::iterator it = victory.begin(); it != victory.end(); it++){
        ofs<<this->m_Speaker[*it].name<<","<<this->m_Speaker[*it].score[1]<<",";
    }
    ofs<<endl;

    ofs.close();

    cout<<"The data have been recorded!"<<endl;

    this->file_empty = false;
}

void speechManager::load_Record() {
    ifstream ifs("speech.csv", ios::in);

    if(!ifs.is_open()){
        this->file_empty = true;
        //cout<<"file name is wrong!"<<endl;
        ifs.close();
        return;
    }

    //file is cleared
    char ch;
    ifs>>ch;
    if(ifs.eof()){
        //cout<<"The file is empty."<<endl;
        this->file_empty = true;
        ifs.close();
        return;
    }

    //file not empty
    this->file_empty = false;

    ifs.putback(ch);    //Put the single character read above back

    string data;
    int ind;

    while(ifs>>data){
        //cout<<data<<endl;

        //store 6 strings
        vector<string> v;


        int pos = -1;   //find ','
        int start = 0;

        while(true){
            pos = data.find(",", start);
            if(pos == -1){
                break;
            }

            string temp = data.substr(start, pos - start);
            //cout<<temp;
            v.push_back(temp);

            start = pos + 1;
        }

        this->m_Record.insert(make_pair(ind, v));
        ind++;
    }

    ifs.close();

}

void speechManager::show_Record() {
//    for(map<int, vector<string>>::iterator it = m_Record.begin(); it != m_Record.end(); it++){
//        cout<<"The "<<index<<" th contest top three: "<<endl;
//        cout<<"Champion: "<<this->m_Record[i][0]<<" with a score of "<<this->m_Record[i][1]<<endl;
//        cout<<"Second place: "<<this->m_Record[i][2]<<" with a score of "<<this->m_Record[i][3]<<endl;
//        cout<<"Third place: "<<this->m_Record[i][4]<<" with a score of "<<this->m_Record[i][5]<<endl;
//    }
    for(int i = 0; i < this->m_Record.size(); i++){
        cout<<"The "<<i+1<<" th contest top three: "<<endl;
        cout<<"Champion: "<<this->m_Record[i][0]<<"\t with a score of "<<this->m_Record[i][1]<<endl;
        cout<<"Second place: "<<this->m_Record[i][2]<<"\t with a score of "<<this->m_Record[i][3]<<endl;
        cout<<"Third place: "<<this->m_Record[i][4]<<"\t with a score of "<<this->m_Record[i][5]<<endl;
        cout<<endl;
    }
}

speechManager::~speechManager() {

}
