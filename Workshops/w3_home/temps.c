// Name: Ilias Halemi	
// Student Number: 062111133
// Email:ihalemi@myseneca.ca
// Section:L	
// Workshop:3

#include <stdio.h>
#define NUMS 4
int main()
{

	int highValue;
	int lowValue;
	int i;
	int totalHigh = 0;
	int totalLow = 0; 
	float totalTemperature;
	float  mean;
	int highestValue = -40;
	int highestValueDate = 0;
	int lowestValue = 40;
	int lowestValueDate = 0;

	printf("---=== IPC Temperature Analyzer ===---\n");

	for (i = 0; i < NUMS; i++)
	{

		printf("Enter the high value for day %d: ", i+1);
		scanf("%d", &highValue);
		printf("\n");
		if (highValue >= highestValue) {
			highestValue = highValue;
			highestValueDate = i + 1;
		}

		printf("Enter the low value for day %d: ", i+1);
		scanf("%d", &lowValue);
		printf("\n");
		if (lowValue <= lowestValue) {
			lowestValue = lowValue;
			lowestValueDate = i + 1;
		}
		

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
	printf("The highest temperature was %d, on day %d\n", highestValue, highestValueDate);
	printf("The lowest temperature was %d, on day %d\n", lowestValue, lowestValueDate);
	

	
	return 0; 
}

