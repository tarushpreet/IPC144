//Name-Tarushpreet Singh
//Student no.- 136579166
//Student email-
//Workshop- 5
//Section- home
#include<stdio.h>
#define size 4
struct employee
{
	int	id[10];
	int age[3];
	double sal[7];


};
int main()
{
	double S[10];
	int ID[10];
	int idd[10];
	int a = 0;
	int b = 0;
	int n = 0;
	int v = 0;
	int f = 0;
	struct employee emp[size];
	int options;


	do {
		printf("---=== EMPLOYEE DATA ===---\n\n");
		printf("1. Display Employee Information\n");
		printf("2. Add Employee\n");
		printf("3. Update Employee Salary\n");
		printf("4. Remove Employee\n");
		printf("0. Exit\n");
		printf("\nPlease select from the above options: ");
		scanf("%d", &options);

		switch (options)
		{
		case 0:
		{
			b = 1;
			break;
		}



		case 1:
		{
			printf("\nEMP ID  EMP AGE  EMP SALARY\n");
			printf("========  =======   =========\n");


			for (int n = 0; n < a; n++)
			{
				if (strcmp(emp[n].id, "") == 1)
					printf("   %s\t    %s\t %s \n", emp[n].id, emp[n].age, emp[n].sal);
			}

			break;
		}
		case 2:
		{
			if (a < size) {
				printf("\nAdding Emoloyee\n===============\n");
				printf("Enter Employee ID: ");
				scanf("%s", &emp[a].id);
				printf("Enter Employee Age: ");
				scanf("%s", &emp[a].age);
				printf("Enter Employee Salary: ");
				scanf("%s", &emp[a].sal);
				printf("\n");
				a++;
			}
			else
			{
				printf("\nAdding Employee\n");
				printf("=================\n");
				printf("\nERROR!!!Maximum Number of Employees Reached\n");

			}
			break;
		}
		case 3:
		{
			do
			{
				printf("Update Employee Salary\n");
				printf("======================\n");
				printf("Enter Employee ID : ");
				scanf("%s", &ID);
				for (int j = 0; j < size; j++)
				{
					if (strcmp(ID, emp[j].id) == 0)
					{
						printf("\nThe current salary is %s", emp[j].sal);
						printf("\nEnter new Salary:");
						scanf("%s", &S);
						strcpy(emp[j].sal, S);
						v = 1;
					}
				}

			} while (v < 1);
			break;
		}
		case 4:
		{
			do
			{
				printf("\nRemove Employee\n===============\n");
				printf("Enter Employee ID :");
				scanf("%s", &idd);
				for (int c = 0; c < size; c++)
				{
					if (strcmp(idd, emp[c].id) == 0)
					{
						printf("Employer with ID %s will be removed", idd);
						printf("\n");
						strcpy(emp[c].id, "");
						strcpy(emp[c].age, "");
						strcpy(emp[c].sal, "");

						f = 1;

					}

				}
			} while (f < 1);
			break;
		}
		default:
		{
			printf("\nERROR: Incorrect Option: Try Again\n");
			break;

		}
		}
	} while (b<1);
	printf("\nExiting Employee Data Program. Good Bye!!!\n");
	return 0;
}