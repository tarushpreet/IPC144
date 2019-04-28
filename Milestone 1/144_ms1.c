#include <stdio.h>
// tools
void welcome(void);
void printTitle(void);
void printFooter(double gTotal);
void flushKeyboard(void);
void pause(void);
int getInt(void);
double getDouble(void);
int getIntLimited(int lowerLimit, int upperLimit);
double getDoubleLimited(double lowerLimit, double upperLimit);
// app interface
int yes(void);
void GroceryInventorySystem(void);
int menu(void);


// code your functions here:

void welcome(void)
{
	printf("---=== Grocery Inventory System ===---\n");
	printf("\n");
}

void printTitle(void)
{
	printf("Row |SKU| Name               | Price  |Taxed| Qty | Min |   Total    |Atn\n");
	printf("----+---+--------------------+--------+-----+-----+-----+------------|---\n");
}

void printFooter(double grandTotal)
{
	printf("--------------------------------------------------------+-----------------\n");
	if (grandTotal > 0)
	{
		printf("                                       Grand Total: |       %12.2lf\n", grandTotal);
	}
}

void flushKeyboard(void)
{
	char z='a';
	while (z != '\n')
	{
		z = getchar();
	}

}

void pause(void)
{
	printf("Press <ENTER> to continue...");
	flushKeyboard();
}

int getInt(void)
{
	char NL = 'x';
	int Value;
	scanf("%d%c", &Value, &NL);
	while (NL != '\n')
	{
		flushKeyboard();
		printf("Invalid integer, please try again: ");
		scanf("%d%c", &Value, &NL);
	}
	return(Value);
}

int getIntLimited(int lowerLimit, int upperLimit)
{
	int value=getInt();
	while (value<lowerLimit || value>upperLimit)
	{
		printf("Invalid value, %d < value < %d: ", lowerLimit, upperLimit);
		value=getInt();
	}
	return(value);
}

double getDouble(void)
{
	char NL = 'x';
	double Value;
	scanf("%lf%c", &Value, &NL);
	while (NL != '\n')
	{
		flushKeyboard();
		printf("Invalid number, please try again: ");
		scanf("%lf%c", &Value, &NL);
	}
	return(Value);
}

double getDoubleLimited(double lowerLimit, double upperLimit)
{
	double value = getDouble();
	while (value<lowerLimit || value>upperLimit)
	{
		printf("Invalid value, %lf < value < %lf: ", lowerLimit, upperLimit);
		value=getDouble();
	}
	return(value);
}

int yes(void)
{
	char ch;
	scanf("%c", &ch);
	flushKeyboard();
	while (ch != 'y' && ch != 'Y' && ch != 'N' && ch != 'n')
	{
		printf("Only (Y)es or (N)o are acceptable: ");
		scanf(" %c", &ch);
		flushKeyboard();
	}
	if (ch == 'y' || ch == 'Y')
		return(1);
	
	else if (ch == 'n' || ch == 'N')
		return(0);
}

int menu(void)
{
	int m;
	printf("1- List all items\n");
	printf("2- Search by SKU\n");
	printf("3- Checkout an item\n");
	printf("4- Stock an item\n");
	printf("5- Add new item or update item\n");
	printf("6- delete item\n");
	printf("7- Search by name\n");
	printf("0- Exit program\n");
	printf(">");
	m=getIntLimited(0, 7);
	return(m);
}

void GroceryInventorySystem(void)
{
	int r, u=0;
	welcome();
	do 
	{
		r = menu();
			switch (r)
			{

			case 1: printf("List Items under construction!\n");
				pause();
				break;

			case 2: printf("Search Items under construction!\n");
				pause();
				break;

			case 3: printf("Checkout Item under construction!\n");
				pause();
				break;

			case 4: printf("Stock Item under construction!\n");
				pause();
				break;

			case 5: printf("Add/Update Item under construction!\n");
				pause();
				
				break;
			case 6: printf("Delete Item under construction!\n");
				pause();
				
				break;
			case 7: printf("Search by name under construction!\n");
				pause();
				
				break;
			case 0: printf("Exit the program? (Y)es/(N)o: ");
				u=yes();
				
			}

	} while (u != 1);
	



}
