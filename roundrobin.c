#include <stdio.h>

struct Process{
    int processId;
    int arrivalTime;
    int burstTime;
    int remainingTime;
    int completionTime;
    int turnAroundTime;
    int waitTime;
};


int main(){
    int n, timeQuantum;
    float totalTurnAroundTime = 0, totalWaitingTime = 0;
    int currentTime = 0;
    int remainingProcesses;

    printf("Enter the number of processes: ");
    scanf("%d", &n);

    printf("Enter the time quantum: ");
    scanf("%d", &timeQuantum);

    remainingProcesses = n;
    struct Process processes[n];

    for(int i=0; i<n; i++){
        printf("\nEnter the burst time, for process %d: ", i);
        scanf("%d", &processes[i].burstTime);
        processes[i].arrivalTime = i;
        // printf("Arrival time of P%d is %d\n", i, processes[i].arrivalTime);
        processes[i].remainingTime = processes[i].burstTime;
        // printf("Remaining time of P%d is %d\n", i, processes[i].remainingTime);
    }

    int i = 0;
    while(remainingProcesses>0){
        if(processes[i].remainingTime > 0){
            if(processes[i].remainingTime <= timeQuantum){
                currentTime += processes[i].remainingTime;
                printf("P%d: Remaining time: %d Current time: %d\n", i, processes[i].remainingTime, currentTime);
                processes[i].completionTime = currentTime;
                processes[i].remainingTime = 0;
                
                remainingProcesses--;
            }
            else{
                processes[i].remainingTime -= timeQuantum;
                currentTime += timeQuantum;
            }
        }
        i = (i+1)%n;
    }

    for(int i=0; i<n; i++){
        processes[i].turnAroundTime = processes[i].completionTime - processes[i].arrivalTime;
        processes[i].waitTime = processes[i].turnAroundTime - processes[i].burstTime;

        totalTurnAroundTime += processes[i].turnAroundTime;
        totalWaitingTime += processes[i].waitTime;
    }

    printf("\t PROCESS \t ARRIVAL TIME \t BURST TIME \t COMPLETION TIME \t WAITING TIME \t TURNAROUND TIME\n");
    
    for(int i=0; i<n; i++){
        printf("\n\t P%d \t\t %d \t\t %d \t\t %d \t\t\t\t %d \t\t %d", i, processes[i].arrivalTime, processes[i].burstTime, processes[i].completionTime, processes[i].waitTime, processes[i].turnAroundTime);
    }

    printf("\nAverage Waiting Time -- %f", totalWaitingTime/n);
    printf("\nAverage Turnaround Time -- %f", totalTurnAroundTime/n);

    return 0;
}