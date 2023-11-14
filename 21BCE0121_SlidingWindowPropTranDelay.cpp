#include <iostream>
#include <vector>
#include <queue>
#include <thread>
#include <chrono>

using namespace std;
using namespace chrono_literals;

const int TRANSMISSION_DELAY_MS = 10; // Transmission delay in milliseconds
const int PROPAGATION_DELAY_MS = 5; // Propagation delay in milliseconds
const int TIMEOUT_DURATION_MS = 2000; // Timeout duration in milliseconds

struct Packet {
    int sequenceNumber;
    string data;
    bool acknowledged;
};

void sendPacket(Packet& packet) {
    // Simulate transmission delay
    this_thread::sleep_for(chrono::milliseconds(TRANSMISSION_DELAY_MS));

    // Simulate packet loss
    if (rand() % 10 < 3) {
        cout << "Packet with sequence number " << packet.sequenceNumber << " lost!" << endl;
        return;
    }

    // Simulate propagation delay
    this_thread::sleep_for(chrono::milliseconds(PROPAGATION_DELAY_MS));

    cout << "Packet with sequence number " << packet.sequenceNumber << " sent!" << endl;
}

void sender() {
    int sequenceNumber = 0;
    queue<Packet> buffer;
    vector<Packet> window;
    int base = 0;
    int nextSequenceNumber = 0;

    while (true) {
        // Calculate window size based on RTT, transmission delay, and propagation delay
        int rtt = TRANSMISSION_DELAY_MS + PROPAGATION_DELAY_MS;
        int windowSize = (rtt + TRANSMISSION_DELAY_MS) / PROPAGATION_DELAY_MS;

        // Fill the window with new packets
        while (buffer.size() < windowSize && nextSequenceNumber < sequenceNumber + windowSize) {
            Packet packet;
            packet.sequenceNumber = nextSequenceNumber;
            packet.data = "Some data";
            packet.acknowledged = false;
            buffer.push(packet);
            nextSequenceNumber++;
        }

        // Send packets in the window
        for (int i = base; i < nextSequenceNumber; i++) {
            Packet& packet = buffer.front();

            if (!packet.acknowledged) {
                sendPacket(packet);
            }

            buffer.pop();
            window.push_back(packet);
        }

        // Check for acknowledgments
        while (!window.empty()) {
            Packet& packet = window[0];

            // Simulate random acknowledgment loss
            if (rand() % 10 < 3) {
                cout << "Acknowledgment for packet with sequence number " << packet.sequenceNumber << " lost!" << endl;
                break;
            }

            // Simulate transmission delay
            this_thread::sleep_for(chrono::milliseconds(TRANSMISSION_DELAY_MS));

            packet.acknowledged = true;
            cout << "Received acknowledgment for packet with sequence number " << packet.sequenceNumber << endl;
            base++;
            window.erase(window.begin());
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

        // Simulate propagation delay
        this_thread::sleep_for(chrono::milliseconds(PROPAGATION_DELAY_MS));

        cout << "Received packet with sequence number " << expectedSequenceNumber << endl;
        expectedSequenceNumber++;

        // Simulate random acknowledgment loss
        if (rand() % 10 < 3) {
            cout << "Acknowledgment for packet with sequence number " << expectedSequenceNumber - 1 << " lost!" << endl;
            continue;
        }

        // Simulate transmission delay
        this_thread::sleep_for(chrono::milliseconds(TRANSMISSION_DELAY_MS));

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
