#include <stdio.h>
#include <unistd.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <sys/types.h>          
#include <sys/socket.h>


int main() {

	int fd[2];
    static const int parentsocket = 0;
    static const int childsocket = 1;
    pid_t pid;

    socketpair(PF_LOCAL, SOCK_STREAM, 0, fd);

    pid = fork();
    if (pid == 0) { 
        close(fd[parentsocket]);
    } else { 
        close(fd[childsocket]); 
    }

}