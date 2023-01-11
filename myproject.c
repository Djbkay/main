#include <stdio.h>
#include <stdlib.h>

void FCFS(processes P[],int n){
   processes temp[10];
   int sumw=0,sumt=0;
   int x = 0;
   float avgwt=0.0,avgta=0.0;
   int i,j;
   for(i=0;i<n;i++)
       temp[i]=P[i];

   sortFunction(temp,n);

       printf("\n\n PROG.\tB.T.\tA.T.");
       for(i=0;i<n;i++)
           printf("\n %s\t%d\t%d",temp[i].name,temp[i].burstTime,temp[i].arrivalTime);

       sumw = temp[0].waitingTime = 0;
       sumt = temp[0].turnAround = temp[0].burstTime - temp[0].arrivalTime;

       for(i=1;i<n;i++){
           temp[i].waitingTime = (temp[i-1].burstTime + temp[i-1].arrivalTime + temp[i-1].waitingTime) - temp[i].arrivalTime;;
           temp[i].turnAround = (temp[i].waitingTime + temp[i].burstTime);
           sumw+=temp[i].waitingTime;
           sumt+=temp[i].turnAround;
       }
       avgwt = (float)sumw/n;
       avgta = (float)sumt/n;
       printf("\n\n PROG.\tB.T.\tA.T.\tW.T\tT.A.T");
       for(i=0;i<n;i++)
           printf("\n %s\t%d\t%d\t%d\t%d",temp[i].name,temp[i].burstTime,temp[i].arrivalTime,temp[i].waitingTime,temp[i].turnAround);

       printf("\n\n GANTT CHART\n ");
       for(i=0;i<n;i++)
           printf(" %s ",temp[i].name);
       printf("\n ");

       printf("0\t");
       for(i=1;i<=n;i++){
           x+=temp[i-1].burstTime;
           printf("%d ",x);
       }
       printf("\n\n Average waiting time = %0.2f\n Average turn-around = %0.2f.",avgwt,avgta);
}

void PRT_NP(processes P[],int n)
{
   processes temp[10];
   processes t;
   int sumw=0,sumt=0;
   float avgwt=0.0,avgta=0.0;
   int i,j;
   int x = 0;

   for(i=0;i<n;i++)
       temp[i]=P[i];

   sortFunction(temp,n);

   for(i=2;i<n;i++)
       for(j=1;j<n-i+1;j++){
           if(temp[j].priority > temp[j+1].priority){
               t = temp[j];
               temp[j] = temp[j+1];
               temp[j+1] = t;
           }
       }

   printf("\n\n PROC.\tB.T.\tA.T.");
       for(i=0;i<n;i++)
           printf("\n %s\t%d\t%d",temp[i].name,temp[i].burstTime,temp[i].arrivalTime);

       sumw = temp[0].waitingTime = 0;
       sumt = temp[0].turnAround = temp[0].burstTime - temp[0].arrivalTime;

       for(i=1;i<n;i++){
           temp[i].waitingTime = (temp[i-1].burstTime + temp[i-1].arrivalTime + temp[i-1].waitingTime) - temp[i].arrivalTime;;
           temp[i].turnAround = (temp[i].waitingTime + temp[i].burstTime);
           sumw+=temp[i].waitingTime;
           sumt+=temp[i].turnAround;
       }
       avgwt = (float)sumw/n;
       avgta = (float)sumt/n;
       printf("\n\n PROC.\tB.T.\tA.T.\tW.T\tT.A.T");
       for(i=0;i<n;i++)
           printf("\n %s\t%d\t%d\t%d\t%d",temp[i].name,temp[i].burstTime,temp[i].arrivalTime,temp[i].waitingTime,temp[i].turnAround);

       printf("\n\n GANTT CHART\n ");
       for(i=0;i<n;i++)
           printf(" %s ",temp[i].name);
       printf("\n ");

       printf("0\t");
       for(i=1;i<=n;i++){
           x+=temp[i-1].burstTime;
           printf("%d ",x);
       }
       printf("\n\n Average waiting time = %0.2f\n Average turn-around = %0.2f.",avgwt,avgta);
}

