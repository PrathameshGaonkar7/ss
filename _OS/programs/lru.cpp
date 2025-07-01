#include <iostream>
#include <list>
#include <unordered_map>
using namespace std;

int main() {
    int n, frameSize;
    cout << "Enter number of pages: ";
    cin >> n;

    int pages[n];
    cout << "Enter the page reference string:\n";
    for (int i = 0; i < n; i++) {
        cin >> pages[i];
    }

    cout << "Enter number of frames: ";
    cin >> frameSize;

    list<int> frameList; // To maintain order (least recently used at front)
    unordered_map<int, list<int>::iterator> pageMap;
    int pageFaults = 0;

    for (int i = 0; i < n; i++) {
        int page = pages[i];

        // Page not in frame -> page fault
        if (pageMap.find(page) == pageMap.end()) {
            pageFaults++;

            // If frame full, remove LRU page
            if (frameList.size() == frameSize) {
                int lru = frameList.back();
                frameList.pop_back();
                pageMap.erase(lru);
            }
        } else {
            // If hit, move page to front
            frameList.erase(pageMap[page]);
        }

        // Insert (or reinsert) page to front
        frameList.push_front(page);
        pageMap[page] = frameList.begin();

        cout << "Page " << page << (pageMap.size() > frameSize ? " caused" : " hit (no)") << " a page fault.\n";
    }

    cout << "\nTotal Page Faults (LRU) = " << pageFaults << endl;
    return 0;
}
