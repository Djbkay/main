#include <iostream>

typedef struct Action{
	
	char name[10];  
	int bursttime;
	int arrivaltime;
	int priority;
	int waitingtime,turnaround,flag;
	
}Action;

int acceptAction(Action A[])
{
	int i,x;
	cout<<"\n Enter Number Of Process:  ";
	cin>>x;
	
	for(i=0;i<x;i++)
	{
		cout<<"\n Enter Process Name : ";
		cin>>A[i].name;
		cout<<"Enter Burst Time :";
		cin>>A[i].bursttime;
		cout<<"Enet Arrivaltime:";
		cin>>A[i].arrivaltime;
		cout<<"Enter Priority:";
		cin>>A[i].priority;
	}
	
	  cout<<"\n   Name | Burst time | Arrivaltime | Priority" ;
	  for(i=0;i,x;i++)
	  cout<<A[i].name ,A[i].bursttime , A[i].arrivaltime, A[i].priority;
	  
	  
}






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
        cout<<"\n 7. Enter Process Data ";
        cout<<"\n 8. Exit\n Select : ";
	 cin>>choice;
        
        switch(choice)
        {
        	case 1:
        		FCFS(A,x);
        		break;
        		
        	case 2:
        		SJF_Preemptive(A,x);
        		break;
        		
        	case 3:
        		SJF_NonPreemptive(A,x);
        		break;
				
			case 4:
        		PS_Preemptive(A,x);
        		break;
				
			case 5:
        		PS_NonPreemptive(A,x);
        		break;
				
			case 6:
        		RR(A,x);
        		break;
				
			case 7:
        		(A,x);
        		break;
				
			CASE 8:
			    exit(0);						
        		
        					
		}
		 
		 
	 }
	 
	 
	 	
}
