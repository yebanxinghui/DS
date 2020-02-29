#include<stdio.h>
#include<stdlib.h>
#include<malloc.h>

#define TRUE 1
#define OK 1
#define FALSE 0
#define ERROR 0
#define INFEASIBLE -1
#define OVERFLOW -2

typedef int status;    ///����״̬���Ͷ���
typedef int ElemType;  ///����Ԫ�����Ͷ���

typedef struct Node
{
    ElemType data;     ///dataΪ����Ԫ������
    struct Node *next; ///nextΪָ������
} Node, *Linklist;

status IntiaList(Linklist *L);                                ///����ձ�L
status DestroyList(Linklist *L);                              ///���ٵ�����
status ClearList(Linklist *L);                                ///��LΪ�ձ�
status ListEmpty(Linklist L);                                 ///�ж�L�Ƿ�Ϊ�ձ�
int ListLength(Linklist L);                                   ///���L�ĳ���
status GetElem(Linklist L,int i,ElemType *e);                 ///ȡԪ��i,��e����i
status LocateElem(Linklist L,ElemType e);                     ///���ҷ���������Ԫ��
status PriorElem(Linklist L,ElemType cur,ElemType *pre_e);    ///���cur��ǰ��
status NextElem(Linklist L,ElemType cur,ElemType *next_e);    ///���cur�ĺ��
status ListInsert(Linklist *L,int i,ElemType e);              ///Ԫ��ai֮ǰ������Ԫ��e
status ListDelete(Linklist *L,int i,ElemType *e);             ///ɾ����i��Ԫ��
status ListTrabverse(Linklist L);                             ///������,��L��ÿ������Ԫ�ص��ú���
status ReadFile(Linklist L, char *filename);                 ///���ļ�
status WriteFile(Linklist L, char *filename);                 ///д�ļ�

int main(void)
{
    char filename[30];
    int op=1,i=0,j=0,num,k=0;
    ElemType e,cur;
    ElemType pre_e,next_e;
    printf("ʹ�ü������Ա�");
    scanf("%d",&num);
    Linklist L[num];
    for(j=0;j<num;j++)
    {
        L[j] = NULL;
    }
    printf("����ʹ�õڼ����");
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
                if(IntiaList(&L[j])==OK) printf("���������ɹ���\n");
                else printf("��������ʧ�ܣ�\n");
                system("pause");
                //���ߣ� printf("�������������������");  getch();
                break;
            case 2:
                if(DestroyList(&L[j])==OK) printf("���������ٳɹ���\n");
                else printf("����������ʧ�ܣ�\n");
                //printf("\n----DestroyList���ܴ�ʵ�֣�\n");
                system("pause");
                break;
            case 3:
                if(ClearList(&L[j])==OK) printf("��������ճɹ���\n");
                else printf("���������ʧ�ܣ�\n");
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
                else printf("��������Ϊ%d\n",ListLength(L[j]));
                //printf("\n----ListLength���ܴ�ʵ�֣�\n");
                system("pause");
                break;
            case 6:
                printf("������Ҫȡ���ڼ���Ԫ��i:");
                scanf("%d",&i);
                if(GetElem(L[j],i,&e) == OK) printf("ȡ����Ԫ���� %d\n", e);
                else printf("ȡ��Ԫ��ʧ�ܣ�\n");
                //printf("\n----GetElem���ܴ�ʵ�֣�\n");
                system("pause");
                break;
            case 7:
                printf("������ҪѰ�ҵ�Ԫ�أ�");
                scanf("%d",&e);
                if((i = LocateElem(L[j],e))== -1)   printf("�ñ�����");
                else if(i != 0) printf("���ҵ����ϵ�Ԫ�أ����ǵ�%d��Ԫ��\n", i);
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
                if(ListInsert(&L[j],i,e) == OK) printf("����ɹ�\n");
                else printf("����ʧ�ܣ�\n");
                //printf("\n----ListInsert���ܴ�ʵ�֣�\n");
                system("pause");
                break;
            case 11:
                printf("������ָ���ǵڼ���Ԫ�أ�");
                scanf("%d",&i);
                if(ListDelete(&L[j],i,&e) == OK) printf("ɾ��Ԫ��%d�ɹ�,\n",e);
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
                if(ReadFile(L[j], filename) == OK) printf("�����ļ��ɹ���");
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
    return 0;
}//end of main()

