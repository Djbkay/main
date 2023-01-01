#include <iostream>

typedef struct Action{
	
	char name[10];
	int bursttime;
	int arrivaltime;
	int priority;
	int waitingtime,turnaround,flag;
	
}Action;






int main()
{
     Action A[10];
	 int x , choice;
	 
	 do{
	 	cout<<"\n Slect CPU Scheduling Method:";
	 	cout<<"\n 1. First Come First Served(FCFS)";
	 	cout<<"\n 2. Shortest-Job-First Scheduling(SJF) (Preemptive)";
        cout<<"\n 2. Shortest-Job-First Scheduling(SJF) (Non Preemptive)";
	    cout<<"\n 4. Priority Scheduling (Preemptive)";
        cout<<"\n 5. Priority Scheduling (Non Preemptive)";
        cout<<"\n 6. Round Robin";
        cout<<"\n 7. Exit\n Select : ";
	 }
	 
	 
	 	
}
