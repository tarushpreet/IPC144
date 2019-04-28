#include <stdio.h>

#define LINEAR 1
#define FORM 0
double TAX = 0.13;




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
// item related functions (ms2)
double totalAfterTax(struct Item item);
int isLowQuantity(struct Item item);
struct Item itemEntry(int sku);
void displayItem(struct Item item, int linear);
void listItems(const struct Item item[], int noOfItems);
int locateItem(const struct Item item[], int NoOfRecs, int sku, int* index);




struct Item {
	double price;
	int sku;
	int isTaxed;
	int quantity;
	int minQuantity;
	char name[21];
};


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
	char z = 'a';
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
	int value = getInt();
	while (value<lowerLimit || value>upperLimit)
	{
		printf("Invalid value, %d < value < %d: ", lowerLimit, upperLimit);
		value = getInt();
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
		value = getDouble();
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
	m = getIntLimited(0, 7);
	return(m);
}

void GroceryInventorySystem(void)
{
	int r, u = 0;
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
			u = yes();

		}

	} while (u != 1);

}


//MILESTONE2



double totalAfterTax(struct Item item)
{
	double z;
	z = item.price * item.quantity;
	
	if (item.isTaxed == 1)
	{
		z = z + z*TAX;
	}
	
	return(z);
}

int isLowQuantity(struct Item item)
{
	if (item.quantity <= item.minQuantity)
	{
		return(1);
	}
	else return(0);
}

struct Item itemEntry(int sku)
{
	struct Item item;
	item.sku = sku;

	printf("            Name: ");
	scanf("%20[^\n]", &item.name);
	flushKeyboard();

	printf("           Price: ");
	item.price = getDouble();

	printf("        Quantity: ");
	item.quantity = getInt();

	printf("Minimum Quantity: ");
	item.minQuantity = getInt();

	printf("        Is Taxed: ");
	item.isTaxed = yes();

	return item;
}

void displayItem(struct Item item, int linear)
{
	double z;
	z = totalAfterTax(item);

	if (linear == 1)
	{
		if (item.isTaxed == 0)
		{
			printf("|%3d|%-20s|%8.2lf|   No| %3d | %3d |%12.2lf|\n", item.sku, item.name, item.price, item.quantity, item.minQuantity, z);
		}
		else if (item.isTaxed == 1)
		{
			printf("|%3d|%-20s|%8.2lf|  Yes| %3d | %3d |%12.2lf|***\n", item.sku, item.name, item.price, item.quantity, item.minQuantity, z);
		}
	
	}
	
	else
	{
		printf("             SKU: %d\n", item.sku);

		printf("            Name: %s\n", item.name);
		
		printf("           Price: %0.2lf\n", item.price);
		
		printf("        Quantity: %d\n", item.quantity);
		
		printf("Minimum Quantity: %d\n", item.minQuantity);

		if (item.isTaxed == 0)
		{
			printf("        Is Taxed: No\n");
		}
		else if (item.isTaxed == 1)
		{
			printf("        Is Taxed: Yes\n");
		}

		int x;
		x = isLowQuantity(item);

		if (x == 1)
		{
			printf("WARNING: Quantity low, please order ASAP!!!\n");
		}

	}

}

void listItems(const struct Item item[], int noOfItems)
{
	int i = 0;
	double gt = 0;
	double z;
	char t = "No";

	printTitle();

	
		if (item[i].isTaxed == 1)
		{
		
			for (i = 0; i < noOfItems; i++)
			{
				z = totalAfterTax(item[i]);
				printf("%4d|%3d|%-20s|%8.2lf|  Yes| %3d | %3d |%12.2lf|\n", i + 1, item[i].sku, item[i].name, item[i].price, item[i].quantity, item[i].minQuantity, z);
				gt = gt + z;
			}
			
		}
		
		else
		{

			for (i = 0; i < noOfItems; i++)
			{
				z = totalAfterTax(item[i]);
				printf("%4d|%3d|%-20s|%8.2lf|   No| %3d | %3d |%12.2lf|\n", i + 1, item[i].sku, item[i].name, item[i].price, item[i].quantity, item[i].minQuantity, z);
				gt = gt + z;
			}

		}

	printFooter(gt);

}


int locateItem(const struct Item item[], int NoOfRecs, int sku, int* index)
{
	int i;
	int fl = -1;

	for (i = 0; i <= NoOfRecs&&fl == -1; i++)
	{
		if (sku == item[i].sku)
		{
			fl = i;
		}
	}
	if (fl != -1)
	{
		*index = fl;
		return(1);
	}
	
	else return(0);

}