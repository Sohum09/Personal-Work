#include <iostream>
#include <thread>
#include <queue>
#include <mutex>
#include <condition_variable>
#include <chrono>

const int BUFFER_SIZE = 5;  // Size of the buffer
const int NUM_PRODUCERS = 2;  // Number of producer threads
const int NUM_CONSUMERS = 3;  // Number of consumer threads
const int NUM_ITEMS = 10;  // Number of items to be produced

std::queue<int> buffer;  // Shared buffer
std::mutex mtx;  // Mutex for protecting buffer access
std::condition_variable bufferEmpty;  // Condition variable for buffer empty
std::condition_variable bufferFull;  // Condition variable for buffer full
int itemCount = 0;  // Counter for produced items

// Producer thread function
void producer(int id) {
    for (int i = 0; i < NUM_ITEMS; ++i) {
        std::this_thread::sleep_for(std::chrono::milliseconds(rand() % 1000));

        std::unique_lock<std::mutex> lock(mtx);
        bufferFull.wait(lock, [] { return buffer.size() < BUFFER_SIZE; });

        int item = rand() % 100;  // Generate a random item
        buffer.push(item);
        itemCount++;

        std::cout << "Producer " << id << " produced item: " << item << std::endl;

        bufferEmpty.notify_all();
        lock.unlock();
    }
}

// Consumer thread function
void consumer(int id) {
    while (true) {
        std::this_thread::sleep_for(std::chrono::milliseconds(rand() % 1000));

        std::unique_lock<std::mutex> lock(mtx);
        bufferEmpty.wait(lock, [] { return buffer.size() > 0; });

        int item = buffer.front();
        buffer.pop();

        std::cout << "Consumer " << id << " consumed item: " << item << std::endl;

        if (itemCount >= NUM_ITEMS && buffer.empty()) {
            bufferFull.notify_all();
            lock.unlock();
            break;
        }

        bufferFull.notify_all();
        lock.unlock();
    }
}

int main() {
    srand(time(nullptr));

    std::thread producers[NUM_PRODUCERS];
    std::thread consumers[NUM_CONSUMERS];

    // Create producer threads
    for (int i = 0; i < NUM_PRODUCERS; ++i) {
        producers[i] = std::thread(producer, i + 1);
    }

    // Create consumer threads
    for (int i = 0; i < NUM_CONSUMERS; ++i) {
        consumers[i] = std::thread(consumer, i + 1);
    }

    // Wait for producer threads to finish
    for (int i = 0; i < NUM_PRODUCERS; ++i) {
        producers[i].join();
    }

    // Wait for consumer threads to finish
    for (int i = 0; i < NUM_CONSUMERS; ++i) {
        consumers[i].join();
    }

    return 0;
}
