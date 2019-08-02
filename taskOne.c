//this is solution to display those array elements which contains at least two
//distinct elements which are greater than the themselves.
//Array could contain duplicate elements
//ex.
//2,1,4,5,8
//output-1,2,4

#include<stdio.h>
#include<stdlib.h>

//merge function for merge sort
void merge(int a[],int low,int mid,int high)
{
        int i=low;
        int k=mid+1,l=0;
        int temp[high-low+1];
        while(i<=mid && k<=high)
        {
                if(a[i]<=a[k])
                {

                        temp[l++]=a[i++];
          	}	  else
                {
                        temp[l++]=a[k++];
              
                }
        }
	 while(i<=mid)
                {
                        temp[l++]=a[i++];

                }
                while(k<=high)
                        temp[l++]=a[k++];

                for(int g=low,l=0;g<=high;g++,l++)
                {
                        a[g]=temp[l];

                }


}

//insertin sort function

void insertion_sort(int a[],int low,int high)
{
	int element;
	int i,j;
	for(i=low+1;i<=high;i++)
	{
	element=a[i];
	for(j=i-1;j>=low;j--)
	{
		if(element<a[j])
		{
		  a[j+1]=a[j];
		}
		else break;	
	}
		a[j+1]=element;
	}
	

}

//mergesort function to which act as tim sort
//for low no of elements it use insertion sort instead of merge
void mergesort(int a[],int l,int r)
{
        
	int m;
	m=((l+r)/2);
	if(r-l+1>4)
	{
		//printf("Merge\t");
                mergesort(a,l,m);
                mergesort(a,m+1,r);
                merge(a,l,m,r);
	}
	else
	{
		//printf("Insertion \t");
		insertion_sort(a,l,r);
	}
	
}
void main()
{
	int eleNoInt,iterInt;
	int point1Int,point2Int;

	printf("Enter no of element-");
	scanf("%d",&eleNoInt);
	int arrayInt[eleNoInt];

//accpeting array elements from user
	printf("Enter the elements\n");
	for(iterInt = 0; iterInt < eleNoInt; iterInt++)	
	{
		scanf("%d",&arrayInt[iterInt]);
	}

//applying the merger sort function on array 
	mergesort(arrayInt,0,eleNoInt - 1);
	printf("Output-");

//Actual logic
	if(eleNoInt > 2)
	{
		point1Int = eleNoInt - 2;
		point2Int = eleNoInt - 1;
		for(iterInt = 0; iterInt < eleNoInt - 2; iterInt++)
		{
//cheking the intended element and the second last element
//iterInt start from 0 and point1 and point2 start from ending of array

			if(arrayInt[iterInt] == arrayInt[point1Int])
			
				break;
//checking for duplicates
			else if(iterInt != 0 && arrayInt[iterInt] == arrayInt[iterInt-1])
			{continue;}
			else
			{
//iterating until two elements greater than intended element
				while(1)
				{
					if(arrayInt[iterInt] < arrayInt[point2Int] && arrayInt[iterInt] < arrayInt[point1Int] && arrayInt[point1Int] != arrayInt[point2Int])
					{
						printf("%d,",arrayInt[iterInt]);
						break;
					}
					else if(arrayInt[iterInt] < arrayInt[point2Int] && arrayInt[iterInt] < arrayInt[point1Int] && arrayInt[point1Int] == arrayInt[point2Int])
					{
						point1Int--;
					}
					else if(arrayInt[point1Int] == arrayInt[iterInt]){exit(0);}

				}
			}
		}	
	}
}
