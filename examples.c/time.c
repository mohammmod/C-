#include <stdio.h>
#include <time.h>

int main(void) {

    time_t rawtime;
    struct tm*  time_;

    time(&rawtime);
    time_ = localtime(&rawtime);

    printf("%i:%i:%i %i %i %i\n", time_->tm_hour, time_->,
            time_->tm_sec, time_->tm_mday, time_->tm_mon+1,
            time_->tm_year+1900);

    return 0;
}