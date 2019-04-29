#include<stdio.h>
#define NUMS 3
int main()
{
	printf("---=== IPC Temperature Analyzer ===---\n");
	
	double a[2];
	double b[2];
	double sum=0;
	int i;
	for (i=0; i<NUMS; ++i){
	
	printf("Enter the high value for day %d: ", i+1);
	scanf("%lf", &a[i]);

	printf("\nEnter the low value for day %d: ", i+1);
	scanf("%lf", &b[i]);
	printf("\n");
	

	while (a[i]>40 || b[i]<-40 || a[i]<b[i])
	{	printf("Incorrect values, temperatures must be in range -40 to 40, high must be greater than low.\n\n");
		
		printf("Enter the high value for day %d: ", i+1);
		scanf("%lf", &a[i]);
		printf("\nEnter the low value for day %d: ", i+1);
		scanf("%lf", &b[i]);
		printf("\n");
		break;
	}

	sum=sum+a[i]+b[i];
	       		    
				}

	double  mean;
	mean=sum/(NUMS+NUMS);
	
		printf("The average (mean) temperature was: %.2lf", mean);

	
		printf("\n");
				
	return 0;
}

