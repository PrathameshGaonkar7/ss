#include <iostream>
#include <vector>
using namespace std;

struct Process {
    int pid;
    int at;
    int bt;
    int priority;
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
        cout << "Enter Arrival Time, Burst Time, and Priority for Process " << proc[i].pid << ": ";
        cin >> proc[i].at >> proc[i].bt >> proc[i].priority;
    }

    int completed = 0, time = 0;

    while (completed < n) {
        int idx = -1;
        int highestPriority = 1e9;

        // Find highest priority process that has arrived and is not done
        for (int i = 0; i < n; i++) {
            if (!proc[i].done && proc[i].at <= time) {
                if (proc[i].priority < highestPriority) {
                    highestPriority = proc[i].priority;
                    idx = i;
                }
            }
        }

        if (idx != -1) {
            time += proc[idx].bt;
            proc[idx].ct = time;
            proc[idx].tat = proc[idx].ct - proc[idx].at;
            proc[idx].wt = proc[idx].tat - proc[idx].bt;
            proc[idx].done = true;
            completed++;
        } else {
            time++;  // Idle time if no process has arrived
        }
    }

    // Output
    cout << "\nPID\tAT\tBT\tPriority\tCT\tTAT\tWT\n";
    for (auto& p : proc) {
        cout << p.pid << "\t" << p.at << "\t" << p.bt << "\t" << p.priority << "\t\t"
             << p.ct << "\t" << p.tat << "\t" << p.wt << endl;
    }

    return 0;
}
