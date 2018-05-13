/*
Name: Ilias	Halemi	
Student number: 062111133
Email: ihalemi@myseneca.ca
Workshop: 7	
Section: L
Date: 07/07/2017
*/

#include <stdio.h>
#define SIZE 3
void decompose(const long long phone_number, int *area, int *prefix, int *line);

void decompose(const long long phone_number, int *area, int *prefix, int *line) {
	*area = phone_number / 10000000L;
	*prefix = (phone_number % 10000000L) / 10000L;
	*line = (phone_number % 10000000L) % 10000L;
}




/* main program */
int main(void) {

	int option;
	int area, prefix, line;
	int counter = 0;
	int x = 0;

	long long phoneNumber[SIZE] = { 0LL };

	printf("---=== Phone Numbers ===---\n\n");

	do {
		// Display the Option List
		printf("1. Display Phone List\n");
		printf("2. Add a Number\n");
		printf("0. Exit\n\n");
		printf("Please select from the above options: ");
		scanf("%d", &option);
		printf("\n");

		switch (option) {
		case 0:	// Exit the program
			printf("Exiting Phone Number App. Good Bye!!!\n");
			break;

		case 1: // Display the Phone List
				// @IN-LAB
			
			printf("Phone Numbers\n");
			printf("==============\n");
			// Display each number in decomposed form
				for (x = 0; x < counter; x++)
				{
					decompose(phoneNumber[x], &area, &prefix, &line);
					printf("(%3d)-%3d-%4d", area, prefix, line);
					printf("\n");
					
				}
				printf("\n");
				break;


		case 2:	// Add a Phone Number
				// @IN-LAB
			if (counter == SIZE) {
				printf("Add a Number\n");
				printf("============\n");
				printf("ERROR!!! Phone Number List is Full\n");
			    printf("\n");
		}
			else {
				printf("Add a Number\n");
				printf("============\n");
				scanf("%lld", &phoneNumber[counter]);
				printf("\n");
				counter++;
			}

		default:
			break;
		}

	} while (option != 0);

	return 0;
}




