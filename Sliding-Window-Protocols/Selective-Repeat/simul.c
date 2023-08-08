#include<stdio.h>
#include<stdlib.h>
int input(int a[],int frame_size)
{
    printf("\nInput\n");
    for(int i=1;i<=frame_size;i++)
    {
        printf("Enter Value For Frame[%d]: ",i);
        scanf("%d",&a[i]);
    }
    return 1;
}
int display(int a[],int frame_size)
{
    printf("\nDisplay\n");
    for(int i = 1 ; i <= frame_size ; i++)
    {
        printf("Frame[%d]: %d" , i , a[i]);
        printf("\n");
    }
    printf("\n");
    return 1;
}
int selective_repeat(int frames[],int window_size,int frame_size)
{
    int nt=0;
    int k=0;
    int left[10000]={-1};
    int i ;
    for(i=1;i<=frame_size;i++)
    {
        int flag=rand()%2;
        if(flag)
        {
            printf("Frame[%d] with value %d Acknowledged!!!\n",i,frames[i]);
            nt++;
        }
        else
        {
            printf("Frame[%d] with value %d Not Acknowledged!!!\n",i,frames[i]);
            left[k++]=frames[i];
            nt++;
        }
        if(i%window_size==0)
        {
            for(int x = 0 ; x < k ; x++)
            {
                printf("Frame[%d] with value %d Retransmitted\n",x,left[x]);
                nt++;
                printf("Frame[%d] with value %d Acknowledged on Second Attempt\n",x,left[x]);
            }
            k=0;
        }
    }
    for(i=0;i<k;i++)
    {
        printf("Frame[%d] with value %d Retransmitted\n",i,left[i]);
        nt++;
        printf("Frame[%d] with value %d Acknowledged on Second Attempt\n",i,left[i]);
    }
    printf("Total Transmissions:%d \n", nt);
    return 0;
}
int main()
{
    int frames[50];
    int window_size;
    int frame_size;
    printf("Enter Window Size: ");
    scanf("%d",&window_size);
    printf("Enter Number Of Frames To Be Transmitted: ");
    scanf("%d",&frame_size);
    input(frames,frame_size);
    display(frames,frame_size);
    selective_repeat(frames,window_size,frame_size);
    return 0;
}