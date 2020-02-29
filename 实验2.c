#include<stdio.h>
#include<stdlib.h>
#include<malloc.h>

#define TRUE 1
#define OK 1
#define FALSE 0
#define ERROR 0
#define INFEASIBLE -1
#define OVERFLOW -2

typedef int status;    ///返回状态类型定义
typedef int ElemType;  ///数据元素类型定义

typedef struct Node
{
    ElemType data;     ///data为抽象元素类型
    struct Node *next; ///next为指针类型
} Node, *Linklist;

status IntiaList(Linklist *L);                                ///构造空表L
status DestroyList(Linklist *L);                              ///销毁单链表
status ClearList(Linklist *L);                                ///置L为空表
status ListEmpty(Linklist L);                                 ///判断L是否为空表
int ListLength(Linklist L);                                   ///求表L的长度
status GetElem(Linklist L,int i,ElemType *e);                 ///取元素i,由e返回i
status LocateElem(Linklist L,ElemType e);                     ///查找符合条件的元素
status PriorElem(Linklist L,ElemType cur,ElemType *pre_e);    ///获得cur的前驱
status NextElem(Linklist L,ElemType cur,ElemType *next_e);    ///获得cur的后继
status ListInsert(Linklist *L,int i,ElemType e);              ///元素ai之前插入新元素e
status ListDelete(Linklist *L,int i,ElemType *e);             ///删除第i个元素
status ListTrabverse(Linklist L);                             ///遍历表,对L的每个数据元素调用函数
status ReadFile(Linklist L, char *filename);                 ///读文件
status WriteFile(Linklist L, char *filename);                 ///写文件

int main(void)
{
    char filename[30];
    int op=1,i=0,j=0,num,k=0;
    ElemType e,cur;
    ElemType pre_e,next_e;
    printf("使用几组线性表：");
    scanf("%d",&num);
    Linklist L[num];
    for(j=0;j<num;j++)
    {
        L[j] = NULL;
    }
    printf("现在使用第几组表：");
    while(scanf("%d",&j)!=EOF)
    {
        if(j<=0 || j>num){
            printf("无法获取这个表，请重新输入！\n");
            printf("现在使用第几组表：");
            continue;
        }
        j--;
        while(op)
        {
            system("cls");
            printf("\n\n");
            printf("      Menu for Linear Table On Sequence Structure \n");
            printf("-------------------------------------------------\n");
            printf("    	  1. IntiaList       8. PriorElem\n");
            printf("    	  2. DestroyList     9. NextElem\n");
            printf("    	  3. ClearList       10. ListInsert\n");
            printf("    	  4. ListEmpty       11. ListDelete\n");
            printf("    	  5. ListLength      12. ListTrabverse\n");
            printf("    	  6. GetElem         13. ReadFile\n");
            printf("    	  7. LocateElem      14. WriteFile\n");
            printf("    	  0. Exit\n");
            printf("-------------------------------------------------\n");
            printf("    请选择你的操作[0~14]:");
            if(scanf("%d",&op)==0)
            {
                break;    ///异常输入，直接退出
            }
            switch(op)
            {
            case 1:
                //printf("\n----IntiaList功能待实现！\n");
                if(IntiaList(&L[j])==OK) printf("单链表创建成功！\n");
                else printf("单链表创建失败！\n");
                system("pause");
                //或者： printf("输入任意键继续。。。");  getch();
                break;
            case 2:
                if(DestroyList(&L[j])==OK) printf("单链表销毁成功！\n");
                else printf("单链表销毁失败！\n");
                //printf("\n----DestroyList功能待实现！\n");
                system("pause");
                break;
            case 3:
                if(ClearList(&L[j])==OK) printf("单链表清空成功！\n");
                else printf("单链表清空失败！\n");
                //printf("\n----ClearList功能待实现！\n");
                system("pause");
                break;
            case 4:
                k=ListEmpty(L[j]);
                if(k==TRUE) printf("L为空表！\n");
                else if(k==FALSE) printf("L不为空表！\n");
                else if(k==-1);
                system("pause");
                break;
            case 5:
                if(ListLength(L[j])==-1) ;
                else printf("单链表长度为%d\n",ListLength(L[j]));
                //printf("\n----ListLength功能待实现！\n");
                system("pause");
                break;
            case 6:
                printf("请输入要取出第几个元素i:");
                scanf("%d",&i);
                if(GetElem(L[j],i,&e) == OK) printf("取出的元素是 %d\n", e);
                else printf("取出元素失败！\n");
                //printf("\n----GetElem功能待实现！\n");
                system("pause");
                break;
            case 7:
                printf("请输入要寻找的元素：");
                scanf("%d",&e);
                if((i = LocateElem(L[j],e))== -1)   printf("该表不存在");
                else if(i != 0) printf("查找到符合的元素，它是第%d个元素\n", i);
                else printf("未找到符合的元素！\n");
                //printf("\n----LocateElem功能待实现！\n");
                system("pause");
                break;
            case 8:
                printf("请输入指定的元素：");
                scanf("%d",&cur);
                if(PriorElem(L[j],cur,&pre_e)==TRUE) printf("获得L的前驱为 %d！\n",pre_e);
                else printf("获取L的前驱失败\n");
                //printf("\n----PriorElem功能待实现！\n");
                system("pause");
                break;
            case 9:
                printf("请输入指定的元素：");
                scanf("%d",&cur);
                if(NextElem(L[j],cur,&next_e)==TRUE) printf("获得L的后继为 %d！\n",next_e);
                else printf("获取L的后继失败\n");
                //printf("\n----NextElem功能待实现！\n");
                system("pause");
                break;
            case 10:
                printf("请输入指定是第几个元素之前以及插入的是什么元素：");
                scanf("%d%d",&i,&e);
                if(ListInsert(&L[j],i,e) == OK) printf("插入成功\n");
                else printf("插入失败！\n");
                //printf("\n----ListInsert功能待实现！\n");
                system("pause");
                break;
            case 11:
                printf("请输入指定是第几个元素：");
                scanf("%d",&i);
                if(ListDelete(&L[j],i,&e) == OK) printf("删除元素%d成功,\n",e);
                else printf("删除失败！\n");
                //printf("\n----ListDelete功能待实现！\n");
                system("pause");
                break;
            case 12:
                //printf("\n----ListTrabverse功能待实现！\n");
                ListTrabverse(L[j]);
                system("pause");
                break;
            case 13:
                printf("请输入新文件目录：");
                scanf("%s",filename);
                if(ReadFile(L[j], filename) == OK) printf("读入文件成功！");
                else printf("读入文件失败!");
                system("pause");
                break;
            case 14:
                printf("请输入新文件目录：");
                scanf("%s",filename);
                if(WriteFile(L[j], filename) == OK) printf("写入文件成功！");
                else printf("写入文件失败!");
                system("pause");
                break;
            case 0:
                break;
            }//end of switch
        }//end of while
        op=1;
        printf("现在使用第几组表：(按ctrl+z退出系统)");
    }
    printf("欢迎下次再使用本系统！\n");
    system("pause");
    return 0;
}//end of main()

