// #include <stdio.h>
// #include <stdlib.h>
// #include <pthread.h>

// void	*entry_point(void * value)
// {
// 	printf("Hello 2\n");

// 	return (NULL);
// }

// int		main(void)
// {
// 	printf("Hello 1\n");
// 	 int num = 123;
// 	pthread_t	thread;

// 	pthread_create(&thread, NULL, entry_point, &num);

// 	pthread_join(thread, NULL);
// }

/*
 * threadIntro.c
 *
 *  Created on: Feb 22, 2014
 *      Author: marknorton
 */

// #include <stdio.h>
// #include <pthread.h>

// #define NUMTHRDS 2

// pthread_t t[NUMTHRDS];

// int coin_flip = 0;

// static void *thread2(void *_)
// {
// 	printf("Thread 2: flipped coin %d\n", coin_flip);
// }

// static void *thread1(void *_)
// {

// 	coin_flip = 23;
// 	printf("Thread 1: flipped coin %d\n", coin_flip);
// }

// int main()
// {
// 	/**
// 	 * You have no idea what order initial threads will be done with first
// 	 *
// 	 */
// 	pthread_create(&t[1], NULL, thread2, NULL);
// 	pthread_create(&t[0], NULL, thread1, NULL);

// 	//must have this as main will block until all the supported threads are done
// 	pthread_exit(NULL);

// 	return 1;
// }

/*
 * Mutexes.c
 *
 *  Created on: Feb 22, 2014
 *      Author: marknorton
 */
#include <stdio.h>
#include <pthread.h>

#define NUMTHRDS 2

pthread_t t[NUMTHRDS];
int coin_flip;

pthread_mutex_t flip_done;

static void *thread2(void *_)
{
	pthread_mutex_lock(&flip_done);
	printf("Thread 2: flipped coin %d\n", coin_flip);
}

static void *thread1(void *_)
{
	coin_flip = 23;
	printf("Thread 1: flipped coin %d\n", coin_flip);
	pthread_mutex_unlock(&flip_done);
}

int main()
{
	pthread_mutex_init(&flip_done, NULL);
	pthread_mutex_lock(&flip_done);
	pthread_create(&t[1], NULL, thread2, NULL);
	pthread_create(&t[0], NULL, thread1, NULL);

	pthread_mutex_destroy(&flip_done);

	//must have this as main will block until all the supported threads are done
	pthread_exit(NULL);

	return 1;
}
