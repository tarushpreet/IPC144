//Student name - Sahul Narang
//Student number- 136560166
//Student email- snarang3@myseneca.ca
//Workshop 6
// In lab section
#include <stdio.h>

#define distRate1  0.69			// Rate per Kilometer from 0km to 100km (inclusive)
#define distRate2  0.49			// Rate per Kilometer above 100km 


// Structure Declaration for Vehicle Rentals

struct Rental

{

	int id;						// ID of the Rental Vehicle
	double baseDay;				// Daily Base Price 
	double earnings;			// Total earnings from this rental
};



/* prototype functions addPositive Here*/
double addpositive(double amount, double newamount);





/* Implement Function addPositive Here*/

double addpositive(double amount, double newamount)
{
	if (newamount > 0)
		return amount + newamount;
	else 
		return amount;
}








/* main program */

void main()

{

	int noVehicles = 2;			// Number of Vehicles

	int option;							// Variable to store the option selected

	int flag;							// Flag to support vehicle ID find

	int tempID;							// To hold user input for vehicle ID

	int i = 0;							// Variable for "for-loop" counters

	int days;
	double baseprices;
	int kmdrive;
	
	double kmcost;
	double charge;
	// Initialize the struct Vehicle Rental

	struct Rental vRent[2] = { {123,9.95,0}, {124,19.95,0} };
	
	/*Declare Your Variables Here*/

	printf("***** Rental Vehicle Management App *****\n\n");



	do

	{

		// Display the option list

		printf("1.) Rental Status\n");

		printf("2.) Apply Charges\n");

		printf("0.) Log out\n\n");

		printf("Please enter an option to continue: ");

		scanf("%d", &option);



		switch (option)

		{

		case 0: // Exit the program

			break;



		case 1: // Rental Vehicle Status



			printf("\n-- Rental Vehicle Status --\n\n");

			printf("ID#      Earnings\n");

			printf("-------- ----------\n");
			for (int j = 0; j < noVehicles; j++) {
				printf("%8d %10.2lf\n", vRent[j].id,vRent[j].earnings);
			}
			// Use "%8d %10.2lf" formatting to display ID and Earnings for each rental

			// using a loop construct
			printf("\n");


			break;



		case 2: // Calculate Rental Charges



			flag = -1;

			printf("\n-- Rental Charges --\n\n");

			printf("Enter vehicle ID: ");

			scanf("%d", &tempID);



			// Finding the correct vehicle index

			for (i = 0; i < noVehicles && flag == -1; i++) {

				if (tempID == vRent[i].id) {

					flag = i;

				}

			}



			if (flag != -1) {

				
				// Capture #days for the rental from user input
				printf("Enter Rental period (in days): ");
				scanf("%d", &days);



				baseprices = days * vRent[flag].baseDay;


				// Calculate the base price (baseDay * Days)


				printf("Enter Kilometers driven: ");
				scanf("%d", &kmdrive);

				if (kmdrive <= 100)
				{
					
					kmcost = kmdrive * distRate1;
				}
				else {
					kmcost = 100 * distRate1 + distRate2 * (kmdrive-100);
				}
				// Calculate cost for Kilometers driven using "distRate1 & 2 above"

				charge = baseprices + kmcost;





				// Add base Price and cost for kilometer driven in to a new variable 

				// "charge"


				vRent[flag].earnings = addpositive(vRent[flag].earnings , charge);


				/* Call addPositive function with current earnings for the rental and

				charge(calculated above) as arguments and assign the returned

				result back to earnings

				*/





				// Display Base Charge, cost for km and the Total 

				printf("\nBase   kmCost Total\n");

				printf("====== ====== ======\n");

				// Use "%6.2lf %6.2lf %6.2lf" formatting inside a printf statement
				printf("%6.2lf %6.2lf %6.2lf\n\n", baseprices, kmcost, vRent[flag].earnings);


			}

			else {

				printf("ERROR: Vehicle ID does not exist.\n\n");

			}



			break;





		default:

			printf("Error: Please enter a valid option to continue\n\n");

			break;

		}





	} while (option != 0);
	
	
	getch();

}