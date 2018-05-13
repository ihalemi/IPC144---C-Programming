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
	int isbn2find;
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
			
			addBook(filename, &mybook);
			break;

		case 3:
			printf("Please input the ISBN number of the book:\n\n");
			scanf("%d", &isbn2find);
			checkPrice(filename, isbn2find);
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
	//Close the file
	fclose(fp);
	}
	fp = NULL;	
    
    
    //Use a while loop to call readRecord and display the records.
   // while(/*call readRecord and check its return value*/)
        //display the record
        
}


void addBook(const char filename[], struct Book *b2Add)
{
	int status;
	FILE *fp = fopen(filename, "a+");

	printf("ISBN:");
	scanf("%d", &(*b2Add)._isbn);
	printf("Title:");
	scanf(" %20[^\n]", (*b2Add)._title);
	printf("Year:");
	scanf("%d", &(*b2Add).year);
	printf("Price:");
	scanf("%f", &(*b2Add).price);
	printf("Quantity:");
	scanf("%d", &(*b2Add).qty);

	status = searchInventory(fp, (*b2Add)._isbn);

	if (status != -1) {
		printf("The book exists in the repository!\n\n");
	}
	else if (fprintf(fp, "%d;%.2f;%d;%d;%s\n", (*b2Add)._isbn, (*b2Add).price, (*b2Add).year, (*b2Add).qty, (*b2Add)._title)) {
		printf("The book is successfully added to the inventory.\n\n");
		fclose(fp);
	}
}

void checkPrice(const char filename[],const int isbn2find)
{
	struct Book book;

	FILE *fp = fopen(filename, "r");

	if (fp != NULL) {

		while (readRecord(fp, &book) == 5) { // CG2017-07-28: 5 IS FOR THE VALID FIELDS PER RECORD
			if (book._isbn == isbn2find) {
				printf("Book %d costs $%.2f\n\n", isbn2find, book.price);
			}
		}
	}
	else {
		printf("Book does not exist in the bookstore! Please try again.\n\n");
	}
	fclose(fp);
 
}

int searchInventory(FILE *fp,const int isbn2find)
{
	//Define an object of struct Book and other necessary variables
	struct Book book;
	int i = 0;
	int status = -1;
	//If the file ponter is not NULL:
	if (fp != NULL) {
		while (readRecord(fp, &book) == 5) { // CG2017-07-28: 5 IS FOR THE VALID FIELDS PER RECORD
			if (book._isbn == isbn2find) {
				status = i;
			}
		}
	}
	//as long as the record is not found,
	//use the function readRecord to read the recods and look for isbn2find

	return status;
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

		//Close the file
		fclose(fp);
	}
	fp = NULL;

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
