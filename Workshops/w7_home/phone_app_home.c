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
// Prototype
void decompose(const long long phone_number, int *area, int *prefix, int *line);
int isValid(const long long);


/* main program */
int main(void) {
	
	int option;
	int area, prefix, line;
	int counter = 0;
	int x = 0;
	long long tempNo;					// temporary variable to store phoneNumber



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
				scanf("%lld", &tempNo);						           // Use tempNo to temporarily store phone number
					
				
				if (isValid(tempNo) == 0) {
					printf("ERROR!!! Phone Number is not Valid\n"); // Invalid phone number, don't add to array
					printf("\n");
				}
				else {
					phoneNumber[counter] = tempNo;					   // Valid phone number, add to the array
					counter++;
					printf("\n");
				}
			}
			break;

		default:
			// Error message not a correct option
			printf("ERROR!!!: Incorrect Option: Try Again\n\n");
			break;
		}

	} while (option != 0);

	return 0;
}

//Function Definitions


int isValid (const long long phoneNum) {

	// Variable Declarations
	int i;
	int result = 0;
	int areacode = 0;
	int Prefix = 0;
	int lineNum = 0;
	int areaCode[3] = { 416, 647, 905 };

	// Decompose phone number before isValid function
	decompose(phoneNum, &areacode, &Prefix, &lineNum);

	for (i = 0; i < 3 && result == 0; i++) {
		if (areacode == areaCode[i] && Prefix >= 100 && Prefix <= 999) {	// validates area code and prefix range	
			result = 1;													// result = 1 means number is valid
		}
	}
	return result;														// result = 0 means number is invalid
}


void decompose(const long long phone_number, int *area, int *prefix, int *line) {
	*area = phone_number / 10000000L;
	*prefix = (phone_number % 10000000L) / 10000L;
	*line = (phone_number % 10000000L) % 10000L;
}
