#include <iostream>
#include <vector>
using namespace std;

struct Process {
    int pid;
    int at;
    int bt;
    int ct;
    int tat;
    int wt;
    bool done = false;
};

int main() {
    int n;
    cout << "Enter number of processes: ";
    cin >> n;

    vector<Process> proc(n);
    for (int i = 0; i < n; i++) {
        proc[i].pid = i + 1;
        cout << "Enter Arrival Time and Burst Time for Process " << proc[i].pid << ": ";
        cin >> proc[i].at >> proc[i].bt;
    }

    int completed = 0, time = 0;

    while (completed < n) {
        int idx = -1;
        int minBT = 1e9;

        // Find process with shortest BT that has arrived and is not done
        for (int i = 0; i < n; i++) {
            if (!proc[i].done && proc[i].at <= time && proc[i].bt < minBT) {
                minBT = proc[i].bt;
                idx = i;
            }
        }

        if (idx != -1) {
            proc[idx].ct = time + proc[idx].bt;
            proc[idx].tat = proc[idx].ct - proc[idx].at;
            proc[idx].wt = proc[idx].tat - proc[idx].bt;
            time = proc[idx].ct;
            proc[idx].done = true;
            completed++;
        } else {
            time++; // If no process has arrived yet, increment time
        }
    }

    // Output
    cout << "\nPID\tAT\tBT\tCT\tTAT\tWT\n";
    for (const auto& p : proc) {
        cout << p.pid << "\t" << p.at << "\t" << p.bt << "\t"
             << p.ct << "\t" << p.tat << "\t" << p.wt << endl;
    }

    return 0;
}
