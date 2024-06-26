#include "Clock.h"

// Display the menu
void menu() {
    cout << "*************************************" << endl;
    cout << "* 1 - Add One Hour *" << endl;
    cout << "* 2 - Add One Minute *" << endl;
    cout << "* 3 - Add One Second *" << endl;
    cout << "* 4 - Exit *" << endl;
    cout << "*************************************" << endl;
}

int main() {
    // Create two clocks
    Clock clock12(false), clock24(true);

    int choice;
    bool exit = false;

    while (!exit) {
        cout << "**************** ****************" << endl;
        cout << "* " << setw(12);
        clock12.displayTime(cout);
        cout << " * ";
        cout << "* " << setw(12);
        clock24.displayTime(cout);
        cout << " *" << endl;
        cout << "**************** ****************" << endl;
        cout << endl;

        // Display the menu
        menu();

        // Get user choice
        cin >> choice;

        switch (choice) {
            case 1:
                // Add one hour to both clocks
                clock12.addHours(1);
                clock24.addHours(1);
                break;
            case 2:
                // Add one minute to both clocks
                clock12.addMinutes(1);
                clock24.addMinutes(1);
                break;
            case 3:
                // Add one second to both clocks
                clock12.addSeconds(1);
                clock24.addSeconds(1);
                break;
            case 4:
                // Exit the program
                exit = true;
            default:
                break;
        }
    }
    return 0;
}