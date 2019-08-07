//First come first serve cpu scheduling algorithm

#include<stdio.h>
struct process
{
	int pno,bTime,aTime,wTime,taTime,cTime;
};
typedef struct process job;
void calTime(job proArray[],int num)
{
        int cT=0,i;
        int sumTat=0,sumWt=0;
        printf("Process Burst Arrival Completion TurnedAround Waiting\n");
        for (i=0;i<num;i++)
        {
                proArray[i].cTime = cT + proArray[i].bTime;
		cT=proArray[i].cTime;
                proArray[i].taTime = proArray[i].cTime - proArray[i].aTime;
                proArray[i].wTime = proArray[i].taTime - proArray[i].bTime;
                sumTat=sumTat + proArray[i].taTime;
                sumWt=sumWt + proArray[i].wTime;
		printf("\n%d  \t%d  \t%d  \t%d  \t\t%d  \t%d",proArray[i].pno,proArray[i].bTime,proArray[i].aTime,proArray[i].cTime,proArray[i].taTime,proArray[i].wTime);

        }
        printf("\nAverage TAT=%f\nAverage Wait Time=%f\n",(float)sumTat/num,(float)sumWt/num);

}

void main()
{
	int num,loop;
	printf("Enter how many process-");
	scanf("%d",&num);
	job proArray[num];
	printf("\nEnter process No,Burst time,Arrival time like 1 2 0 then press 'Enter'\n");
	for(loop=0;loop<num;loop++)
	{
		scanf("%d%d%d",&proArray[loop].pno,&proArray[loop].bTime,&proArray[loop].aTime);
	
	}
	calTime(proArray,num);	


}
