#include <stdio.h>
#include <stdlib.h>

typedef enum {false,true} bool;

int main()
{
	int i,random;
	int currValue=0;
	int numValues=100;
	int randomValues[numValues];
	srand(time(NULL));
	for(i=0; i < numValues; i++)
	{
		random=rand()%5+1;
		currValue+=random;
		randomValues[i]=currValue;
	}
	
	for(i=0; i < numValues; i++)
	{
		printf("%d : %d\n",i,randomValues[i]);
	}
	
	int checkValue=38;
	int foundIndex=binaryChop(randomValues,numValues,checkValue);
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

int binaryChop(int values[],int numValues,int number)
{
	bool done=false;
	int foundIndex=-1;
	int currIndex=numValues/2;
	int offset=numValues/2;
	
	while(done==false)
	{
		printf("%d => %d : %d\n",number,currIndex,values[currIndex]);
		if(values[currIndex] == number)
		{
			foundIndex=currIndex;
			break;
		}
		else if(currIndex==0 || currIndex==numValues-1 
			|| (values[currIndex-1] < number && values[currIndex] > number))
		{
			break;
		}
		//Go higher
		else if(values[currIndex] < number)
		{
			//Go to middle position between the current position and the current position plus offset
			if(offset>1)
			{
				offset/=2; //Cut offset by 2
			}
			currIndex+=offset;
		}
		//Go lower
		else if(values[currIndex] > number)
		{
			//Go to middle position between current position minus offset and current position
			if(offset>1)
			{
				offset/=2;
			}
			currIndex-=offset;
		}
		
	}
	
	return foundIndex;
}