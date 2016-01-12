#ifndef PROJECT_TIMEKEEPER_H
#define PROJECT_TIMEKEEPER_H

#include <SDL.h>

class timekeeper {
public:
    timekeeper();
    void start();
    void stop();
    void pause();
    void unpause();

    long get_ticks();

    bool is_started();
    bool is_paused();

    virtual ~timekeeper();

private:
    long start_ticks;
    long pause_ticks;

    bool paused;
    bool started;
};


#endif //PROJECT_TIMEKEEPER_H
