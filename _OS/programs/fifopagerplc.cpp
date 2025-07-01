#include <iostream>
#include <queue>
#include <unordered_set>
using namespace std;

int main() {
    int n, frameSize;

    cout << "Enter the number of pages in the reference string: ";
    cin >> n;

    int pages[n];
    cout << "Enter the page reference string:\n";
    for (int i = 0; i < n; i++) {
        cin >> pages[i];
    }

    cout << "Enter the number of frames: ";
    cin >> frameSize;

    unordered_set<int> frames;
    queue<int> order;
    int pageFaults = 0;

    for (int i = 0; i < n; i++) {
        int currentPage = pages[i];

        // If page is not already in frames
        if (frames.find(currentPage) == frames.end()) {
            if (frames.size() == frameSize) {
                // Remove the oldest page
                int pageToRemove = order.front();
                order.pop();
                frames.erase(pageToRemove);
            }

            // Insert the new page
            frames.insert(currentPage);
            order.push(currentPage);
            pageFaults++;

            cout << "Page " << currentPage << " caused a page fault.\n";
        } else {
            cout << "Page " << currentPage << " hit (no fault).\n";
        }
    }

    cout << "\nTotal Page Faults = " << pageFaults << endl;

    return 0;
}
