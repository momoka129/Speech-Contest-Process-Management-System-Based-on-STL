#include <iostream>
using namespace std;
#include "speechManager.h"

int main() {

    speechManager sm;

    int choice;

    while(true){

        sm.show_Menu();

        cout<<"Enter your choice: ";
        cin>>choice;

        switch (choice) {
            //start the contest
            case 1:
                break;

            //check the previous records
            case 2:
                break;

            //clear the records
            case 3:
                break;

            //exit the program
            case 0:
                sm.exitSystem();
                break;


            default:
                system("cls");
                break;
        }
    }



    return 0;
}
