// -------------------------------------------
//  Name: Ilias Halemi	
//  ID: 062111133
//  Email: ihalemi@myseneca.ca
//  Description: Milestone #2
// -------------------------------------------

#include <stdio.h>
#define LINEAR 1
#define FROM 0
#define STOCK 1
#define CHECKOUT 0
//#define MAX_ITEM_NO 21
#define MAX_QTY 999
#define SKU_MAX 999
#define SKU_MIN 100
#define FORM 0

// MS4 Definitions
#define MAX_ITEM_NO 500
#define DATAFILE "144_fp_items.txt"
const double TAX = 0.13;

struct Item {
 double price;
 int sku;
 char isTaxed;
 int quantity;
 int minQuantity;
 char name[21];
};

// ---------------------------------------
// place function PROTOTYPES below here...
// ---------------------------------------

// user interface tools function PROTOTYPES:

// Milestone 1 Prototype
void welcome(void);
void printTitle(void);
void printFooter(double gTotal);
void flushKeyboard(void);
void pause(void);
int getInt(void);
int getIntLimited(int lowerLimit, int upperLimit);
double getDouble(void);
double getDoubleLimited(double lowerLimit, double upperLimit);

// Milestone 2 Prototypes
double totalAfterTax(struct Item item);
int isLowQuantity(struct Item item);
struct Item itemEntry(int sku);
void displayItem(struct Item item,int linear);
void listItems(const struct Item item[], int noOfItems);
int locateItem(const struct Item item[], int NoOfRecs, int sku, int* index);

// Milestone 3 Prototypes
void search(const struct Item item[], int NoOfRecs);
void updateItem(struct Item* itemptr);
void addItem(struct Item item[], int *NoOfRecs, int sku);
void addOrUpdateItem(struct Item item[], int* NoOfRecs);
void adjustQuantity(struct Item item[], int NoOfRecs, int stock);

// Milestone 4 Prototypes
void saveItem(struct Item item, FILE* dataFile);
int loadItem(struct Item* item, FILE* dataFile);
int saveItems(const struct Item item[], char filename[], int NoOfRecs);
int loadItems(struct Item item[], char filename[], int* NoOfRecsPtr);

// application user interface function PROTOTYPES:

int yes(void);
int menu(void);
void GroceryInventorySystem(void);

int i;

// ----------------------------------------
// place function DEFINITIONS below here...
// ----------------------------------------

//********************************
//Milestone 1 Function Defenitions
//********************************


void welcome(void){
  printf("---=== Grocery Inventory System ===---\n\n");

}

void printTitle(void){
  printf("Row |SKU| Name               | Price  |Taxed| Qty | Min |   Total    |Atn\n");
  printf("----+---+--------------------+--------+-----+-----+-----+------------|---\n");
}

// Prints only when gTotal is greater than 0
void printFooter(double gTotal){
  printf("--------------------------------------------------------+----------------\n");
  if (gTotal > 0){
    printf("                                           Grand Total: |%12.2lf\n", gTotal);
  }
}

// Keeps reading single characters until newline is entered
void flushKeyboard(void){
  while(getchar() != '\n');
}

// Pause the program and use flushKeyboard function to enter \n to continue
void pause(void){
  printf("Press <ENTER> to continue...");
  flushKeyboard();
}

// Checks that the user entered input is an interger by making sure that the second input is a newline
int getInt(void){
  int Value;
  char NL = 'x';
  while(NL != '\n'){
    scanf("%d%c", &Value, &NL);
    if(NL != '\n'){
      flushKeyboard();
      printf("Invalid integer, please try again: ");
    }
  }
  return Value;
}

// Checks that value is between upperLimit and lowerLimit 
int getIntLimited(int lowerLimit, int upperLimit){
  int Value = getInt();
  while(Value > upperLimit || Value < lowerLimit){
    printf("Invalid value, %d < value < %d: ", lowerLimit, upperLimit);
    Value = getInt();
  }
  return Value;
}

// Works the same way as getInt function but accepts a double user input 
double getDouble(void){
  double Value;
  char NL = 'x';
  while(NL != '\n'){
    scanf("%lf%c", &Value, &NL);
    if(NL != '\n'){
      flushKeyboard();
      printf("Invalid number, please try again: ");
    }
  }
  return Value;
}

// Works the same way as getIntLimited function but scans double user input
double getDoubleLimited(double lowerLimit, double upperLimit){
  double Value = getDouble();
  while(Value > upperLimit || Value < lowerLimit){
    printf("Invalid value, %lf< value < %lf: ", lowerLimit, upperLimit);
    Value = getDouble();
  }
  return Value;
}

// Accepts and checks user input and then clears the keyboard
int yes(void){
	int retValue = 0;
  char input;
  scanf("%c", &input);
  flushKeyboard();
  while(input != 'Y' && input != 'y' && input != 'N' && input != 'n'){
    printf("Only (Y)es or (N)o are acceptable: ");
    scanf("%c", &input);
    flushKeyboard();
  }
  if(input == 'Y' || input == 'y'){
    retValue = 1;
	return retValue;
  }
  else{
    return retValue;
  }
}

