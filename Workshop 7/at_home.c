/*
Name:Tarushpreet Singh
Student number:136579166
Email:
Workshop:7
Section:home
Date:
*/

#include <stdio.h>

#define SIZE 3



long long phoneNumber[SIZE] = { 0LL };

void decompose(long long n, int *a, int *b, int *c);
int isValid(long long v);

void decompose(long long n, int *a, int *b, int *c)
{
	*a = n / 10000000;
	*b = (n % 10000000) / 10000;
	*c = n % 10000;
}

/* main program */
int main(void) {

	int option;
	int j = 0;
	int x = 0, y = 0, z = 0;
	long long t;
	int r;

	printf("---=== Phone Numbers ===---\n\n");

	do {
		// Display the Option List
		printf("1. Display Phone List\n");
		printf("2. Add a Number\n");
		printf("0. Exit\n\n");
		printf("Please select from the above options: ");
		scanf("%d", &option);
		printf("\n");

		switch (option) {
		case 0:	// Exit the program
			printf("Exiting Phone Number App. Good Bye!!!");

		case 1: // Display the Phone List
				// @IN-LAB
			printf("Phone Numbers\n");
			printf("==============\n");
			// Display each number in decomposed form

			int i;

			for (i = 0; i < j; i++)
			{
				decompose(phoneNumber[i], &x, &y, &z);
				printf("(%3d)-%3d-%4d\n", x, y, z);
			}
			printf("\n");
			break;

		case 2:	// Add a Phone Number
				// @IN-LAB
			printf("Add a Number\n");
			printf("============\n");

			scanf("%lld", &t);
			r = isValid(t);
			if (r == 1)
			{

				if (j < SIZE)
				{
					phoneNumber[j] = t;
					printf("\n");
					j++;
				}
				else printf("ERROR!!! Phone Number List is Full\n\n");
			}
			
			else printf("ERROR!!! Phone Number is not Valid\n\n");
			
			
			break;

		default: printf("\n");

		}

	} while (option != 0);

	return 0;
}


int isValid(long long v)
{
	int arr[3] = { 416,647,905 };
	int a, b;
	int i, fl = -1;

	a = v / 10000000;
	b = (v % 10000000) / 10000;
	
	for (i = 0; i < 3 && fl == -1; i++)
	{
		if (a == arr[i])
		{
			fl = i;
		}
	}

	if (fl != -1 && b >= 100 && b <= 999)
	{
		return(1);
	}
	else return(0);
}