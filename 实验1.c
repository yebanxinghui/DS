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

typedef int status;    ///����״̬���Ͷ���
typedef int ElemType;  ///����Ԫ�����Ͷ���

typedef struct         ///˳���˳��ṹ���Ķ���
{
    ElemType *elem;    ///�洢�ռ����ַ
    int length;        ///��
    int listsize;      ///��ǰ����Ĵ洢����

} SqList;

status IntiaList(SqList *L);                                ///����ձ�L
status DestroyList(SqList *L);                              ///�������Ա�
status ClearList(SqList *L);                                ///��LΪ�ձ�
status ListEmpty(SqList L);                                 ///�ж�L�Ƿ�Ϊ�ձ�
int ListLength(SqList L);                                   ///���L�ĳ���
status GetElem(SqList L,int i,ElemType *e);                 ///ȡԪ��i,��e����i
status LocateElem(SqList L,ElemType e);                     ///���ҷ���������Ԫ��
status PriorElem(SqList L,ElemType cur,ElemType *pre_e);    ///���cur��ǰ��
status NextElem(SqList L,ElemType cur,ElemType *next_e);    ///���cur�ĺ��
status ListInsert(SqList *L,int i,ElemType e);              ///Ԫ��ai֮ǰ������Ԫ��e
status ListDelete(SqList *L,int i,ElemType *e);             ///ɾ����i��Ԫ��
status ListTrabverse(SqList L);                             ///������,��L��ÿ������Ԫ�ص��ú���
status ReadFile(SqList *L, char *filename);                 ///���ļ�
status WriteFile(SqList L, char *filename);                 ///д�ļ�

