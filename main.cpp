#include <iostream>
#include <cstdlib>
#include <pthread.h>

pthread_mutex_t   mutex;
pthread_cond_t    cond;
pthread_barrier_t barrier;

void* waiter_cond(void *arg) {

    std::cout << "Condition waiter starts...\n";

	bool flag = true;

    pthread_mutex_lock(&mutex);

    while(flag) {
        std::cout << "Condition waiter is here\n";
        pthread_cond_wait(&cond, &mutex);
        flag = false;
    }
    pthread_mutex_unlock(&mutex);

    pthread_exit(NULL);
}


void* waiter_bar(void* arg) {
    std::cout << "Barrier waiter is here\n";
    pthread_barrier_wait(&barrier);
    pthread_exit(NULL);
}

int main() {

    pthread_mutex_init(&mutex, 0);
    pthread_barrier_init(&barrier, NULL, 1);

	pthread_t threads1, threads2;

	if (pthread_create(&threads1, NULL, waiter_cond, NULL)) std::cout << "Can't to start condition waiter\n";
	if (pthread_create(&threads2, NULL, waiter_bar,  NULL)) std::cout << "Can't to start barrieer waiter\n";

	pthread_mutex_destroy(&mutex);
	pthread_barrier_destroy(&barrier);

	std::cout << "OK\n";

    pthread_exit(NULL);

}
