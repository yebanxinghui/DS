#include<stdio.h>
#include<stdlib.h>
#include<malloc.h>

#define TRUE 1
#define OK 1
#define FALSE 0
#define ERROR 0
#define INFEASIBLE -1
#define OVERFLOW -2
//A1B2C3*0*0*0D4*0*0
//A1B2*0*0C3*0*0
//A1B2C3*0*0D4*0*0E5F6*0*0G7*0*0
///A1B2C4D8*0*0*0E5*0F9*0*0G3H6*0*0I7J10*0*0K11*0*0
///L20M12N13*0O15*0*0P14*0Q16*0*0*0
typedef int status;                 ///返回状态类型定义
typedef char ElemType;

typedef struct BiTNode              ///二叉树结点
{
    int flag;
    int data;                       ///结点储存数据
    char mark;                      ///标记结点
    struct BiTNode *lchild,*rchild; ///左右孩子指针
} BiTNode, *BiTree;

typedef struct Linklist             ///用单链表储存多个二叉树的根结点位置
{
    BiTree elem;                    ///指向二叉树根节点
    struct Linklist *next;          ///指向下一个表
    int index;                      ///单链表的标记
}Node, *Linklist;

typedef struct                      ///标记域
{
    Linklist elem;                  ///指向单链表的第一个位置
    int length;                     ///标识单链表的长度
}Tag;

status IntiaList(Linklist *L);                  ///新建一个单链表，默认为一个
status AddList(Linklist *L);                    ///在后面新增一个结点储存二叉树的根，也就是多一个二叉树

status Visit(BiTree T);                         ///遍历函数
BiTree Find(BiTree T,char e);                   ///寻找结点

