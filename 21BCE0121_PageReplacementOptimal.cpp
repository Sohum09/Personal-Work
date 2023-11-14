#include <iostream>
#include <vector>
#include <unordered_set>
#include <queue>
#include <algorithm>

using namespace std;

int optimalPageReplacement(vector<int> pages, int capacity) {
    unordered_set<int> pageSet;
    queue<int> pageQueue;
    int pageFaults = 0;

    for (int page : pages) {
        if (pageSet.size() < capacity) {
            if (pageSet.find(page) == pageSet.end()) {
                pageSet.insert(page);
                pageQueue.push(page);
                pageFaults++;
            }
        } else {
            if (pageSet.find(page) == pageSet.end()) {
                int furthestPage = -1;
                int maxDistance = -1;

                for (int i = 0; i < capacity; i++) {
                    int currentPage = pageQueue.front();
                    pageQueue.pop();

                    if (find(pages.begin(), pages.end(), currentPage) == pages.end()) {
                        furthestPage = currentPage;
                        break;
                    }

                    int distance = find(pages.begin(), pages.end(), currentPage) - pages.begin();

                    if (distance > maxDistance) {
                        maxDistance = distance;
                        furthestPage = currentPage;
                    }

                    pageQueue.push(currentPage);
                }

                pageSet.erase(furthestPage);
                pageSet.insert(page);
                pageQueue.push(page);
                pageFaults++;
            }
        }
    }

    return pageFaults;
}

int main() {
    vector<int> pages = {1, 2, 3, 4, 1, 2, 5, 1, 2, 3, 4, 5};
    int capacity = 3;

    int pageFaults = optimalPageReplacement(pages, capacity);

    cout << "Number of Page Faults: " << pageFaults << endl;

    return 0;
}
