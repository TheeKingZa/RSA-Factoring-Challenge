#include <stdio.h>
#include <stdlib.h>

void factorize(int number)
{
	printf("%d =", number);
	int first_factor = 1;

	for (int i = 2; i <= number; i++)
	{
	while (number % i == 0)
	{
		if (first_factor)
		{
			printf(" %d", i);
			first_factor = 0;
		}
		else 
		{
			printf(" %d", i);
		}
		number /= i;
}
}
printf("\n");
}

int main(int argc, char *argv[])
{
	if (argc != 2)
	{
		fprintf(stderr, "Usage: %s <file>\n", argv[0]);
		return (EXIT_FAILURE);
	}
	FILE *file = fopen(argv[1], "r");
	if (file == NULL)
	{
		fprintf(stderr, "Error opening file.\n");
		return (EXIT_FAILURE);
	}
	
	char line[20]; 
	/* Assuming the numbers are not larger than 20 digits */
	while (fgets(line, sizeof(line), file))
	{
		int number = atoi(line);
		factorize(number);
	}
	fclose(file);

	return (EXIT_SUCCESS);
}
