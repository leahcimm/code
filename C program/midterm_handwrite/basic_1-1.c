#include <stdio.h>
int main()
{
	int sets, input;
	printf("How many sets of test data: ");
	scanf("%d",&sets);
	for(int i=0;i<sets;i++)
	{
		printf("Input a number:");
		scanf("%d",&input);
		if(input%7==0)
			printf("%d is a multiple of 7\n",input);
		if(input%5==0)
			printf("%d is a multiple of 5\n",input);
	}
	printf("Over!");
}