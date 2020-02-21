#include<stdio.h>
void main()
{
        int n;
        printf("Enter total number of activities=");
        scanf("%d",&n);
        int sel[n][3],a[n];

        for(int i=0;i<n;i++)
        {
                scanf("%d",&sel[i][0]);
                scanf("%d",&sel[i][1]);
                sel[i][2]=i+1;
        }

        printf("Before Sorting=\n");
        for (int i = 0; i < n; ++i)
        {
                printf("%d\t", sel[i][0]);
                printf("%d\t", sel[i][1]);
                printf("%d\t", sel[i][2]);
                printf("\n");
        }

        for(int step=0;step<n-1;++step)
                for(int i=0;i<n-step-1;++i)
                        if(sel[i][1]>sel[i+1][1])
                        {
                                int temp=sel[i][0];
                                sel[i][0]=sel[i+1][0];
                                sel[i+1][0]=temp;

                                temp=sel[i][1];
                                sel[i][1]=sel[i+1][1];
                                sel[i+1][1]=temp;
                        }

        printf("After Sorting=\n");
        for (int i = 0; i < n; ++i)
        {
                printf("%d\t", sel[i][0]);
                printf("%d\t", sel[i][1]);
                printf("%d\t", sel[i][2]);
                printf("\n");
        }

        a[0]=sel[0][2];
        int temp=0,flag=1;
        for(int i=1;i<n;i++)
        {
                if(sel[i][0]>=sel[temp][1])
                {
                        a[flag]=sel[i][2];
                        flag++;
                        temp=i;
                }
        }
        printf("Job schedule\n");
        for(int i=0;i<flag;i++)
        {
                printf("%d\t",a[i]);
        }
}
