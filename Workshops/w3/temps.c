// Name: Ilias Halemi	
// Student Number: 062111133
// Email:ihalemi@myseneca.ca
// Section:L	
// Workshop:3

#include <stdio.h>
#define NUMS 3
int main()
{

	int highValue;
	int lowValue;
	int i;
	int totalHigh = 0;
	int totalLow = 0; 
	float totalTemperature;
	float  mean;

	printf("---=== IPC Temperature Analyzer ===---\n");

	for (i = 0; i < NUMS; i++)
	{

		printf("Enter the high value for day %d: ", i+1);
		scanf("%d", &highValue);
		printf("\n");

		printf("Enter the low value for day %d: ", i+1);
		scanf("%d", &lowValue);
		printf("\n");

		

		while (highValue < lowValue || highValue > 40 || highValue < -40 || lowValue < -40)
		{
			printf("Incorrect values, temperatures must be in the range -40 to 40, high must be greater than low.\n");
			printf("\n");

			printf("Enter the high value for day %d: ", i+1);
			scanf("%d", &highValue);
			printf("\n");

			printf("Enter the low value for day %d: ", i+1);
			scanf("%d", &lowValue);
			printf("\n");
		}
			

		totalHigh = totalHigh + highValue;
		totalLow = totalLow + lowValue;
		
	}

	totalTemperature = (totalHigh + totalLow);
	mean = totalTemperature / (NUMS*2);

	printf("The average (mean) temperature was: %.2f\n", mean);

	
	return 0; 
}

