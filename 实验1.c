#include<stdio.h>
#include<stdlib.h>
#include<malloc.h>

#define LIST_INIT_SIZE 100
#define LISTINCREMENT 10

#define TRUE 1
#define OK 1
#define FALSE 0
#define ERROR 0
#define INFEASIBLE -1
#define OVERFLOW -2

typedef int status;    ///返回状态类型定义
typedef int ElemType;  ///数据元素类型定义

typedef struct         ///顺序表（顺序结构）的定义
{
    ElemType *elem;    ///存储空间基地址
    int length;        ///表长
    int listsize;      ///当前分配的存储容量

} SqList;

status IntiaList(SqList *L);                                ///构造空表L
status DestroyList(SqList *L);                              ///销毁线性表
status ClearList(SqList *L);                                ///置L为空表
status ListEmpty(SqList L);                                 ///判断L是否为空表
int ListLength(SqList L);                                   ///求表L的长度
status GetElem(SqList L,int i,ElemType *e);                 ///取元素i,由e返回i
status LocateElem(SqList L,ElemType e);                     ///查找符合条件的元素
status PriorElem(SqList L,ElemType cur,ElemType *pre_e);    ///获得cur的前驱
status NextElem(SqList L,ElemType cur,ElemType *next_e);    ///获得cur的后继
status ListInsert(SqList *L,int i,ElemType e);              ///元素ai之前插入新元素e
status ListDelete(SqList *L,int i,ElemType *e);             ///删除第i个元素
status ListTrabverse(SqList L);                             ///遍历表,对L的每个数据元素调用函数
status ReadFile(SqList *L, char *filename);                 ///读文件
status WriteFile(SqList L, char *filename);                 ///写文件

void main(void)
{
    char filename[30],ch;
    int op=1,i=0,j=0,num,k=0;
    ElemType e,cur;
    ElemType pre_e,next_e;
    printf("使用几组线性表：");
    scanf("%d",&num);
    SqList L[num];
    printf("现在使用第几组表：");
    for(j=0;j<num;j++)
        L[j].elem=NULL;
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
                if(IntiaList(&L[j])==OK) printf("线性表创建成功！\n");
                else printf("线性表创建失败！\n");
                system("pause");
                //或者： printf("输入任意键继续。。。");  getch();
                break;
            case 2:
                if(DestroyList(&L[j])==OK) printf("线性表销毁成功！\n");
                else printf("线性表销毁失败！\n");
                //printf("\n----DestroyList功能待实现！\n");
                system("pause");
                break;
            case 3:
                if(ClearList(&L[j])==OK) printf("线性表清空成功！\n");
                else printf("线性表清空失败！\n");
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
                else printf("线性表长度为%d\n",ListLength(L[j]));
                //printf("\n----ListLength功能待实现！\n");
                system("pause");
                break;
            case 6:
                printf("请输入要取出第几个元素i:");
                scanf("%d",&i);
                if(GetElem(L[j],i-1,&e) == OK) printf("取出的元素是 %d\n", e);
                else printf("取出元素失败！\n");
                //printf("\n----GetElem功能待实现！\n");
                system("pause");
                break;
            case 7:
                printf("请输入要寻找的元素：");
                scanf("%d",&e);
                if((L[j].length != 0) && (i = LocateElem(L[j],e))) printf("查找到符合的元素，它是第%d个元素\n", i+1);
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
                if(ListInsert(&L[j],i-1,e) == OK) printf("插入成功\n");
                else printf("插入失败！\n");
                //printf("\n----ListInsert功能待实现！\n");
                system("pause");
                break;
            case 11:
                printf("请输入指定是第几个元素：");
                scanf("%d",&i);
                if(ListDelete(&L[j],i-1,&e) == OK) printf("删除元素%d成功,\n",e);
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
                if(ReadFile(&L[j], filename) == OK) printf("读入文件成功！");
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
}//end of main()

/*--------page 23 on textbook --------------------*/
status IntiaList(SqList *L)    ///构造空表L
{
    L->elem = (ElemType *)malloc( LIST_INIT_SIZE * sizeof (ElemType));
    if(!L->elem) exit(OVERFLOW); ///存储空间失败
    L->length=0;      ///空表长度为0
    L->listsize=LIST_INIT_SIZE;  ///初始存储容量
    return OK;
}

status DestroyList(SqList *L)  ///销毁线性表
{
    if(!L->elem){
         printf("该表不存在");
         return FALSE;
    }
    free(L->elem);
    L->elem = NULL;
    L->length = L->listsize = 0;
    return OK;
}

status ClearList(SqList *L)///置L为空表
{
    if(!L->elem){
         printf("该表不存在");
         return FALSE;
    }
    L->length = 0;
    return OK;
}

