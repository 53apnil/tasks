//Diplaying the alternative prime from given list 

#include<stdio.h>
int isPrime(int number)
{
	int loopVar;
	if (number < 1)
		return 0;
	else if (number <= 3)
		return 1;
	else if (number % 2 == 0 || number % 3 == 0)
		return 0;
	else 
	{
		for (loopVar = 5; loopVar * loopVar <= number; loopVar += 6)
	{
		if(number % loopVar == 0 || number % (loopVar + 2) == 0)
		return 0;
	}
		return 1;
	}

}
void main()
{
	int elementNo;
	int loopVar;
	printf("Enter the count of elements in array-");
	scanf("%d",&elementNo);
	printf("Enter the elements\n");
	int elementArr[elementNo];
	int ppFlag;

//Taking elementsvia loop from user
	for(loopVar = 0; loopVar < elementNo; loopVar++)
	{
		scanf("%d",&elementArr[loopVar]);
	}

	loopVar=0;
	ppFlag=0;
	while (loopVar < elementNo)
		{	
			if (elementArr[loopVar] == 2)
			{
				if (ppFlag==0)
				{
					printf("2,");
					ppFlag=1;
					loopVar++;
				}
				else if(ppFlag==1)
				{ppFlag=0;loopVar++;}
	
			}
			else if( elementArr[loopVar] != 1 && elementArr[loopVar] % 2 != 0 && (isPrime(elementArr[loopVar])==1))
			{
				if (ppFlag==0)
				{	
					printf("%d,",elementArr[loopVar]);
					ppFlag=1;
					loopVar++;
				}
				else
				{ppFlag=0;loopVar++;}
			}
			else
			loopVar++;
		}
}
