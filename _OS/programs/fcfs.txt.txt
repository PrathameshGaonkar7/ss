#include <iostream>
using namespace std;

struct Process {
    int pid;    // Process ID
    int at;     // Arrival Time
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

    // Input process details
    for (int i = 0; i < n; i++) {
        proc[i].pid = i + 1;
        cout << "Enter arrival time and burst time for process " << proc[i].pid << ": ";
        cin >> proc[i].at >> proc[i].bt;
    }

    // Sort processes by arrival time (FCFS basis)
    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            if (proc[i].at > proc[j].at) {
                swap(proc[i], proc[j]);
            }
        }
    }

    // Calculate Completion, Turnaround and Waiting times
    proc[0].ct = proc[0].at + proc[0].bt;
    proc[0].tat = proc[0].ct - proc[0].at;
    proc[0].wt = proc[0].tat - proc[0].bt;

    for (int i = 1; i < n; i++) {
        if (proc[i].at > proc[i - 1].ct)
            proc[i].ct = proc[i].at + proc[i].bt; // CPU idle time
        else
            proc[i].ct = proc[i - 1].ct + proc[i].bt;

        proc[i].tat = proc[i].ct - proc[i].at;
        proc[i].wt = proc[i].tat - proc[i].bt;
    }

    // Output results
    cout << "\nPID\tAT\tBT\tCT\tTAT\tWT\n";
    for (int i = 0; i < n; i++) {
        cout << proc[i].pid << "\t" << proc[i].at << "\t" << proc[i].bt << "\t"
             << proc[i].ct << "\t" << proc[i].tat << "\t" << proc[i].wt << endl;
    }

    return 0;
}
