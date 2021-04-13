
#include<stdio.h> 
#include <stdlib.h>  
#include <string.h> 
 
#define N 10 
 
typedef struct 
{ 
      int id;   // The id of the process 
      int arr_time, burst_time; // allocate process arrival and CPU execution time 
      int prior; // priority of the process 
      int q;
      int ready; //The process is completed
}psb; 
 
int queue(int t1) 
{ 
      if(t1 == 0 || t1 == 1 || t1 == 2 || t1 == 3) 
      { 
            return 1; 
      } 
      else
      {
            return 0; 
      }
} 
 
int main() 
{ 
      int limit = 3, p; //3 processes and count p to 3
      int temp_process, time, j, y; 
      psb temp; 
      psb process[limit]; 
      for(p = 0; p < limit; p++) 
      { 
            printf("\nProcess ID:\t"); 
            scanf("%d", &process[p].id); 
            printf("Arrival Time:\t"); 
            scanf("%d", &process[p].arr_time); 
            printf("Burst Time:\t");    
            scanf("%d", &process[p].burst_time); 
            printf("Process Priority:\t"); 
            scanf("%d", &process[p].prior); 
            temp_process = process[p].prior; 
            process[p].q = queue(temp_process);
            process[p].ready = 0;  // for inserting the process into the next ready queue  
      }
      time = process[0].burst_time; 
      for(y = 0; y < limit; y++) 
      { 
            for(p = y; p < limit; p++) 
            { 
                  if(process[p].arr_time < time) 
                  {
                        process[p].ready = 1; 
                  } 
            } 
      //Creates a ready queue, specifying that the smaller the priority number, the lower the priority
            for(p = y; p < limit - 1; p++) 
            { 
                  for(j = p + 1; j < limit; j++) 
                  {
                        if(process[p].ready == 1 && process[j].ready == 1) 
                        { 
                              if(process[p].q == 1 && process[j].q == 1) 
                              { 
                                    if(process[p].burst_time > process[j].burst_time) 
                                    { 
                                          temp = process[p]; 
                                          process[p] = process[j]; 
                                          process[j] = temp; 
                                    } 
                                    else 
                                    { 
                                          break; 
                                    } 
                              } 
                        } 
                  } 
            } 
            
            
            printf("\nProcess[%d]:\tTime:\t%d To %d\n", process[y].id, time, time + process[y].burst_time); 
            time = time + process[y].burst_time; 
            for(p = y; p < limit; p++) 
            { 
                  if(process[p].ready == 1) 
                  { 
                        process[p].ready = 0; 
                  } 
            } 
      } 
      return 0; 
}
