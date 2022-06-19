#include "scheduling_functions.h"
#include<iostream>

using namespace std;

scheduling_functions::scheduling_functions()
{
    //ctor
}

scheduling_functions::~scheduling_functions()
{
    //dtor
}
//start of fcfs

void scheduling_functions::fcfs()
{
	int choice = -1;
    cout << "\n       ~ Round Robin Scheduling ~";
    while(choice != 0)
        {
            cout << "\n=========================================" << endl;
            cout << "\t\tOptions" << endl;
            cout << "=========================================\n" << endl;
            cout << "[1] - Start" << endl;
            cout << "[0] - Back" << endl;
            cout << "\n=========================================" << endl;
            cout << "\n";

            cout << "Choose Option: ";
            cin >> choice;

            switch(choice)
            {
                case 1:
                    fcfs();
                    cin.clear();
                    fflush(stdin);
                    system("pause");
                    system("CLS");
                    break;

                case 0:
                    system("CLS");
                    choice = 0;
                    break;

                default:
                    cout << "\t\nInvalid!" << endl;
        }
    }
}
//end of fcfs

//start of sjf
void scheduling_functions::sjf()
{

}
//end of sjf

//start of srt
void scheduling_functions::srt()
{

}
//end of srt

//start of ps
void scheduling_functions::ps()
{

}
//end of ps

//start of Round Robin Scheduling
void queue_updation(int queue[],int timer,int arrival[],int n, int max_proccess_index)
{
    int zero_index;
    for(int i = 0; i < n; i++)
    {
        if(queue[i] == 0)
        {
            zero_index = i;
            break;
        }
    }
    queue[zero_index] = max_proccess_index + 1;
}

void queue_maintainence(int queue[], int n)
{
    for(int i = 0; (i < n-1) && (queue[i+1] != 0) ; i++)
    {
        int temp = queue[i];
        queue[i] = queue[i+1];
        queue[i+1] = temp;
    }
}

void check_new_arrival(int timer, int arrival[], int n, int max_proccess_index,int queue[])
{
    if(timer <= arrival[n-1])
    {
        bool new_arrival = false;
        for(int j = (max_proccess_index+1); j < n; j++)
        {
            if(arrival[j] <= timer)
            {
                if(max_proccess_index < j)
                {
                    max_proccess_index = j;
                    new_arrival = true;
                }
            }
        }
        if(new_arrival)
        queue_updation(queue,timer,arrival,n, max_proccess_index);
    }
}
void rrs_function()
{
    int n,tq, timer = 0, max_proccess_index = 0;
    float avg_wait = 0, avg_tt = 0;
    system("CLS");
    cout << "\n\t ========================" << endl;
    cout << "\n\t| Round Robin Scheduling |" << endl;
    cout << "\n\t ========================" << endl;
    cout << "\nEnter the Time Quantum: ";
    cin >> tq;
        while(tq <= 0)
        {
            cout << "\nTime Quantum should be greater than or equal to 1.\n" << endl;
            system("pause");
            system("CLS");
            cout << "\n\t ========================" << endl;
            cout << "\n\t| Round Robin Scheduling |" << endl;
            cout << "\n\t ========================" << endl;
            cout << "\nEnter the Time Quantum: ";
            cin >> tq;
        }
    cout << "\nEnter the Number of Processes: ";
    cin >> n;
    int arrival[n], burst[n], wait[n], turn[n], queue[n], temp_burst[n];
    bool complete[n];

    cout << "\nEnter the Arrival Time of the Processes: \n";
    for(int i = 0; i < n; i++)
    {
        cout<<"AT["<<i+1<<"]:";
        cin >> arrival[i];
    }

    cout << "\nEnter the Burst Time of the Processes: \n";
    for(int i = 0; i < n; i++)
    {
        cout<<"BT["<<i+1<<"]:";
        cin >> burst[i];
        temp_burst[i] = burst[i];
    }

    for(int i = 0; i < n; i++)
    {
        complete[i] = false;
        queue[i] = 0;
    }
    while(timer < arrival[0])
        timer++;
    queue[0] = 1;

    while(true)
    {
        bool flag = true;
        for(int i = 0; i < n; i++)
        {
            if(temp_burst[i] != 0)
            {
                flag = false;
                break;
            }
        }
        if(flag)
            break;

        for(int i = 0; (i < n) && (queue[i] != 0); i++)
        {
            int ctr = 0;
            while((ctr < tq) && (temp_burst[queue[0]-1] > 0))
            {
                temp_burst[queue[0]-1] -= 1;
                timer += 1;
                ctr++;

                check_new_arrival(timer, arrival, n, max_proccess_index, queue);
            }
            if((temp_burst[queue[0]-1] == 0) && (complete[queue[0]-1] == false))
            {
                turn[queue[0]-1] = timer;
                complete[queue[0]-1] = true;
            }
            bool idle = true;
            if(queue[n-1] == 0)
            {
                for(int i = 0; i < n && queue[i] != 0; i++)
                {
                    if(complete[queue[i]-1] == false)
                    {
                        idle = false;
                    }
                }
            }
            else
                idle = false;

            if(idle)
            {
                timer++;
                check_new_arrival(timer, arrival, n, max_proccess_index, queue);
            }
            queue_maintainence(queue,n);
        }
    }

    for(int i = 0; i < n; i++)
    {
        turn[i] = turn[i] - arrival[i];
        wait[i] = turn[i] - burst[i];
    }

    cout << "\nProgram No.\tArrival Time\tBurst Time\tWait Time\tTurnAround Time" << endl;
    for(int i = 0; i < n; i++)
    {
        cout << i+1 << "\t\t" << arrival[i] << "\t\t" << burst[i] << "\t\t" << wait[i] << "\t\t" <<turn[i] << endl;
    }
    for(int i =0; i< n; i++)
    {
        avg_wait += wait[i];
        avg_tt += turn[i];
    }
    cout << "\nAverage Wait Time : " << (avg_wait/n) << "\nAverage Turn Around Time : " << (avg_tt/n);
    cout << "\n\n";
}
void scheduling_functions::rrs()
{
    int choice = -1;
    cout << "\n       ~ Round Robin Scheduling ~";
    while(choice != 0)
        {
            cout << "\n=========================================" << endl;
            cout << "\t\tOptions" << endl;
            cout << "=========================================\n" << endl;
            cout << "[1] - Start" << endl;
            cout << "[0] - Back" << endl;
            cout << "\n=========================================" << endl;
            cout << "\n";

            cout << "Choose Option: ";
            cin >> choice;

            switch(choice)
            {
                case 1:
                    rrs_function();
                    cin.clear();
                    fflush(stdin);
                    system("pause");
                    system("CLS");
                    break;

                case 0:
                    system("CLS");
                    choice = 0;
                    break;

                default:
                    cout << "\t\nInvalid!" << endl;
        }
    }
}
//end of Round Robin Scheduling

//start of mlqs
void scheduling_functions::mlqs()
{

}
//end of mlqs
