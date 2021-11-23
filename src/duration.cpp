#include "duration.hpp"

#include <assert.h>

Duration::Duration()
{
    time = 0;
    alarm = NULL;
    alarmHasBeenSet = false;
}

Duration::Duration(int t)
{
    assert(t >= 0);
    time = t;
    alarm = NULL;
    alarmHasBeenSet = false;
}

Duration::~Duration()
{}

int Duration::GetDuration()
{
    return time;
}

bool Duration::Tick()
{
    time++;
    return CheckAndUpdateAlarm();
    
}

bool Duration::Tick(int t)
{
    assert(t > 0);
    time += t;
    return CheckAndUpdateAlarm();
    
}

bool Duration::CheckAndUpdateAlarm()
{
    if (time > alarm)
    {
        alarm = NULL;
        alarmHasBeenSet = false;
        return true;
    }
    else
    {
        return false;
    }
}

void Duration::SetAlarm(int t)
{
    assert(t >= 0);
    // Avoid setting alarm in the past
    assert(t >= time);

    alarm = t;
    alarmHasBeenSet = true;
}