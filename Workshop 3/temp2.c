#include<stdio.h>
#define NUMS 4
int main()
{
	printf("---=== IPC Temperature Analyzer ===---\n");

	int a[3];
	int b[3];
	int i;
	for (i = 0; i<NUMS; ++i) {

		printf("Enter the high value for day %d: ", i + 1);
		scanf("%d", &a[i]);

		printf("\nEnter the low value for day %d: ", i + 1);
		scanf("%d", &b[i]);
		printf("\n");

		while (a[i]>40 || b[i]<-40 || a[i]<b[i])
		{
			printf("Incorrect values, temperatures must be in range -40 to 40, high must be greater than low.\n");

			printf("Enter the high value for day %d: ", i + 1);
			scanf("%d", &a[i]);
			printf("Enter the low value for day %d: ", i + 1);
			scanf("%d", &b[i]);
		}

	}

	double sum = 0.00;
	double  mean;
	for (i = 0; i<NUMS; ++i) {
		sum = sum + a[i] + b[i];
	}
	mean = sum / (NUMS + NUMS);

	printf("The average (mean) temperature was: %.2lf", mean);

	printf("\n");

	if (a[0] > a[1] && a[2] > a[3] && a[0] > a[3])
		printf("The highest temperature was %d, on day 1", a[0]);
	else if (a[1] > a[0] && a[1] > a[2] && a[1] > a[3])
		printf("The highest temperature was %d, on day 2", a[1]);
	else if (a[2] > a[0] && a[2] > a[1] && a[2] > a[3])
		printf("The highest temperature was %d, on day 3", a[2]);
	else if(a[3] > a[0] && a[3] > a[1] && a[3] > a[2])
		printf("The highest temperature was %d, on day 4", a[3]);

	printf("\n");

	if (b[0] < b[1] && b[0] < b[2] && b[0] < b[3])
		printf("The lowest temperature was %d, on day 1", b[0]);
	else if (b[1] < b[0] && b[1] < b[2] && b[1] < b[3])
		printf("The lowest temperature was %d, on day 2", b[1]);
	else if (b[2] < b[0] && b[2] < b[1] && b[2] < b[3])
		printf("The lowest temperature was %d, on day 3", b[2]);
	else if (b[3] < b[0] && b[3] < b[1] && b[3] < b[2])
		printf("The lowest temperature was %d, on day 4", b[3]);





	getch();
	return 0;
}

