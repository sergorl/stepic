#include <stdio.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/sem.h>

int main()
{
    key_t key = ftok("/tmp/sem.temp", 1);
    int sem = semget(key, 16, 0777 | IPC_PRIVATE);
    
    for(size_t i = 0; i<16; ++i) {
    	union semun arg;
    	arg.val = i ;
    	semctl(sem, i, SETVAL, arg);
    }
    
    printf("ok.\n");

    return 0;
}
