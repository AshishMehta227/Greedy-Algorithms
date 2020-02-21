#include<stdio.h>
#include<stdlib.h>
void swap(float *a, float *b)
{
    float temp=*a;
    *a=*b;
    *b=temp;
}
void read(float *V, float *A, int n)
{
    printf("Enter the values of the items respectively\n");
    for(int i=0;i<n;i++){
        scanf("%f",&V[i]);
    }
    printf("Enter the weights of the items respectively\n");
    for(int i=0;i<n;i++){
        scanf("%f",&A[i]);
    }
}
void print(float *V, float *A, int n)
{
    printf("V = ");
    for(int i=0;i<n;i++)
    {
        printf(" %f ",V[i]);
    }
    printf("\n");
    printf("W = ");
    for(int i=0;i<n;i++)
    {
        printf(" %f ",A[i]);
    }
    printf("\n");
}
void sort(float *a,float *V, float *A, int n)
{
    int i,j;
    for(i=0;i<n;i++){
        for(j=i+1;j<n;j++){
            if(a[i]<a[j]){
                swap(&a[i],&a[j]);
                swap(&V[i],&V[j]);
                swap(&A[i],&A[j]);
            }
        }
    }
    for(i=0;i<n;i++)
        printf("%f\n",V[i]);
    for(i=0;i<n;i++)
        printf("%f\n",A[i]);
}
float Knapsack(float *V, float *A, float *R, int n, int W)
{
    int i=0;
    float vv=0,ww=0,y;
    while(ww<(float)W && i<=n)
    {
        if(A[i]<=(W-ww))
            vv+=V[i];
        else
        {
            y=(W-ww)/A[i];
            vv+=V[i]*y;
        }
        ww+=A[i];
        i++;
    }
    return vv;
}
int main()
{
    int i,n,W;
    float *R,*V,*A,res;

    printf("Enter the number of items n\n");
    scanf("%d",&n);

    printf("Enter the total weight allowed\n");
    scanf("%d",&W);

    V=malloc(n*sizeof(float));
    A=malloc(n*sizeof(float));
    R=malloc(n*sizeof(float));
    read(V,A,n);
    print(V,A,n);

    printf("Enter 0 to change values, 1 to continue\n");
    scanf("%d",&i);
    if(i==0)
        read(V,A,n);
    for(i=0;i<n;i++)
        R[i]=V[i]/A[i];
    sort(R,V,A,n);
    for(i=0;i<n;i++)
        printf("%f\n",R[i]);
    res=Knapsack(V,A,R,n,W);
    printf("The total value is %f\n",res);
    return 0;
}
