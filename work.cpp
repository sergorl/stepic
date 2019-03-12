#include <stdio.h>
#include <unistd.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <sys/types.h>          
#include <sys/socket.h>

void child(int socket) {
//     const char hello[] = "hello parent, I am child";
//     write(socket, hello, sizeof(hello));
	while(1);
}

void parent(int socket) {
//     char buf[1024];
//     int n = read(socket, buf, sizeof(buf));	
	while(1);
}

int main() {

	int fd[2];
	static const int parentsocket = 0;
	static const int childsocket = 1;
	pid_t pid;

	socketpair(PF_LOCAL, SOCK_STREAM, 0, fd);

	pid = fork();
	
	if (pid == 0) { 
		close(fd[parentsocket]);
		child(fd[childsocket]);
	} else {
		close(fd[childsocket]); 
		parent(fd[parentsocket]);
	}
	exit(0);
}
