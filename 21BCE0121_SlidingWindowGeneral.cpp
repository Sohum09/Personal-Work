#include <iostream>
#include <vector>
#include <queue>
#include <thread>
#include <chrono>

using namespace std;
using namespace chrono_literals;

const int WINDOW_SIZE = 4; // Maximum number of unacknowledged packets
const int TIMEOUT_DURATION_MS = 2000; // Timeout duration in milliseconds

struct Packet {
    int sequenceNumber;
    string data;
    bool acknowledged;
};

void sendPacket(Packet& packet) {
    // Simulate network delay
    this_thread::sleep_for(50ms);

    // Simulate packet loss
    if (rand() % 10 < 3) {
        cout << "Packet with sequence number " << packet.sequenceNumber << " lost!" << endl;
        return;
    }

    // Simulate network delay
    this_thread::sleep_for(50ms);

    cout << "Packet with sequence number " << packet.sequenceNumber << " sent!" << endl;
}

void sender() {
    int sequenceNumber = 0;
    queue<Packet> buffer;
    vector<Packet> window(WINDOW_SIZE);
    int base = 0;
    int nextSequenceNumber = 0;

    while (true) {
        // Fill the window with new packets
        while (buffer.size() < WINDOW_SIZE && nextSequenceNumber < sequenceNumber + WINDOW_SIZE) {
            Packet packet;
            packet.sequenceNumber = nextSequenceNumber;
            packet.data = "Some data";
            packet.acknowledged = false;
            buffer.push(packet);
            nextSequenceNumber++;
        }

        // Send packets in the window
        for (int i = base; i < nextSequenceNumber; i++) {
            Packet& packet = window[i % WINDOW_SIZE];

            if (!packet.acknowledged) {
                sendPacket(packet);
            }
        }

        // Check for acknowledgments
        while (base < nextSequenceNumber) {
            Packet& packet = window[base % WINDOW_SIZE];

            // Simulate random acknowledgment loss
            if (rand() % 10 < 3) {
                cout << "Acknowledgment for packet with sequence number " << packet.sequenceNumber << " lost!" << endl;
                continue;
            }

            // Simulate network delay
            this_thread::sleep_for(50ms);

            packet.acknowledged = true;
            cout << "Received acknowledgment for packet with sequence number " << packet.sequenceNumber << endl;
            base++;
        }
    }
}

void receiver() {
    int expectedSequenceNumber = 0;

    while (true) {
        // Simulate random packet loss
        if (rand() % 10 < 3) {
            cout << "Packet with sequence number " << expectedSequenceNumber << " lost!" << endl;
            continue;
        }

        // Simulate network delay
        this_thread::sleep_for(50ms);

        cout << "Received packet with sequence number " << expectedSequenceNumber << endl;
        expectedSequenceNumber++;

        // Simulate random acknowledgment loss
        if (rand() % 10 < 3) {
            cout << "Acknowledgment for packet with sequence number " << expectedSequenceNumber - 1 << " lost!" << endl;
            continue;
        }

        // Simulate network delay
        this_thread::sleep_for(50ms);

        cout << "Sending acknowledgment for packet with sequence number " << expectedSequenceNumber - 1 << endl;
    }
}

int main() {
    srand(static_cast<unsigned>(time(nullptr)));

    thread senderThread(sender);
    thread receiverThread(receiver);

    senderThread.join();
    receiverThread.join();

    return 0;
}
