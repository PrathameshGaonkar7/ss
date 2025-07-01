#include <iostream>
#include <vector>
#include <unordered_set>
using namespace std;

int predict(const vector<int>& pages, const unordered_set<int>& frames, int index) {
    int farthest = index, result = -1;

    for (int page : frames) {
        int j;
        for (j = index; j < pages.size(); j++) {
            if (pages[j] == page) {
                if (j > farthest) {
                    farthest = j;
                    result = page;
                }
                break;
            }
        }

        // If not found in future, return this page
        if (j == pages.size())
            return page;
    }

    // If all pages are used again, remove the one farthest in future
    return (result == -1) ? *frames.begin() : result;
}

int main() {
    int n, frameSize;
    cout << "Enter number of pages: ";
    cin >> n;

    vector<int> pages(n);
    cout << "Enter the page reference string:\n";
    for (int i = 0; i < n; i++) {
        cin >> pages[i];
    }

    cout << "Enter number of frames: ";
    cin >> frameSize;

    unordered_set<int> frames;
    int pageFaults = 0;

    for (int i = 0; i < n; i++) {
        int current = pages[i];

        if (frames.find(current) != frames.end()) {
            cout << "Page " << current << " hit (no fault).\n";
            continue;
        }

        if (frames.size() < frameSize) {
            frames.insert(current);
        } else {
            int pageToRemove = predict(pages, frames, i + 1);
            frames.erase(pageToRemove);
            frames.insert(current);
        }

        pageFaults++;
        cout << "Page " << current << " caused a page fault.\n";
    }

    cout << "\nTotal Page Faults (Optimal) = " << pageFaults << endl;
    return 0;
}
