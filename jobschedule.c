#include<stdio.h>
void main()
{
    int n,i,temp,ascii=65,j;
    printf("Enter number of jobs to schedule:");
    scanf("%d",&n);
    int profit[n],deadline[n];
    char job[n],temp1;
    for(i=0;i<n;i++)
        job[i]=ascii++;
    for(i=0;i<n;i++)
    {
        printf("Enter profit and its deadline for job %c:",job[i]);
        scanf("%d%d",&profit[i],&deadline[i]);
    }

    for(i=0;i<n;i++)
        for(j=i+1;j<n;j++)
            if(profit[i]<profit[j])
            {
                temp=profit[i];
                profit[i]=profit[j];
                profit[j]=temp;

                temp=deadline[i];
                deadline[i]=deadline[j];
                deadline[j]=temp;

                temp1=job[i];
                job[i]=job[j];
                job[j]=temp1;
            }
    int max=0,prof=0;
    for(i=0;i<n;i++)
    {
        if(deadline[i]>max)
            max=deadline[i];
    }
    int job_sch[max];
	for(i=0;i<max;i++)
		job_sch[i]=-1;
    for(i=0;i<n;i++)
    {
            j=deadline[i]-1;
            while(job_sch[j]!=-1 && j>=0)
                j--;
            if(job_sch[j]==-1)
	{
                job_sch[j]=i;
		prof=prof+profit[i];
	}
   }
    printf("After job scheduling:\n");
    for(i=0;i<max;i++)
        printf("%c\t",job[job_sch[i]]);
    printf("\nTotal Profit:%d\n",prof);
}
