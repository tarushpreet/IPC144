#include <stdio.h>
#include <stdbool.h>
#include<stdlib.h>
#include <ctype.h>
#include <string.h>

#define  MAX_LENGTH 22
#define  LINEAR 1
#define  FORM 0
#define MAX_QTY 999
#define SKU_MAX 999
#define SKU_MIN 100
#define STOCK 1
#define CHECKOUT 0
#define MAX_ITEM_NO 500
#define DATAFILE "items.txt"


const double TAX = 0.13;




struct Item
{
   double price;
   int    sku;
   int    isTaxed;
   int    quantity;
   int    minQuantity;
   char   name[MAX_LENGTH+1];
};

// ms1 functions
void   welcome(void);
void   printTitle(void);
void   printFooter(double);
void   flushKeyboard(void);
void   pause(void);
int    getInt(void);
double getDouble(void);
int    getIntLimited(int lowerLimit, int upperLimit);
double getDoubleLimited(double lowerLimit, double upperLimit);
int    yes(void);
int    getMenuChoice(void);
void   runInventorySystem(void);
void GroceryInventorySystem();

int main(void) {
 GroceryInventorySystem();
 return 0;
}

// ms2 functions
double  totalAfterTax(struct Item item);
int isLowQuantity(struct Item item);
struct Item itemEntry(int sku);
void displayItem(struct Item item, int linear);
void listItems(struct Item item[], int  NoOfItems);
int locateItem(const struct Item item[], int NoOfItems, int SKU, int *index);

// ms3 functions
void search(const struct Item item[], int NoOfRecs);
void updateItem(struct Item* itemptr);
void addItem(struct Item item[], int *NoOfRecs, int sku);
void addOrUpdateItem(struct Item item[], int* NoOfRecs);
void adjustQuantity(struct Item item[], int NoOfRecs, int stock);

// ms4 functions
void saveItem(struct Item item, FILE* dataFile);
int loadItem(struct Item* item, FILE* dataFile);
int saveItems(const struct Item item[], char fileName[], int NoOfRecs);
int loadItems(struct Item item[], char fileName[], int* NoOfRecsPtr);

// code your functions

//functions ms1

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
    printf("--------------------------------------------------------+----------------\n");
    if(grandTotal>0)
    {
    printf("                                           Grand Total: |%12.2lf\n",grandTotal);
    }
}

void flushKeyboard(void)
{
    char i='a';
    while(i!='\n')
    {
	    i=getchar();
    }
}//citation= ctutorials.com


void pause(void)
{
    printf("Press <ENTER> to continue...");
    flushKeyboard();
}

int getInt(void)
{   char NL = 'x';
    int Value;
    scanf("%d%c",&Value,&NL);
    while(NL != '\n'){
        flushKeyboard();
        printf("Invalid integer, please try again: ");
        scanf("%d%c", &Value,&NL);
    }
    return (Value);
}

int getIntLimited(int lowerLimit, int upperLimit)
{
	int Value;
	do {
		Value = getInt();
        if (Value < lowerLimit || Value > upperLimit) {
			printf("Invalid value, %d < value < %d: ", lowerLimit, upperLimit);
		}
	} while (Value < lowerLimit || Value > upperLimit);
	return Value;
}

double getDouble(void)
{
   char NL = 'x';
   double Value;
   scanf("%lf%c",&Value,&NL);
   while(NL != '\n'){
    flushKeyboard();
    printf("Invalid number, please try again: ");
    scanf("%lf%c", &Value,&NL);
   }
   return (Value);
}

double getDoubleLimited(double lowerLimit, double upperLimit)
{
	double x;
	char ch;
	do
	{
		scanf("%lf%c", &x, &ch);
		if (x >= lowerLimit || x <= upperLimit)
		{
			printf("Invalid value, 10.000000 <= value <= 20.000000: ");
		}
	} while (x >= lowerLimit || x <= upperLimit);
	return x;
}


int yes(void)
{
    char c;
    scanf("%c", &c);
    flushKeyboard();
    while(c!='y' && c!='Y' && c!='n' && c!='N')//citation= c tutorials youtube
    {
        printf("Only (Y)es or (N)o are acceptable: ");
        scanf(" %c",&c);
        flushKeyboard();
    }
    if(c=='y' || c=='Y')
    {
        return(1);
    }
    else if(c=='n' || c=='N')
    {
        return(0);
    }
  return (c);
}

