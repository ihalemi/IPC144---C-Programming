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
	
	
	printf("Please enter the amount to be paid: $");
	scanf("%lf", &a);

	balance = ((a * 100) + 0.005);
	loonies = balance / 100;
	balance = (balance % 100 );
	
		
		printf("Loonies required: %d, balance owing $%1.2lf\n" ,loonies, (float)balance/100.0 );

		quarters = balance / 25;
		balance = ((balance % 25) + 0.005);

	
		printf("Quarters required: %d, balance owing $%1.2lf\n", quarters, (float)balance/100.0 );



	
	return 0;


}
