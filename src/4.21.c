#include <pthread.h>
#include <stdio.h>

void *get_average(void *param);
void *get_maximum(void *param);
void *get_minimum(void *param);


int numbers[7] = {90, 81, 78, 95, 79, 72, 85};

int main(int argc, char *argv[])
{
   pthread_t average_thread;
   pthread_create(&average_thread, NULL, get_average, NULL);

   pthread_t maximum_thread;
   pthread_create(&maximum_thread, NULL, get_maximum, NULL);

   pthread_t minimum_thread;
   pthread_create(&minimum_thread, NULL, get_minimum, NULL);

   pthread_join(average_thread, NULL);
   pthread_join(maximum_thread, NULL);
   pthread_join(minimum_thread, NULL);
}

void *get_average(void *param)
{
   float sum = 0;
   for(int i = 0; i < (sizeof(numbers)/sizeof(int)); i++)
   {
  	sum += numbers[i];
   }
   float average = sum / (sizeof(numbers)/sizeof(int));
   printf("Average: %f\n", average);
}

void *get_maximum(void *param)
{
   int maximum = numbers[0];
   for(int i = 0; i < (sizeof(numbers)/sizeof(int)); i++)
   {
  	if(maximum < numbers[i])
  	{
     	maximum = numbers[i];
  	}
   }
   printf("Maximum: %d\n", maximum);
}

void *get_minimum(void *param)
{
   int minimum = numbers[0];
   for(int i = 0; i < (sizeof(numbers)/sizeof(int)); i++)
   {
  	if(minimum > numbers[i])
  	{
     	minimum = numbers[i];
  	}
   }
   printf("Minimum: %d\n", minimum);
}
 