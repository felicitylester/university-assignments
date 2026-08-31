//  Felicity Lester
//  10/3/24
//  CS.3360-HW2
//  PROBLEM 1

#include <iostream>
#include <cmath>
#include <cstdlib>
#include <ctime>

using namespace std;

// generates exponentially distributed random numbers
double generateExponential(double lambda) {
    double n = rand() / static_cast<double>(RAND_MAX);
    return -log(1 - n) / lambda; // inverse method
}

// generate Poisson Distribution arrival times
double generatePoisson(double lambda) {
    double L = exp(-lambda);
    int k = 0;
    double p = 1.0;

    do {
        k++;
        double n = rand() / static_cast<double>(RAND_MAX);
        p *= n;
    } while (p > L);

    return k - 1;
}

int main() {
    srand(time(0)); // Seed for random number generation

    const int numProcesses = 1000;
    const double avgArrivalRate = 2.0;
    const double avgServiceTime = 1.0;

    double totalArrivalTime = 0.0;
    double totalServiceTime = 0.0;

    for (int i = 1; i <= numProcesses; i++) {
        double arrivalTime = generatePoisson(avgArrivalRate);
        double serviceTime = generateExponential(1.0 / avgServiceTime);

        totalArrivalTime += arrivalTime;
        totalServiceTime += serviceTime;

        cout << "Process ID: " << i << ", Arrival Time: " << arrivalTime
             << ", Requested Service Time: " << serviceTime << endl;
    }

    double actualAvgArrivalRate = totalArrivalTime / numProcesses;
    double actualAvgServiceTime = totalServiceTime / numProcesses;

    cout << "\n\nAverage Arrival Rate: " << actualAvgArrivalRate << " processes per second" << endl;
    cout << "Average Service Time: " << actualAvgServiceTime << " seconds" << endl;

    return 0;
}
