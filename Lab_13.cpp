#include <array>
#include <fstream>
#include <iostream>
using namespace std;

int main() {
    
    constexpr size_t N = 30;           // Fixed size for the array       
    vector<int> attendees;           // Our fixed-size container
                         
    ifstream fin("attendance.txt");     // Open the input file  
    if (!fin) {                         // Always check file I/O (housekeeping)
        cerr << "Could not open attendance.txt\n";
        return 1;
    }

   int x;                            // Temporary variable to hold each value
    while (fin >> x) {               // Read until we run out of values by putting the fin itteration into x until no more goes into x
        attendees.push_back(x);      // append to the end of the vector
    }
    if (attendees.size() < N) {
        cerr << "Need at least " << N << " integers in the file.\n";
        return 1;
    }

    cout << "Loaded " << attendees.size()                            // .size() for number of elements
         << " values :) \nEmpty? : " << (attendees.empty() ? "Yes" : "No") // .empty() to check if empty (True or false)
         << "\n";

    cout << "First = " << attendees.front()                            // .front() for first element
         << "  Fifteenth = " << attendees.at(14)                       // .at() for specific element
         << "  Last = " << attendees.back()                            // .back() for last element
         << "\n";

    cout  << "---------All attendees--------- \n";
    for (const auto& val : attendees) {                                // Range-based for loop
        cout << val << ' ';                                            // Print each value
    }
}