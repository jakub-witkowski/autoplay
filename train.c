#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <stdlib.h>
#include <time.h>

typedef struct {
    char affiliation[2];
    char unit_type[2];
    int unit_id;
    int x_coord;
    int y_coord;
    int current_stamina;
    int remaining_movement;
    int attack_count;
    char is_base_busy[2];
    int training_time;
} au;

void train(char fname[], long* g, au a[], int* u)
{
	srand(time(NULL)); // providing core for generating random numbers

	int value; // holds the drawing drawing result;
	char* phrase; // phrase printed once training is initiated;
	int choice_made = 0; // controls the selection process;

	/* variables holding values that go into active_units once training is initiated */
	int training_time;
	int unit_cost;
	int unit_stamina;
	char* t;
	
	if (choice_made == 0 && *g < 200)
	{
		unit_cost = 100;
        unit_stamina = 20;
		training_time = 2;
		phrase = "training a worker";
		t = "W";
		choice_made = 1;
	}

	if (choice_made == 0 && (*g >= 100 && *g < 250))
	{
		value = rand() % 21;
		if (value <=10)
		{
			unit_cost = 100;
			unit_stamina = 20;
			training_time = 2;
			phrase = "training a worker";
			t = "W";
			choice_made = 1;
		}
		else if (value >10 && value <= 20)
		{
			unit_cost = 200;
            unit_stamina = 50;
			training_time = 3;
			phrase = "training a pikeman";
			t = "P";
			choice_made = 1;
		}
	}

	if (choice_made == 0 && (*g >= 250 && *g < 400))
	{
		value = rand() % 41;
		if (value <= 10)
		{
			unit_cost = 100;
			unit_stamina = 20;
			training_time = 2;
			phrase = "training a worker";
			t = "W";
			choice_made = 1;
		}
		else if (value > 10 && value <= 20)
		{
			unit_cost = 200;
            unit_stamina = 50;
			training_time = 3;
			phrase = "training a pikeman";
			t = "P";
			choice_made = 1;
		}
		else if (value > 20 && value <= 30)
		{
			unit_cost = 250;
            unit_stamina = 60;
			training_time = 3;
			phrase = "training a swordsman";
			t = "S";
			choice_made = 1;
		}
		else if (value > 30 && value <= 40)
		{
			unit_cost = 250;
            unit_stamina = 40;
			training_time = 3;
			phrase = "training an archer";
			t = "A";
			choice_made = 1;
		}
	}

	if (choice_made == 0 && (*g >= 400 && *g < 500))
	{
		value = rand() % 51;
		if (value <= 10)
		{
			unit_cost = 100;
			unit_stamina = 20;
			training_time = 2;
			phrase = "training a worker";
			t = "W";
			choice_made = 1;
		}
		else if (value > 10 && value <= 20)
		{
			unit_cost = 200;
            unit_stamina = 50;
			training_time = 3;
			phrase = "training a pikeman";
			t = "P";
			choice_made = 1;
		}
		else if (value > 20 && value <= 30)
		{
			unit_cost = 250;
            unit_stamina = 60;
			training_time = 3;
			phrase = "training a swordsman";
			t = "S";
			choice_made = 1;
		}
		else if (value > 30 && value <= 40)
		{
			unit_cost = 250;
            unit_stamina = 40;
			training_time = 3;
			phrase = "training an archer";
			t = "A";
			choice_made = 1;
		}
		else if (value > 40 && value <= 50)
		{
			unit_cost = 400;
            unit_stamina = 70;
			training_time = 5;
			phrase = "training a knight";
			t = "K";
			choice_made = 1;
		}
	}

	if (choice_made == 0 && (*g >= 500 && *g < 800))
	{
		value = rand() % 61;
		if (value <= 10)
		{
			unit_cost = 100;
			unit_stamina = 20;
			training_time = 2;
			phrase = "training a worker";
			t = "W";
			choice_made = 1;
		}
		else if (value > 10 && value <= 20)
		{
			unit_cost = 200;
            unit_stamina = 50;
			training_time = 3;
			phrase = "training a pikeman";
			t = "P";
			choice_made = 1;
		}
		else if (value > 20 && value <= 30)
		{
			unit_cost = 250;
            unit_stamina = 60;
			training_time = 3;
			phrase = "training a swordsman";
			t = "S";
			choice_made = 1;
		}
		else if (value > 30 && value <= 40)
		{
			unit_cost = 250;
            unit_stamina = 40;
			training_time = 3;
			phrase = "training an archer";
			t = "A";
			choice_made = 1;
		}
		else if (value > 40 && value <= 50)
		{
			unit_cost = 400;
            unit_stamina = 70;
			training_time = 5;
			phrase = "training a knight";
			t = "K";
			choice_made = 1;
		}
		else if (value > 50 && value <= 60)
		{
			unit_cost = 500;
            unit_stamina = 90;
			training_time = 4;
			phrase = "producing a ram";
			t = "R";
			choice_made = 1;	
		}
	}

	if (choice_made == 0 && *g > 800)
	{
		value = rand() % 71;
		if (value <= 10)
		{
			unit_cost = 100;
			unit_stamina = 20;
			training_time = 2;
			phrase = "training a worker";
			t = "W";
			choice_made = 1;
		}
		else if (value > 10 && value <= 20)
		{
			unit_cost = 200;
            unit_stamina = 50;
			training_time = 3;
			phrase = "training a pikeman";
			t = "P";
			choice_made = 1;
		}
		else if (value > 20 && value <= 30)
		{
			unit_cost = 250;
            unit_stamina = 60;
			training_time = 3;
			phrase = "training a swordsman";
			t = "S";
			choice_made = 1;
		}
		else if (value > 30 && value <= 40)
		{
			unit_cost = 250;
            unit_stamina = 40;
			training_time = 3;
			phrase = "training an archer";
			t = "A";
			choice_made = 1;
		}
		else if (value > 40 && value <= 50)
		{
			unit_cost = 400;
            unit_stamina = 70;
			training_time = 5;
			phrase = "training a knight";
			t = "K";
			choice_made = 1;
		}
		else if (value > 50 && value <= 60)
		{
			unit_cost = 500;
            unit_stamina = 90;
			training_time = 4;
			phrase = "producing a ram";
			t = "R";
			choice_made = 1;	
		}
		else if (value > 60)
		{
			unit_cost = 800;
            unit_stamina = 50;
			training_time = 6;
			phrase = "producing a catapult";
			t = "C";
			choice_made = 1;			
		}	
	}

	if (choice_made == 1)
	{
		/* training start successful */
		strcpy(a[*u].affiliation, "P");
		strcpy(a[*u].unit_type, t);
		a[*u].unit_id = *u;
		a[*u].x_coord = 0;
		a[*u].y_coord = 0;
		a[*u].current_stamina = unit_stamina;
		a[*u].training_time = training_time;

		*g -= unit_cost;
		(*u)++;

		/* save order to rozkazy.txt */
		FILE *fptr; 
		fptr = fopen(fname, "a");
        if (!fptr)
		{
            printf("Cannot open rozkazy.txt");
        }

        if (fprintf(fptr, "0 B %c\n", *t) < 0)
		{
            fprintf(stderr, "\nUnable to write order to file.\n");
        }

        fclose(fptr);

		printf("Started %s.\n", phrase);
		//printf("Gold left: %ld. \n", *g);
		strcpy(a[0].is_base_busy, t);
	}
	
}