#include <stdio.h>
#include <stdlib.h>

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


