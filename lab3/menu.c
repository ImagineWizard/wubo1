#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "linklist.h"
int help();
int quit();
int introduce();
int area();
int average();
int add();
int minus();
int division();
#define MAX_LEN 128
static tDataNode head[]=
{
    {"help","this is help cmd.",help,&head[1]},
    {"quit","exit this menu",quit,&head[2]},
    {"introduce","introduce myself",introduce,&head[3]},
    {"area","show the area of a circle",area,&head[4]},
    {"average","show the average of 2 num",average,&head[5]},
    {"add","show the sum of 10 num",add,&head[6]},
    {"minus","show the result 1st num - 2nd num",minus,&head[7]},
    {"division","show the result 1st num / 2nd num",division,NULL},
};
int main ()
{
    while(1)
    {
        char cmd[MAX_LEN];
        tDataNode *p;
        printf("please input the cmd\n");
        scanf("%s",cmd);
        p = FindCmd(head,cmd);
        if(p == NULL)
        {
            printf("this is a wrong cmd\n");
            continue;
        }
        if(p->hander!=NULL)
        {
            p->hander();    
        }
    }
    return 0;
};
int help()
{
    ShowAllCmd(head);
    return 0;
}
int quit()
{
    exit(0);
    return 0;
}
int introduce()
{
    printf("My name is WuBo.My studentID is SA17225395\n");
    return 0;
};
int area()
{
    double r,s;
    printf("please input r of a circle:\n");
    scanf("%lf",&r);
    s = r * r * 3.14159;
    printf("the area of the circle is %lf\n",s);
    return 0;
};
int average()
{
    int a[10];
    printf("please input ten numbers\n");
    int i=0,tol=0;
    for(i=0;i<10;i++){
        scanf("%d",&a[i]);
    };
    for(i=0;i<10;i++)
    {
        tol+=a[i];
    };
    printf("The average is %d",tol/10);
    return 0;
};
int add()
{
    double a,b,c;
    printf("please input 2 numbers:\n");
    scanf("%lf %lf",&a,&b);
    c = a + b;
    printf("the sum is %lf\n",c);
    return 0;
};
int minus()
{
    double a,b,c;
    printf("please input 2 numbers:\n");
    scanf("%lf %lf",&a,&b);
    c = a - b;
    printf("the sum is %lf\n",c);
    return 0;
};
int division()
{
    double a,b,c;
    printf("please input 2 numbers:\n");
    scanf("%lf %lf",&a,&b);
    c = a / b;
    printf("the sum is %lf\n",c);
    return 0;
};
