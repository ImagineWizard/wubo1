#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <math.h>
#include "linktable.h"

#define CMD_MAX_LEN 128

int help();
int quit();
int introduce();
int area();
int average();
int add();
int minus();
int division();

typedef struct DataNode
{
    tLinkTableNode * pNext;
    char* cmd;
    char* desc;
    int (*handler)();
}tDataNode;

tDataNode * FindCmd(tLinkTable *head, char *cmd)
{
    tDataNode *pNode = (tDataNode*)GetLinkTableHead(head);
    while(pNode != NULL)
    {
        if(strcmp(pNode->cmd, cmd) == 0)
        {
            return pNode;
        }
        pNode = (tDataNode*)GetNextLinkTableNode(head, (tLinkTableNode*)pNode);
    }
    return NULL;
}

int ShowAllCmd(tLinkTable *head)
{
    tDataNode *pNode = (tDataNode*)GetLinkTableHead(head);
    while(pNode != NULL)
    {
        printf("%s ------------ %s\n", pNode->cmd, pNode->desc);
        pNode= (tDataNode*)GetNextLinkTableNode(head, (tLinkTableNode*)pNode);
    }
    return 0;
}

static tDataNode menu[] =
{
        {(tLinkTableNode*)&menu[1],"version", "menu 3.0",NULL},
        {(tLinkTableNode*)&menu[2],"help", "this is help cmd.",help},
        {(tLinkTableNode*)&menu[3],"minus","show the result 1st num - 2nd num",minus},
        {(tLinkTableNode*)&menu[4],"introduce","introduce myself",introduce},
        {(tLinkTableNode*)&menu[5],"area","show the area of a circle",area},
        {(tLinkTableNode*)&menu[6],"average","show the average of 2 num",average},
        {(tLinkTableNode*)&menu[7],"add","show the sum of 10 num",add},
        {(tLinkTableNode*)&menu[8],"division","show the result 1st num / 2nd num",division},
        {(tLinkTableNode*)NULL,"quit","exit this menu",quit}
};

int InitMenuData(tLinkTable **ppLinkTable)
{
    *ppLinkTable = CreateLinkTable();
    (*ppLinkTable)->pHead = (tLinkTableNode*)&menu[0];
    (*ppLinkTable)->pTail = (tLinkTableNode*)&menu[8];
}

tLinkTable *head = NULL;

int main()
{
    InitMenuData(&head);
    printf("input 'help' to know how to use this system.\n");
    while(1)
    {
        char cmd[CMD_MAX_LEN];
        printf("input cmd: >");
        scanf("%s", cmd);
        tDataNode *p = FindCmd(head, cmd);
        if(p == NULL)
        {
            printf("Wrong cmd!\n");
            continue;
        }
        if(p->handler != NULL)
        {
            p->handler();
        }
    }
}

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
