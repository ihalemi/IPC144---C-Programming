/*
Name: Ilias Halemi
Student number: 062111133
Email: ihalemi@myseneca.ca
Workshop: 8
Section: L
Date: 07/12/2017
*/
#include <stdio.h>
#define	MAX_BOOKS 10
#define MAX_TITLE_SIZE 21

// Structure Declaration
struct Book {
	int _isbn;
	float _price;
	int _year;
	char _title[MAX_TITLE_SIZE];
	int _qty;
};

// Function Declaration
void menu();
void displayInventory(const struct Book book[], const int size);
int searchInventory(const struct Book book[], const int isbn, const int size);
void addBook(struct Book book[], int *size);
void checkPrice(const struct Book book[], const int size);

// Maim Program

int main()
{
	struct Book book[MAX_BOOKS];				// An array of Book representing the current inventory

	int size = 0;								// Inventory size which is initially empty
	int option;

	printf("Welcome to the Book Store\n");		// Welcome message
	printf("=========================\n");

	do {
		menu();									// Call menu function
		printf("\nSelect: ");
		scanf("%d", &option);

		switch (option) {
		case 0:									// Exits Program
			printf("Goodbye!\n");
			break;
		case 1:
				//Call function displayInventory

			displayInventory(book, size);
			break;
		case 2:
				// Call function addBook	

				addBook(book, &size);
			break;
		case 3:
			   // Call function checkPrice
		
			checkPrice(book, size);
			break;
		default:
				printf("Invalid input, try again:\n");
				break;
		}
	} while (option != 0);
	return 0;

}//End of main program

// Function Definition

void menu() {

	printf("Please select from the following options:\n");
	printf("1) Display the inventory.\n");
	printf("2) Add a book to the inventory.\n");
	printf("3) Check price.\n");
	printf("0) Exit.\n");

}

void displayInventory(const struct Book book[], const int size) {
	int i;

	if (size > 0) {
		printf("\n\nInventory\n");
		printf("===================================================\n");
		printf("ISBN      Title               Year Price  Quantity\n");
		printf("---------+-------------------+----+-------+--------\n");
		for (i = 0; i < size; i++){
			printf("%-10.0d%-20s%-5d$%-8.2f%-8d\n", book[i]._isbn, book[i]._title, book[i]._year, book[i]._price, book[i]._qty);
		}
		printf("===================================================\n\n");
	}
	else {
		printf("The inventory is empty!\n");
		printf("===================================================\n\n");
	}
}

void addBook(struct Book book[], int *size) {
		// At Home
	int a;
	int tmpISBN;
	int qty;
	
		printf("ISBN:");
		scanf("%d", &tmpISBN);

		printf("Quantity:");
		scanf("%d", &qty);

		a = searchInventory(book, tmpISBN, *size);
		if (a == -1) {
			if (*size == MAX_BOOKS) {
				printf("the inventory is full\n");
			}
			else {
				book[*size]._qty = qty;
				book[*size]._isbn = tmpISBN;

				printf("Title:");
				scanf(" %20[^\n]", book[*size]._title);

				printf("Year:");
				scanf("%d", &book[*size]._year);

				printf("Price:");
				scanf("%f", &book[*size]._price);

				*size += 1;

				printf("The book is successfully added to the inventory.\n\n");
			}
		}
		else {
			book[a]._qty += qty;

				printf("The book exists in the repository, quantity is updated.\n\n");
		}
	

	}

// At home part

int searchInventory(const struct Book book[], const int isbn, const int size) {
	int i;
	int retIndex = -1;

	for (i = 0; i < size && retIndex == -1; i++) {
		if (book[i]._isbn == isbn) {
			retIndex = i;
		}
	}
	return retIndex;
}

void checkPrice(const struct Book book[], const int size) {
	int a;
	int tmpISBN;

	printf("Please input the ISBN number of the book:\n\n");
	scanf("%d", &tmpISBN);

	a = searchInventory(book, tmpISBN, size);

	if (a == -1) {
		printf("Book does not exist in the bookstore! Please try again.\n\n");
	}
	else {
		printf("Book %d costs $%.2lf\n\n", tmpISBN, book[a]._price);
	}
}
