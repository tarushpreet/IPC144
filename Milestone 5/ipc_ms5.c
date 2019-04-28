
#include <stdio.h>
#include <string.h>

#define LINEAR 1
#define FORM 0
#define STOCK 1
#define CHECKOUT 0
#define MAX_ITEM_NO 500
#define MAX_QTY 999
#define SKU_MAX 999
#define SKU_MIN 100


struct Item {
	double price;
	int sku;
	int isTaxed;
	int quantity;
	int minQuantity;
	char name[21];

};




/********************************************************************

  Milestones 1 to 4  prototypes, definitions and etc...*/
void GrocInvSys(void);
void welcome(void);
void prnTitle(void);
void prnFooter(double gTotal);
void pause(void);
void clrKyb(void);
int getInt(void);
double getDbl(void);
int getIntLimited(int lowerLimit, int upperLimit);
double getDblLimited(double lowerLimit, double upperLimit);
double totalAfterTax(struct Item item);
int isLowQty(struct Item item);
struct Item itemEntry(int sku);
void dspItem(struct Item item, int linear);
void listItems(const struct Item item[], int NoOfItems);
int locateItem(const struct Item item[], int NoOfRecs, int sku, int* index);
int yes(void);
void search(const struct Item item[], int NoOfRecs);
void updateItem(struct Item* itemptr);
void addItem(struct Item item[], int *NoOfRecs, int sku);
void addOrUpdateItem(struct Item item[], int* NoOfRecs);
void adjustQty(struct Item item[], int NoOfRecs, int stock);
int menu(void);



//constant tax

const double TAX = 0.13;




/*End of milestone 1 to 4 stuff
*********************************************************************/



/********************************************************************
Milestone 5 prototypes*/


#define MAX_ITEM_NO 500   
//#define DATAFILE "items.txt"
#define DATAFILE "ipc_ms5_short.txt"

void saveItem(struct Item item, FILE* dataFile);
int loadItem(struct Item* item, FILE* dataFile);
int saveItems(struct Item* item, char fileName[], int NoOfRecs);
int loadItems(struct Item* item, char fileName[], int* NoOfRecsPtr);

/*End of milestone 5 prototypes
*********************************************************************/

/**************************************************************************
TTTTTTTTT   EEEEEEEE   SSSSSSSS   TTTTTTTTTT   EEEEEEEEE   RRRRRRRR
TT       EE         SS             TT       EE          RR     RR
TT       EEEEEEEE   SSSSSSSS       TT       EEEEEEEEE   RRRRRRRR
TT       EE               SS       TT       EE          RR  RR
TT       EEEEEEEE   SSSSSSSS       TT       EEEEEEEEE   RR    RR
***************************************************************************
Tester for saveItem, loadItem, saveItems and loadItems:
uncomment this to test your functions prior to putting all the code together by adding a * and / here:

*/

