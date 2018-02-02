#include <stdio.h>
char word[1000001];
int main()
{
	int counter = 0;

	for (;;)
	{
		int temp = scanf("%s", word);
		if (temp == true)
			counter++;
		else
			break;
	}

	printf("%d", counter);

}