status InitBiTree(BiTree *T);                   ///构造一个空二叉树（类似于头结点）
status DestroyBiTree(BiTree *T);                ///销毁一个二叉树
status CreateBiTree(BiTree *T);                 ///根据定义创建一个二叉树，分先序，中序，后序
status ClearBiTree(BiTree *T);                  ///清空一个二叉树
status BiTreeEmpty(BiTree T);                   ///判断一个二叉树是否为空
int BiTreeDepth(BiTree T);                      ///二叉树的深度
BiTree Root(BiTree T);                          ///返回二叉树的根
int Value(BiTree T,ElemType e);                 ///获取与e相同的结点
status Assign(BiTree *T,ElemType e,int value);   ///给与e相同的结点赋值value
BiTree Parent(BiTree T,ElemType e);             ///获取e结点的双亲
BiTree LeftChild(BiTree T,ElemType e);          ///获取e结点的左孩子
BiTree RightChild(BiTree T,ElemType e);         ///获取e结点的右孩子
BiTree LeftSibling(BiTree T,ElemType e);        ///获取e结点的左兄弟
BiTree RightSibling(BiTree T,ElemType e);       ///获取e结点的右兄弟
status InsertChild(BiTree *T,int LR,char e);    ///插入一个结点
status DeleteChild(BiTree *T,int LR,char e);    ///删除一个结点
status PreOrderTraverse(BiTree T);              ///先序遍历
status InOrderTraverse(BiTree T);               ///中序遍历
status PostOrderTraverse(BiTree T);             ///后序遍历
status LevelOrderTraverse(BiTree T);            ///按层遍历
status ReadFile(BiTree *T,FILE *fp,char *filename);
status WriteFile(BiTree T,FILE *fp,char *filename);
Tag tag;
Linklist L;
int main()
{
    tag.length = 0;                 ///初始化标记域的长度为0
    IntiaList(&L);                  ///新建一个单链表，默认为一个
    tag.elem = L;                   ///使标记域指向单链表单链表第一个结点
    FILE *fp;
    char filename[50];              ///文件名
    int op=1,i=0,j=0,num,definition,non,e,value,LR;
    BiTree nonsense;
    printf("需要几个二叉树：");
    scanf("%d",&num);
    BiTree t[num];
    for(i=0; i<num; i++)
    {
        t[i]=NULL;
        tag.length++;
    }
    printf("现在使用第几个二叉树：(输入EOF退出程序！)");
    while(scanf("%d",&j)!=EOF)
    {
        if(j<=0 || j>num)
        {
            printf("无法获取这个二叉树，请重新输入！\n");
            printf("现在使用第几个二叉树：");
            continue;
        }
        j--;
        op=1;
        while(op)
        {
            system("cls");
            printf("\n\n");
            printf("      Menu for Linear Table On Sequence Structure \n");
            printf("-------------------------------------------------\n");
            printf("    	  1. InitBiTree        12. RightChild\n");
            printf("    	  2. DestroyBiTree     13. LeftSibling\n");
            printf("    	  3. CreateBiTree      14. RightSibling\n");
            printf("    	  4. ClearBiTree       15. InsertChild\n");
            printf("    	  5. BiTreeEmpty       16. DeleteChild\n");
            printf("    	  6. BiTreeDepth       17. PreOrderTraverse\n");
            printf("    	  7. Root              18. InOrderTraverse\n");
            printf("    	  8. Value             19. PostOrderTraverse\n");
            printf("    	  9. Assign            20. LevelOrderTraverse\n");
            printf("    	  10. Parent           21. ReadFile\n");
            printf("    	  11. LeftChild        22. WriteFile\n");
            printf("    	  0. Exit\n");
            printf("-------------------------------------------------\n");
            printf("    请选择你的操作[0~22]:");
            scanf("%d",&op);
            getchar();
            if(op != 0)
                if(t[j] == NULL && op != 1)
                {
                    printf("该二叉树不存在");
                    system("pause");
                    continue;
                }
            switch(op)
            {
            case 1:
                //printf("\n----IntiaList功能待实现！\n");
                if(InitBiTree(&t[j])==OK) printf("二叉树初始化成功！\n");
                else printf("二叉树初始化失败！\n");
                system("pause");
                //或者： printf("输入任意键继续。。。");  getch();
                break;
            case 2:
                if(DestroyBiTree(&t[j])==ERROR)
                    printf("操作失败！ \n");
                else printf("树销毁成功！\n");
                system("pause");
                break;
            case 3:
                if(CreateBiTree(&t[j]->lchild)==ERROR) printf("二叉树创建失败！\n");
                else printf("二叉树创建成功！\n");
                //printf("\n----DestroyList功能待实现！\n");
                system("pause");
                break;
            case 4:
                non = ClearBiTree(&t[j]->lchild);
                if(non == OK) printf("二叉树清空成功");
                else if(t[j]->lchild==NULL)
                    printf("树为空！ \n");
                else if(non==ERROR) printf("二叉树清空失败");
                //printf("\n----DestroyList功能待实现！\n");
                system("pause");
                break;
            case 5:
                if(BiTreeEmpty(t[j]->lchild)==OK) printf("该二叉树为空");
                else printf("该二叉树不为空！\n");
                //printf("\n----DestroyList功能待实现！\n");
                system("pause");
                break;
            case 6:
                printf("该二叉树的深度为 %d\n",BiTreeDepth(t[j]->lchild));
                //printf("\n----DestroyList功能待实现！\n");
                system("pause");
                break;
            case 7:
                nonsense = Root(t[j]->lchild);
                if(t[j]->lchild==NULL)
                    printf("树为空！ \n");
                else if(nonsense != NULL) printf("获取根节点成功，其对应元素是%c:%d\n",nonsense->mark,nonsense->data);
                else printf("获取根节点失败\n");
                //printf("\n----DestroyList功能待实现！\n");
                system("pause");
                break;
            case 8:
                if(t[j]->lchild==NULL){
                    printf("树为空！ \n");
                    system("pause");
                    break;
                }
                printf("请输入结点对应标记：\n");
                scanf("%c",&e);
                non = Value(t[j]->lchild,e);

                if(non) printf("%c 结点对应数据为 %d \n",e,non);
                else printf("找不到其对应结点\n");
                system("pause");
                break;
            case 9:
                if(t[j]->lchild==NULL){
                    printf("树为空！ \n");
                    system("pause");
                    break;
                }
                printf("请输入结点对应标记以及想要赋予的值：\n");
                scanf("%c%d",&e,&value);
                if(Assign(&t[j]->lchild,e,value) == OK) printf("赋值成功");
                else printf("找不到其对应结点\n");
                system("pause");
                break;
            case 10:
                if(t[j]->lchild==NULL){
                    printf("树为空！ \n");
                    system("pause");
                    break;
                }
                printf("请输入结点对应标记：\n");
                scanf("%c",&e);
                nonsense = Parent(t[j]->lchild,e);
                if(nonsense != NULL) printf("获取双亲成功，其对应元素是%c:%d\n",nonsense->mark,nonsense->data);
                else printf("获取双亲失败\n");
                //printf("\n----DestroyList功能待实现！\n");
                system("pause");
                break;
            case 11:
                if(t[j]->lchild==NULL){
                    printf("树为空！ \n");
                    system("pause");
                    break;
                }
                printf("请输入结点对应标记：\n");
                scanf("%c",&e);
                nonsense = LeftChild(t[j]->lchild,e);
                if(nonsense != NULL) printf("获取左孩子成功，其对应元素是%c:%d\n",nonsense->mark,nonsense->data);
                else printf("获取左孩子失败或为空\n");
                //printf("\n----DestroyList功能待实现！\n");
                system("pause");
                break;
            case 12:
                if(t[j]->lchild==NULL){
                    printf("树为空！ \n");
                    system("pause");
                    break;
                }
                printf("请输入结点对应标记：\n");
                scanf("%c",&e);
                nonsense = RightChild(t[j]->lchild,e);
                if(nonsense != NULL) printf("获取右孩子成功，其对应元素是%c:%d\n",nonsense->mark,nonsense->data);
                else printf("获取右孩子失败或为空\n");
                //printf("\n----DestroyList功能待实现！\n");
                system("pause");
                break;
            case 13:
                if(t[j]->lchild==NULL){
                    printf("树为空！ \n");
                    system("pause");
                    break;
                }
                printf("请输入结点对应标记：\n");
                scanf("%c",&e);
                nonsense = LeftSibling(t[j]->lchild,e);
                if(nonsense) printf("获取左兄弟成功，其对应元素是%c:%d\n",nonsense->mark,nonsense->data);
                else printf("获取左兄弟失败或为空\n");
                //printf("\n----DestroyList功能待实现！\n");
                system("pause");
                break;
            case 14:
                if(t[j]->lchild==NULL){
                    printf("树为空！ \n");
                    system("pause");
                    break;
                }
                printf("请输入结点对应标记：\n");
                scanf("%c",&e);
                nonsense = RightSibling(t[j]->lchild,e);//A1B2*0*0C3*0*0
                if(nonsense) printf("获取右兄弟成功，其对应元素是%c:%d\n",nonsense->mark,nonsense->data);
                else printf("获取右兄弟失败或为空\n");
                //printf("\n----DestroyList功能待实现！\n");
                system("pause");
                break;
            case 15:
                printf("请输入结点对应标记以及LD的值：(0左1右)\n");
                scanf("%c%d",&e,&LR);
                getchar();
                if(t[j]->lchild==NULL)
                    printf("树为空！ \n");
                else if(InsertChild(&t[j],LR,e) == ERROR) printf("插入失败！");
                else printf("插入成功\n");
                system("pause");
                break;
            case 16:
                printf("请输入结点对应标记以及LD的值：(0左1右)\n");
                scanf("%c%d",&e,&LR);
                getchar();
                if(t[j]->lchild==NULL)
                    printf("树为空！ \n");
                else if(DeleteChild(&t[j],LR,e) == ERROR) printf("删除失败！");
                else printf("删除成功\n");
                system("pause");
                break;
            case 17:
                if(t[j]->lchild==NULL)
                    printf("树为空！ \n");
                else if(PreOrderTraverse(t[j]) == OK) printf("前序遍历成功！");
                else printf("前序遍历失败\n");
                //printf("\n----DestroyList功能待实现！\n");
                system("pause");
                break;
            case 18:
                if(t[j]->lchild==NULL)
                    printf("树为空！ \n");
                else if(InOrderTraverse(t[j]) == OK) printf("中序遍历成功！");
                else printf("中序遍历失败\n");
                //printf("\n----DestroyList功能待实现！\n");
                system("pause");
                break;
            case 19:
                if(t[j]->lchild==NULL)
                    printf("树为空！ \n");
                else if(PostOrderTraverse(t[j]) == OK) printf("后序遍历成功！");
                else printf("后序遍历失败\n");
                //printf("\n----DestroyList功能待实现！\n");
                system("pause");
                break;
            case 20:
                if(t[j]->lchild==NULL)
                    printf("树为空！ \n");
                else if(LevelOrderTraverse(t[j]) == OK) printf("按层遍历成功！");
                else printf("按层遍历失败\n");
                //printf("\n----DestroyList功能待实现！\n");
                system("pause");
                break;
            case 21:
                printf("输入文件名: ");
                scanf("%s",filename);
                if ((fp=fopen(filename,"rb"))==NULL)
                {
                    printf("File open error\n ");
                    return 1;
                }
                if( fp==NULL&&t[j]->lchild==NULL ){
                    printf("树为空！ \n");
                    system("pause");
                    break;
                }
                else
                {
                    if(t[j]->lchild!=NULL)
                    {
                        DestroyBiTree(&t[j]->lchild);
                        t[j]->lchild=NULL;
                        if(ReadFile(&t[j]->lchild,fp,filename)==OK)
                            printf("文件读取成功! \n");
                        else printf("文件读取失败！ \n");
                    }
                    else
                    {
                        t[j]->lchild=NULL;
                        if(ReadFile(&t[j]->lchild,fp,filename)==OK)
                        printf("文件读取成功! \n");
                        else printf("文件读取失败！ \n");
                    }
                }
                fclose(fp);
                system("pause");
                break;
            case 22:
                printf("输入文件名: ");
                scanf("%s",filename);
                if(t[j]->lchild==NULL){
                    printf("树为空！ \n");
                    system("pause");
                    break;
                }
                else if ((fp=fopen(filename,"wb"))==NULL)
                {
                    printf("文件打开失败\n ");
                    return 1;
                }
                else if(WriteFile(t[j]->lchild,fp,filename)==OK)
                    printf("文件写入成功！\n");
                else printf("文件写入失败！\n");
                fclose(fp);
                system("pause");
                break;
            case 0:
                break;
            }//end of switch
        }//end of while
        op=1;
        printf("现在使用第几个二叉树：(按ctrl+z退出系统)");
    }
    printf("欢迎下次再使用本系统！\n");
    system("pause");
    return 0;
}//end of main()

