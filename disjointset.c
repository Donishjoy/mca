#include<stdio.h>
#include<stdlib.h>
int p[10],el[10],i,j,ele,size,a=0,b=0,c=0,k,m,brep,r=0,crep;
void makeset(int m)
{
    p[m]=m;
}
int find(int a)
{
    for(i=0;i<size;i++)
    {
        if(el[i]==a)
        {
            return p[i];
        }
    }
}
void unionop(int b,int c)
{
    brep=find(b);
    crep=find(c);
    if(brep!=crep)
    {
        for(i=0;i<size;i++)
        {
            if(p[i]==crep)
            {
                p[i]=brep;
            }
        }
    }
}
void display()
{
    printf("\nDisjoint sets are\n");
    for(i=0;i<size;i++)
    {
        for(j=0;j<size;j++)
        {
            if(p[j]==i)
            {
                printf("%d-",el[j]);
            }
        }
        printf("\n");
    }
}
void main()
{
    int choice;
    printf("Enter the no of disjoint sets\n ");
    scanf("%d",&size);
    for(i=0;i<size;i++)
    {
        printf("Enter the %d disjoint set\n",i+1);
        scanf("%d",&el[i]);
        makeset(i);
    }
    printf(" disjoint sets are\n",i+1);
    for(i=0;i<size;i++)
    {
        printf("%d  ",el[i]);
    }
    while(1)
    {
        printf("\n1.Find\n2.Union\n3.Display\n4.Exit\n");
        scanf("%d",&choice);
        switch(choice)
        {
            case 1:
            printf("Enter the element\n");
            scanf("%d",&ele);
            printf("Parent of %d is %d",ele,find(ele));
            break;
            case 2:
            printf("Enter two disjoint sets for union operation\n");
            scanf("%d%d",&b,&c);
            unionop(b,c);
            break;
            case 3:
            display();
            break;
            case 4:
            exit(0);
            break;
            default:
            printf("Invalid choice");
        }
    }
}
