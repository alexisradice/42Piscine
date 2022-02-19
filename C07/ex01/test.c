#include "ft_range.c"
#include <stdio.h>

void test(int min, int max)
{
	int *range = ft_range(min, max);
	
	printf("%i - %i | ", min, max);

	if (range)
	{
		for (int i = 0; i <  max - min; i++)
		{
			printf("%i ", range[i]);
		}

		free(range);

		printf("\n");
	}
	else
		printf("ERROR\n");
}

int main()
{
	test(0, 10);
	test(10, 10);
	test(15, 16);
	test(0, 1);
	test(-10, 10);
	test(-105, -104);
	test(50, 55);
	test(10, 8);
	test(2147483647 - 5, 2147483647);
	test(-2147483648, -2147483648 + 5);
}
