#include <iostream>
#include <cstdlib>
#include <ctime>
#include <chrono>
#include <thread>

using namespace std;
using namespace chrono_literals;

const int PACKET_SIZE = 1024;
const int TIMEOUT_DURATION_MS = 2000;

enum class MessageType {
    Data,
    Ack
};

struct Message {
    MessageType type;
    int sequenceNumber;
    string data;
};

// Simulate network delay
void simulateDelay() {
    this_thread::sleep_for(chrono::milliseconds(50) + chrono::milliseconds(rand() % 100));
}

// Send a message to the receiver
void sendMessage(const Message& message) {
    simulateDelay();

    if (message.type == MessageType::Data) {
        cout << "Sender: Sending data packet with sequence number " << message.sequenceNumber << endl;
    } else {
        cout << "Sender: Sending ACK with sequence number " << message.sequenceNumber << endl;
    }

    simulateDelay();
}

// Receive a message from the sender
Message receiveMessage() {
    simulateDelay();

    // Simulate random packet loss
    if (rand() % 10 < 3) {
        cout << "Receiver: Packet lost!" << endl;
        return { MessageType::Data, -1, "" };
    }

    // Simulate network delay
    simulateDelay();

    // Simulate random ACK loss
    if (rand() % 10 < 3) {
        cout << "Receiver: ACK lost!" << endl;
        return { MessageType::Ack, -1, "" };
    }

    // Generate random ACK or data packet
    if (rand() % 2 == 0) {
        int sequenceNumber = rand() % 2;
        cout << "Receiver: Received data packet with sequence number " << sequenceNumber << endl;
        return { MessageType::Data, sequenceNumber, "Some data" };
    } else {
        int sequenceNumber = rand() % 2;
        cout << "Receiver: Received ACK with sequence number " << sequenceNumber << endl;
        return { MessageType::Ack, sequenceNumber, "" };
    }
}

void sender() {
    int sequenceNumber = 0;
    Message message = { MessageType::Data, sequenceNumber, "Some data" };

    while (true) {
        sendMessage(message);

        Message ack = receiveMessage();

        if (ack.type == MessageType::Ack && ack.sequenceNumber == sequenceNumber) {
            sequenceNumber = (sequenceNumber + 1) % 2;
            message.sequenceNumber = sequenceNumber;
        }
    }
}

void receiver() {
    int expectedSequenceNumber = 0;

    while (true) {
        Message message = receiveMessage();

        if (message.type == MessageType::Data && message.sequenceNumber == expectedSequenceNumber) {
            sendMessage({ MessageType::Ack, expectedSequenceNumber, "" });
            expectedSequenceNumber = (expectedSequenceNumber + 1) % 2;
        }
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
