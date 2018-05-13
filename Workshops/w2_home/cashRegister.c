/* Name: Ilias Halemi
Student ID: 062111133
Email: ihalemi@myseneca.ca*/

#include <stdio.h>
int main()
{
	double a;
	int loonies;
	int balance;
	int quarters;
	double GST;
	double balanceOwing;
	int dimes;
	int nickels;
	int pennies;


	printf("Please enter the amount to be paid: $");
	scanf("%lf", &a);

	GST = a * .13 + .005;

		printf("GST: %.2lf\n", GST);

	balanceOwing = a + GST;

		printf("Balance owing: $%.2lf\n", balanceOwing);

	balance = balanceOwing * 100;
	loonies = balance / 100;
	balance = (balance % 100);


	printf("Loonies required: %d, balance owing $%1.2lf\n", loonies, (float)balance / 100.0);

	quarters = balance / 25;
	balance = balance % 25;


	printf("Quarters required: %d, balance owing $%1.2lf\n", quarters, (float)balance / 100.0);

	dimes = balance / 10;
	balance = balance % 10;

	printf("Dimes required: %d, balance owing $%1.2lf\n", dimes, (float)balance / 100.0);

	nickels = balance / 5;
	balance = balance % 5;

	printf("Nickels required: %d, balance owing $%1.2lf\n", nickels, (float)balance / 100.0);

	pennies = balance / 1;
	balance = balance % 1;

	printf("Pennies required: %d, balance owing $%1.2lf\n", pennies, (float)balance / 100.0);




	return 0;


}