/*--------page 23 on textbook --------------------*/
status IntiaList(Linklist *L)            ///�����ͷ���Ŀձ�L
{
    *L = (Node *)malloc(sizeof(Node));   ///����һ��ͷ���
    if(*L == NULL)  exit(OVERFLOW);             ///�洢�ռ�ʧ��
    (*L)->data = 0;                        ///��ʼ����Ϊ0
    (*L)->next = NULL;                     ///��next����ΪNULL
    return OK;
}

status DestroyList(Linklist *L)  ///���ٵ�����
{
    if(*L == NULL){
         printf("�ñ�����");
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

status ClearList(Linklist *L)///��LΪ�ձ�
{
    if(*L == NULL){
         printf("�ñ�����");
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

status ListEmpty(Linklist L)///�ж�L�Ƿ�Ϊ�ձ�
{
    if(L == NULL){
         printf("�ñ�����");
         return -1;
    }
    if(L->data == 0)
        return TRUE;
    else
        return FALSE;
}

int ListLength(Linklist L)///���L�ĳ���
{
    if(L == NULL){
         printf("�ñ�����");
         return -1;
    }
    return L->data;
}

status GetElem(Linklist L, int i, ElemType *e)///ȡԪ��i,��e����i
{
    int j = 0;
    if(L == NULL){
         printf("�ñ�����");
         return FALSE;
    }
    Linklist p=L;
    if(i < 0 || i > L->data)   ///�Ƿ�Ϊ�����±귶Χ
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

status LocateElem(Linklist L,ElemType e) ///���ҷ���������Ԫ��
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

status PriorElem(Linklist L,ElemType cur,ElemType *pre_e) ///���cur��ǰ��
{
    if(L == NULL){
         printf("�ñ�����");
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

status NextElem(Linklist L,ElemType cur,ElemType *next_e)///���cur�ĺ��
{
    if(L == NULL){
         printf("�ñ�����");
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

status ListInsert(Linklist *L,int i,ElemType e)///��i��Ԫ��֮ǰ������Ԫ��e
{
    if(*L == NULL){
         printf("�ñ�����");
         return FALSE;
    }
    int j = 1;
    if(i <= 0 || i > ((*L)->data+1))       ///�Ƿ�Ϊ�����±귶Χ
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
status ListDelete(Linklist *L,int i,ElemType *e)///ɾ����i��Ԫ��
{
    int j = 0;
    if(*L == NULL){
         printf("�ñ�����");
         return FALSE;
    }
    if(i <= 0 || i > (*L)->data)    ///�Ƿ�Ϊ�����±귶Χ
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

status ListTrabverse(Linklist L) ///������,��L��ÿ������Ԫ�ص��ú���
{
    if(L == NULL){
         printf("�ñ�����");
         return FALSE;
    }
    Linklist p = L->next;
    int i = 0;
    if(L->data != 0) printf("����Ϊ�������:\n");
    else printf("�õ�����Ϊ�ձ�\n");
    for(; i < L->data; i++)
    {
        printf("%d\n",p->data);
        p=p->next;
    }
    return OK;
}

status ReadFile(Linklist L, char *filename) ///���ļ�
{
    if(L == NULL){
         printf("�ñ�����");
         return FALSE;
    }
    Linklist p=L,s=NULL;
    FILE *fp;
    //int t;
    L->data=0;
    if ((fp=fopen(filename,"rb"))==NULL)   ///���ļ�ʧ��
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
    ///������ļ��������ȡ����Ԫ�ػָ����������ڲ�ͬ������ṹ����ͨ����
    ///ȡ������Ԫ�ػָ��ڴ��е�����ṹ��
    fclose(fp);  ///�ر��ļ�
    return OK;
}

status WriteFile(Linklist L, char *filename) ///д�ļ�
{
    if(L == NULL){
         printf("�ñ�����");
         return FALSE;
    }
    Linklist p = L->next;
    int i = 0;
    FILE  *fp;
    if((fp=fopen(filename,"wb"))==NULL)        ///���ļ�ʧ��
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
    ///������1����д�룬������������ṹ����ͨ�������������������Ԫ��
    ///��д�뵽�ļ���
    fclose(fp); ///���沢�ر��ļ�
    return OK;
}
