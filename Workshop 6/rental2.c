//Student name - Sahul Narang
//Student number- 136560166
//Student email- snarang3@myseneca.ca
//Workshop 6
// At home section

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

double taxes;

/* prototype functions addPositive , taxCalc & subtractPositive*/
double addPositive(double amount, double newamount);
double taxCalc(double price, double rate);
double subtractPositive(double amount ,double newamount);



/* Implement Function addPositive Here*/
double addPositive(double amount,double newamount)
{
	if (newamount > 0)
		return amount + newamount;
	else
	return amount;
}

double taxCalc(double price, double rate)
{
	taxes=(price * rate )/ 100;
	return taxes;
}

double subtractPositive(double amount, double newamount) 
{
	if (newamount > 0)
	{
		return amount - newamount;
		
	}
	else
	{
		return amount;
	}
}
/* Implement Function taxCalc Here */





/* Implement Function subtractPositive Here*/





/* main program */

int main()

{

	const int noVehicles = 3;			// Number of Vehicles [ Changed to 3]

	int option;							// Variable to store the option selected

	int flag;							// Flag to support vehicle ID find

	int tempID;							// To hold user input for vehicle ID

	int i = 0;							// Variable for "for-loop" counters

	int j = 0;
	int days;
	double baseprices;
	double kmcost;
	double sum;
	double charge;
	int kmdrive;
	char d;
	double gift;
	
	int a;

										// Initialize the struct Vehicle Rental [ New addition for 3 Rentals]

	struct Rental vRent[] = { { 123, 9.95, 0 },{ 124, 19.95, 0 },{ 125, 29.95, 0 } };



	double taxRate = 14;				// Tax rate is 14%

	double discount = 5;    			// Discount amount for rentals (in CAD)



										/*Declare Your Variables Here*/





	printf("***** Rental Vehicle Management App *****\n\n");



	do

	{

		// Display the option list

		printf("1.) Rental Status\n");

		printf("2.) Apply Charges\n");

		printf("3.) Apply Taxes to All Rentals\n");

		printf("4.) Apply Gift Card\n");

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
			for (j = 0; j < noVehicles; j++) {
				printf("%8d %10.2lf\n", vRent[j].id, vRent[j].earnings);
				// Use "%8d %10.2lf" formatting to display ID and Earnings for each rental
			}
			printf("\n");

			/* Copy and Paste from In-Lab Case - 1 */





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


				printf("Enter Rental period (in days): ");
				scanf("%d", &days);
				// Capture #days for the rental from user input   

				/* Copy and Paste from In-Lab Case - 2 */



				baseprices = days * vRent[flag].baseDay;

				// Calculate the base price (baseDay * Days)   

				/* Copy and Paste from In-Lab Case - 2 */


				printf("Enter Kilometers driven: ");
				scanf("%d", &kmdrive);

				if (kmdrive <= 100)
				{

					kmcost = kmdrive * distRate1;
				}
				else {
					kmcost = 100 * distRate1 + distRate2 * (kmdrive - 100);
				}
				// Calculate cost for Kilometers driven   

				/* Copy and Paste from In-Lab Case - 2 */

				charge = baseprices + kmcost;



				// Add base Price and cost for kilometer driven in to a new variable "charge"    

				/* Copy and Paste from In-Lab Case - 2 */


				vRent[flag].earnings = addPositive(vRent[flag].earnings,charge);


				/* Call addPositive function with current earnings for the rental and

				charge(calculated above) as arguments and assign the returned

				result back to earnings

				*/

				/* Copy and Paste from In-Lab Case - 2 */


				printf("Apply discount: ");
				scanf(" %c",&d);

				// Apply Discount with a prompt for Y or N

				// If the user input is skipped without being prompted, have one space infront 

				// of %c in the scanf statement => " %c" instead of "%c"

				if (d == 'y' || d == 'Y')
				{
					vRent[flag].earnings = subtractPositive(vRent[flag].earnings, discount);


				}





					/* If the input is 'Y' or 'y' then call function subtractPositive with current earnings

					for the rental and discount (5 CAD) as arguments and assign the returned

					result back to earnings

					*/







					// Display Base Charge, cost for km and the Total 

					printf("\nBase   kmCost DiscStatus Total\n");

					printf("====== ====== ========== ======\n");
					printf("%6.2lf %6.2lf %10c %6.2lf\n", baseprices, kmcost, d, vRent[flag].earnings);
					// Use "%6.2lf %6.2lf %10c %6.2lf" formatting inside a printf statement
					printf("\n");
				
			}

			else {

				printf("ERROR: Vehicle ID does not exist.\n\n");

			}
			break;

		case 3: // Apply Taxes to all Earnings

			printf("\n-- Apply Taxes To all Accounts--\n\n");

			printf("ID#      Earnings   Taxes\n");

			printf("-------- ---------- ------\n");
			

     		for (int a = 0; a < noVehicles; a++)
			{
				taxes = taxCalc(vRent[a].earnings, taxRate);

				vRent[a].earnings = addPositive(vRent[a].earnings, taxes);

				printf("%8d %10.2lf %6.2lf\n", vRent[a].id, vRent[a].earnings, taxes);
			}
			printf("\n");
			// Iterate over all Rentals. For each rental, calculate the taxes by calling taxCalc 

			// by passing current earnings and tax rate

			// Then call addPositive with current earnings and the taxes returned from taxCalc function

			// Then use "%8d %10.2lf %6.2lf" formatting to display ID, Earnings and taxes for each rental



			break;



		case 4: // Apply Gift Card

			flag = -1;

			printf("\n-- Apply Gift Card --\n\n");

			printf("Enter vehicle ID: ");

			scanf("%d", &tempID);



			// Finding the correct vehicle index

			for (i = 0; i < noVehicles && flag == -1; i++) {

				if (tempID == vRent[i].id) {

					flag = i;

				}

			}

			if (flag != -1) {

				printf("Enter Gift Card amount: ");
				scanf("%lf",&gift);
				// Capture Gift card amount



				vRent[flag].earnings = subtractPositive(vRent[flag].earnings,gift);

				/* call function subtractPositive with current earnings for the rental and Gift card

				amount as arguments and assign the returned result back to earnings

				*/
				printf("Discount Applied\n");




			}

			else {

				printf("ERROR: Vehicle ID does not exist.\n\n");

			}



			printf("\n");



			break;



		default:

			printf("Error: Please enter a valid option to continue\n\n");

			break;

		}





	} while (option != 0);





	return 0;

}