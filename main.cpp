#include <iostream>
#include <string>
#include <conio.h>
#include "scheduling_functions.h"

using namespace std;
int n;
int main()
{
    int choice = -1;
    cout << "\n      ~ CPU SCHEDULING CALCULATOR ~\n";

    while(choice != 0)
    {
        cout << "\n=========================================" << endl;
        cout << "\t   Calculator Options" << endl;
        cout << "=========================================\n" << endl;
        cout << "[1] - First Come First Serve (FCFS)" << endl;
        cout << "[2] - Shortest-Job-First (SJF) Scheduling" << endl;
        cout << "[3] - Shortest Remaining Time" << endl;
        cout << "[4] - Priority Scheduling" << endl;
        cout << "[5] - Round Robin Scheduling" << endl;
        cout << "[6] - Multilevel Queue Scheduling" << endl;
        cout << "[0] - Exit Calculator" << endl;
        cout << "\n=========================================" << endl;
        cout << "\n";

        cout << "Choose Calculator Option: ";
        cin >> choice;



        switch(choice)
        {
            case 1:
                fcfs();
                cin.clear();
                fflush(stdin);
                system("CLS");

                break;
            case 2:
                sjf();
                cin.clear();
                fflush(stdin);


                break;
            case 3:
                srt();
                cin.clear();
                fflush(stdin);


                break;
            case 4:
                ps();



                break;
            case 5:
                rrs();
                cin.clear();
                fflush(stdin);



                break;
            case 6:
                mlqs();
                cin.clear();
                fflush(stdin);


                break;
            case 0:
                cout << "\n\tThank you!" << endl;
                return 0;

            default:
                cout << "\t\nInvalid!" << endl;

        }
    }
}