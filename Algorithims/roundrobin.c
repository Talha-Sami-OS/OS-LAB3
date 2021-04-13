#include<stdio.h> 

 
int main() 
{ 
      //int resp = 0;
      int i, limit = 3; //3 processes and count p to 3
      int total = 0, x, per = 0;
      int quant; //min time for each process
      int wait_time = 0, turn_around = 0;
      int arr_time[10], burst_time[10], temp[10], response[10]; 
      float avg_wait_time, avg_turn_around;
      x = limit; 
      for(i = 0; i < limit; i++) //user input for each process 
      {
            printf("\nEnter Details of Process[%d]\n", i + 1);
            printf("Arrival Time:\t");
            scanf("%d", &arr_time[i]);
            printf("Burst Time:\t");
            scanf("%d", &burst_time[i]); 
            temp[i] = burst_time[i];
      } 
      printf("\nEnter Time Quantum:\t"); 
      scanf("%d", &quant); 
      printf("\nProcess ID\t\tBurst Time\t Turnaround Time\t Waiting Time \t Response Time\n");
      for(total = 0, i = 0; x != 0;) //for time slice approach
      { 
            if(temp[i] <= quant && temp[i] > 0)  /* If the quantum time is less tnan temp variable value */ 
            { 
                  total = total + temp[i]; 
                  temp[i] = 0; 
                  per = 1; 
            } 
            else if(temp[i] > 0) 
            { 
                  temp[i] = temp[i] - quant;  //qunatum time stored in temp variable
                  total = total + quant; 
            } 
            else if(temp[i] == 0 && per == 1) 
            { 
                  x--; 
                  printf("\nProcess[%d]\t\t%d\t\t %d\t\t\t %d\t\t %d", i + 1, burst_time[i], total - arr_time[i], total - arr_time[i] - burst_time[i], response[i]);
                  wait_time = wait_time + total - arr_time[i] - burst_time[i]; 
                  turn_around = turn_around + total - arr_time[i]; 
                  response[i] = response[i] + total - burst_time[i]; 
                  per = 0;  //The counter is cleared to prepare for the next time
            } 
            else if(i == limit - 1)    //process executed
            {
                  i = 0; 
            }
            else if(arr_time[i + 1] <= total) //if arrival trime increase the total then increment i
            {
                  i++;
            }
            else 
            {
                  i = 0;   //process executed
            }
      } 
      avg_wait_time = wait_time * 1.0 / limit;
      avg_turn_around = turn_around * 1.0 / limit;
      printf("\n\nAverage Waiting Time:\t%f", avg_wait_time); 
      printf("\nAvg Turnaround Time:\t%f\n", avg_turn_around); 
      return 0; 
}
