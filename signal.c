#include <stdio.h>
#include <signal.h>
#include <stdbool.h>
#include <unistd.h>

bool gStop = false;

void signal_handler(int sig) {
        printf("Signal handler called - Signal %d !\n", sig);
        gStop = true;
}


int main(void) {
        printf("registering signal handler \n");
        signal(SIGINT, signal_handler);

        while(!gStop) {
                printf("still running..\n");
                sleep(1);
        }

        printf(" and terminating politely now...\n");
        return 0;

}