/*--------page 23 on textbook --------------------*/
status IntiaList(Linklist *L)            ///构造带头结点的空表L
{
    *L = (Node *)malloc(sizeof(Node));   ///创建一个头结点
    if(*L == NULL)  exit(OVERFLOW);             ///存储空间失败
    (*L)->data = 0;                        ///初始长度为0
    (*L)->next = NULL;                     ///将next设置为NULL
    return OK;
}

status DestroyList(Linklist *L)  ///销毁单链表
{
    if(*L == NULL){
         printf("该表不存在");
         return FALSE;
    }
    Linklist p,q;
    p = *L;
    while(p)
    {
        q = p->next;
        free(p);
        p = q;
    }
    *L = NULL;
    return OK;
}

status ClearList(Linklist *L)///置L为空表
{
    if(*L == NULL){
         printf("该表不存在");
         return FALSE;
    }
    Linklist p,q;
    p = (*L)->next;
    while(p)
    {
        q = p->next;
        free(p);
        p = q;
    }
    (*L)->data = 0;
    (*L)->next = NULL;
    return OK;
}

status ListEmpty(Linklist L)///判断L是否为空表
{
    if(L == NULL){
         printf("该表不存在");
         return -1;
    }
    if(L->data == 0)
        return TRUE;
    else
        return FALSE;
}

int ListLength(Linklist L)///求表L的长度
{
    if(L == NULL){
         printf("该表不存在");
         return -1;
    }
    return L->data;
}

status GetElem(Linklist L, int i, ElemType *e)///取元素i,由e返回i
{
    int j = 0;
    if(L == NULL){
         printf("该表不存在");
         return FALSE;
    }
    Linklist p=L;
    if(i < 0 || i > L->data)   ///是否为超出下标范围
        return ERROR;
    else{
        for(;j<i;j++)
        {
            p = p->next;
        }
        *e = p->data;
    }
    return OK;
}