void prnFile() {
	FILE* tp = fopen("test.txt", "r");
	char ch;
	if (tp) {
		for (; fscanf(tp, "%c", &ch) == 1; putchar(ch));
		fclose(tp);
	}
	else {
		printf("text.txt not found\n");
	}
}
/*
int main(void) {
int i, n;
struct Item GI[3] = {
{ 4.4, 275, 0, 10, 2, "Royal Gala Apples"},
{ 5.99, 386, 0, 20, 4, "Honeydew Melon"},
{ 3.99, 240, 0, 30, 5, "Blueberries"},
};
struct Item I;
struct Item IN[3];
printf("***********Testing saveItem:\n");
printf("Your saveItem saved the following in test.txt: \n");
FILE* tp = fopen("test.txt", "w");
if (tp) {
for (i = 0; i < 3; i++)
saveItem(GI[i], tp);
fclose(tp);
prnFile();
}
printf("*******************************\nThey have to match the following:\n");
printf("275,10,2,4.40,0,Royal Gala Apples\n");
printf("386,20,4,5.99,0,Honeydew Melon\n");
printf("240,30,5,3.99,0,Blueberries\n");
printf("***********END Testing saveItem!\n\n\n");
pause();
printf("***********Testing loadItem:\n");
printf("Your loadItem loaded the following from test.txt: \n");
tp = fopen("test.txt", "r");
if (tp) {
for (i = 0; i < 3; i++) {
loadItem(&I, tp);
dspItem(I, LINEAR);
}
fclose(tp);
tp = fopen("test.txt", "w");
fclose(tp);
}
printf("*******************************\nThey have to match the following:\n");
printf("|275|Royal Gala Apples   |    4.40|   No|  10 |   2 |       44.00|\n");
printf("|386|Honeydew Melon      |    5.99|   No|  20 |   4 |      119.80|\n");
printf("|240|Blueberries         |    3.99|   No|  30 |   5 |      119.70|\n");
printf("***********END Testing loadItem!\n\n\n");
pause();
printf("***********Testing saveItems:\n");
printf("Your saveItems saved the following in test.txt: \n");
saveItems(GI, "test.txt", 3);
prnFile();
printf("*******************************\nThey have to match the following:\n");
printf("275,10,2,4.40,0,Royal Gala Apples\n");
printf("386,20,4,5.99,0,Honeydew Melon\n");
printf("240,30,5,3.99,0,Blueberries\n");
printf("***********END Testing saveItems!\n\n\n");
pause();
printf("***********Testing loadItems:\n");
printf("Your loadItems loaded the following from test.txt: \n");
loadItems(IN, "test.txt", &n);
for (i = 0; i < n; i++) {
dspItem(IN[i], LINEAR);
}
printf("*******************************\nThey have to match the following:\n");
printf("|275|Royal Gala Apples   |    4.40|   No|  10 |   2 |       44.00|\n");
printf("|386|Honeydew Melon      |    5.99|   No|  20 |   4 |      119.80|\n");
printf("|240|Blueberries         |    3.99|   No|  30 |   5 |      119.70|\n");
printf("***********END Testing loadItems!\n\n\n");
pause();
printf("Done!\n");
return 0;
}
*/
/*
End MS5 functions' tester
***************************************************************************
***************************************************************************
***************************************************************************
***************************************************************************
***************************************************************************
***************************************************************************/


/********************************************************************
Main function to run the application
uncomment this to test your functions after putting all the code together by adding a * and / here:
*/
int main(void) {
	GrocInvSys();
	return 0;
}
/*
End Main function
********************************************************************/





/********************************************************************
Milestone 5 functions*/

/*End of milestone 5 functions
*********************************************************************/

/********************************************************************
Milestones 1  to 4 functions*/
void GrocInvSys(void)
{
	struct Item Items[MAX_ITEM_NO];
	int SEL, hold;
	int done = 0;
	welcome();
	if (0 == loadItems(Items, DATAFILE, &hold))
	{
		printf("Could not read from %s.\n", DATAFILE);

	}
	while (!done)
	{
		SEL = menu();
		if (SEL == 1)
		{

			listItems(Items, hold);
			pause();
		}
		else if (SEL == 2)
		{

			search(Items, hold);
			pause();
		}
		else if (SEL == 3)
		{
			adjustQty(Items, hold, CHECKOUT);
			saveItems(Items, DATAFILE, hold);
			if (0 == saveItems(Items, DATAFILE, hold))
			{
				printf("could not update data file %s\n", DATAFILE);
			}
			pause();
		}
		else if (SEL == 4)
		{
			adjustQty(Items, hold, STOCK);
			saveItems(Items, DATAFILE, hold);
			if (0 == saveItems(Items, DATAFILE,hold))
			{
				printf("could not update data file %s\n", DATAFILE);
			}
			pause();
		}
		else if (SEL == 5)
		{
			addOrUpdateItem(Items, &hold);
			saveItems(Items, DATAFILE, hold);
			if (0 == saveItems(Items, DATAFILE, hold))
			{
				printf("could not update data file %s\n", DATAFILE);
			}
			pause();
		}
		else if (SEL == 6)
		{
			//if(SEL>0||SEL<6)
		       // SEL=getIntLimited(0,6);
			printf("Not Implemented!\n");
			pause();
		}
		else if (SEL == 0)
		{
			printf("Exit the program? (Y)es/(N)o): ");
			done = yes();
		}
	}
}
void search(const struct Item item[], int NoOfRecs) {

	int tempsku = 0, done = 0,i;
	printf("Please enter the SKU: ");
	scanf("%d", &tempsku);
	if (tempsku > SKU_MIN && tempsku < SKU_MAX)
	{

		done = locateItem(item, NoOfRecs, tempsku, &i);

		if (done == 1)
			dspItem(item[i], 0);

	}

	if (done != 1)
    {

		printf("Item not found!\n");
	}


}

