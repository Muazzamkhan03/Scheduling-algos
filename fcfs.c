# include <stdio.h>
# include <conio.h>

int main(){
    int burstTimes[20], waitingTimes[20], turnAroundTimes[20], n;
    float totalWaitTime, totalTurnAroundTime;

    printf("\nEnter the number of processess --- ");
    scanf("%d",&n);

    for(int i=0; i<n; i++){
        printf("\nEnter Burst Time for Process %d --- ", i+1);
        scanf("%d", &burstTimes[i]);
    }

    waitingTimes[0] = 0;
    totalWaitTime = 0;
    turnAroundTimes[0] = burstTimes[0];
    totalTurnAroundTime = burstTimes[0];

    for(int i=1; i<n; i++){
        // waitingTimes[i] = waitingTimes[i-1] + burstTimes[i-1];
        waitingTimes[i] = turnAroundTimes[i-1];
        turnAroundTimes[i] = turnAroundTimes[i-1] + burstTimes[i];

        totalTurnAroundTime = totalTurnAroundTime + turnAroundTimes[i];
        totalWaitTime = totalWaitTime + waitingTimes[i];
    }
    

    printf("\t PROCESS \t BURST TIME \t WAITING TIME \t TURNAROUND TIME\n");
    
    for(int i=0; i<n; i++){
        printf("\n\t P%d \t\t %d \t\t %d \t\t %d", i+1, burstTimes[i], waitingTimes[i], turnAroundTimes[i]);
    }

    printf("\nAverage Waiting Time -- %f", totalWaitTime/n);
    printf("\nAverage Turnaround Time -- %f", totalTurnAroundTime/n);

    return 0;
}