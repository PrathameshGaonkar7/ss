#include <iostream>
using namespace std;

struct Process {
    int pid;
    int bt;
    int rt;  // Remaining Time
    int ct;
    int tat;
    int wt;
};

int main() {
    int n, tq;
    cout << "Enter number of processes: ";
    cin >> n;
    cout << "Enter Time Quantum: ";
    cin >> tq;

    Process proc[n];

    for (int i = 0; i < n; i++) {
        proc[i].pid = i + 1;
        cout << "Enter Burst Time for Process " << proc[i].pid << ": ";
        cin >> proc[i].bt;
        proc[i].rt = proc[i].bt;
    }

    int time = 0;
    bool done;

    while (true) {
        done = true;

        for (int i = 0; i < n; i++) {
            if (proc[i].rt > 0) {
                done = false;

                if (proc[i].rt > tq) {
                    time += tq;
                    proc[i].rt -= tq;
                } else {
                    time += proc[i].rt;
                    proc[i].ct = time;
                    proc[i].rt = 0;
                }
            }
        }

        if (done)
            break;
    }

    // Calculate TAT and WT
    for (int i = 0; i < n; i++) {
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
