#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>
#include "logger.h"

// -----------------------------------------------------------------------------------------------
void* generate_logs(void* arg){
    long id = (long)arg;
    char buf[50];
    for(int i=0; i<15; i++){
        sprintf(buf, "Watek %ld dziala...", id);
        logger_message(LOG_MIN, buf);
        sleep(1);
    }
    return NULL;
}

// -----------------------------------------------------------------------------------------------
int main(){
    printf("PID: %d. Start...\n", getpid());

    // proba przed init
    logger_message(LOG_MIN, "To nie powinno sie pojawic");

    if(logger_init("app.log") != 0){
        return 1;
    }

    // proba drugiego init
    logger_init("app2.log");

    pthread_t t1, t2;
    pthread_create(&t1, NULL, generate_logs, (void*)1);
    pthread_create(&t2, NULL, generate_logs, (void*)2);

    union sigval val;
    
    // ZRZUT STOSU
    sleep(2);
    val.sival_int = DUMP_STACK;
    printf("[MAIN] Wysylam DUMP STACK\n");
    sigqueue(getpid(), SIG_DUMP, val);

    // ZMIANA POZIOMU
    // sleep(2);
    // printf("[MAIN] Wysylam ZMIANE POZIOMU (na STANDARD)\n");
    // sigqueue(getpid(), SIG_LEVEL, val);

    // ZRZUT STERTY
    sleep(2);
    val.sival_int = DUMP_HEAP;
    printf("[MAIN] Wysylam DUMP HEAP\n");
    sigqueue(getpid(), SIG_DUMP, val);

    // WYLACZENIE
    sleep(2);
    printf("[MAIN] Wysylam TOGGLE (OFF)\n");
    sigqueue(getpid(), SIG_TOGGLE, val);

    // KONIEC
    pthread_join(t1, NULL);
    pthread_join(t2, NULL);
    
    logger_close();
    
    printf("Koniec.\n");
    return 0;
}