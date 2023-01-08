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

