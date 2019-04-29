#include<stdio.h>
int main()
{
	printf("---=== IPC Temperature Analyzer V2.0===---\n");

	int i, j;
	int a[10];
	int b[10];

	printf("Please enter the number of days between 3 and 10, inclusive: ");
	scanf("%d", &i);
	while (i < 3 || i > 10)
	{
		printf("Invalid entry, please enter a number between 3 and 10, inclusive: ");
		scanf("%d", &i);
	}
	printf("\n");

	for (j = 0; j < i; j++)
	{
		printf("Day %d - High: ", j + 1);
		scanf("%d", &a[j]);

		printf("Day %d - Low: ", j + 1);
		scanf("%d", &b[j]);
	}
	printf("\n");
	printf("Day Hi Low");

	for (j = 0; j < i; j++)
	{
		printf("\n%d   %d  %d", j + 1, a[j], b[j]);
	}
	
	
	int k;
	vote:
		printf("\n\nEnter a number between 1 and %d to see the average temperature for the entered number of days, enter a negative number to exit: ", i);
		scanf("%d", &k);

		while (k > i)
		{
			printf("\nInvalid entry, please enter a number between 1 and %d, inclusive: ", i);
			scanf("%d", &k);
		}


		if (k > 0)
		{
			double sum = 0;
			for (j = 0; j < k; j++)

			{
				sum = sum + a[j] + b[j];
			}

			double avg;
			avg = sum / (k + k);
			printf("\nThe average temperature upto day %d is: %.2lf", k, avg);
			goto vote;
		}


	
		else if (k < 0)
		{
			printf("\nGoodbye!");
		}
	

	getch();
	return 0;
}



