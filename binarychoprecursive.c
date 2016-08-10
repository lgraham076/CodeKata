#include <stdio.h>
#include <stdlib.h>

#define NUMVALUES 100

typedef enum {false,true} bool;
int *randomValues;

int main()
{
	int i,random;
	int currValue=0;
	srand(time(NULL));
	
	randomValues=malloc(NUMVALUES*sizeof(int));
	for(i=0; i < NUMVALUES; i++)
	{
		random=rand()%5+1;
		currValue+=random;
		randomValues[i]=currValue;
	}
	
	for(i=0; i < NUMVALUES; i++)
	{
		printf("%d : %d\n",i,randomValues[i]);
	}
	
	int checkValue=38;
	int foundIndex=binaryChop(checkValue,-1,-1);
	if(foundIndex>=0)
	{
		printf("\n\n\n%d found at index %d",checkValue,foundIndex);
	}
	else
	{
		printf("\n\n\nIndex not found for %d!",checkValue);
	}
	
	return 0;
}

int binaryChop(int number,int index,int offset)
{
	if(index==-1)
	{
		index=NUMVALUES/2;
		offset=NUMVALUES/2;
	}
	
	if(offset > 1)
	{
		offset/=2;
	}
	printf("%d => %d : %d\n",number,index,randomValues[index]);
	if(randomValues[index]==number)
	{
		return index;
	}
	else if(index==0 || index==NUMVALUES-1 
			|| (randomValues[index-1] < number && randomValues[index] > number))
	{
		return -1; //Indicates value not found
	}
	//Number is smaller
	else if(randomValues[index] > number)
	{
		index-=offset;
		binaryChop(number,index,offset);
	}
	//Number is larger
	else if(randomValues[index] < number)
	{
		index+=offset;
		binaryChop(number,index,offset);
	}
}