void updateItem(struct Item* itemptr)
{
	int sku = itemptr->sku, choice;
	struct Item item;

	printf("Enter new data:\n");
	clrKyb();

	item = itemEntry(sku);
	item.sku = sku;

	printf("Overwrite old data? (Y)es/(N)o:");
	choice = yes();

	if (choice == 1)
	{

		*itemptr = item;
		printf("--== Updated! ==--\n");

	}
	else
	{

		printf("--== Aborted! ==--\n");
	}

}

void addItem(struct Item item[], int *NoOfRecs, int sku) {
	struct Item i;
	int choice;

	if (*NoOfRecs >= MAX_ITEM_NO)
	{
		printf("Can not add new item; Storage Full!\n");
	}
	else
	{
		clrKyb();
		i = itemEntry(sku);

		printf("Add Item? (Y)es/(N)o: ");
		choice = yes();

		if (choice == 1)
		{
			i.sku = sku;
			item[*NoOfRecs] = i;
			*NoOfRecs += 1;

			printf("--== Added! ==--\n");
		}
		else
		{
			printf("--== Aborted! ==--\n");
		}


	}
}

void addOrUpdateItem(struct Item item[], int* NoOfRecs)
{
	int tempsku = 0, i = 0, found = 0, answer = 0;

	printf("Please enter the SKU: ");
	scanf("%d", &tempsku);

	if (tempsku > SKU_MIN && tempsku < SKU_MAX)
	{

		found = locateItem(item, *NoOfRecs, tempsku, &i);

		if (found == 1)
		{

			dspItem(item[i], 0);

			printf("Item already exists, Update? (Y)es/(N)o: ");
			answer = yes();

			if (answer == 1)
			{
				updateItem(&item[i]);
			}

			else if (answer == 0)
			{

				printf("--== Aborted! ==--\n");
			}

		}
		else

		{
			addItem(item, NoOfRecs, tempsku);
		}

	}


}

void adjustQty(struct Item item[], int NoOfRecs, int stock)
{
	int found, sku, index, choice;
	char tempstock[] = "to stock", tempcheck[] = "to checkout";
	
    printf("Please enter the SKU: ");
	scanf("%d", &sku);
	
    found = locateItem(item, NoOfRecs, sku, &index);
	
    if (found == 0)
	{
		printf("SKU not found in storage!\n");
	}
	
    else
	{
		dspItem(item[index], FORM);
		if (stock == STOCK)
		{
			printf("Please enter the quantity %s; Maximum of %d or 0 to abort: ", tempstock, MAX_QTY - item[index].quantity);
			scanf("%d", &choice);
			if (choice == 0)
			{
				printf("--== Aborted! ==--\n");
			}
			
            else
			{
				item[index].quantity += choice;
				printf("--== Stocked! ==--\n");

			}
		}
		
        else
		{
			printf("Please enter the quantity %s; Maximum of %d or 0 to abort: ", tempcheck, item[index].quantity);
			scanf("%d", &choice);
			if (choice == 0)
			{
				printf("--== Aborted! ==--\n");
			}
			
            else
			{
				item[index].quantity -= choice;

				printf("--== Checked out! ==--\n");
				
                if (item[index].quantity <= choice)
				{
					printf("Quantity is low, please reorder ASAP!!!\n");
				}
			}
		}
	}
}

double totalAfterTax(struct Item item)
{

	double sum;
	if (item.isTaxed == 1)
	{
		sum = (item.quantity * item.price) + (item.quantity * item.price * TAX);
	}
	
    else if (item.isTaxed == 0)
	{
		sum = item.quantity * item.price;
	}
	
return sum;
}

int isLowQty(struct Item item)
{
	int ret = 0;

	if (item.minQuantity > item.quantity)

		ret = 1;

	return ret;
}

struct Item itemEntry(int sku)
{
	struct Item item;
	printf("        SKU: %d\n", sku);

	printf("       Name: ");

	scanf("%20[^\n]", item.name);

	printf("      Price: ");
	item.price = getDblLimited(0.01, 1000.00);
	
    printf("   Quantity: ");
	item.quantity = getIntLimited(0, 100);
	
    printf("Minimum Qty: ");
	item.minQuantity = getIntLimited(0, MAX_QTY);
	
    printf("   Is Taxed: ");
	item.isTaxed = yes();
	