void main(void)
{
    char filename[30],ch;
    int op=1,i=0,j=0,num,k=0;
    ElemType e,cur;
    ElemType pre_e,next_e;
    printf("ʹ�ü������Ա�");
    scanf("%d",&num);
    SqList L[num];
    printf("����ʹ�õڼ����");
    for(j=0;j<num;j++)
        L[j].elem=NULL;
    while(scanf("%d",&j)!=EOF)
    {
        if(j<=0 || j>num){
            printf("�޷���ȡ��������������룡\n");
            printf("����ʹ�õڼ����");
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
            printf("    ��ѡ����Ĳ���[0~14]:");
            if(scanf("%d",&op)==0)
            {
                break;    ///�쳣���룬ֱ���˳�
            }
            switch(op)
            {
            case 1:
                //printf("\n----IntiaList���ܴ�ʵ�֣�\n");
                if(IntiaList(&L[j])==OK) printf("���Ա����ɹ���\n");
                else printf("���Ա���ʧ�ܣ�\n");
                system("pause");
                //���ߣ� printf("�������������������");  getch();
                break;
            case 2:
                if(DestroyList(&L[j])==OK) printf("���Ա����ٳɹ���\n");
                else printf("���Ա�����ʧ�ܣ�\n");
                //printf("\n----DestroyList���ܴ�ʵ�֣�\n");
                system("pause");
                break;
            case 3:
                if(ClearList(&L[j])==OK) printf("���Ա���ճɹ���\n");
                else printf("���Ա����ʧ�ܣ�\n");
                //printf("\n----ClearList���ܴ�ʵ�֣�\n");
                system("pause");
                break;
            case 4:
                k=ListEmpty(L[j]);
                if(k==TRUE) printf("LΪ�ձ�\n");
                else if(k==FALSE) printf("L��Ϊ�ձ�\n");
                else if(k==-1);
                system("pause");
                break;
            case 5:
                if(ListLength(L[j])==-1) ;
                else printf("���Ա���Ϊ%d\n",ListLength(L[j]));
                //printf("\n----ListLength���ܴ�ʵ�֣�\n");
                system("pause");
                break;
            case 6:
                printf("������Ҫȡ���ڼ���Ԫ��i:");
                scanf("%d",&i);
                if(GetElem(L[j],i-1,&e) == OK) printf("ȡ����Ԫ���� %d\n", e);
                else printf("ȡ��Ԫ��ʧ�ܣ�\n");
                //printf("\n----GetElem���ܴ�ʵ�֣�\n");
                system("pause");
                break;
            case 7:
                printf("������ҪѰ�ҵ�Ԫ�أ�");
                scanf("%d",&e);
                if((L[j].length != 0) && (i = LocateElem(L[j],e))) printf("���ҵ����ϵ�Ԫ�أ����ǵ�%d��Ԫ��\n", i+1);
                else printf("δ�ҵ����ϵ�Ԫ�أ�\n");
                //printf("\n----LocateElem���ܴ�ʵ�֣�\n");
                system("pause");
                break;
            case 8:
                printf("������ָ����Ԫ�أ�");
                scanf("%d",&cur);
                if(PriorElem(L[j],cur,&pre_e)==TRUE) printf("���L��ǰ��Ϊ %d��\n",pre_e);
                else printf("��ȡL��ǰ��ʧ��\n");
                //printf("\n----PriorElem���ܴ�ʵ�֣�\n");
                system("pause");
                break;
            case 9:
                printf("������ָ����Ԫ�أ�");
                scanf("%d",&cur);
                if(NextElem(L[j],cur,&next_e)==TRUE) printf("���L�ĺ��Ϊ %d��\n",next_e);
                else printf("��ȡL�ĺ��ʧ��\n");
                //printf("\n----NextElem���ܴ�ʵ�֣�\n");
                system("pause");
                break;
            case 10:
                printf("������ָ���ǵڼ���Ԫ��֮ǰ�Լ��������ʲôԪ�أ�");
                scanf("%d%d",&i,&e);
                if(ListInsert(&L[j],i-1,e) == OK) printf("����ɹ�\n");
                else printf("����ʧ�ܣ�\n");
                //printf("\n----ListInsert���ܴ�ʵ�֣�\n");
                system("pause");
                break;
            case 11:
                printf("������ָ���ǵڼ���Ԫ�أ�");
                scanf("%d",&i);
                if(ListDelete(&L[j],i-1,&e) == OK) printf("ɾ��Ԫ��%d�ɹ�,\n",e);
                else printf("ɾ��ʧ�ܣ�\n");
                //printf("\n----ListDelete���ܴ�ʵ�֣�\n");
                system("pause");
                break;
            case 12:
                //printf("\n----ListTrabverse���ܴ�ʵ�֣�\n");
                ListTrabverse(L[j]);
                system("pause");
                break;
            case 13:
                printf("���������ļ�Ŀ¼��");
                scanf("%s",filename);
                if(ReadFile(&L[j], filename) == OK) printf("�����ļ��ɹ���");
                else printf("�����ļ�ʧ��!");
                system("pause");
                break;
            case 14:
                printf("���������ļ�Ŀ¼��");
                scanf("%s",filename);
                if(WriteFile(L[j], filename) == OK) printf("д���ļ��ɹ���");
                else printf("д���ļ�ʧ��!");
                system("pause");
                break;
            case 0:
                break;
            }//end of switch
        }//end of while
        op=1;
        printf("����ʹ�õڼ����(��ctrl+z�˳�ϵͳ)");
    }
    printf("��ӭ�´���ʹ�ñ�ϵͳ��\n");
    system("pause");
}//end of main()

/*--------page 23 on textbook --------------------*/
status IntiaList(SqList *L)    ///����ձ�L
{
    L->elem = (ElemType *)malloc( LIST_INIT_SIZE * sizeof (ElemType));
    if(!L->elem) exit(OVERFLOW); ///�洢�ռ�ʧ��
    L->length=0;      ///�ձ���Ϊ0
    L->listsize=LIST_INIT_SIZE;  ///��ʼ�洢����
    return OK;
}

status DestroyList(SqList *L)  ///�������Ա�
{
    if(!L->elem){
         printf("�ñ�����");
         return FALSE;
    }
    free(L->elem);
    L->elem = NULL;
    L->length = L->listsize = 0;
    return OK;
}

status ClearList(SqList *L)///��LΪ�ձ�
{
    if(!L->elem){
         printf("�ñ�����");
         return FALSE;
    }
    L->length = 0;
    return OK;
}

