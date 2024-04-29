#ifndef CLOCK_H_
#define CLOCK_H_

#include <iostream>
#include <ctime>
#include <cstdlib>
#include <iomanip>

using namespace std;

class Clock {
private:
    struct tm *localTime;
    int d_hours;
    int d_mins;
    int d_secs;
    bool format_24;

public:
    // Constructor
    explicit Clock(bool format_24);

    // Function to add hours to the clock
    void addHours(int hours);

    // Function to add minutes to the clock
    void addMinutes(int mins);

    // Function to add seconds to the clock
    void addSeconds(int secs);

    // Function to display the time
    void displayTime(ostream &out);
};

#endif /* CLOCK_H_ */