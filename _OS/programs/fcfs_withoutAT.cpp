#include <iostream>
using namespace std;

struct Process {
    int pid;    // Process ID
    int bt;     // Burst Time
    int ct;     // Completion Time
    int tat;    // Turnaround Time
    int wt;     // Waiting Time
};

int main() {
    int n;
    cout << "Enter number of processes: ";
    cin >> n;

    Process proc[n];

    // Input burst times
    for (int i = 0; i < n; i++) {
        proc[i].pid = i + 1;
        cout << "Enter burst time for process " << proc[i].pid << ": ";
        cin >> proc[i].bt;
    }

    // FCFS Scheduling logic (no arrival time)
    proc[0].ct = proc[0].bt;
    proc[0].tat = proc[0].ct;
    proc[0].wt = 0;

    for (int i = 1; i < n; i++) {
        proc[i].ct = proc[i - 1].ct + proc[i].bt;
        proc[i].tat = proc[i].ct;
        proc[i].wt = proc[i].tat - proc[i].bt;
    }

    // Output
    cout << "\nPID\tBT\tCT\tTAT\tWT\n";
    for (int i = 0; i < n; i++) {
        cout << proc[i].pid << "\t" << proc[i].bt << "\t" << proc[i].ct << "\t"
             << proc[i].tat << "\t" << proc[i].wt << endl;
    }

    return 0;
}