void PRT_P(processes P[],int n){
   int i,t_total=0,tcurr,b[10],j,x,min_pr;
   int sumw=0,sumt=0;
   float avgwt=0.0,avgta=0.0;
   processes temp[10],t;

   for(i=0;i<n;i++){
       temp[i]=P[i];
       t_total+=P[i].burstTime;
   }

   sortFunction(temp,n);

   for(i=0;i<n;i++)
       b[i] = temp[i].burstTime;

   i=j=0;
   printf("\n GANTT CHART\n\n %d %s",i,temp[i].name);
   for(tcurr=0;tcurr<t_total;tcurr++)
   {

       if(b[i] > 0 && temp[i].arrivalTime <= tcurr)
           b[i]--;

       if(i!=j)
           printf(" %d %s",tcurr,temp[i].name);

       if(b[i]<=0 && temp[i].flag != 1)
       {
           temp[i].flag = 1;
           temp[i].waitingTime = (tcurr+1) - temp[i].burstTime - temp[i].arrivalTime;
           temp[i].turnAround = (tcurr+1) - temp[i].arrivalTime;
           sumw+=temp[i].waitingTime;
           sumt+=temp[i].turnAround;
       }
       j=i;
       min_pr = 999;
       for(x=0;x<n;x++){

           if(temp[x].arrivalTime <= (tcurr+1) && temp[x].flag != 1){

               if(min_pr != temp[x].priority && min_pr > temp[x].priority){
                   min_pr = temp[x].priority;
                   i=x;
               }
           }
       }

   }
   printf(" %d",tcurr);
   avgwt = (float)sumw/n;
   avgta = (float)sumt/n;
   printf("\n\n Average waiting time = %0.2f\n Average turn-around = %0.2f.",avgwt,avgta);
}

void RR(processes P[],int n)
{
   int pflag=0,t,tcurr=0,k,i,Q=0;
   int sumw=0,sumt=0;
   float avgwt=0.0,avgta=0.0;
   processes temp1[10],temp2[10];

   for(i=0;i<n;i++)
       temp1[i]=P[i];

   sortFunction(temp1,n);

   for(i=0;i<n;i++)
       temp2[i]=temp1[i];

 printf("\n Enter quantum time : ");
   scanf("%d",&Q);

   for(k=0;;k++){
       if(k>n-1)
           k=0;
       if(temp1[k].burstTime>0)
           printf(" %d %s",tcurr,temp1[k].name);
       t=0;
       while(t<Q && temp1[k].burstTime > 0){
           t++;
           tcurr++;
           temp1[k].burstTime--;
       }
       if(temp1[k].burstTime <= 0 && temp1[k].flag != 1){
           temp1[k].waitingTime = tcurr - temp2[k].burstTime - temp1[k].arrivalTime;
           temp1[k].turnAround = tcurr - temp1[k].arrivalTime;
           pflag++;
           temp1[k].flag = 1;
           sumw+=temp1[k].waitingTime;
           sumt+=temp1[k].turnAround;
       }
       if(pflag == n)
           break;
   }
   printf(" %d",tcurr);
   avgwt = (float)sumw/n;
   avgta = (float)sumt/n;
   printf("\n\n Average waiting time = %0.2f\n Average turn-around = %0.2f.",avgwt,avgta);
}

//SJF NONPREEMPTIVE