status ListEmpty(SqList L)///�ж�L�Ƿ�Ϊ�ձ�
{
    if(!L.elem){
         printf("�ñ�����");
         return -1;
    }
    if(L.length == 0)
        return TRUE;
    else
        return FALSE;
}

int ListLength(SqList L)///���L�ĳ���
{
    if(!L.elem){
         printf("�ñ�����");
         return -1;
    }
    return L.length;
}

status GetElem(SqList L, int i, ElemType *e)///ȡԪ��i,��e����i
{
    if(!L.elem){
         printf("�ñ�����");
         return FALSE;
    }
    if(i < 0 || i >= L.length)   ///�Ƿ�Ϊ�����±귶Χ
        return ERROR;
    else
        *e = L.elem[i];
    return OK;
}

status LocateElem(SqList L,ElemType e) ///���ҷ���������Ԫ��
{
    if(!L.elem){
         printf("�ñ�����");
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

status PriorElem(SqList L,ElemType cur,ElemType *pre_e) ///���cur��ǰ��
{
    if(!L.elem){
         printf("�ñ�����");
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

status NextElem(SqList L,ElemType cur,ElemType *next_e)///���cur�ĺ��
{
    if(!L.elem){
         printf("�ñ�����");
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

status ListInsert(SqList *L,int i,ElemType e)///Ԫ��ai֮ǰ������Ԫ��e
{
    if(!L->elem){
         printf("�ñ�����");
         return FALSE;
    }
    if(i != L->length)
        if(i < 0 || i >= L->length-1 )           ///�Ƿ�Ϊ�����±귶Χ
            return ERROR;
    if(L->listsize >= L->length)        ///�ж��Ƿ�ռ䲻��
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
status ListDelete(SqList *L,int i,ElemType *e)///ɾ����i��Ԫ��
{
    if(!L->elem){
         printf("�ñ�����");
         return FALSE;
    }
    if(i < 0 || i >= L->length)    ///�Ƿ�Ϊ�����±귶Χ
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

status ListTrabverse(SqList L) ///������,��L��ÿ������Ԫ�ص��ú���
{
    if(!L.elem){
         printf("�ñ�����");
         return FALSE;
    }
    int i = 0;
    if(L.length != 0) printf("����Ϊ�������:\n");
    else printf("�����Ա�Ϊ�ձ�\n");
    for(; i < L.length && L.elem; i++)
    {
        printf("%d ",L.elem[i]);
    }
    return OK;
}

status ReadFile(SqList *L, char *filename) ///���ļ�
{
    if(!L->elem){       ///�ñ�����
        printf("���Ա����ڣ����Զ���ʼ��һ�����Ա�");
        IntiaList(L);
    }
    FILE *fp;
    L->length=0;
    if ((fp=fopen(filename,"rb"))==NULL)   ///���ļ�ʧ��
    {
        printf("File open error!\n ");
        return FALSE;
    }

    while(fread(&L->elem[L->length],sizeof(ElemType),1,fp))
        L->length++;
    ///������ļ��������ȡ����Ԫ�ػָ�˳������ڲ�ͬ������ṹ����ͨ����
    ///ȡ������Ԫ�ػָ��ڴ��е�����ṹ��
    fclose(fp);  ///�ر��ļ�
    return OK;
}

status WriteFile(SqList L, char *filename) ///д�ļ�
{
    if(!L.elem){       ///�ñ�����
        printf("���Ա����ڣ����Զ���ʼ��һ�����Ա�");
        IntiaList(&L);
    }
    FILE  *fp;
    if((fp=fopen(filename,"wb"))==NULL)        ///���ļ�ʧ��
    {
        printf("File open error\n ");
        return FALSE;
    }
    fwrite(L.elem,sizeof(ElemType),L.length,fp);
    ///������1����д�룬������������ṹ����ͨ�������������������Ԫ��
    ///��д�뵽�ļ���
    fclose(fp); ///���沢�ر��ļ�
    return OK;
}
