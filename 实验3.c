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
typedef int status;                 ///����״̬���Ͷ���
typedef char ElemType;

typedef struct BiTNode              ///���������
{
    int flag;
    int data;                       ///��㴢������
    char mark;                      ///��ǽ��
    struct BiTNode *lchild,*rchild; ///���Һ���ָ��
} BiTNode, *BiTree;

typedef struct Linklist             ///�õ����������������ĸ����λ��
{
    BiTree elem;                    ///ָ����������ڵ�
    struct Linklist *next;          ///ָ����һ����
    int index;                      ///������ı��
}Node, *Linklist;

typedef struct                      ///�����
{
    Linklist elem;                  ///ָ������ĵ�һ��λ��
    int length;                     ///��ʶ������ĳ���
}Tag;

status IntiaList(Linklist *L);                  ///�½�һ��������Ĭ��Ϊһ��
status AddList(Linklist *L);                    ///�ں�������һ����㴢��������ĸ���Ҳ���Ƕ�һ��������

status Visit(BiTree T);                         ///��������
BiTree Find(BiTree T,char e);                   ///Ѱ�ҽ��

status InitBiTree(BiTree *T);                   ///����һ���ն�������������ͷ��㣩
status DestroyBiTree(BiTree *T);                ///����һ��������
status CreateBiTree(BiTree *T);                 ///���ݶ��崴��һ�������������������򣬺���
status ClearBiTree(BiTree *T);                  ///���һ��������
status BiTreeEmpty(BiTree T);                   ///�ж�һ���������Ƿ�Ϊ��
int BiTreeDepth(BiTree T);                      ///�����������
BiTree Root(BiTree T);                          ///���ض������ĸ�
int Value(BiTree T,ElemType e);                 ///��ȡ��e��ͬ�Ľ��
status Assign(BiTree *T,ElemType e,int value);   ///����e��ͬ�Ľ�㸳ֵvalue
BiTree Parent(BiTree T,ElemType e);             ///��ȡe����˫��
BiTree LeftChild(BiTree T,ElemType e);          ///��ȡe��������
BiTree RightChild(BiTree T,ElemType e);         ///��ȡe�����Һ���
BiTree LeftSibling(BiTree T,ElemType e);        ///��ȡe�������ֵ�
BiTree RightSibling(BiTree T,ElemType e);       ///��ȡe�������ֵ�
status InsertChild(BiTree *T,int LR,char e);    ///����һ�����
status DeleteChild(BiTree *T,int LR,char e);    ///ɾ��һ�����
status PreOrderTraverse(BiTree T);              ///�������
status InOrderTraverse(BiTree T);               ///�������
status PostOrderTraverse(BiTree T);             ///�������
status LevelOrderTraverse(BiTree T);            ///�������
status ReadFile(BiTree *T,FILE *fp,char *filename);
status WriteFile(BiTree T,FILE *fp,char *filename);
Tag tag;
Linklist L;
int main()
{
    tag.length = 0;                 ///��ʼ�������ĳ���Ϊ0
    IntiaList(&L);                  ///�½�һ��������Ĭ��Ϊһ��
    tag.elem = L;                   ///ʹ�����ָ�����������һ�����
    FILE *fp;
    char filename[50];              ///�ļ���
    int op=1,i=0,j=0,num,definition,non,e,value,LR;
    BiTree nonsense;
    printf("��Ҫ������������");
    scanf("%d",&num);
    BiTree t[num];
    for(i=0; i<num; i++)
    {
        t[i]=NULL;
        tag.length++;
    }
    printf("����ʹ�õڼ�����������(����EOF�˳�����)");
    while(scanf("%d",&j)!=EOF)
    {
        if(j<=0 || j>num)
        {
            printf("�޷���ȡ��������������������룡\n");
            printf("����ʹ�õڼ�����������");
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
            printf("    ��ѡ����Ĳ���[0~22]:");
            scanf("%d",&op);
            getchar();
            if(op != 0)
                if(t[j] == NULL && op != 1)
                {
                    printf("�ö�����������");
                    system("pause");
                    continue;
                }
            switch(op)
            {
            case 1:
                //printf("\n----IntiaList���ܴ�ʵ�֣�\n");
                if(InitBiTree(&t[j])==OK) printf("��������ʼ���ɹ���\n");
                else printf("��������ʼ��ʧ�ܣ�\n");
                system("pause");
                //���ߣ� printf("�������������������");  getch();
                break;
            case 2:
                if(DestroyBiTree(&t[j])==ERROR)
                    printf("����ʧ�ܣ� \n");
                else printf("�����ٳɹ���\n");
                system("pause");
                break;
            case 3:
                if(CreateBiTree(&t[j]->lchild)==ERROR) printf("����������ʧ�ܣ�\n");
                else printf("�����������ɹ���\n");
                //printf("\n----DestroyList���ܴ�ʵ�֣�\n");
                system("pause");
                break;
            case 4:
                non = ClearBiTree(&t[j]->lchild);
                if(non == OK) printf("��������ճɹ�");
                else if(t[j]->lchild==NULL)
                    printf("��Ϊ�գ� \n");
                else if(non==ERROR) printf("���������ʧ��");
                //printf("\n----DestroyList���ܴ�ʵ�֣�\n");
                system("pause");
                break;
            case 5:
                if(BiTreeEmpty(t[j]->lchild)==OK) printf("�ö�����Ϊ��");
                else printf("�ö�������Ϊ�գ�\n");
                //printf("\n----DestroyList���ܴ�ʵ�֣�\n");
                system("pause");
                break;
            case 6:
                printf("�ö����������Ϊ %d\n",BiTreeDepth(t[j]->lchild));
                //printf("\n----DestroyList���ܴ�ʵ�֣�\n");
                system("pause");
                break;
            case 7:
                nonsense = Root(t[j]->lchild);
                if(t[j]->lchild==NULL)
                    printf("��Ϊ�գ� \n");
                else if(nonsense != NULL) printf("��ȡ���ڵ�ɹ������ӦԪ����%c:%d\n",nonsense->mark,nonsense->data);
                else printf("��ȡ���ڵ�ʧ��\n");
                //printf("\n----DestroyList���ܴ�ʵ�֣�\n");
                system("pause");
                break;
            case 8:
                if(t[j]->lchild==NULL){
                    printf("��Ϊ�գ� \n");
                    system("pause");
                    break;
                }
                printf("���������Ӧ��ǣ�\n");
                scanf("%c",&e);
                non = Value(t[j]->lchild,e);

                if(non) printf("%c ����Ӧ����Ϊ %d \n",e,non);
                else printf("�Ҳ������Ӧ���\n");
                system("pause");
                break;
            case 9:
                if(t[j]->lchild==NULL){
                    printf("��Ϊ�գ� \n");
                    system("pause");
                    break;
                }
                printf("���������Ӧ����Լ���Ҫ�����ֵ��\n");
                scanf("%c%d",&e,&value);
                if(Assign(&t[j]->lchild,e,value) == OK) printf("��ֵ�ɹ�");
                else printf("�Ҳ������Ӧ���\n");
                system("pause");
                break;
            case 10:
                if(t[j]->lchild==NULL){
                    printf("��Ϊ�գ� \n");
                    system("pause");
                    break;
                }
                printf("���������Ӧ��ǣ�\n");
                scanf("%c",&e);
                nonsense = Parent(t[j]->lchild,e);
                if(nonsense != NULL) printf("��ȡ˫�׳ɹ������ӦԪ����%c:%d\n",nonsense->mark,nonsense->data);
                else printf("��ȡ˫��ʧ��\n");
                //printf("\n----DestroyList���ܴ�ʵ�֣�\n");
                system("pause");
                break;
            case 11:
                if(t[j]->lchild==NULL){
                    printf("��Ϊ�գ� \n");
                    system("pause");
                    break;
                }
                printf("���������Ӧ��ǣ�\n");
                scanf("%c",&e);
                nonsense = LeftChild(t[j]->lchild,e);
                if(nonsense != NULL) printf("��ȡ���ӳɹ������ӦԪ����%c:%d\n",nonsense->mark,nonsense->data);
                else printf("��ȡ����ʧ�ܻ�Ϊ��\n");
                //printf("\n----DestroyList���ܴ�ʵ�֣�\n");
                system("pause");
                break;
            case 12:
                if(t[j]->lchild==NULL){
                    printf("��Ϊ�գ� \n");
                    system("pause");
                    break;
                }
                printf("���������Ӧ��ǣ�\n");
                scanf("%c",&e);
                nonsense = RightChild(t[j]->lchild,e);
                if(nonsense != NULL) printf("��ȡ�Һ��ӳɹ������ӦԪ����%c:%d\n",nonsense->mark,nonsense->data);
                else printf("��ȡ�Һ���ʧ�ܻ�Ϊ��\n");
                //printf("\n----DestroyList���ܴ�ʵ�֣�\n");
                system("pause");
                break;
            case 13:
                if(t[j]->lchild==NULL){
                    printf("��Ϊ�գ� \n");
                    system("pause");
                    break;
                }
                printf("���������Ӧ��ǣ�\n");
                scanf("%c",&e);
                nonsense = LeftSibling(t[j]->lchild,e);
                if(nonsense) printf("��ȡ���ֵܳɹ������ӦԪ����%c:%d\n",nonsense->mark,nonsense->data);
                else printf("��ȡ���ֵ�ʧ�ܻ�Ϊ��\n");
                //printf("\n----DestroyList���ܴ�ʵ�֣�\n");
                system("pause");
                break;
            case 14:
                if(t[j]->lchild==NULL){
                    printf("��Ϊ�գ� \n");
                    system("pause");
                    break;
                }
                printf("���������Ӧ��ǣ�\n");
                scanf("%c",&e);
                nonsense = RightSibling(t[j]->lchild,e);//A1B2*0*0C3*0*0
                if(nonsense) printf("��ȡ���ֵܳɹ������ӦԪ����%c:%d\n",nonsense->mark,nonsense->data);
                else printf("��ȡ���ֵ�ʧ�ܻ�Ϊ��\n");
                //printf("\n----DestroyList���ܴ�ʵ�֣�\n");
                system("pause");
                break;
            case 15:
                printf("���������Ӧ����Լ�LD��ֵ��(0��1��)\n");
                scanf("%c%d",&e,&LR);
                getchar();
                if(t[j]->lchild==NULL)
                    printf("��Ϊ�գ� \n");
                else if(InsertChild(&t[j],LR,e) == ERROR) printf("����ʧ�ܣ�");
                else printf("����ɹ�\n");
                system("pause");
                break;
            case 16:
                printf("���������Ӧ����Լ�LD��ֵ��(0��1��)\n");
                scanf("%c%d",&e,&LR);
                getchar();
                if(t[j]->lchild==NULL)
                    printf("��Ϊ�գ� \n");
                else if(DeleteChild(&t[j],LR,e) == ERROR) printf("ɾ��ʧ�ܣ�");
                else printf("ɾ���ɹ�\n");
                system("pause");
                break;
            case 17:
                if(t[j]->lchild==NULL)
                    printf("��Ϊ�գ� \n");
                else if(PreOrderTraverse(t[j]) == OK) printf("ǰ������ɹ���");
                else printf("ǰ�����ʧ��\n");
                //printf("\n----DestroyList���ܴ�ʵ�֣�\n");
                system("pause");
                break;
            case 18:
                if(t[j]->lchild==NULL)
                    printf("��Ϊ�գ� \n");
                else if(InOrderTraverse(t[j]) == OK) printf("��������ɹ���");
                else printf("�������ʧ��\n");
                //printf("\n----DestroyList���ܴ�ʵ�֣�\n");
                system("pause");
                break;
            case 19:
                if(t[j]->lchild==NULL)
                    printf("��Ϊ�գ� \n");
                else if(PostOrderTraverse(t[j]) == OK) printf("��������ɹ���");
                else printf("�������ʧ��\n");
                //printf("\n----DestroyList���ܴ�ʵ�֣�\n");
                system("pause");
                break;
            case 20:
                if(t[j]->lchild==NULL)
                    printf("��Ϊ�գ� \n");
                else if(LevelOrderTraverse(t[j]) == OK) printf("��������ɹ���");
                else printf("�������ʧ��\n");
                //printf("\n----DestroyList���ܴ�ʵ�֣�\n");
                system("pause");
                break;
            case 21:
                printf("�����ļ���: ");
                scanf("%s",filename);
                if ((fp=fopen(filename,"rb"))==NULL)
                {
                    printf("File open error\n ");
                    return 1;
                }
                if( fp==NULL&&t[j]->lchild==NULL ){
                    printf("��Ϊ�գ� \n");
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
                            printf("�ļ���ȡ�ɹ�! \n");
                        else printf("�ļ���ȡʧ�ܣ� \n");
                    }
                    else
                    {
                        t[j]->lchild=NULL;
                        if(ReadFile(&t[j]->lchild,fp,filename)==OK)
                        printf("�ļ���ȡ�ɹ�! \n");
                        else printf("�ļ���ȡʧ�ܣ� \n");
                    }
                }
                fclose(fp);
                system("pause");
                break;
            case 22:
                printf("�����ļ���: ");
                scanf("%s",filename);
                if(t[j]->lchild==NULL){
                    printf("��Ϊ�գ� \n");
                    system("pause");
                    break;
                }
                else if ((fp=fopen(filename,"wb"))==NULL)
                {
                    printf("�ļ���ʧ��\n ");
                    return 1;
                }
                else if(WriteFile(t[j]->lchild,fp,filename)==OK)
                    printf("�ļ�д��ɹ���\n");
                else printf("�ļ�д��ʧ�ܣ�\n");
                fclose(fp);
                system("pause");
                break;
            case 0:
                break;
            }//end of switch
        }//end of while
        op=1;
        printf("����ʹ�õڼ�����������(��ctrl+z�˳�ϵͳ)");
    }
    printf("��ӭ�´���ʹ�ñ�ϵͳ��\n");
    system("pause");
    return 0;
}//end of main()