///寻找结点
BiTree Find(BiTree T,char e)
{
	BiTree non;
	if(!T)
		return NULL;
	else
	{
		if(T->mark == e)
            return T;
		if(T->lchild)
		{
			non = Find(T->lchild,e);
			if(non) return (non);
		}
       	if(T->rchild)
		{
			non = Find(T->rchild,e);
			if(non) return (non);
		}
    }
    return NULL;
}
///遍历函数Visit
status Visit(BiTree T)
{
    if(T->mark != '*'){
        printf("%c : %d\n",T->mark, T->data);
        return OK;
    }
    else
        return 0;
}

///这是多表的实现（单链表）
status IntiaList(Linklist *L)                    ///初始化空表L
{
    *L = (Linklist)malloc(sizeof(Node));         ///创建第一个结点
    if(*L == NULL)  exit(OVERFLOW);              ///存储空间失败
    (*L)->elem = NULL;                           ///暂时没有创建二叉树的根结点
    (*L)->next = NULL;                           ///将next设置为NULL
    tag.length = 1;                              ///标记域的长度变为1
    return OK;
}

status AddList(Linklist *L)     ///在后面新增一个结点
{
    if(*L == NULL)
    {
        printf("该表不存在");
        return FALSE;
    }
    Linklist p;
    p=(Linklist)malloc(sizeof(Node));
    (*L)->next = p;
    p->next = NULL;
    tag.length++;
    return OK;
}

