#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <time.h>
#include <math.h>

#define MULTI_THREADED

const unsigned int DNI = 58481818; // Example: const unsigned int DNI = 12345678 

const unsigned short nThreadsMin = 1;
const unsigned short nThreadsMax = 10;

void Task(unsigned long nElements);
int iterativeBinarySearch(int array[], int start_index, int end_index, int element);
void sortArray(int *array, int nElements);

#ifdef MULTI_THREADED
#include <pthread.h>

void * ThreadJob(void* arg)
{
	unsigned long nElements = *((unsigned long*)arg);
	Task(nElements);
	return NULL;
}
#endif

/**********************************************
* MAIN
**********************************************/
int main(int argc, char* argv[])
{
	unsigned long nElements = DNI/10000;
	unsigned int nThreads = DNI%10;

	struct timespec start, end;
	double dElapsedTimeS;
	int i;

#ifdef MULTI_THREADED
	if (nThreads<2)
		nThreads = 7;
	printf("Running with %d thread(s)...\n", nThreads);
#endif

	printf("Running task    : ");

	clock_gettime(CLOCK_REALTIME, &start);

#ifdef MULTI_THREADED
	pthread_t Threads[nThreads];
	for (i = 0; i < nThreads; i++)
	{
		int pthread_ret = pthread_create(&Threads[i], NULL, ThreadJob, &nElements);
		if (pthread_ret)
		{
			printf("ERROR: pthread_create error code: %d.\n", pthread_ret);
			exit(EXIT_FAILURE);
		}
	}

	for (i = 0; i < nThreads; i++)
		pthread_join(Threads[i], NULL);

#else
	Task(nElements);

#endif

	clock_gettime(CLOCK_REALTIME, &end);

	printf("Execution finished\n");

	dElapsedTimeS = (end.tv_sec - start.tv_sec);
	dElapsedTimeS += (end.tv_nsec - start.tv_nsec) / 1e+9;

	printf("Elapsed time    : %f s.\n", dElapsedTimeS);

	return 0;
}


/**********************************************
* FUNCION Task
**********************************************/
void Task(unsigned long nElements)
{
	srand((unsigned)clock());

	int array[nElements];
	int element = 9, nTimes = 10;
	
	for(int j=0;j<nTimes;j++){
		for(int i=0;i<nElements;i++)
			array[i]=rand()%100;

		sortArray(array, nElements);
		iterativeBinarySearch(array, 0, nElements-1, element);
	}
}

/**********************************************
* Auxiliary functions
**********************************************/
int iterativeBinarySearch(int array[], int start_index, int end_index, int element){
	
	while (start_index <= end_index)
	{
		int middle = start_index + (end_index- start_index )/2;
		
		if (array[middle] == element)
			return middle;

		if (array[middle] < element)
			start_index = middle + 1;
		else
			end_index = middle - 1;
	}
	return -1;
}

void sortArray(int *array, int nElements){
	
	int temp;

	for (int i = 0; i < nElements; i++)
	{     
		for (int j = i+1; j < nElements; j++) 
		{     
			if(array[i] > array[j]) 
			{    
				temp = array[i];    
				array[i] = array[j];    
				array[j] = temp;    
			}     
		}     
	} 
} 
