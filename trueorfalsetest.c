#include <stdlib.h>
#include <stdio.h>
#define PROBLEMS 2 /*change the source code here, in the problem function to add the problem, and in the check function to check.*/
#define PRIVATE static

/*trueorfalse.c: a simple true or false test.*/
/*Created by Nishant Kompella, circa 2021.*/

PRIVATE void problem(int); /*takes in problem number, prints out problem*/
void rules(); /*prints the rules*/
PRIVATE int check(int, char); /*checks if the given input is right*/

int main(){ /*the user interface, live and point counter, etc.*/
	int pc = 0; /*pc: problem count*/
	int problems = PROBLEMS; /*variable number, for printfs and such*/
	int strikes = 0, points = 0;
	int c; /*getchar man*/
	printf("would you like to take a true/false test? (y/n)");
	/* Example switch-case.
	switch (getchar()){
		case 'n':
			printf("next time, don't call this program then!\n");
			return -2;
		case 'y':
			break;
	}*/
	if((c = getchar()) == 't');
	else{
		printf("sucks\n"); /*any other key will be interpreted as false*/
		return 0;
	}
	rules();
	for(; pc < PROBLEMS && strikes > 0; pc++){
		problem(pc + 1);
		check(getchar()) == 1? points++: strikes--;
		pc++;
	}
} 

void rules(){ /*rules: prints out the rules*/
	printf("Welcome to the true or false test!\nThe rules are simple\n.");
	printf("1. You have 3 strikes. You lose them, you are out.\n"); /*the actual rules*/
	printf("2. For every problem you get right, you get a point, and for every wrong problem, you get nothing.\n");
	printf("3. You are dealing with a fairly stupid parser (and developer), so use the following commands:\n\tt: true\n\tf: false\n\tcntrl+d: quit\nUsing any other key will either lead to a core dump or a deformed program.\n");
}

PRIVATE void problem(int p){ /*problem: main bulk of this program; takes in problem #, prints out problem*/
	if(p == 1)
		printf("stand-in 1 (answer is true)");
	if(p == 2)
		printf("stand-in 2 (answer is false)");
}

PRIVATE int check(int p, char ans){ /*check: takes in problem # and response, checks whether or not the response is right*/
	if((p == 1 && ans == 't') || (p == 2 && ans == 'f'))
		return 1; /*correct!*/
	else
		return 0; /*wrong... :(*/
}
