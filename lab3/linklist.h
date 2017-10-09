#ifndef _LINKLIST_H_
#define _LINKLIST_H_
typedef struct DataNode
{
    char *cmd;
    char *desc;
    int (*hander)();
    struct DataNode *next;
}tDataNode;
tDataNode *FindCmd(tDataNode *head,char *cmd);
int ShowAllCmd(tDataNode *head);
#endif
