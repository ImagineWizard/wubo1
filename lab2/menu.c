#include <stdio.h>
#include <stdlib.h>
void help();
void quit();
void introduce();
void area();
void average();
void add();
void minus();
void division();
int main()
{
    char cmd[100];
    printf("input help to know the function:\n");
    while(1)
    {
	scanf("%s",cmd);
        if(strcmp(cmd,"help") == 0)
        {
       	    help();
        }
        else if(strcmp(cmd,"quit") == 0)
        {
	    quit();
        } 
        else if(strcmp(cmd,"introduce") == 0)
        {
	    introduce();
        }
        else if(strcmp(cmd,"area") == 0)
        {
	    area();
        }
        else if(strcmp(cmd,"average") == 0)
        {
	    average();
        }
        else if(strcmp(cmd,"add") == 0)
        {
	    add();
        }
        else if(strcmp(cmd,"minus") == 0)
        {
	    minus();
        }
        else if(strcmp(cmd,"division") == 0)
        {
	    division();
        }
        else
        {
	    printf("Error command!\n");
        }
  }
  return 0;
}
void help()
{
    printf("----COMMAND---------FUNCTION-----\n");
    printf("----------------------------------\n");
    printf("----quit------------exit this menu\n");
    printf("----introduce-------introduce myself\n");
    printf("----average---------show the average of 2 num\n");
    printf("----add-------------show the sum of 2 num\n");
    printf("----minus-----------show the result 1st num minus 2nd num\n");
    printf("----area------------show the area of a circle\n");
    printf("----division-------------show the result 1st num / 2nd num\n");
}
void quit()
{
    exit(0);
}
void introduce()
{
    printf("My name is WuBo.My studentID is SA17225395\n");
}
void area()
{
    printf("please input r of a circle:\n");
    double r,s;
    scanf("%lf",&r);
    s = r * r * 3.14159;
    printf("the area of the circle is :%lf \n",s);
}
void average()
{
    printf("please input 2 num:\n");
    double a,b,c;
    scanf("%lf %lf",&a,&b);
    c = (a + b) / 2;
    printf("the average of 2 num is:%lf \n",c);
}
void add()
{
    printf("please input 2 num:\n");
    double a,b,c;
    scanf("%lf %lf",&a,&b);
    c = a + b;
    printf("the sum is :%lf \n",c);
}
void minus()
{
    printf("please input 2 num:\n");
    double a,b,c;
    scanf("%lf %lf",&a,&b);
    c = a - b;
    printf("1st - 2nd = %lf \n",c);
}
void division()
{
    printf("please input 2 num:\n");
    double a,b,c;
    scanf("%lf %lf",&a,&b);
    c = a / b;
    printf("1st / 2nd = %lf \n",c);
}
