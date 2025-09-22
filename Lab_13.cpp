#include <array>
#include <fstream>
#include <iostream>
using namespace std;

int main() {
    
    constexpr size_t N = 30;           // Fixed size for the array        

    array<int, N> attendees;           // Our fixed-size container

                                    
    ifstream fin("attendance.txt");     // Open the input file  
    if (!fin) {                         // Always check file I/O (housekeeping)
        cerr << "Could not open attendance.txt\n";
        return 1;
    }

    for (size_t i = 0; i < attendees.size(); ++i) {             // Using size_t since we are indexing things
        if (!(fin >> attendees.at(i))) {                        // stop if the file runs out early
            cerr << "Need " << attendees.size() << " integers in the file.\n"; //displays the error message and size needed
            return 1;
        }
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