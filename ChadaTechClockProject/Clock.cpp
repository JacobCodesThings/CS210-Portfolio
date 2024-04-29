#include "Clock.h"

// Constructor
Clock::Clock(bool format_24) {
    time_t seconds = time(0);
    localTime = localtime(&seconds);
    d_hours = 0;
    d_secs = 0;
    d_mins = 0;
    this->format_24 = format_24;
}

// Function to add hours to the clock
void Clock::addHours(int hours) {
    d_hours += hours;
}

// Function to add minutes to the clock
void Clock::addMinutes(int mins) {
    d_mins += mins;
}

// Function to add seconds to the clock
void Clock::addSeconds(int secs) {
    d_secs += secs;
}

// Function to display the time
void Clock::displayTime(ostream &out) {
    int seconds = 0, minutes = 0, hours = 0;
    seconds = localTime->tm_sec + d_secs;
    minutes += (seconds / 60);
    seconds = seconds % 60;

    minutes += localTime->tm_min + d_mins;
    hours += minutes / 60;
    minutes = minutes % 60;

    hours = (hours + localTime->tm_hour + d_hours) % 24;

    out << setw(2) << setfill('0') << (format_24 ? hours : (hours % 12)) << ":";
    out << setw(2) << setfill('0') << minutes << ":";
    out << setw(2) << setfill('0') << seconds << " ";

    if (!format_24) {
        if (hours > 12) {
            out << "PM";
        } else {
            out << "AM";
        }
    }
}