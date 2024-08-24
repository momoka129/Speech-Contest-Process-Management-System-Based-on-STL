#include <iostream>
using namespace std;
#include "speechManager.h"
#include <ctime>

int main() {

    srand((unsigned int)time(NULL));

    speechManager sm;

//    for(map<int, Speaker>::iterator it = sm.m_Speaker.begin(); it != sm.m_Speaker.end(); it++){
//        cout<<"player number: "<<it->first<<"\tname: "<<it->second.name<<"\tscore: "<<it->second.score[0]<<endl;
//    }

    int choice;

    while(true){

        cout<<endl;
        sm.show_Menu();

        cout<<"Enter your choice: ";
        cin>>choice;
        cout<<endl;

        switch (choice) {
            //start the contest
            case 1:
                sm.Process_contest();
                break;

            //check the previous records
            case 2:
                //sm.load_Record();
                sm.show_Record();
                break;

            //clear the records
            case 3:
                sm.clear_Record();
                break;

            //exit the program
            case 0:
                sm.exitSystem();
                break;


            default:
                //system("cls");
                break;
        }
    }



    return 0;
}
