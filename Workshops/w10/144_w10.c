/*----------------------------------------
Name : Ilias Halemi	
ID   : 062111133
Email: ihalemi@myseneca.ca
-----------------------------------------*/

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>

int isJediMaster(const char name[]) {
  int isJedi = 0;
  char string[21];
  FILE *fp;

  fp = fopen("jedi_master.txt", "r");
  while (fscanf(fp, "%[^\n]%*c", string) > 0) {
	  if (strcmp(string, name) == 0) {
		  isJedi = 1;
	  }
  }
  fclose(fp);

  return isJedi;
}

void formatJediPhoneRecord(char formattedRecord[], const char fullName[], const char npa[], const char co[], const char number[]) {
	int length = 0;
	int i, space = 0;
	char tempName[16] = { 0 };

	length = strlen(fullName);

	strcpy(formattedRecord, fullName);
	if (length > 16) {
		for (i = 0; i < 14; i++) {
			tempName[i] = fullName[i];
		}
		strcpy(formattedRecord, tempName);
		strcat(formattedRecord, "..");
	}

	if (length < 16) {
		space = 16 - length;
		for (i = 0; i<space; i++) {
			strcat(formattedRecord, " ");
		}
	}

	strcat(formattedRecord, " (");
	strcat(formattedRecord, npa);
	strcat(formattedRecord, ") ");
	strcat(formattedRecord, co);
	strcat(formattedRecord, "-");
	strcat(formattedRecord, number);

	if (isJediMaster(fullName) == 1) {
		strcat(formattedRecord, " Jedi Master");
	}

}


/* Example formatted strings:
Padme Amidala    (418) 555-0105
Mace Windu       (438) 555-0155 Jedi Master.
Emperor Palpat.. (450) 555-0143
*/