void SJF_NP(processes P[],int n){
   processes temp[10];
   processes t;
   int sumw=0,sumt=0;
   int x = 0;
   float avgwt=0.0,avgta=0.0;
   int i,j;

   for(i=0;i<n;i++)
       temp[i]=P[i];

   sortFunction(temp,n);

   for(i=2;i<n;i++)
       for(j=1;j<n-i+1;j++){
           if(temp[j].burstTime > temp[j+1].burstTime){
               t = temp[j];
               temp[j] = temp[j+1];
               temp[j+1] = t;
           }
       }

   printf("\n\n PROC.\tB.T.\tA.T.");
       for(i=0;i<n;i++)
           printf("\n %s\t%d\t%d",temp[i].name,temp[i].burstTime,temp[i].arrivalTime);

       sumw = temp[0].waitingTime = 0;
       sumt = temp[0].turnAround = temp[0].burstTime - temp[0].arrivalTime;

       for(i=1;i<n;i++){
           temp[i].waitingTime = (temp[i-1].burstTime + temp[i-1].arrivalTime + temp[i-1].waitingTime) - temp[i].arrivalTime;;
           temp[i].turnAround = (temp[i].waitingTime + temp[i].burstTime);
           sumw+=temp[i].waitingTime;
           sumt+=temp[i].turnAround;
       }
       avgwt = (float)sumw/n;
       avgta = (float)sumt/n;
       printf("\n\n PROC.\tB.T.\tA.T.\tW.T\tT.A.T");
       for(i=0;i<n;i++)
           printf("\n %s\t%d\t%d\t%d\t%d",temp[i].name,temp[i].burstTime,temp[i].arrivalTime,temp[i].waitingTime,temp[i].turnAround);

       printf("\n\n GANTT CHART\n ");
       for(i=0;i<n;i++)
           printf(" %s ",temp[i].name);
       printf("\n ");

       printf("0\t");
       for(i=1;i<=n;i++){
           x+=temp[i-1].burstTime;
           printf("%d ",x);
       }
       printf("\n\n Average waiting time = %0.2f\n Average turn-around = %0.2f.",avgwt,avgta);
}



//Shortest JOB_FIRST PREEMPTIVE
void sjfPreemptive(processes P[],int n){
   int i,t_total=0,tcurr;
   int b[10],min_at;
   int j,x,min_bt;
   int sumw=0,sumt=0;
   float avgwt=0.0,avgta=0.0;
   processes temp[10],t;

   for(i=0;i<n;i++){
       temp[i]=P[i];
       t_total+=P[i].burstTime;
   }

   sortFunction(temp,n);

   for(i=0;i<n;i++)
       b[i] = temp[i].burstTime;

   i=j=0;
   printf("\n GANTT CHART\n\n %d %s",i,temp[i].name);
   for(tcurr=0;tcurr<t_total;tcurr++){

       if(b[i] > 0 && temp[i].arrivalTime <= tcurr)
           b[i]--;

       if(i!=j)
           printf(" %d %s",tcurr,temp[i].name);

       if(b[i]<=0 && temp[i].flag != 1){

           temp[i].flag = 1;
           temp[i].waitingTime = (tcurr+1) - temp[i].burstTime - temp[i].arrivalTime;
           temp[i].turnAround = (tcurr+1) - temp[i].arrivalTime;
           sumw+=temp[i].waitingTime;
           sumt+=temp[i].turnAround;
       }
       j=i;   min_bt = 999;
       for(x=0;x<n;x++){

           if(temp[x].arrivalTime <= (tcurr+1) && temp[x].flag != 1){

               if(min_bt != b[x] && min_bt > b[x]){
                   min_bt = b[x];
                   i=x;
               }
           }
       }

   }
   printf(" %d",tcurr);
   avgwt = (float)sumw/n;   avgta = (float)sumt/n;
   printf("\n\n Average waiting time = %0.2f\n Average turn-around = %0.2f.",avgwt,avgta);
}

int main(){

   processes P[10];
   int choice,n;
   do{
       printf("\n\n CPU SCHEDULING ALGORITHMS SIMULATION \n");
       printf("\n Options:");
       printf("\n 0. Enter process data.");
       printf("\n 1. FCFS");
       printf("\n 2. SJF (Preemptive)");
       printf("\n 3. SJF (Non Preemptive)");
       printf("\n 4. Priority Scheduling (Preemptive)");
       printf("\n 5. Priority Scheduling (Non Preemptive)");
       printf("\n 6. Round Robin");
       printf("\n 7. Exit\n Select : ");
       scanf("%d",&choice);
       switch(choice){
           case 0:
               n=accept(P);
               break;
           case 1:
               FCFS(P,n);
               break;
           case 2:
               sjfPreemptive(P,n);
               break;
           case 3:
               SJF_NP(P,n);
               break;
           case 4:
               PRT_P(P,n);
               break;
           case 5:
               PRT_NP(P,n);
               break;
           case 6:
               RR(P,n);
               break;
           case 7:exit(0);
       }
   }while(choice != 7);

   return 0;
}