///Ѱ�ҽ��
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
///��������Visit
status Visit(BiTree T)
{
    if(T->mark != '*'){
        printf("%c : %d\n",T->mark, T->data);
        return OK;
    }
    else
        return 0;
}

///���Ƕ���ʵ�֣�������
status IntiaList(Linklist *L)                    ///��ʼ���ձ�L
{
    *L = (Linklist)malloc(sizeof(Node));         ///������һ�����
    if(*L == NULL)  exit(OVERFLOW);              ///�洢�ռ�ʧ��
    (*L)->elem = NULL;                           ///��ʱû�д����������ĸ����
    (*L)->next = NULL;                           ///��next����ΪNULL
    tag.length = 1;                              ///�����ĳ��ȱ�Ϊ1
    return OK;
}

status AddList(Linklist *L)     ///�ں�������һ�����
{
    if(*L == NULL)
    {
        printf("�ñ�����");
        return FALSE;
    }
    Linklist p;
    p=(Linklist)malloc(sizeof(Node));
    (*L)->next = p;
    p->next = NULL;
    tag.length++;
    return OK;
}

///���Ƕ�������ʵ��
status InitBiTree(BiTree *T)
{
    *T = (BiTNode *)malloc(sizeof(BiTNode)); ///����һ��ͷ��㣬���𴢴�������Ľ����
    if(*T == NULL)  exit(OVERFLOW);          ///�洢�ռ�ʧ��
    (*T)->data = 0;                            ///��ʼ����������Ϊ0
    (*T)->mark = '*';                          ///��ʼ���Ϊ��
    (*T)->lchild = NULL;                       ///��lchild����ΪNULL
    (*T)->rchild = NULL;                       ///��rchild����ΪNULL
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
    if(ch=='*') (*T)=NULL;                   ///����
    else if(ch!='\n'){
        (*T)=(BiTNode*)malloc(sizeof(BiTNode));
        (*T)->data=dat;
        (*T)->mark=ch;
        CreateBiTree(&(*T)->lchild);         ///�ݹ鹹��������
        CreateBiTree(&(*T)->rchild);         ///�ݹ鹹��������
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
        printf("����Ѿ��Ǹ��ڵ�\n");
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
            printf("�������ֵܾ���������");
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
            printf("�������ֵܾ���������");
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