// Uses getIntLimited function to make sure selection is between 0 and 7 then returns selection
int menu(void){
  printf("1- List all items\n");
  printf("2- Search by SKU\n");
  printf("3- Checkout an item\n");
  printf("4- Stock an item\n");
  printf("5- Add new item or update item\n");
  printf("6- Delete item\n");
  printf("7- Search by name\n");
  printf("0- Exit program\n> ");

  int selection = getIntLimited(0,7);
  return selection;
}

// Recieves user input to display menu options
void GroceryInventorySystem(void){
  int exit = 0;
  welcome();
  
  while(exit != 1){
    int selection = menu();

    switch (selection) {
	case 1:
      printf("List Items under construction!\n");
      pause();
	  break;

	case 2:
      printf("Search Items under construction!\n");
      pause();
	  break;

	case 3:
      printf("Checkout Item under construction!\n");
      pause();
	  break;

	case 4:
      printf("Stock Item under construction!\n");
      pause();
	  break;

	case 5:
      printf("Add/Update Item under construction!\n");
      pause();
	  break;

	case 6:
      printf("Delete Item under construction!\n");
      pause();
	  break; 

	case 7:
      printf("Search by name under construction!\n");
      pause();
	  break;

	case 0:														// Pronpts user if they want to exit the menu
      printf("Exit the program? (Y)es/(N)o: ");
      exit = yes();
	  break;

  default :
	  printf("Invalid value, 0 < value < 7: ");
	  break;
    }
  }
}

//*********************************
// Milestore 2 Function Definitions
//*********************************


// Gives the total price for an item and adds tax if the item is taxed
double totalAfterTax(struct Item item){
  double total = item.price * item.quantity;
  if (item.isTaxed == 1) {
    total = total * TAX + total;
  }
  return total;
}

// Checks true or false for item quantity
int isLowQuantity(struct Item item){
	int retValue = 0;
  if(item.quantity < item.minQuantity) {
	  retValue = 1;
	  return retValue;
  }
  return retValue;
}


struct Item itemEntry(int sku){
  struct Item newItem;
  newItem.sku = sku;
  printf("		 SKU: %d\n", sku);

  printf("       Name: ");
  scanf("%20[^\n]", newItem.name);
  flushKeyboard();

  printf("      Price: ");
  newItem.price = getDouble();

  printf("   Quantity: ");
  newItem.quantity = getInt();

  printf("Minimum Qty: ");
  newItem.minQuantity = getInt();

  printf("   Is Taxed: ");
  newItem.isTaxed = yes();
  return newItem;
}

// Prints two formats of an items depending on whether linar is true or false
void displayItem(struct Item item,int linear){
  if(linear == 1){
    printf("|%03d|%-20s|%8.2lf| ", item.sku, item.name, item.price);
    if(item.isTaxed == 1){
      printf("%3s| ", "Yes");
    }
    else{
      printf("%3s| ", "No");
    }
    printf("%3d | %3d |%12.2lf|", item.quantity, item.minQuantity, totalAfterTax(item));
    if(isLowQuantity(item) == 1){
      printf("***");
    }
  }
  else{
    printf("        SKU: %03d\n", item.sku);
    printf("       Name: %s\n", item.name);
    printf("      Price: %.2lf\n", item.price);
    printf("   Quantity: %d\n", item.quantity);
    printf("Minimum Qty: %d\n", item.minQuantity);
    if(item.isTaxed){
      printf("   Is Taxed: %s\n", "Yes");
    }
    else{
      printf("   Is Taxed: %s\n", "No");
    }
    if(isLowQuantity(item) == 1){
      printf("WARNING: Quantity low, please order ASAP!!!\n");
    }
  }
}


void listItems(const struct Item item[], int noOfItems){
    double grandTotal = 0.0;
    printTitle();
    for (i = 0; i < noOfItems; i++){
      printf("%-4d", i+1);
      displayItem(item[i],1);
      printf("\n");
      grandTotal += totalAfterTax(item[i]);
    }
    printFooter(grandTotal);
}

// Checks if the sku argument is the same as the sku of the item
int locateItem(const struct Item item[], int NoOfRecs, int sku, int* index){
	int retValue = 0;
  for (i = 0; i < NoOfRecs; i++){
    if(item[i].sku == sku){
      *index = i;
      retValue = 1;
	  return retValue;
    }
  }
  return retValue;
}


// ********************************
// Milestone 3 Definitions Declared 
// ********************************

void search(const struct Item item[], int NoOfRecs) {
	int userIn;
	int index;
	printf("Please enter the SKI: ");
	userIn = getIntLimited(SKU_MIN, SKU_MAX);

	if (locateItem(item, NoOfRecs, userIn, &index) == 0)
		printf("Item not found!\n");
	else {
		char* YN[4];
		if (item[index].isTaxed == 1) {
			*YN = "Yes";
		}
		else {
			*YN = "No";
		}
		printf("		SKU: %d\n"
			"          Name: %s\n"
			"         Price: %.2lf\n"
			"      Quantity: %d\n"
			"   Minumum Qty: %d\n"
			"      Is Taxed: %s\n", item[index].sku, item[index].name, item[index].price, item[index].quantity, item[index].minQuantity, *YN );
			

	}

}

