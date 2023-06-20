#include <pthread.h>
#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>

#define MAP_SIZE_X 32
#define MAP_SIZE_Y 32
#define MAX_NUMBER_OF_UNITS 1002

#include "load_status.h"
//#include "menu.h"
//#include "train.h"
//#include "move.h"
//#include "attack.h"
#include "map.h"
#include "display_map.h"
#include "list.h"
#include "save.h"
#include "mining.h"

int time_left; // number of seconds the player program is allowed to run;

pthread_t thread; // thread identifier used for time control over the player round;

int temp[MAP_SIZE_Y][MAP_SIZE_X+1]; //temporary array to hold chars read from the file
int map_data[MAP_SIZE_Y][MAP_SIZE_X]; //target array to hold int values representing the map

long gold = 0; // holds the amount of gold
au active_units[MAX_NUMBER_OF_UNITS]; // holds information on player and enemy active units;
char type; // holds the type of the unit to be trained
int units_on_the_map_counter = 0; // holds the number of units currently present on the map

int dice(int max)
{
	int value = rand() % max;
	return value;
}

void *timer(void *arg)
{
    while (1)
	{
        /* Check if time is up in one second intervals */
        sleep(1);

        /* Update timer */
        if (time_left > 0)
		{
            time_left--;
            if (time_left == 0)
			{
                save(&gold, &units_on_the_map_counter, active_units);
			    pthread_join(thread, NULL);
				exit(0);
			}
        }
    }

    return NULL;
}

int main(int argc, char* argv[])
{
	
	int limit; // number of seconds a round is permitted to last
	if (!argv[4])
		limit = 5;
	else
		limit = atoi(argv[4]); // default = 5 seconds, as indicated in the instructions

    time_left = limit;

	/* establishing thread for time control over gameplay */
    int ret = pthread_create(&thread, NULL, timer, NULL);
    if (ret)
        return 1;

	/* erase rozkazy.txt by opening it in write mode */
	FILE *fptr = fopen(argv[3], "w");
	fclose(fptr);

	/* reading status and map data from files, updating gold if workers are present at the mine */
	map(argv[1], map_data, temp); // update map
	//printf("Map data loaded\n");
	display_map(map_data);
	//printf("Map field 16|3: %d\n", map_data[3][16]);
	
	load_status(argv[2], &units_on_the_map_counter, &gold, active_units); // otherwise, read data from status.txt
	//printf("Status loaded\n");
	printf("Number of units on the map: %d\n", units_on_the_map_counter);
	list(active_units, &units_on_the_map_counter);
	
	gold += mining(map_data, active_units, &units_on_the_map_counter); // update gold
	//printf("Gold updated\n");
	printf("Gold: %ld\n", gold);

	srand(time(NULL)); // providing core for generating random numbers
	//printf("Dice cast: %d\n", dice(100));

	save(&gold, &units_on_the_map_counter, active_units);
	pthread_join(thread, NULL);

    return 0;
}