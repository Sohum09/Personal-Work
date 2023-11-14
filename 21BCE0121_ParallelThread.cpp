#include <iostream>
#include <pthread.h>
#include <vector>

using namespace std;

// Function executed by each thread
void* threadFunction(void* arg) {
    int threadId = *(int*)arg;
    cout << "Thread " << threadId << " started." << endl;

    // Perform some work
    // ...

    cout << "Thread " << threadId << " finished." << endl;

    pthread_exit(NULL);
}

int main() {
    int numThreads;
    cout << "Enter the number of threads: ";
    cin >> numThreads;

    vector<pthread_t> threads(numThreads);
    vector<int> threadIds(numThreads);

    // Create threads
    for (int i = 0; i < numThreads; i++) {
        threadIds[i] = i;
        int result = pthread_create(&threads[i], NULL, threadFunction, (void*)&threadIds[i]);
        if (result != 0) {
            cerr << "Failed to create thread " << i << ". Error code: " << result << endl;
            exit(EXIT_FAILURE);
        }
    }

    // Wait for threads to complete
    for (int i = 0; i < numThreads; i++) {
        pthread_join(threads[i], NULL);
    }

    cout << "All threads finished." << endl;

    return 0;
}