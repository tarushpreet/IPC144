/*
Name:Tarushpreet Singh
Student number:136579166
Email:
Workshop:7
Section:lab
Date:
*/

#include <stdio.h>

#define SIZE 3



long long phoneNumber[SIZE] = { 0LL };

void decompose(long long n, int *a, int *b, int *c);

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

			if (j < SIZE)
			{
				scanf("%lld", &phoneNumber[j]);
				printf("\n");
				j++;
			}
			else printf("ERROR!!! Phone Number List is Full\n\n");

			break;


		default: printf("\n");

		}

	} while (option != 0);

	return 0;
}