int menu(void)
{
  int no;
  printf("1- List all items\n");
  printf("2- Search by SKU\n");
  printf("3- Checkout an item\n");
  printf("4- Stock an item\n");
  printf("5- Add new item or update item\n");
  printf("6- delete item\n");
  printf("7- Search by name\n");
  printf("0- Exit program\n");
  printf("> ");
  no = getIntLimited(0,7);
  return(no);
}

void GroceryInventorySystem()
{
  int a;
  int NoOfRecords;
  struct Item Arrayitem[MAX_ITEM_NO];
  welcome();
  int g = loadItems(Arrayitem, DATAFILE,  &NoOfRecords);
  int abc=0;
  if(g==0)
  {
	  printf("could not update data file %s\n",DATAFILE);
	  
  }
  else
  {
	  do
	  {

	  a = menu();

	  if( a == 1)
	  {
		  listItems(Arrayitem,NoOfRecords);
		  pause();
	  }
	  else if(a==2)
	  {
		  search(Arrayitem, NoOfRecords);
		  pause();
	  }
	   else if(a==3)
	  {
		 
		  adjustQuantity(Arrayitem, NoOfRecords, CHECKOUT);
		  int c = saveItems(Arrayitem, DATAFILE, NoOfRecords);
		  if(c==0)
         {  
	          printf("could not update data file %s\n",DATAFILE);
		 
         }
		  pause();
	  }
	   else if(a==4)
	  {
		 
		  adjustQuantity(Arrayitem, NoOfRecords, STOCK);
		  int c = saveItems(Arrayitem, DATAFILE, NoOfRecords);
		  if(c==0)
         {
	          printf("could not update data file %s\n",DATAFILE);
		 
         }
		  pause();
	  }
	  else if(a==5)
	  {
		 
		  addOrUpdateItem(Arrayitem, &NoOfRecords);
		  int c = saveItems(Arrayitem, DATAFILE, NoOfRecords);
		  if(c==0)
         {
	        printf("could not update data file %s\n",DATAFILE);
		
         }
		  pause();
	  }
	  else if(a==6)
	  {
		  printf("Not implemented!\n");
		  pause();
	  }
	   else if(a==7)
	  {
		  printf("Not implemented!\n");
		  pause();
	  }
	  else if(a==0)
	  {
		printf("Exit the program? (Y)es/(N)o): ");
          int xl;
		xl=yes();
	      if(xl==1)
	      {
		     abc=1;
		      break;	      
	  
	  }
	     
	  }
	  }while (abc!=1);
  }
  
  /*do
  {
      a=menu();
    switch(a)
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

      case 0:  printf("Exit the program? (Y)es/(N)o: ");
          b=yes();
    }

  }while(b != 1);*/
}

//functions ms2

double  totalAfterTax ( struct Item item )
{
	double call;
	double TAX=0.13;
	if (item.isTaxed == 1)
	{
		call = (((item.price) * (item.quantity))* TAX ) + ((item.price) * (item.quantity));
	}
	else
	{
		call = (item.price) * (item.quantity);

	}
	return call;

}

int isLowQuantity(struct Item item)
{
	int a = 0;
	if ( item.quantity <= item.minQuantity)
	{
		a = 1;
		return a;
	}
	else
	{
		return a;
	}
}


struct Item itemEntry(int sku)
{
	struct Item item;
	item.sku = sku;
	printf("        SKU: %d\n",sku);
	printf("       Name: ");
	scanf("%20[^\n]",item.name);
	flushKeyboard();
	printf("      Price: ");
	item.price = getDouble();
	printf("   Quantity: ");
	item.quantity = getInt();
	printf("Minimum Qty: ");
	item.minQuantity = getInt();
	printf("   Is Taxed: ");
	item.isTaxed = yes();
	return item;

}

