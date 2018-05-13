// ---------------------------------------
// Name: Ilias Halemi	
// ID: 062111133
// Email: ihalemi@myseneca.ca
// ---------------------------------------

#include <stdio.h>
#define MAX_TITLE_SIZE 21

//Type the struct here
struct Book {
	int _isbn;
	float price;
	int year;
	int qty;
	char _title[MAX_TITLE_SIZE];
};

//Type the function prototypes here
void menu();
void displayInventory(const char filename[]);
void addBook(const char filename[], struct Book *b2Add);
void checkPrice(const char filename[], const int isbn2find);
int searchInventory(FILE *fp, const int isbn2find);
float calculateCapital(const char filename[]);
int readRecord(FILE *fp, struct Book *b2read);


int main()
{
   //Type your code here:
	struct Book mybook = { (0) };
	int option;
	float capitalTotal;
	char filename[] = "144_w9_inventory.txt";

	printf("Welcome to the Book Store\n");		// Welcome message
	printf("=========================\n");

	do {
		menu();

		printf("\nSelect: ");
		scanf("%d", &option);
		switch (option) {

		case 1:
			displayInventory(filename);
			break;

		case 2:
			//Not implemented
			addBook(filename, &mybook);
			break;

		case 3:
			//Not implemented
			break;

		case 4:
			capitalTotal = calculateCapital(filename);
			printf("The total capital is: $%.2f.\n", capitalTotal);
			break;

		case 0:
			printf("Goodbye!\n");
			break;

		default:
			printf("Invalid input, try again:\n");
			break;

		}

	} while (option != 0);
    
	return 0;
}

void menu()
{
	printf("Please select from the following options:\n");
	printf("1) Display the inventory.\n");
	printf("2) Add a book to the inventory.\n");
	printf("3) Check price.\n");
	printf("4) Calculate total capital of the store.\n");
	printf("0) Exit.\n");

}



void displayInventory(const char filename[])
{
    //Define an object of struct Book
	struct Book book;
	
    //Open the file, and check for null pointer
	FILE *fp = NULL;
	fp = fopen(filename, "r");
    //If the file is properly opened, display headers, similar to workshop 8
	if (fp != NULL) {
		printf("\n\nInventory\n");
		printf("===================================================\n");
		printf("ISBN      Title               Year Price  Quantity\n");
		printf("---------+-------------------+----+-------+--------\n");

		while (readRecord(fp, &book) == 5) {
			printf("%-10.0d%-20s%-5d$%-8.2f%-8d\n", book._isbn, book._title, book.year, book.price, book.qty);
		}
	//Display the footer
	printf("===================================================\n\n");
	}
	//Close the file
	fclose(fp);
        
}


void addBook(const char filename[], struct Book *b2Add)
{
 //Not implemented!
	printf("Not implemented!");
}

void checkPrice(const char filename[],const int isbn2find)
{
    
 //Not implemented!
	printf("Not implemented!");
}

int searchInventory(FILE *fp,const int isbn2find)
{
 //Not implemented!
 printf("Not implemented!");
	return 0;
}


float calculateCapital(const char filename[])
{
    //Define an object of struct Book
	struct Book book;
    //Define and initialize total_capital
	float total_capital = 0;
    //Open the file, and check for null pointer
	FILE *fp = NULL;
	fp = fopen(filename, "r");
	if (fp != NULL) {
		while (readRecord(fp, &book) == 5) {
			total_capital = total_capital + (book.price * book.qty);
		}
	}
	
	//Close the file
	fclose(fp);
	//return the total_capital
	return total_capital;

}

int readRecord(FILE *fp, struct Book *b2read)
{
    //Define a variable int rv = 0
	int rv = 0;

	if (fp != NULL) 
		rv = fscanf(fp, "%d;%f;%d;%d;%20[^\n]", &b2read->_isbn, &b2read->price, &b2read->year, &b2read->qty, b2read->_title);
	
	return rv;
}
