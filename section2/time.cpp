#include <iostream>
#include <iomanip>

using namespace std;

class Time {
public:
    void Init(int hours, int minutes, int seconds);
private:
    void PrintIn24HourFormat(int hours, int minutes, int seconds);
    void PrintIn12HourFormat(int hours, int minutes, int seconds);
};

void Time::Init(int hours, int minutes, int seconds) {
    if((hours >= 0 && hours <= 23) && (minutes >= 0 && minutes <= 59) && (seconds >= 0 && seconds <= 59)) {
        PrintIn24HourFormat(hours, minutes, seconds);
        PrintIn12HourFormat(hours, minutes, seconds);
    }
    else {
        cout << "Input hours must be in the range of 0 to 23\nInput minutes must be in the range of 0 to 59\nInput seconds must be in the range of 0 to 59" << endl;
    }
}

void Time::PrintIn24HourFormat(int hours, int minutes, int seconds) {
    string am_or_pm = (hours >= 12 && hours <= 23) ? "PM" : "AM";
    cout << "It's " << setw(2) << setfill('0') << hours << ":" << setw(2) << setfill('0') << minutes << ":" << setw(2) << setfill('0') << seconds << " " << am_or_pm << endl;
}

void Time::PrintIn12HourFormat(int hours, int minutes, int seconds) {
    if(hours == 0) {
        cout << "It's " << setw(2) << setfill('0') << hours + 12 << ":" << setw(2) << setfill('0') << minutes << ":" << setw(2) << setfill('0') << seconds << " AM" << endl;
    }
    else {
        int corrected_hours = (hours > 12) ? hours - 12 : hours;
        string am_or_pm = (hours >= 12 && hours <= 23) ? "PM" : "AM";
        cout << "It's " << setw(2) << setfill('0') << corrected_hours << ":" << setw(2) << setfill('0') << minutes << ":" << setw(2) << setfill('0') << seconds << " " << am_or_pm << endl;
    }
}

int main() {
    Time t;

    t.Init(23, 14, 35);
    t.Init(0, 18, 21);
    t.Init(24, 60, 60);
    t.Init(12, 25, 36);

    return 0;
}