///这是二叉树的实现
status InitBiTree(BiTree *T)
{
    *T = (BiTNode *)malloc(sizeof(BiTNode)); ///创建一个头结点，负责储存二叉树的结点数
    if(*T == NULL)  exit(OVERFLOW);          ///存储空间失败
    (*T)->data = 0;                            ///初始二叉树长度为0
    (*T)->mark = '*';                          ///初始标记为空
    (*T)->lchild = NULL;                       ///将lchild设置为NULL
    (*T)->rchild = NULL;                       ///将rchild设置为NULL
    return OK;
}

status DestroyBiTree(BiTree *T)
{
    if(*T==NULL)
        return ERROR;
    else{
        DestroyBiTree(&(*T)->lchild);
        DestroyBiTree(&(*T)->rchild);
        if((*T)->lchild == NULL && (*T)->rchild == NULL)
        {
            *T = NULL;
            free(*T);
        }
    }
}
status ClearBiTree(BiTree *T)
{
    if(*T == NULL)
        return ERROR;
    else{
        ClearBiTree(&(*T)->lchild);
        ClearBiTree(&(*T)->rchild);
        if((*T)->lchild==NULL&&(*T)->rchild==NULL)
        {
            (*T)=NULL;
            free(*T);
        }
        return OK;
    }
}
status CreateBiTree(BiTree *T)
{
    char ch;
    int dat;
    scanf("%c%d",&ch,&dat);
    if(ch=='*') (*T)=NULL;                   ///先序
    else if(ch!='\n'){
        (*T)=(BiTNode*)malloc(sizeof(BiTNode));
        (*T)->data=dat;
        (*T)->mark=ch;
        CreateBiTree(&(*T)->lchild);         ///递归构造左子树
        CreateBiTree(&(*T)->rchild);         ///递归构造右子树
    }
    return OK;
}

