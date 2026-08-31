//  Felicity Lester
//  10/3/24
//  CS.3360-HW2
//  PROBLEM 2

// 20 years = 20 × 365 × 24 = 175,200 hours.

#include <iostream>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <vector>

using namespace std;

// generates exponentially distributed random numbers for server
double generateExponentialForServer(double mean) {
    double n = rand() / static_cast<double>(RAND_MAX);
    return -log(1 - n) * mean; // inverse method
}

int main() {
    srand(time(0)); // Seed for random number generation

    const double mtbf = 500.0; // MTBF of 500 hours
    const double restorationTime = 10.0; // 10 hours to restore data
    const double totalHours = 20 * 365 * 24; // Total hours in 20 years

    vector<double> server1Failures;
    vector<double> server2Failures;

    double currentTime1 = 0.0, currentTime2 = 0.0;

    while (currentTime1 < totalHours || currentTime2 < totalHours) {
        // Server 1 failure
        double failureInterval1 = generateExponentialForServer(mtbf);
        currentTime1 += failureInterval1;
        if (currentTime1 < totalHours) {
            server1Failures.push_back(currentTime1);
            currentTime1 += restorationTime; // Add restoration time
        }

        // Server 2 failure
        double failureInterval2 = generateExponentialForServer(mtbf);
        currentTime2 += failureInterval2;
        if (currentTime2 < totalHours) {
            server2Failures.push_back(currentTime2);
            currentTime2 += restorationTime; // Add restoration time
        }
    }

    // Print the failure and restoration times for server 1
    cout << "Server 1 Failures and Restorations:" << endl;
    for (double time : server1Failures) {
        cout << "Failure at hour: " << time << ", Restored by hour: " << time + restorationTime << endl;
    }

    // Print the failure and restoration times for server 2
    cout << "\nServer 2 Failures and Restorations:" << endl;
    for (double time : server2Failures) {
        cout << "Failure Time: " << time << ",  Restoration Time: " << time + restorationTime << endl;
    }

    return 0;
}
