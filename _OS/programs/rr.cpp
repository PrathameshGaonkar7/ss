#include <iostream>
#include <queue>
#include <vector>
using namespace std;

struct Process {
    int pid;
    int at;
    int bt;
    int rt;
    int ct;
    int tat;
    int wt;
    bool visited = false;
};

int main() {
    int n, tq;
    cout << "Enter number of processes: ";
    cin >> n;
    cout << "Enter Time Quantum: ";
    cin >> tq;

    vector<Process> proc(n);
    for (int i = 0; i < n; i++) {
        proc[i].pid = i + 1;
        cout << "Enter Arrival Time and Burst Time for Process " << proc[i].pid << ": ";
        cin >> proc[i].at >> proc[i].bt;
        proc[i].rt = proc[i].bt;
    }

    queue<int> q;
    int time = 0, completed = 0;
    q.push(0);
    proc[0].visited = true;

    while (completed < n) {
        if (q.empty()) {
            time++;
            for (int i = 0; i < n; i++) {
                if (!proc[i].visited && proc[i].at <= time) {
                    q.push(i);
                    proc[i].visited = true;
                }
            }
            continue;
        }

        int idx = q.front();
        q.pop();

        if (proc[idx].rt > tq) {
            time += tq;
            proc[idx].rt -= tq;
        } else {
            time += proc[idx].rt;
            proc[idx].rt = 0;
            proc[idx].ct = time;
            proc[idx].tat = proc[idx].ct - proc[idx].at;
            proc[idx].wt = proc[idx].tat - proc[idx].bt;
            completed++;
        }

        // Add newly arrived processes to queue
        for (int i = 0; i < n; i++) {
            if (!proc[i].visited && proc[i].at <= time) {
                q.push(i);
                proc[i].visited = true;
            }
        }

        // Re-add current process if it's not finished
        if (proc[idx].rt > 0) {
            q.push(idx);
        }
    }

    // Output
    cout << "\nPID\tAT\tBT\tCT\tTAT\tWT\n";
    for (auto& p : proc) {
        cout << p.pid << "\t" << p.at << "\t" << p.bt << "\t" << p.ct
             << "\t" << p.tat << "\t" << p.wt << endl;
    }

    return 0;
}
