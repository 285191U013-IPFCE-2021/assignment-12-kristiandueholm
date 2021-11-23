#ifndef DURATION_H
#define DURATION_H

class Duration
{
    private:
        int time;
        int alarm;
        bool alarmHasBeenSet;
    public:
        // Constructor
        Duration();
        Duration(int t);
        // Destructor
        ~Duration();
        int GetDuration();
        bool Tick();
        bool Tick(int t);
        bool CheckAndUpdateAlarm();
        void SetAlarm(int t);
};

#endif