/*
Name:
Student number:
Email:
Workshop:
Section:
Date:
*/
#include<stdio.h>
#include<string.h>
#include<stdlib.h>

#define max_books 10
#define max_title_size 20

struct Book {
	int isbn;
	float price;
	int year;
	char title[max_title_size];
	int qty;
};


void checkprice(const struct Book book[], const int size);
void addbook(struct Book book[], int *size);
void searchInventory(const struct Book book[], const int isbn, const int size);
void displayinventory(const struct Book book[], const int size);
void menu();



main()
{
	struct Book book[max_books] = { {0} };
	int size = 0;
	int opt;

	printf("Welcome to the Book Store\n");
	printf("=========================\n");

	do
	{
		menu();
		printf("\nSelect: ");
		scanf("%d", &opt);
	
		switch (opt)
		{
		case 0: printf("Goodbye!");
			break;

		case 1: displayinventory(book, size);
			break;


		case 2: addbook(book, &size);
			break;

		case 3: checkprice(book, size);
			break;
		
		default: printf("Invalid input, try again: \n");
		}
	
	
	} while (opt != 0);


}



void menu()
{
	printf("Please select from the following options: \n");
	printf("1) Display the inventory.\n"); 
	printf("2) Add a book to the inventory.\n");
	printf("3) Check price.\n");
	printf("0) Exit.\n");
}


void displayinventory(const struct Book book[], const int size)
{
	if (size == 0)
	{
		printf("The inventory is empty!\n");
		printf("===================================================\n");
		printf("\n");
	}
	
	else
	{
		printf("Inventory\n\n");
		printf("===================================================\n");
		printf("ISBN      Title               Year Price  Quantity\n");
		printf("---------+-------------------+----+-------+--------\n");
		int i = 0;
		for (i = 0; i < size; i++)
		{
			printf("%-10.0d%-20s%-5d$%-8.2f%-8d\n", book[i].isbn, book[i].title, book[i].year, book[i].price, book[i].qty);
		}
		printf("===================================================\n");
		printf("\n");
	}

}


void searchInventory(const struct Book book[], const int isbn, const int size)
{
	printf("Not implemented\n\n");
}


void addbook(struct Book book[], int *size)
{
	if (size == max_books)
	{
		printf("the inventory is full\n");
	}

	else 
	{
		printf("ISBN:");
		scanf("%d", &book[*size].isbn);

		while (getchar() != '\n');

		printf("Title:");
		scanf("%[a-zA-Z0-9 ]", &book[*size].title);
		
		printf("Year:");
		scanf("%d$", &book[*size].year);

		printf("Price:");
		scanf("%f", &book[*size].price);

		printf("Quantity:");
		scanf("%d", &book[*size].qty);

		*size = *size + 1;
	
		printf("The book is successfully added to the inventory.\n\n");
	}

}



void checkprice(const struct Book book[], const int size)
{
	printf("Not implemented\n\n");
}



