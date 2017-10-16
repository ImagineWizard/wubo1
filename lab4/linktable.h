#ifndef _LINK_TABLE_H_
#define _LINK_TABLE_H_
#include <pthread.h>
#define  SUCCESS 0
#define  FAILURE (-1)

typedef struct LinkTableNode
{
    struct LinkTableNode *pNext;
}tLinkTableNode;

typedef struct LinkTable
{
    tLinkTableNode * pHead;
    tLinkTableNode * pTail;
    int            SumOfNode;
}tLinkTable;

tLinkTable * CreateLinkTable();
int DelLinkTable(tLinkTable* pLinkTable);
int AddLinkTable(tLinkTable* pLinkTable,tLinkTableNode *pNode);
int DelLinkTableNode(tLinkTable* pLinkTable,tLinkTableNode *pNode);
tLinkTableNode * GetLinkTableHead(tLinkTable *pLinkTable);
tLinkTableNode * GetNextLinkTableNode(tLinkTable* pLinkTable,tLinkTableNode *pNode);
#endif