status LocateElem(Linklist L,ElemType e) ///查找符合条件的元素
{
    if(L == NULL) return -1;
    Linklist p=L->next;
    int i = 1;
    for(; i <= L->data; i++)
    {
        if(p->data == e)
            return i;
        p = p->next;
    }
    return FALSE;

}

status PriorElem(Linklist L,ElemType cur,ElemType *pre_e) ///获得cur的前驱
{
    if(L == NULL){
         printf("该表不存在");
         return FALSE;
    }
    Linklist p = L->next,q = p;
    int i = 1;
    for(; i < L->data; i++)
    {
        p = p->next;
        if(p->data == cur)
        {
            *pre_e = q->data;
            return TRUE;
        }
        q = q->next;
    }
    return FALSE;
}

status NextElem(Linklist L,ElemType cur,ElemType *next_e)///获得cur的后继
{
    if(L == NULL){
         printf("该表不存在");
         return FALSE;
    }
    Linklist p = L->next,q = p;
    int i = 0;
    for(; i < L->data-1; i++)
    {
        p = p->next;
        if(q->data == cur)
        {
            *next_e = p->data;
            return TRUE;
        }
        q = q->next;
    }
    return FALSE;
}

status ListInsert(Linklist *L,int i,ElemType e)///第i个元素之前插入新元素e
{
    if(*L == NULL){
         printf("该表不存在");
         return FALSE;
    }
    int j = 1;
    if(i <= 0 || i > ((*L)->data+1))       ///是否为超出下标范围
        return ERROR;
    Linklist p = (*L),s;
    for(;j<i;j++)
    {
        p = p->next;
    }
    s=(Linklist)malloc(sizeof(Node));
    s->data = e;
    if(p->next != NULL){
        s->next = p->next;
        p->next = s;
    }
    else{
        p->next = s;
        s->next = NULL;
    }
    (*L)->data++;
    return OK;
}
status ListDelete(Linklist *L,int i,ElemType *e)///删除第i个元素
{
    int j = 0;
    if(*L == NULL){
         printf("该表不存在");
         return FALSE;
    }
    if(i <= 0 || i > (*L)->data)    ///是否为超出下标范围
        return ERROR;
    Linklist p = (*L),q;
    while(p->next && j<i-1){
        p = p->next;
        ++j;
    }
    if(!(p->next) ||j > i - 1) return ERROR;
    q = p->next;
    p->next = q->next;
    *e = q->data;
    free(q);
    (*L)->data--;
    return OK;
}

status ListTrabverse(Linklist L) ///遍历表,对L的每个数据元素调用函数
{
    if(L == NULL){
         printf("该表不存在");
         return FALSE;
    }
    Linklist p = L->next;
    int i = 0;
    if(L->data != 0) printf("以下为遍历结果:\n");
    else printf("该单链表为空表\n");
    for(; i < L->data; i++)
    {
        printf("%d\n",p->data);
        p=p->next;
    }
    return OK;
}

status ReadFile(Linklist L, char *filename) ///读文件
{
    if(L == NULL){
         printf("该表不存在");
         return FALSE;
    }
    Linklist p=L,s=NULL;
    FILE *fp;
    //int t;
    L->data=0;
    if ((fp=fopen(filename,"rb"))==NULL)   ///打开文件失败
    {
        printf("File open error!\n ");
        return FALSE;
    }
    int a=0;
    fseek(fp,0L,SEEK_SET);
    while(fread(&a,sizeof(ElemType),1,fp)){
        s=(Linklist)malloc(sizeof(Node));
        s->data = a;
        p->next=s;
        p=s;
        p->next = NULL;
        L->data++;
    }
    ///这里从文件中逐个读取数据元素恢复单链表，对于不同的物理结构，可通过读
    ///取的数据元素恢复内存中的物理结构。
    fclose(fp);  ///关闭文件
    return OK;
}

status WriteFile(Linklist L, char *filename) ///写文件
{
    if(L == NULL){
         printf("该表不存在");
         return FALSE;
    }
    Linklist p = L->next;
    int i = 0;
    FILE  *fp;
    if((fp=fopen(filename,"wb"))==NULL)        ///打开文件失败
    {
        printf("File open error\n ");
        return FALSE;
    }
    int a;
	fseek(fp,0L,SEEK_SET);
	while(p!=NULL){
		a=p->data;
		fwrite(&a,sizeof(int),1,fp);
		p=p->next;
	}
    ///这里是1次性写入，对于其它物理结构，可通过遍历，逐个访问数据元素
    ///并写入到文件中
    fclose(fp); ///储存并关闭文件
    return OK;
}
