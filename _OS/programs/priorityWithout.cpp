#include <iostream>
using namespace std;

struct Process {
    int pid;
    int bt;         // Burst Time
    int priority;   // Lower value means higher priority
    int ct;         // Completion Time
    int tat;        // Turnaround Time
    int wt;         // Waiting Time
};

int main() {
    int n;
    cout << "Enter number of processes: ";
    cin >> n;

    Process proc[n];

    // Input burst time and priority for each process
    for (int i = 0; i < n; i++) {
        proc[i].pid = i + 1;
        cout << "Enter Burst Time and Priority for Process " << proc[i].pid << ": ";
        cin >> proc[i].bt >> proc[i].priority;

        // Basic validation
        if (proc[i].bt < 0 || proc[i].priority < 0) {
            cout << "Invalid input! Burst Time and Priority must be non-negative.\n";
            return 1;
        }
    }

    // Sort by priority (ascending order — lower number = higher priority)
    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            if (proc[j].priority < proc[i].priority) {
                swap(proc[i], proc[j]);
            }
        }
    }

    // Calculate Completion, Turnaround, and Waiting times
    proc[0].ct = proc[0].bt;
    proc[0].tat = proc[0].ct;
    proc[0].wt = 0;

    for (int i = 1; i < n; i++) {
        proc[i].ct = proc[i - 1].ct + proc[i].bt;
        proc[i].tat = proc[i].ct;
        proc[i].wt = proc[i].tat - proc[i].bt;
    }

    // Display table
    cout << "\nPID\tBT\tPriority\tCT\tTAT\tWT\n";
    for (int i = 0; i < n; i++) {
        cout << proc[i].pid << "\t" << proc[i].bt << "\t" << proc[i].priority << "\t\t"
             << proc[i].ct << "\t" << proc[i].tat << "\t" << proc[i].wt << endl;
    }

    return 0;
}
