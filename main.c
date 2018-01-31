#include <stdio.h>
#include <signal.h>
#include <unistd.h>
#include <sys/types.h>


int main() {

	pid_t pid;
	
	if (pid = fork()) {
		FILE* f = fopen("/home/box/pid", "w");
		fprintf(f, "%d", pid);
		fclose(f);

		struct sigaction new_action;
	    new_action.sa_handler = SIG_IGN;
	    new_action.sa_flags = SA_RESTART;

	    sigemptyset(&new_action.sa_mask);

		sigaddset(&new_action.sa_mask, SIGINT);
		sigaddset(&new_action.sa_mask, SIGTERM);

		sigaction(SIGINT, &new_action, NULL);
		sigaction(SIGTERM, &new_action, NULL);

		return 0;
	}

	// printf("Hello from C-code :)\n");

	return 0;
}