status BiTreeEmpty(BiTree T)
{
    if(T == NULL)
        return OK;
    else
        return ERROR;
}
int BiTreeDepth(BiTree T)
{
    int height = 0;
    if(T == NULL)
         return 0;
    else{
        int LHeight = BiTreeDepth(T->lchild);
        int RHeight = BiTreeDepth(T->rchild);
        height = (LHeight>=RHeight) ? LHeight + 1 :RHeight + 1;
        return height;
    }
}
BiTree Root(BiTree T)
{
    return (T);
}
int Value(BiTree T,ElemType e)
{
    int non;
    if(T->mark == e)
        return T->data;
    else{
        if(T->lchild!=NULL){
            non = Value(T->lchild,e);
            if(non!=0) return(non);
        }
        if(T->rchild!=NULL){
            non = Value(T->rchild,e);
            if(non!=0) return(non);
        }
    }
    return FALSE;
}
status Assign(BiTree *T,ElemType e,int value)
{
    int non;
    if((*T)->mark == e){
        (*T)->data = value;
        return OK;
    }
    else{
        if((*T)->lchild!=NULL){
            non = Assign(&(*T)->lchild,e,value);
            if(non!=FALSE) return(non);
        }
        if((*T)->rchild!=NULL){
            non = Assign(&(*T)->rchild,e,value);
            if(non!=FALSE) return(non);
        }
    }
    return FALSE;
}
BiTree Parent(BiTree T,ElemType e)
{
    BiTree non;
    if(T->mark == e){
        printf("结点已经是根节点\n");
        return NULL;
    }
    else if((T->lchild!=NULL && T->lchild->mark == e )||(T->rchild!=NULL && T->rchild->mark == e))
        return T;
    else{
        if(T->lchild!=NULL){
            non = Parent(T->lchild,e);
            if(non!=FALSE) return(non);
        }
        if(T->rchild!=NULL){
            non = Parent(T->rchild,e);
            if(non!=FALSE) return(non);
        }
    }
    return NULL;
}
BiTree LeftChild(BiTree T,ElemType e)
{
    BiTree non;
    if(T->mark == e)
        return T->lchild;
    else{
        if(T->lchild!=NULL){
            non = LeftChild(T->lchild,e);
            if(non!=NULL) return(non);
        }
        if(T->rchild!=NULL){
            non = LeftChild(T->rchild,e);
            if(non!=NULL) return(non);
        }
    }
    return NULL;
}
BiTree RightChild(BiTree T,ElemType e)
{
    BiTree non;
    if(T->mark == e)
        return T->rchild;
    else{
        if(T->lchild!=NULL){
            non = RightChild(T->lchild,e);
            if(non!=NULL) return(non);
        }
        if(T->rchild!=NULL){
            non = RightChild(T->rchild,e);
            if(non!=NULL) return(non);
        }
    }
    return NULL;
}
BiTree LeftSibling(BiTree T,ElemType e)
{
    BiTree non;
    if(T->mark == e){
        return NULL;
    }
    else{
        BiTree p = Parent(T,e);
        non = Find(T,e);
        if(!non) return NULL;
        else if(non == p->lchild){
            printf("他的左兄弟就是他自身，");
            return NULL;
        }
        return (p->lchild);
    }
    return NULL;
}
BiTree RightSibling(BiTree T,ElemType e)
{
    BiTree non;
    if(T->mark == e){
        return NULL;
    }
    else{
        BiTree p = Parent(T,e);
        non = Find(T,e);
        if(!non) return NULL;
        else if(non == p->rchild){
            printf("他的右兄弟就是他自身，");
            return NULL;
        }
        return (p->rchild);
    }
    return NULL;
}
status InsertChild(BiTree *T,int LR,char e)
{
    BiTree p = NULL;
	if(LR == 0)
	{
		p = Find((*T)->lchild,e);
		if(p!=NULL)
        {
            if(p->lchild==NULL)
            {
				CreateBiTree(&p->lchild);
			    return OK;
            }
            else if(p->lchild!=NULL)
            {
                BiTree s=NULL;
                CreateBiTree(&s);
                s->rchild=p->lchild;
                p->lchild=s;
                return OK;
            }
            else return ERROR;
        }
		else return ERROR;
	}
	else if(LR==1)
	{
		p=Find((*T)->lchild,e);
		if(p!=NULL)
		{
            if(p->rchild==NULL)
                CreateBiTree(&p->rchild);
            else if(p->rchild!=NULL)
            {
                BiTree s=NULL;
                CreateBiTree(&s);
                s->rchild=p->rchild;
                p->rchild=s;
            }
            else return ERROR;
        }
		else return ERROR;
	}
	else return ERROR;
}
status DeleteChild(BiTree *T,int LR,char e)
{
	BiTree p=NULL;
	if(LR==0)
	{
		p=Find((*T)->lchild,e);
		if(p!=NULL&&p->lchild!=NULL)
		{
            if(p->lchild!=NULL){
                DestroyBiTree(&p->lchild);
                return OK;
            }
            else return ERROR;
		}
		else return ERROR;
	}
	else if(LR==1)
	{
		p=Find((*T)->lchild,e);
		if(p!=NULL&&p->rchild!=NULL)
		{
            if(p->rchild!=NULL){
                DestroyBiTree(&p->rchild);
                return OK;
            }
            else return ERROR;
		}
		else return ERROR;
	}
	else return ERROR;
}
status PreOrderTraverse(BiTree T)
{
    if(T == NULL)
        return 0;
    else{
        Visit(T);
        PreOrderTraverse(T->lchild);
        PreOrderTraverse(T->rchild);
    }
    return OK;
}
status InOrderTraverse(BiTree T)
{
    if(T == NULL)
        return 0;
    else{
        InOrderTraverse(T->lchild);
        Visit(T);
        InOrderTraverse(T->rchild);
    }
    return OK;
}
status PostOrderTraverse(BiTree T)
{
    if(T == NULL)
        return 0;
    else{
        PostOrderTraverse(T->lchild);
        PostOrderTraverse(T->rchild);
        Visit(T);
    }
    return OK;
}
status LevelOrderTraverse(BiTree T)
{
   BiTree Queue[100],p;
   int front=0,rear=0;
   Queue[rear++]=T;
   while(rear!=front&&p!=NULL)
   {
        p=Queue[(front++)%10];
        if(p->lchild)
            Queue[(rear++)%10]=p->lchild;
        if(p->rchild)
            Queue[(rear++)%10]=p->rchild;
        if(p->mark != '*')
            printf("%c %d\n",p->mark,p->data);
   }
   return OK;
}

status ReadFile(BiTree *T,FILE *fp,char *filename)
{
    int data;
    char mark;
    fread(&mark,sizeof(char),1,fp);
    fread(&data,sizeof(int),1,fp);
    if(mark=='*')
    {
        T=NULL;
        return OK;
    }
    else
    {
        (*T)=(BiTree)malloc(sizeof(BiTNode));
        (*T)->lchild=NULL;
        (*T)->rchild=NULL;
        (*T)->data=data;
        (*T)->mark=mark;
        ReadFile(&(*T)->lchild,fp,filename);
        ReadFile(&(*T)->rchild,fp,filename);
    }
    return OK;
}

status WriteFile(BiTree T,FILE *fp,char *filename)
{
	int data;
	char mark;
	if(!T)
    {
    	data=0;
    	mark='*';
    	fwrite(&mark,sizeof(char),1,fp);
    	fwrite(&data,sizeof(int),1,fp);
    	return OK;
	}
    else
    {
        data=T->data;
        mark=T->mark;
        fwrite(&mark,sizeof(char),1,fp);
        fwrite(&data,sizeof(int),1,fp);
        WriteFile(T->lchild,fp,filename);
        WriteFile(T->rchild,fp,filename);
    }
    return OK;
    }
