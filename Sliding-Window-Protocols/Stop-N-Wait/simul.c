#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
int main()
{
int i,j,noframes,x,x1=10,x2;
printf("Enter number of frames: ");
scanf("%d",&noframes);
while(noframes>0)
{
    printf("\nSending frame %d",i);
    srand(x1++); 
    x = rand()%10;
    if(x%2 == 0)
    {
        for (x2=1; x2<2; x2++)
        {
            printf("\nWaiting for %d seconds\n", x2);
            sleep(x2);
            printf("Missing Acknowledgement %d",i);
        }
        printf("\nSending frame %d",i);
        srand(x1++);
        x = rand()%10;
    }
    printf("\nACK received for frame %d",j);
    noframes-=1;
    i++;
    j++;
}
printf("\nEnd of stop and wait protocol\n");
return 0;
}