    clrKyb();
	
    return item;
}

void dspItem(struct Item item, int linear)
{

	double total;
	char *tax;

	total = totalAfterTax(item);

	if (item.isTaxed != 0)
	{
		tax = "Yes";
	}

	else
	{
		tax = "No";
	}
	
    if (linear == 1)
	{
		printf("|%3d|%-20s|%8.2lf|%5s|%4d | %3d |%12.2lf|", item.sku, item.name, item.price, tax, item.quantity, item.minQuantity, total);
		if (item.quantity <= item.minQuantity)
		{
			printf("***");
		}
		printf("\n");
	}
	
    if (linear == 0)
	{
		printf("        SKU: %d\n", item.sku);
		printf("       Name: %s\n", item.name);
		printf("      Price: %.2lf\n", item.price);
		printf("   Quantity: %d\n", item.quantity);
		printf("Minimum Qty: %d\n", item.minQuantity);
		printf("   Is Taxed: %s\n", tax);
		if (item.quantity <= item.minQuantity)
		{
			printf("WARNING: Quantity low, please order ASAP!!!\n");
		}

	}
}

void listItems(const struct Item item[], int NoOfItems)
{
	int i = 0;
	float grand = 0;
	prnTitle();
	
    for (i = 0; i < NoOfItems; i++)
	{
		printf("%-4d", i + 1);
		dspItem(item[i], 1);
		grand += totalAfterTax(item[i]);
	}
	
    prnFooter(grand);
	return;
}


int locateItem(const struct Item item[], int NoOfRecs, int sku, int* index)
{
	int i;
	int Num = 0;
	for (i = 0; i < NoOfRecs; i++)
	{
		if (sku == item[i].sku)
		{
			*index = i;
			Num = 1;
		}
	}
	return Num;
}

int yes(void)
{
	char istaxed;

	scanf("%c", &istaxed);
	do {

		if (istaxed == 'Y' || istaxed == 'y')
		{
			return 1;
		}
		
        else if (istaxed == 'N' || istaxed == 'n')
		{
			return 0;
		}
		
        else
		{
			
			scanf("%c", &istaxed);
		}
	} while (1);

}

int menu(void)
{
	int choice;
	
    printf("\n1- List all items\n");
	printf("2- Search by SKU\n");
	printf("3- Checkout an item\n");
	printf("4- Stock an item\n");
	printf("5- Add new item or update item\n");
	printf("0- Exit program\n");
	printf("> ");
	scanf("%d", &choice);
	while (choice < 0 || choice > 7)
	{
		printf("Invalid value, 0 < value < 7: ");
		scanf("%d", &choice);
		clrKyb();
	}

	return (choice);
}

void welcome(void)

{
	printf("---=== Grocery Inventory System ===---\n");

}

void prnTitle(void)
{
	printf("Row |SKU| Name               | Price  |Taxed| Qty | Min |   Total    |Atn\n");
	printf("----+---+--------------------+--------+-----+-----+-----+------------|---\n");

}

void prnFooter(double gTotal)
{
	printf("--------------------------------------------------------+----------------\n");
	
        if (gTotal > 0)
	
    {
		printf("                                           Grand Total: |%12.2lf\n", gTotal);
	}
}

void clrKyb(void)
{

	while (getchar() != '\n');

}

void pause(void)
{

	printf("Press <ENTER> to continue...");
	clrKyb();


}

int getInt(void)
{
	int Value;
	char input;
	do
	{
		scanf("%d%c", &Value, &input);
		
        if (input != '\n')
		{
			printf("Invalid integer, please try again: ");
			
                clrKyb();
		
        }
	} while (input != '\n');
	return (Value);
}

int getIntLimited(int lowerLimit, int upperLimit)
{
	int Value;
	do
	{
		scanf("%d", &Value);
		
        if (Value <= lowerLimit || Value >= upperLimit)
		{
			printf("Invalid value, %d < value < %d: ", lowerLimit, upperLimit);
			clrKyb();
		}
        
	} while (Value <= lowerLimit || Value >= upperLimit);
	return (Value);

}

double getDbl()
{
	double dValue;
	char type;
	do {
		scanf("%lf%c", &dValue, &type);
		
        if (type != '\n')
		{
			printf("Invalid number, please try again: ");
			clrKyb();
		}
	} while (type != '\n');
	return (dValue);
}

