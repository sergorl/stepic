#include <stdio.h>
#include <signal.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

void pid2file(pid_t pid, const char* path2file) {
	FILE* f = fopen(path2file, "w");
	fprintf(f, "%d", pid);
	fclose(f);
}

int main() {

	pid_t pid; 
	
	if (pid = fork()) {
		
		//printf("Child pid is %d", pid);

		pid2file(getpid(), "/home/box/pid_parent");
		pid2file(pid, "/home/box/pid_child");

		int status, w;

		do {
			waitpid(pid, &status, 0);
			if (w == -1) perror("Error in waitpid!\n");

		} while(!WIFSIGNALED(status));

		//printf("Child with pid %d is KILLED!\n", pid);	

		return 0;
	}

	//while(1) printf("Child is here with pid %d\n", getpid());	
	while(1);

	return 0;
}