void displayItem ( struct Item item , int linear)
{
	double total = 0;
	if ( linear == LINEAR )
	{
		if ( item.isTaxed == 1 )
		{
			 if ( item.quantity <= item.minQuantity )
			 {
				  total = totalAfterTax(item);
		printf("|%3d|%-20s|%8.2lf|  Yes| %3d | %3d |%12.2lf|***\n",item.sku,item.name,item.price,item.quantity,item.minQuantity,total);
			 }
			 else
			 {
				  total = totalAfterTax(item);
				 printf("|%3d|%-20s|%8.2lf|   Yes| %3d | %3d |%12.2lf|\n",item.sku,item.name,item.price,item.quantity,item.minQuantity,total);


			 }

		}
		else
		{
			if ( item.quantity <= item.minQuantity )
			{
				 total = totalAfterTax(item);
			 printf("|%3d|%-20s|%8.2lf|   No| %3d | %3d |%12.2lf|***\n",item.sku,item.name,item.price,item.quantity,item.minQuantity,total);
			}
			else
			{
				 total = totalAfterTax(item);
				 printf("|%3d|%-20s|%8.2lf|   No| %3d | %3d |%12.2lf|\n",item.sku,item.name,item.price,item.quantity,item.minQuantity,total);

			}
		}
	}
	else if ( linear == FORM )
	{
		if ( item.isTaxed == 1 )
		{
			if ( item.quantity <= item.minQuantity )
			{

				printf("        SKU: %d\n"
				       "       Name: %s\n"
				       "      Price: %.2lf\n"
				       "   Quantity: %d\n"
				       "Minimum Qty: %d\n"
				       "   Is Taxed: Yes\nWARNING: Quantity low, please order ASAP!!!\n",item.sku,item.name,item.price,item.quantity,item.minQuantity);

			}
			else
			{
				printf("        SKU: %d\n"
			       	       "       Name: %s\n"
				       "      Price: %.2lf\n"
				       "   Quantity: %d\n"
				       "Minimum Qty: %d\n"
				       "   Is Taxed: Yes\n",item.sku,item.name,item.price,item.quantity,item.minQuantity);


			}

		}
		else
		{
			if ( item.quantity <= item.minQuantity )
			{
		 		printf("        SKU: %d\n"
				       "       Name: %s\n"
				       "      Price: %.2lf\n"
				       "   Quantity: %d\n"
				       "Minimum Qty: %d\n"
				       "   Is Taxed: No\nWARNING: Quantity low, please order ASAP!!!\n",item.sku,item.name,item.price,item.quantity,item.minQuantity);

			}
			else
			{
				printf("        SKU: %d\n"
			               "       Name: %s\n"
				       "      Price: %.2lf\n"
				       "   Quantity: %d\n"
				       "Minimum Qty: %d\n"
				       "   Is Taxed: No\n",item.sku,item.name,item.price,item.quantity,item.minQuantity);

			}
		}
	}
}

void  listItems(struct Item item[], int  NoOfItems)
{
	double grandTotal[21], total = 0, sum = 0;
	int counter, i, call;
	printTitle();
	for (counter = 0; counter < NoOfItems; counter++)
	{
		if (item[counter].isTaxed == 1)
		{
			call = counter;
			total = totalAfterTax(item[counter]);
			if (item[counter].quantity < item[counter].minQuantity)
			{
				printf("%-3d |%3d|%-20s|%8.2lf|  Yes| %3d | %3d |%12.2lf|***\n", ++call, item[counter].sku, item[counter].name, item[counter].price, item[counter].quantity, item[counter].minQuantity, total);
				grandTotal[counter] = total;
			}
			else
			{

				printf("%-3d |%3d|%-20s|%8.2lf|  Yes| %3d | %3d |%12.2lf|\n", ++call, item[counter].sku, item[counter].name, item[counter].price, item[counter].quantity, item[counter].minQuantity, total);			grandTotal[counter] = total;
			}
		}
		else
		{
			call = counter;
			total = totalAfterTax(item[counter]);
			if (item[counter].quantity < item[counter].minQuantity)
			{
				printf("%-3d |%3d|%-20s|%8.2lf|   No| %3d | %3d |%12.2lf|***\n", ++call, item[counter].sku, item[counter].name, item[counter].price, item[counter].quantity, item[counter].minQuantity, total);
				grandTotal[counter] = total;
			}
			else
			{
				printf("%-3d |%3d|%-20s|%8.2lf|   No| %3d | %3d |%12.2lf|\n", ++call, item[counter].sku, item[counter].name, item[counter].price, item[counter].quantity, item[counter].minQuantity, total);
				grandTotal[counter] = total;
			}
		}
	}
	for (i = 0; i < NoOfItems; i++)
		sum = sum + grandTotal[i];
	printFooter(sum);

}

int locateItem(const struct Item item[], int NoOfItems, int SKU, int *index )
{
	int i, found = 0;
	for ( i = 0 ; i < NoOfItems ; i++)
	{
		if ( SKU == item[i].sku )
		{
			found = 1;
			*index = i;
		}
	}

	return found;


}

//functions ms3

void search(const struct Item item[], int NoOfRecs)
{
	int index;
	int SKU;
	printf("Please enter the SKU: ");
	SKU = getIntLimited(SKU_MIN, SKU_MAX);
	int n = locateItem(item, NoOfRecs, SKU, &index);
	if (n == 1) {
		displayItem(item[index], FORM);
	}
	else {
		printf("Item not found!\n");
	}
	return;
}

