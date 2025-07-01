#include <iostream>
using namespace std;

struct Process {
    int pid;
    int bt;
    int ct;
    int tat;
    int wt;
};

int main() {
    int n;
    cout << "Enter number of processes: ";
    cin >> n;

    Process proc[n];

    for (int i = 0; i < n; i++) {
        proc[i].pid = i + 1;
        cout << "Enter Burst Time for Process " << proc[i].pid << ": ";
        cin >> proc[i].bt;
    }

    // Sort by Burst Time (Shortest Job First)
    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            if (proc[j].bt < proc[i].bt) {
                swap(proc[i], proc[j]);
            }
        }
    }

    // Compute CT, TAT, WT
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
        cout << proc[i].pid << "\t" << proc[i].bt << "\t" << proc[i].ct
             << "\t" << proc[i].tat << "\t" << proc[i].wt << endl;
    }

    return 0;
}
