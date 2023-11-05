# include <stdio.h>

int main(){
    int processes[20], burstTimes[20], waitingTimes[20], turnAroundTimes[20], n;
    int temp;
    float totalWaitingTime, totalTurnAroundTime;

    printf("\nEnter the number of processes --- ");
    scanf("%d", &n);

    for(int i=0; i<n; i++){
        processes[i] = i;
        printf("Enter Burst Time for Process %d ---", i+1);
        scanf("%d", &burstTimes[i]);
    }

    for(int i=0; i<n; i++){
        for(int j=i+1; j<n; j++){
            if(burstTimes[i] > burstTimes[j]){
                temp = burstTimes[i];
                burstTimes[i] = burstTimes[j];
                burstTimes[j] = temp;

                temp = processes[i];
                processes[i] = processes[j];
                processes[j] = temp;
            }
        }
    }

    totalWaitingTime = waitingTimes[0] = 0;
    totalTurnAroundTime = turnAroundTimes[0] = burstTimes[0];

    for(int i=1; i<n; i++){
        waitingTimes[i] = turnAroundTimes[i-1];
        turnAroundTimes[i] = turnAroundTimes[i-1] + burstTimes[i];

        totalTurnAroundTime = totalTurnAroundTime + turnAroundTimes[i];
        totalWaitingTime = totalWaitingTime + waitingTimes[i];
    }

    printf("\n\t PROCESS \tBURST TIME \t WAITING TIME\t TURNAROUND TIME\b");

    for(int i=0; i<n; i++){
        printf("\n\tP%d\t\t%d\t\t%d\t\t%d", processes[i], burstTimes[i], waitingTimes[i], turnAroundTimes[i]);
    }

    printf("\nAverage Waiting Time -- %f", totalWaitingTime/n);
    printf("\nAverage TurnAround Time -- %f", totalTurnAroundTime/n);

    return 0;
}