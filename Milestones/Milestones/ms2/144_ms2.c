// -------------------------------------------
//  Name: Ilias Halemi	
//  ID: 062111133
//  Email: ihalemi@myseneca.ca
//  Description: Milestone #2
// -------------------------------------------

#include <stdio.h>
#define LINEAR 1
#define FROM 0

const double TAX = 0.13;

struct Item {
 double price;
 int sku;
 int isTaxed;
 int quantity;
 int minQuantity;
 char name[21];
};

// ---------------------------------------
// place function PROTOTYPES below here...
// ---------------------------------------

// user interface tools function PROTOTYPES:

void welcome(void);
void printTitle(void);
void printFooter(double gTotal);
void flushKeyboard(void);
void pause(void);
int getInt(void);
int getIntLimited(int lowerLimit, int upperLimit);
double getDouble(void);
double getDoubleLimited(double lowerLimit, double upperLimit);
double totalAfterTax(struct Item item);
int isLowQuantity(struct Item item);
struct Item itemEntry(int sku);
void displayItem(struct Item item,int linear);
void listItems(const struct Item item[], int noOfItems);
int locateItem(const struct Item item[], int NoOfRecs, int sku, int* index);

// application user interface function PROTOTYPES:

int yes(void);
int menu(void);
void GroceryInventorySystem(void);

int i;

// ----------------------------------------
// place function DEFINITIONS below here...
// ----------------------------------------


void welcome(void){
  printf(">---=== Grocery Inventory System ===---<\n\n");
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
    printf("Invalid value, %lf < value < %lf: ", lowerLimit, upperLimit);
    Value = getDouble();
  }
  return Value;
}

// Accepts and checks user input and then clears the keyboard
int yes(void){
  char input;
  scanf("%c", &input);
  flushKeyboard();
  while(input != 'Y' && input != 'y' && input != 'N' && input != 'n'){
    printf("Only (Y)es or (N)o are acceptable: ");
    scanf("%c", &input);
    flushKeyboard();
  }
  if(input == 'Y' || input == 'y'){
    return 1;
  }
  else{
    return 0;
  }
}

// Uses getIntLimited function to make sure selection is between 0 and 7 then returns selection
int menu(void){
  printf("1- List all items\n2- Search by SKU\n3- Checkout an item\n4- Stock an item\n5- Add new item or update item\n6- Delete item\n7- Search by name\n8- Exit program\n> ");
  int selection = getIntLimited(0,7);
  return selection;
}

// Recieves user input to display menu options
void GroceryInventorySystem(void){
  int exit = 0;
  welcome();
  printf("\n");
  while(exit != 1){
    int selection = menu();

    if(selection == 1){
      printf("List Items under construction!\n");
      pause();
    }
    else if(selection == 2){
      printf("Search Items under construction!\n");
      pause();
    }
    else if(selection == 3){
      printf("Search Items under construction!\n");
      pause();
    }
    else if(selection == 4){
      printf("Stock Items under construction!\n");
      pause();
    }
    else if(selection == 5){
      printf("Add/Update Items under construction!\n");
      pause();
    }
    else if(selection == 6){
      printf("Delete Items under construction!\n");
      pause();
    }
    else if(selection == 7){
      printf("Search by name under construction!\n");
      pause();
    }
    else if(selection == 0){							// Pronpts user if they want to exit the menu
      printf("Exit the program? (Y)es/(N)o: ");
      exit = yes();
    }
  }
}

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
  if(item.quantity < item.minQuantity) {
    return 1;
  }
  return 0;
}


struct Item itemEntry(int sku){
  struct Item newItem;
  newItem.sku = sku;
  printf("        SKU: %d\n", sku);

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
    printf("|%03d|%-20s|%8.2lf|  ", item.sku, item.name, item.price);
    if(item.isTaxed == 1){
      printf("%3s| ", "Yes");
    }
    else{
      printf("%3s| ", "No");
    }
    printf("%3d | %3d |%12.2lf|", item.quantity, item.minQuantity, totalAfterTax(item));

    if(isLowQuantity(item) == 1){
      printf("***\n");
    }
    else{
      printf("\n");	
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
   
      grandTotal += totalAfterTax(item[i]);
    }
    printFooter(grandTotal);
}

// Checks if the sku argument is the same as the sku of the item
int locateItem(const struct Item item[], int NoOfRecs, int sku, int* index){
  for (i = 0; i < NoOfRecs; i++){
    if(item[i].sku == sku){
      *index = i;
      return 1;
    }
  }
  return 0;
}