double getDblLimited(double lowerLimit, double upperLimit) {
	double Value;
	do {
		scanf("%lf", &Value);
		
        if (Value <= lowerLimit || Value >= upperLimit)
		{
			printf("Invalid value, %lf <= value <= %lf:", lowerLimit, upperLimit);
			clrKyb();
		}

	} while (Value <= lowerLimit || Value >= upperLimit);
	return Value;
}

/*End of milestone 1 to 4 functions
**


/* ms5 Tester output

***********Testing saveItem:
Your saveItem saved the following in test.txt:
275,10,2,4.40,0,Royal Gala Apples
386,20,4,5.99,0,Honeydew Melon
240,30,5,3.99,0,Blueberries
*******************************
They have to match the following:
275,10,2,4.40,0,Royal Gala Apples
386,20,4,5.99,0,Honeydew Melon
240,30,5,3.99,0,Blueberries
***********END Testing saveItem!


Press <ENTER> to continue...
***********Testing loadItem:
Your loadItem loaded the following from test.txt:
|275|Royal Gala Apples   |    4.40|   No|  10 |   2 |       44.00|
|386|Honeydew Melon      |    5.99|   No|  20 |   4 |      119.80|
|240|Blueberries         |    3.99|   No|  30 |   5 |      119.70|
*******************************
They have to match the following:
|275|Royal Gala Apples   |    4.40|   No|  10 |   2 |       44.00|
|386|Honeydew Melon      |    5.99|   No|  20 |   4 |      119.80|
|240|Blueberries         |    3.99|   No|  30 |   5 |      119.70|
***********END Testing loadItem!


Press <ENTER> to continue...
***********Testing saveItems:
Your saveItems saved the following in test.txt:
275,10,2,4.40,0,Royal Gala Apples
386,20,4,5.99,0,Honeydew Melon
240,30,5,3.99,0,Blueberries
*******************************
They have to match the following:
275,10,2,4.40,0,Royal Gala Apples
386,20,4,5.99,0,Honeydew Melon
240,30,5,3.99,0,Blueberries
***********END Testing saveItems!


Press <ENTER> to continue...
***********Testing loadItems:
Your loadItems loaded the following from test.txt:
|275|Royal Gala Apples   |    4.40|   No|  10 |   2 |       44.00|
|386|Honeydew Melon      |    5.99|   No|  20 |   4 |      119.80|
|240|Blueberries         |    3.99|   No|  30 |   5 |      119.70|
*******************************
They have to match the following:
|275|Royal Gala Apples   |    4.40|   No|  10 |   2 |       44.00|
|386|Honeydew Melon      |    5.99|   No|  20 |   4 |      119.80|
|240|Blueberries         |    3.99|   No|  30 |   5 |      119.70|
***********END Testing loadItems!


Press <ENTER> to continue...
Done!


*/
void saveItem(struct Item item, FILE * dataFile)

{
	fprintf(dataFile, "%d,%d,%d,%.2lf,%d,%s\n", item.sku, item.quantity, item.minQuantity, item.price, item.isTaxed, item.name);

}

int loadItem(struct Item * item, FILE * dataFile)
{
	int done = 0;
	
        if (fscanf(dataFile, "%d,%d,%d,%lf,%d,%17[^\n]%*c", &item->sku, &item->quantity, &item->minQuantity, &item->price, &item->isTaxed, item->name) != EOF)
	{
        
		done = 1;
	}
	return done;
}

int saveItems(struct Item * item, char fileName[], int NoOfRecs)
{
	int j, temp = 1;
	FILE *fp = NULL;
	fp = fopen(fileName, "w");
	
    if (fp != NULL) 
	{
		for (j = 0; j < NoOfRecs; j++)
		{
			saveItem(item[j], fp);
		}
		fclose(fp);
	}
	
    else if (fp == NULL) 
	{
		temp = 0;
	}
	return temp;
}

int loadItems(struct Item * item, char fileName[], int * NoOfRecsPtr)
{
	int tem= 1, j;
	struct Item fake;

	FILE *fp = NULL;
	fp = fopen(fileName, "r");
	if (fp == NULL) 
	{
		tem = 0;
	}

	else 
	{
		for (j = 0; j<4;j++)
		{

			loadItem(&fake, fp);
			item[j] = fake;
			*NoOfRecsPtr = j;
		}

		fclose(fp);
	}
	return tem;
}
