// Name: Ilias Halemi
// Student ID: 062111133
// Email: ihalemi@myseneca.ca

#include <stdio.h>

int main()
{
	int days;
	int i;
	int high[8];
	int low[8];



	printf("---=== IPC Temperature Calculator V2.0 ===---");

	
		printf("\nPlease enter the number of days, between 3 and 10, inclusive: ");
		scanf("%d", &days);
		printf("\n");
	
		if (days < 3 || days > 10)
		{
			printf("Invalid entry, please enter a number between 3 and 10, inclusive: ");
			scanf("%d", &days);
			printf("\n");
		}

		for (i = 0; i < days; i++)
		{
			printf("Day %d - High: ", i+1);
			scanf("%d", &high[i]);

			printf("Day %d - Low: ", i+1);
			scanf("%d", &low[i]);

		}
		
		printf("\nDay Hi Low\n");

		for (i = 0; i < days; i++)
		{
			printf("%d   %d   %d \n", i + 1, high[i], low[i]);
		}

	return 0;
}
