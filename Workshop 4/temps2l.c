#include<stdio.h>
int main()
{
	printf("---=== IPC Temperature Analyzer V2.0 ===---\n");
	
	int i, j;
	int a[10];
	int b[10];
	
	printf("Please enter the number of days between 3 and 10, inclusive: ");
	scanf("%d", &i);
	while (i < 3 || i > 10)
	{
		printf("\n");
		printf("Invalid entry, please enter a number between 3 and 10, inclusive: ");
		scanf("%d", &i);
	}
	printf("\n");
	for (j = 0; j < i; j++)
	{
		printf("Day %d - High: ", j+1);
		scanf("%d", &a[j]);

		printf("Day %d - Low: ", j+1);
		scanf("%d", &b[j]);
	}
	printf("\n");
	printf("Day Hi Low");

	for (j = 0; j < i; j++)
	{
		printf("\n%d   %d   %d", j+1, a[j], b[j]);
	}
	getch();
	return 0;
}