void updateItem(struct Item* itemptr) {
	struct Item item;

	printf("Enter new data: \n");
	item = itemEntry(itemptr->sku);
	printf("Overwrite old data? (Y)es/(N)o: ");

	if (yes() == 1) {
		*itemptr = item;
		printf("--== Updated! ==--\n");
	}
	else {
		printf("--== Aborted! ==--\n");
	}

}

void addItem(struct Item item[], int *NoOfRecs, int sku) {
	struct Item newItem;
	int spec = *NoOfRecs;

	if (spec == MAX_ITEM_NO) {
		printf("Can not add new item; Storage Full!\n");
	}
	else {
		newItem = itemEntry(sku);
		printf("Add Item? (Y)es/(N)o: ");
		if (yes() == 1) {
			item[spec] = newItem;
			spec++;
			*NoOfRecs = spec;
			printf("--== Added! ==--\n");
		}
		else {
			printf("--== Aborted! ==--\n");
		}
	}
}


void addOrUpdateItem(struct Item item[], int* NoOfRecs) {
	int userIn;
	int index;
	printf("Please enter the SKU: ");
	userIn = getIntLimited(SKU_MIN, SKU_MAX);

	if (locateItem(item, *NoOfRecs, userIn, &index) == 1) {
		displayItem(item[index], FORM);
		printf("Item already exists, Update? (Y)es/(N)o: ");
		if (yes() == 1) {
			updateItem(&item[index]);
		}
		else {
			printf("--== Aborted! ==--\n");
		}
	}
	else {
		addItem(item, NoOfRecs, userIn);
	}
}
	
void adjustQuantity(struct Item item[], int NoOfRecs, int stock) {
	int userQut;
	int sku;
	int flag = 0;
	int index;
	int i;
	printf("Please enter the SKU: ");
	sku = getInt();
	for (i = 0; i < NoOfRecs; i++) {
		if (sku == item[i].sku) {
			index = i;
			flag = 1;
		}
	}
	if (flag == 0) {
		printf("SKu not found in storage!\n");
	}
	else {
		displayItem(item[index], FORM);

		if (stock == 1) {
			printf("Please enter the quantity %s; Maximum of %d or 0 to abort: ", "to stock", MAX_QTY - item[index].quantity);
			userQut = getIntLimited(0, MAX_QTY - item[index].quantity);
			if (userQut == 0) {
				printf("--== Aborted! ==--\n");
			}
			else {
				item[index].quantity -= userQut;
				printf("--== Stocked! ==--\n");
			}
		}
		else if (stock == 0) {
			printf("Please enter the quantity %s; Maximum of %d or 0 to abort: ", "to checkout", item[index].quantity);
			userQut = getIntLimited(0, item[index].quantity);
			if (userQut == 0) {
				printf("--== Aborted ! ==--\n");
			}
			else {
				item[index].quantity -= userQut;
				printf("--== Checked out! ==--\n");
			}
		}
		if (item[index].quantity <= item[index].minQuantity) {
			printf("Quantity is low, please reorder ASAP!!!\n");
		}
	}
	
}


// ********************************
// Milestone 4 Definitions Declared
// ********************************

void saveItem(struct Item item, FILE* dataFile) {
	fprintf(dataFile, "%d,%d,%d,%.2lf,%d,%s\n", item.sku, item.quantity, item.minQuantity, item.price, item.isTaxed, item.name);
}

int loadItem(struct Item* item, FILE* dataFile) {
	int retValue = 0;

	if (fscanf(dataFile, "%d,%d,%d,%lf,%s,%[^\n]", &item->sku, &item->quantity, &item->minQuantity, &item->price, &item->isTaxed, item->name) == 6) {
		retValue = 1;
		return retValue;
	}
	else {
		return retValue;
	}

}

int saveItems(const struct Item item[], char filename[], int NoOfRecs) {
	int i;
	int retValue = 0;			// 1 means true and 0 means false
	FILE* fp;
	fp = fopen(filename, "w");

	if (fp == NULL) {
		return retValue;
	}
	else {

		for (i = 0; i < NoOfRecs; i++) {
			saveItem(*(item + i), fp);
		}
		fclose(fp);
		retValue = 1;
		return retValue;
	}
}

int loadItems(struct Item item[], char filename[], int* NoOfRecsPtr) {
	FILE* fp;
	int i = 0;
	int retValue = 0;

	fp = fopen(filename, "r");

	if (fp == NULL) {
		return retValue;
	}
	else {
		for (; loadItem(item, fp) != 0; item++) {
			i += 1;
		}
		*NoOfRecsPtr = i;
		fclose(fp);
		retValue = 1;
		return retValue;
	}


}
