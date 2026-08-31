//  Felicity Lester
//  10/29/24
//  CS.3360-PA2


#include <iostream>
#include <cstdlib>
#include <cmath>
#include <vector>
#include <queue>
#include <ctime>
#include <iomanip>
#include <fstream> // Include fstream for file handling
#include <filesystem> // Include filesystem for checking file existence

using namespace std;

struct Event {
    double time;
    bool isArrival; // true for arrival, false for departure

    Event(double t, bool arrival) : time(t), isArrival(arrival) {}
};

// Comparator for event queue
struct EventComparator {
    bool operator()(const Event& e1, const Event& e2) {
        return e1.time > e2.time;
    }
};

// Generates exponentially distributed random numbers
double exponentialRandom(double lambda) {
    double randVal = rand() / static_cast<double>(RAND_MAX);
    return -log(1 - randVal) / lambda; // Inverse method
}

// Class for ProcessSimulator
class ProcessSimulator {
private:
    double lambda;                  // Arrival rate
    double serviceMean;
    int totalProcesses;
    double currentTime;             // Current simulation time
    double totalBusyTime;
    double totalTimeInQueue;
    double totalIdleTime;
    double totalServiceTime;
    priority_queue<Event, vector<Event>, EventComparator> eventQueue;
    vector<double> arrivalTimes;    // Store arrival times
    vector<double> completionTimes; // Store completion times
    queue<double> readyQueue;       // Queue for processes waiting for CPU
    double nextServiceEndTime;
    ofstream& outputFile;           // Reference to output file stream

public:
    // Initialize the simulator with lambda, service mean, and output file
    ProcessSimulator(double l, double s, ofstream& outFile)
        : lambda(l), serviceMean(s), totalProcesses(0),
          currentTime(0.0), totalBusyTime(0.0), totalTimeInQueue(0.0),
          totalIdleTime(0.0), totalServiceTime(0.0), nextServiceEndTime(0.0),
          outputFile(outFile) {
        scheduleNextArrival();
    }

    void scheduleNextArrival() {
        double interarrivalTime = exponentialRandom(lambda); // Generate interarrival time
        eventQueue.push(Event(currentTime + interarrivalTime, true));
    }

    void processNextEvent() {
        if (eventQueue.empty()) return;

        Event currentEvent = eventQueue.top();
        eventQueue.pop();
        currentTime = currentEvent.time;

        if (currentEvent.isArrival) {
            arrivalTimes.push_back(currentTime);    // Record arrival time
            readyQueue.push(currentTime);           // Add process to the ready queue

            // If the CPU is idle, schedule service completion
            if (nextServiceEndTime <= currentTime) {
                double serviceTime = exponentialRandom(1.0 / serviceMean);
                eventQueue.push(Event(currentTime + serviceTime, false));   // Departure
                totalServiceTime += serviceTime;
                nextServiceEndTime = currentTime + serviceTime;             // Update next service end time
            }

            scheduleNextArrival();
        } else {
            completionTimes.push_back(currentTime); // Record completion time
            totalProcesses++;

            // Remove the process
            double arrivalTime = readyQueue.front();
            readyQueue.pop();

            // Calculate turnaround time
            double turnaroundTime = currentTime - arrivalTime;
            totalTimeInQueue += turnaroundTime;
            
            // Calculate busy time for this process
            totalBusyTime += (currentTime - nextServiceEndTime + (currentEvent.time - arrivalTime));

            // If there are processes left in the queue, schedule the next one
            if (!readyQueue.empty()) {
                double nextServiceTime = exponentialRandom(1.0 / serviceMean);
                eventQueue.push(Event(currentTime + nextServiceTime, false));
                totalServiceTime += nextServiceTime;
                nextServiceEndTime = currentTime + nextServiceTime;
            }
        }
    }

    void runSimulation() {
        while (totalProcesses < 10000) {
            processNextEvent();
        }
        
        // Calculate average turnaround time
        double totalTurnaroundTime = 0.0;
        for (int i = 0; i < totalProcesses; i++) {
            double turnaroundTime = completionTimes[i] - arrivalTimes[i];
            totalTurnaroundTime += turnaroundTime;
        }
        double averageTurnaroundTime = totalProcesses > 0 ? totalTurnaroundTime / totalProcesses : 0.0; // Prevent division by zero

        // Calculate throughput
        double totalSimulationTime = totalProcesses > 0 ? completionTimes.back() : 0.0; // Time last process completed
        double throughput = totalSimulationTime > 0 ? totalProcesses / totalSimulationTime : 0.0; // Prevent division by zero

        // Calculate average CPU utilization
        double cpuUtilization = totalSimulationTime > 0 ? (totalBusyTime / totalSimulationTime) * 100 : 0.0; // Gives percentage

        // Export results to CSV
        exportResultsToCSV(lambda, averageTurnaroundTime, throughput, cpuUtilization);
    }

    // Export results to CSV
    void exportResultsToCSV(double lambda, double avgTurnaround, double throughput, double cpuUtilization) {
        outputFile << lambda << "," << avgTurnaround << "," << throughput << "," << cpuUtilization << "\n"; // Write results to the same file
    }
};

int main(int argc, char* argv[]) {
    // Seed random number generator once
    srand(static_cast<unsigned int>(time(nullptr)));

    ofstream csvFile("/Users/felicitylester/Documents/simulation_results.csv", ios::app); // Open the output file
    if (!csvFile.is_open()) {
        cerr << "Error: Could not open the file!" << endl;
        return 1;
    }

    // Initialize CSV file header if it does not exist
    if (!std::filesystem::exists("/Users/felicitylester/Documents/simulation_results.csv")) {
        csvFile << "Lambda,Average Turnaround Time,Throughput,CPU Utilization (%)\n";
    }

    if (argc == 3) {
        double lambda = atof(argv[1]);
        double serviceMean = atof(argv[2]);
        ProcessSimulator simulator(lambda, serviceMean, csvFile);
        simulator.runSimulation();
    } else {
        double serviceMean = 0.04; // Fixed
        for (double lambda = 10.0; lambda <= 30.0; lambda += 1.0) {
            ProcessSimulator simulator(lambda, serviceMean, csvFile);
            cout << "\nSimulation for λ = " << lambda << endl;
            simulator.runSimulation();
        }
    }

    csvFile.close(); // Ensure the file is closed when done
    return 0;
}

