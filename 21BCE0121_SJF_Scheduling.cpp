#include <iostream>
#include <vector>
#include <algorithm>

struct Process {
    int id;
    int arrivalTime;
    int burstTime;
};

bool compareByArrivalTime(const Process& p1, const Process& p2) {
    return p1.arrivalTime < p2.arrivalTime;
}

bool compareByBurstTime(const Process& p1, const Process& p2) {
    return p1.burstTime < p2.burstTime;
}

void sjfScheduling(std::vector<Process>& processes) {
    // Sort the processes by arrival time
    std::sort(processes.begin(), processes.end(), compareByArrivalTime);

    int n = processes.size();
    std::vector<bool> completed(n, false);
    std::vector<int> waitingTime(n, 0);
    std::vector<int> turnaroundTime(n, 0);

    int currentTime = 0;
    int totalWaitingTime = 0;
    int totalTurnaroundTime = 0;

    for (int i = 0; i < n; ++i) {
        int shortestJob = -1;
        int shortestBurstTime = INT_MAX;

        // Find the process with the shortest burst time among the arrived processes
        for (int j = 0; j < n; ++j) {
            if (!completed[j] && processes[j].arrivalTime <= currentTime && processes[j].burstTime < shortestBurstTime) {
                shortestBurstTime = processes[j].burstTime;
                shortestJob = j;
            }
        }

        if (shortestJob == -1) {
            // No process available at the current time, move to the next arrival time
            currentTime = processes[i].arrivalTime;
            --i;  // Check the same index again
        } else {
            completed[shortestJob] = true;
            waitingTime[shortestJob] = currentTime - processes[shortestJob].arrivalTime;
            turnaroundTime[shortestJob] = waitingTime[shortestJob] + processes[shortestJob].burstTime;

            currentTime += processes[shortestJob].burstTime;

            totalWaitingTime += waitingTime[shortestJob];
            totalTurnaroundTime += turnaroundTime[shortestJob];
        }
    }

    // Calculate average waiting time and turnaround time
    double avgWaitingTime = static_cast<double>(totalWaitingTime) / n;
    double avgTurnaroundTime = static_cast<double>(totalTurnaroundTime) / n;

    // Print the results
    std::cout << "Process\tArrival Time\tWaiting Time\tTurnaround Time\n";
    for (int i = 0; i < n; ++i) {
        std::cout << processes[i].id << "\t\t" << processes[i].arrivalTime << "\t\t" << waitingTime[i] << "\t\t" << turnaroundTime[i] << "\n";
    }
    std::cout << "Average Waiting Time: " << avgWaitingTime << "\n";
    std::cout << "Average Turnaround Time: " << avgTurnaroundTime << "\n";
}

int main() {
    // Create a vector of processes
    std::vector<Process> processes = {
        {1, 0, 6},
        {2, 2, 4},
        {3, 4, 2},
        {4, 5, 5},
    };

    sjfScheduling(processes);

    return 0;
}
