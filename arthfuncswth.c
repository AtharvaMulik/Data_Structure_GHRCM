#include <stdio.h>

void main()
{
    int a,b,ch;
    char s;
    printf("\nEnter Two Values:");
    scanf("%d%d",&a,&b);
    do
    {
        printf("\n1.Addition\n2.Subtraction\n3.Multiplication\n4.Division\n");
        printf("\nEnter your choice:");
        scanf("%d",&ch);
        switch(ch)
        {
        case 1:
             add(a,b);
             break;
        case 2:
            sub(a,b);
            break;
        case 3:
            mult(a,b);
            break;
        case 4:
            div(a,b);
            break;
        default:
            printf("Enter Correct Choice!!!!!");
            break;

        }
        printf("Do You Want To Continue?");
        scanf("%s",&s);
    }while(s=='y'||s=='Y');
    getch();
}
add(int x,int y)
{
    int z;
    z=x+y;
    printf("Addition:%d\n",z);
    return 0;
}
sub(int x,int y)
{
    int z;
    z=x-y;
    printf("Substraction:%d\n",z);
    return 0;
}
mult(int x,int y)
{
    int z;
    z=x*y;
    printf("Multiplication:%d\n",z);
    return 0;
}
div(int x,int y)
{
    int z;
    z=x/y;
    printf("Division:%d\n",z);
    return 0;
}
