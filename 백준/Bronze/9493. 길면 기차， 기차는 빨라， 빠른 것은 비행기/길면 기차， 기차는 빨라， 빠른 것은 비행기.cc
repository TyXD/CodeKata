#include <iostream>
#include <vector>
#include <iomanip>
#include <cmath>

using namespace std;
int main() {
    int M, A, B;
    
    while (true) {
        cin >> M >> A >> B;
        if (M == 0 && A == 0 && B == 0) break; 
        
        double time_diff_hours = ((double)M / (double)A) - ((double)M / (double)B);

        int total_seconds = round(time_diff_hours * 3600);
        
        int seconds = total_seconds % 60;
        int minutes = (total_seconds / 60) % 60;
        int hours = total_seconds / 3600;
        cout << hours << ":"
             << setw(2) << setfill('0') << minutes << ":"
             << setw(2) << setfill('0') << seconds << "\n";
    }
}