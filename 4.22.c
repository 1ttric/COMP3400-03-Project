#include <pthread.h>
#include <stdio.h>
#include <math.h>
#include <stdlib.h>

void *generate_points(void *param);
double get_random_number();
double approximate_pi();

const int MAX_POINTS = 100000;
const double RADIUS = 1;

int in_circle_count = 0;

int main(int arc, char *arcv[])
{
  srand(time(NULL));

  pthread_t thread;
  pthread_create(&thread, NULL, generate_points, NULL);

  pthread_join(thread, NULL);
  printf("Pi is approximatly: %f\n", approximate_pi());
}

// Generates random points. Increments the in_circle_count for each point within the radius
void *generate_points(void *param)
{
   for(int i = 0; i < MAX_POINTS; i++)
   {
   	double x = get_random_number();
   	double y = get_random_number();
   	double distance = sqrt(pow(x, 2) + pow(y, 2));
   	if(distance <= RADIUS)
   	{
        	in_circle_count++;
   	}    	 
   }
}

// Returns a random double between 0 and 1 inclusive
double get_random_number()
{
   return (double)rand() / (double)RAND_MAX;
}

// Monte Carlo equation
double approximate_pi()
{
   return 4.0 * in_circle_count / (double)MAX_POINTS;
}