void updateItem(struct Item* itemptr)
{
	struct Item item;
	printf("Enter new data:\n");
	item = itemEntry(itemptr->sku);
	printf("Overwrite old data? (Y)es/(N)o: ");
	int n = yes();
	if (n == 1) {
		*itemptr = item;
		printf("--== Updated! ==--\n");
	}
	else {
		printf("--== Aborted! ==--\n");
	}
	return;
}

void addItem(struct Item item[], int *NoOfRecs, int sku)
{
	struct Item nitem;
	if (*NoOfRecs >= MAX_ITEM_NO) {
		printf("Can not add new item; Storage Full!\n");
	}
	else {
		nitem = itemEntry(sku);
		printf("Add Item? (Y)es/(N)o: ");
		int n = yes();
		if (n == 1) {
			item[*NoOfRecs] = nitem;
			(*NoOfRecs)++;
			printf("--== Added! ==--\n");
		}
		else {
			printf("--== Aborted! ==--\n");
		}
	}
	return;
}

void addOrUpdateItem(struct Item item[], int* NoOfRecs)
{
	int s1, Index, m;
	printf("Please enter the SKU: ");
	s1 = getIntLimited(SKU_MIN, SKU_MAX);
	int found = locateItem(item, *NoOfRecs, s1, &Index);
	if (found == 1) {
		displayItem(item[Index], FORM);
		printf("Item already exists, Update? (Y)es/(N)o: ");
		m = yes();
		if (m == 1) {
			updateItem(&item[Index]);
		}
		else {
			printf("--== Aborted! ==--\n");
		}
	}
	else {
		addItem(item, NoOfRecs, s1);
	}
	return;
}

void adjustQuantity(struct Item item[], int NoOfRecs, int stock)
{
	int s1 = 0, Index = 0, max = 0, n = 0;
	printf("Please enter the SKU: ");
	s1 = getIntLimited(SKU_MIN, SKU_MAX);
	int found = locateItem(item, NoOfRecs, s1, &Index);
	if (found != 0) {
		displayItem(item[Index], FORM);
		if (stock == STOCK) {
			max = (MAX_QTY - item[Index].quantity);
			printf("Please enter the quantity to stock; Maximum of %d or 0 to abort: ", max);
		}
		else if (stock == CHECKOUT) {
			max = item[Index].quantity;
			printf("Please enter the quantity to checkout; Maximum of %d or 0 to abort: ", max);
		}
		n = getIntLimited(0,max);
		if (n != 0) {
			if (stock == STOCK) {
				item[Index].quantity += n;
				printf("--== Stocked! ==--\n");
			}
			else {
				item[Index].quantity -= n;
				printf("--== Checked out! ==--\n");
			}

			}
		
		else {
			printf("--== Aborted! ==--\n");
		}
	int x;
	x=isLowQuantity(item[Index]);
	if(x==1)
	{
		printf("Quantity is low, please reorder ASAP!!!\n");

	
	}
	}
	else {
		printf("SKU not found in storage!\n");
	}
}


//Functions ms4

void saveItem(struct Item item, FILE* dataFile)
{
	fprintf(dataFile, "%d,%d,%d,%.2lf,%d,%s\n", item.sku, item.quantity, item.minQuantity, item.price, item.isTaxed, item.name);
}


int loadItem(struct Item* item, FILE* dataFile)
{
	int val = 0;
	int a = fscanf(dataFile, "%d,%d,%d,%lf,%d,%[^\n]", &(*item).sku, &(*item).quantity, &(*item).minQuantity, &(*item).price, &(*item).isTaxed, (*item).name);

	if (a == 6) {    
		val = 1;
	}
	return val;
}

int saveItems(const struct Item item[], char fileName[], int NoOfRecs)
{
	int b = 0;
	int val = 0;

	FILE *fp = NULL;
	fp = fopen(fileName, "w");      
	if (fp != NULL) {
		for (b = 0; b < NoOfRecs; b++)
		{
			saveItem(item[b], fp);    
		}
		val = 1;
		fclose(fp);    
	}
	else {
		val = 0; 
	}
	return val;
}


int loadItems(struct Item item[], char fileName[], int* NoOfRecsPtr)
{
	int j = 0;
	int val = 0;


	FILE *f = NULL;
	f = fopen(fileName, "r");      
	if (f != NULL) {
		while (!feof(f)) {

			j = j + loadItem(&item[j], f);    
		}

		val = 1;
		*NoOfRecsPtr = j;
		fclose(f);    
	}
	else {
		val = 0;  
	}
	return val;
}