status ListEmpty(SqList L)///判断L是否为空表
{
    if(!L.elem){
         printf("该表不存在");
         return -1;
    }
    if(L.length == 0)
        return TRUE;
    else
        return FALSE;
}

int ListLength(SqList L)///求表L的长度
{
    if(!L.elem){
         printf("该表不存在");
         return -1;
    }
    return L.length;
}

status GetElem(SqList L, int i, ElemType *e)///取元素i,由e返回i
{
    if(!L.elem){
         printf("该表不存在");
         return FALSE;
    }
    if(i < 0 || i >= L.length)   ///是否为超出下标范围
        return ERROR;
    else
        *e = L.elem[i];
    return OK;
}

status LocateElem(SqList L,ElemType e) ///查找符合条件的元素
{
    if(!L.elem){
         printf("该表不存在");
         return FALSE;
    }
    int i = 0;
    for(; i < L.length; i++)
    {
        if(L.elem[i] == e)
        {
            return i;
        }
    }
    return FALSE;

}

status PriorElem(SqList L,ElemType cur,ElemType *pre_e) ///获得cur的前驱
{
    if(!L.elem){
         printf("该表不存在");
         return FALSE;
    }
    int i = 1;
    for(; i < L.length; i++)
    {
        if(L.elem[i] == cur)
        {
            *pre_e = L.elem[i-1];
            return TRUE;
        }
    }
    return FALSE;
}

status NextElem(SqList L,ElemType cur,ElemType *next_e)///获得cur的后继
{
    if(!L.elem){
         printf("该表不存在");
         return FALSE;
    }
    int i = 0;
    for(; i < L.length - 1; i++)
    {
        if(L.elem[i] == cur)
        {
            *next_e = L.elem[i+1];
            return TRUE;
        }
    }
    return FALSE;
}

status ListInsert(SqList *L,int i,ElemType e)///元素ai之前插入新元素e
{
    if(!L->elem){
         printf("该表不存在");
         return FALSE;
    }
    if(i != L->length)
        if(i < 0 || i >= L->length-1 )           ///是否为超出下标范围
            return ERROR;
    if(L->listsize >= L->length)        ///判断是否空间不够
    {
        L->elem == (ElemType *)realloc(L->elem, L->listsize);
        L->listsize += LISTINCREMENT;
        if(!L->elem)
            exit(OVERFLOW);
    }
    int j = L->length;
    for(; j > i; j--)
        L->elem[j] = L->elem[j-1];
    L->elem[j] = e;
    L->length++;
    return OK;
}
status ListDelete(SqList *L,int i,ElemType *e)///删除第i个元素
{
    if(!L->elem){
         printf("该表不存在");
         return FALSE;
    }
    if(i < 0 || i >= L->length)    ///是否为超出下标范围
        return ERROR;
    int j = i;
    *e = L->elem[j];
    for(; j < L->length-1; j++)
    {
        L->elem[j] = L->elem[j+1];
    }
    L->length--;
    return OK;
}

status ListTrabverse(SqList L) ///遍历表,对L的每个数据元素调用函数
{
    if(!L.elem){
         printf("该表不存在");
         return FALSE;
    }
    int i = 0;
    if(L.length != 0) printf("以下为遍历结果:\n");
    else printf("该线性表为空表\n");
    for(; i < L.length && L.elem; i++)
    {
        printf("%d ",L.elem[i]);
    }
    return OK;
}

status ReadFile(SqList *L, char *filename) ///读文件
{
    if(!L->elem){       ///该表不存在
        printf("线性表不存在，已自动初始化一个线性表！");
        IntiaList(L);
    }
    FILE *fp;
    L->length=0;
    if ((fp=fopen(filename,"rb"))==NULL)   ///打开文件失败
    {
        printf("File open error!\n ");
        return FALSE;
    }

    while(fread(&L->elem[L->length],sizeof(ElemType),1,fp))
        L->length++;
    ///这里从文件中逐个读取数据元素恢复顺序表，对于不同的物理结构，可通过读
    ///取的数据元素恢复内存中的物理结构。
    fclose(fp);  ///关闭文件
    return OK;
}

status WriteFile(SqList L, char *filename) ///写文件
{
    if(!L.elem){       ///该表不存在
        printf("线性表不存在，已自动初始化一个线性表！");
        IntiaList(&L);
    }
    FILE  *fp;
    if((fp=fopen(filename,"wb"))==NULL)        ///打开文件失败
    {
        printf("File open error\n ");
        return FALSE;
    }
    fwrite(L.elem,sizeof(ElemType),L.length,fp);
    ///这里是1次性写入，对于其它物理结构，可通过遍历，逐个访问数据元素
    ///并写入到文件中
    fclose(fp); ///储存并关闭文件
    return OK;
}
