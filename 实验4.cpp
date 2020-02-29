#include<stdio.h>
#include<stdlib.h>

#define MAX_VERTEX_NUM 100
#define TRUE 1
#define OK 1
#define FALSE 0
#define ERROR -1
#define INFEASIBLE -1
#define OVERFLOW -2
typedef int status;         ///����״̬���Ͷ���
typedef struct ArcNode{
	int adjvex;             ///�û���ָ��Ķ����λ��
	struct ArcNode *nextarc;///ָ����һ������ָ��
}ArcNode;
typedef struct VertexType
{
	int data;               ///�����ֵ
	char index;             ///����ؼ��ֱ��
}VertexType;
typedef struct VNode
{
	VertexType key;
	ArcNode *firstarc;      ///ָ���һ�������ö���ıߵ�ָ��
}VNode,AdjList[MAX_VERTEX_NUM];
typedef struct{
	AdjList vertices;       ///��������
	int vexnum,arcnum;      ///ͼ��ǰ�������ͻ���
}ALGraph;
int LocateVex(ALGraph G,char v){         ///��λ����
    int i;
	for(i=0;i<G.vexnum;i++){
		if(v==G.vertices[i].key.index)
            return i;
	}
	return ERROR;
}
status CreateGraph(ALGraph &G,VertexType V[],char VR[]){                 ///��������ͼ
	ArcNode *p,*q;
	int i,j,k;
	char v1,v2;
	for(i=0;i<G.vexnum;i++)
	{
        G.vertices[i].key.index=V[i].index;
        G.vertices[i].key.data=V[i].data;
        G.vertices[i].firstarc = NULL;
	}
    for(i=0;i<2*G.arcnum;i=i+2)
	{
        j = LocateVex(G,VR[i]);
        k = LocateVex(G,VR[i+1]);
        p = (ArcNode*)malloc(sizeof(ArcNode));
        p->adjvex = k;
        p->nextarc = NULL;
        if(G.vertices[j].firstarc == NULL)
        {
            G.vertices[j].firstarc = p;
            p->nextarc = NULL;
        }
        else if(G.vertices[j].firstarc != NULL)
        {
            p->nextarc=G.vertices[j].firstarc; ///ͷ�巨
            G.vertices[j].firstarc=p;
        }
	}
	return OK;
}
status DestroyGraph(ALGraph &G)
{
    int i;
	for(i=0; i<G.vexnum; i++)
	{
		if(G.vertices[i].firstarc != NULL)
		{
			ArcNode *p;
			while(G.vertices[i].firstarc != NULL)
			{
				p = G.vertices[i].firstarc;
				G.vertices[i].firstarc = p->nextarc;
				free(p);
				p=NULL;
				G.arcnum--;
			}
		}
	}
	G.vexnum = G.arcnum = 0;
	return OK;
}
int GetVex(ALGraph G,char v)
{
    int j;
    for(j=0;j<G.vexnum;j++)
        if(G.vertices[j].key.index == v)
            return(G.vertices[j].key.data);
    return ERROR;
}
status PutVex(ALGraph &G,char v,int value)
{
    int j;
    for(j=0;j<G.vexnum;j++){
        if(G.vertices[j].key.index == v){
            G.vertices[j].key.data = value;
            return OK;
        }
    }
    return ERROR;
}
int FirstAdjVex(ALGraph G, char v)
{
    int j;
    for(j=0;j<G.vexnum;j++)
        if(G.vertices[j].key.index == v)
        {
            if(G.vertices[j].firstarc!=NULL)
                return (G.vertices[j].firstarc->adjvex);
            else return ERROR;
        }
    return ERROR;
}
int NextAdjVex(ALGraph G, char v, char w)
{
    int tag = 0;
	ArcNode *p;
	int i;
	for(i = 0; i < G.vexnum; i++)
        if(G.vertices[i].key.index == v)
        {
            tag = 1;
            break;
        }
    if(tag == 0 || G.vertices[i].firstarc == NULL) return ERROR;
    else{
        ArcNode *p = G.vertices[i].firstarc;
        while(p != NULL)
        {
            if(G.vertices[p->adjvex].key.index == w)
            {
                if(p->nextarc!=NULL)
                    return p->nextarc->adjvex;
                else return ERROR;
            }
            p=p->nextarc;
		}
		return ERROR;
    }
}
status InsertVex(ALGraph &G,char v,int value)
{
    int i = LocateVex(G,v);
    if(i != ERROR){
        printf("�Ѵ��ڸý�㣡\n");
        return ERROR;
    }
	G.vertices[G.vexnum].key.index = v;
	G.vertices[G.vexnum].key.data = value;
	G.vertices[G.vexnum].firstarc = NULL;
    G.vexnum++;
	return OK;
}
status DeleteVex(ALGraph &G,char v)
{
    int i,m,n;
	m=LocateVex(G,v);
	if(m == ERROR) return ERROR;
	VNode *p,*q;
	ArcNode *op,*op1;
	int flag = 0;
	for(i=0;i<G.vexnum;i++)
	{
		if(G.vertices[i].key.index==v){
            flag = 1;
            break;
		}
	}
	if(flag == 0) return ERROR;
	for(i=0;i<G.vexnum;i++)
	{
		if(i==m)
		{
			if(G.vertices[i].firstarc==NULL)
			{
				p=&(G.vertices[i]);
				q=&(G.vertices[G.vexnum-1]);
				for(++p;p<=q;++p)
                    *(p-1)=*p;
				G.vexnum--;
			}
			else
			{
				while(G.vertices[i].firstarc!=NULL)
				{
                    op=G.vertices[i].firstarc;
                    G.vertices[i].firstarc=op->nextarc ;
                    op=NULL;
                    free(op);
                    G.arcnum--;
				}
				p=&(G.vertices[i]);
				q=&(G.vertices[G.vexnum-1]);
				for(++p;p<=q;++p)
                    *(p-1)=*p;
				G.vexnum--;
			}

		}
		else if(i!=m && G.vertices[i].firstarc!=NULL)
		{
			op=G.vertices[i].firstarc;
			if(op->adjvex==m)
			{
				if(op->nextarc==NULL)
				{
					op=NULL;
					free(op);
					G.vertices[i].firstarc=NULL;
					G.arcnum--;
					continue;
				}
				else
				{
					G.vertices[i].firstarc=op->nextarc;
					op=NULL;
					free(op);
					G.arcnum--;
					continue;
				}
			}
			else if(op->adjvex!=m)
			{
				if(op->nextarc==NULL)
                    continue;
				else
				{
					op1=op->nextarc;
					while(op1!=NULL)
					{
						if(op1->adjvex==m)
						{
                            op->nextarc=op1->nextarc;
                            op1=NULL;
                            free(op1);
                            G.arcnum--;
                            break;
						}
						op=op->nextarc;
						op1=op->nextarc;
					}
					continue;
				}
			}
		}
		else continue;
	}
	for(i=0;i<G.vexnum;i++)
	{
		if(G.vertices[i].firstarc==NULL)
            continue;
		else
		{
			op=G.vertices[i].firstarc;
			while(op!=NULL)
			{
                if(op->adjvex>m)
                    op->adjvex=op->adjvex-1;
                op=op->nextarc;
			}
		}
    }
	return OK;
}
status InsertArc(ALGraph &G,char v,char w)
{
    int i,j;
	ArcNode *p,*q;
	i = LocateVex(G,v);
	j = LocateVex(G,w);
	p = (ArcNode*)malloc(sizeof(ArcNode));
	p->adjvex = j;
	p->nextarc = NULL;
	if(G.vertices[i].firstarc == NULL)
	{
		G.vertices[i].firstarc = p;
		G.arcnum++;
	}
	else{
        p->nextarc = G.vertices[i].firstarc;
        G.vertices[i].firstarc=p;
        G.arcnum++;
	}
	return OK;
}
status DeleteArc(ALGraph &G,char v,char w)
{
    int m,n;
	m=LocateVex(G,v);
	n=LocateVex(G,w);
	if(m == ERROR || n == ERROR)
        return ERROR;
	ArcNode *p,*q;
	if(G.vertices[m].firstarc==NULL) return ERROR;
	else{
		p=G.vertices[m].firstarc;
        if(p->nextarc==NULL)
        {
        	if(p->adjvex!=n) return ERROR;
        	else{
        		p=NULL;
        		free(p);
        		G.vertices[m].firstarc=NULL;
        		G.arcnum--;
        		return OK;
			}
		}
		else{
		    if(p->adjvex==n)
        	{
			    G.vertices[m].firstarc=p->nextarc;
        		p=NULL;
        		free(p);
        		G.arcnum--;
        		return OK;
			}
        	else
        	{
        		q=p->nextarc;
        		while(q!=NULL)
        		{
        			if(q->adjvex==n)
        			{
                        if(q->nextarc==NULL)
                        {
                            q=NULL;
                            free(q);
                            p->nextarc=NULL;
                            G.arcnum--;
                            return OK;
                        }
                        else
                        {
                            p->nextarc =q->nextarc;
                            q=NULL;
                            free(q);
                            G.arcnum--;
                            return OK;
                        }
					}
                    p=p->nextarc;
					q=p->nextarc;
				}
				return ERROR;
			}
		}
	}
}

status DFS(ALGraph G,int v,int *visited)
{
    int w;
    visited[v] = TRUE;
    printf("%c : %d\n",G.vertices[v].key.index, G.vertices[v].key.data);
    for(w = FirstAdjVex(G,G.vertices[v].key.index);w>=0;w=NextAdjVex(G,G.vertices[v].key.index,G.vertices[w].key.index))
        if(!visited[w])
            DFS(G,w,visited);
}
status DFSTraverse(ALGraph G)
{
    int v,visited[G.vexnum];
    for(v=0;v<G.vexnum;v++)
        visited[v] = FALSE;
    for(v=0;v<G.vexnum;v++)
        if(!visited[v])
            DFS(G,v,visited);
    return OK;
}
status BFSTraverse(ALGraph G)
{
	int i=0;
	int visited[G.vexnum],Q[G.vexnum];
	for(i=0;i<G.vexnum;i++)
        visited[i]=FALSE;
	int rear= 0,front= 0,v,w;
	int *p;
	for(i=0;i<G.vexnum;i++)
	{
		if(visited[i]==FALSE)
		{
			visited[i] = TRUE;
            printf("%c : %d\n",G.vertices[i].key.index, G.vertices[i].key.data);
            Q[rear++] = i;
            p = &Q[rear];
            while(front != rear && p != NULL)
            {
                v = Q[front++];
                for(w = FirstAdjVex(G, G.vertices[v].key.index); w >= 0; w = NextAdjVex(G, G.vertices[v].key.index, G.vertices[w].key.index))
                    if(visited[w] == 0)
                    {
                        visited[w] = 1;
                        printf("%c : %d\n",G.vertices[w].key.index, G.vertices[w].key.data);
                        Q[rear++] = w;
                    }
            }
		}
	}
	return OK;
}
status Write(ALGraph G,FILE *fp,char *filename)
{
    if((fp=fopen(filename,"wb"))==NULL)
	{
        printf("�ļ���ʧ��\n ");
        return ERROR;
	}
	int vexnum, arcnum;
	vexnum = G.vexnum;
	arcnum = G.arcnum;
	fwrite(&vexnum,sizeof(int),1,fp);          ///д�붥����
	fwrite(&arcnum,sizeof(int),1,fp);          ///д�뻡��
	int i, data, index;
	for(i=0;i<G.vexnum;i++)                    ///��˳��д�붥��������Ϣ
	{
		data = G.vertices[i].key.data;
		index = G.vertices[i].key.index;
	    fwrite(&index,sizeof(char),1,fp);
	    fwrite(&data,sizeof(int),1,fp);
	}
	ArcNode *p;
	for(i = 0; i < G.vexnum; i++)              ///��˳��д�뻡����Ϣ
	{
	    if(G.vertices[i].firstarc == NULL)
            continue;
	    else
	    {
            p = G.vertices[i].firstarc;
            while(p!=NULL)
            {
                fwrite(&i,sizeof(int),1,fp);
                fwrite(&(p->adjvex),sizeof(int),1,fp);
                p=p->nextarc;
            }
	    }
	}
    fclose(fp);
    return OK;
}
status Read(ALGraph &G,FILE *fp,char *filename)
{
    if((fp = fopen(filename,"rb")) == NULL)
	{
        printf("�ļ���ʧ��\n ");
        return ERROR;
	}
	fread(&(G.vexnum),sizeof(int),1,fp);
    fread(&(G.arcnum),sizeof(int),1,fp);
    int i=0,m,n;
    ArcNode *p,*q;
    for(i = 0; i < G.vexnum; i++)
    {
        fread(&(G.vertices[i].key.index),sizeof(char),1,fp);
        fread(&(G.vertices[i].key.data),sizeof(int),1,fp);
	}
	for(i=0;i<G.vexnum;i++)
        G.vertices[i].firstarc = NULL;
    for(i=0;i<G.arcnum;i++)
	{
		fread(&m,sizeof(int),1,fp);
		fread(&n,sizeof(int),1,fp);
		p=(ArcNode*)malloc(sizeof(ArcNode));
	    p->adjvex=n;
	    p->nextarc=NULL;
		if(G.vertices[m].firstarc==NULL)
            G.vertices[m].firstarc=p;
	    else{
	   	    q = G.vertices[m].firstarc;
	   	    if(q->nextarc==NULL)
                q->nextarc=p;
	   	    else{
                while(q->nextarc!=NULL)
                    q=q->nextarc;
                q->nextarc=p;
			}
        }
	}
    fclose(fp);
    return OK;
}
int main()
{
    int non;
    char filename[30],v,w;
    int op=1,i=0,j=0,k=0,num,value;
    printf("ʹ�ü���ͼ��");
    scanf("%d",&num);
    ALGraph G[num];
    FILE *fp;
    VertexType V[100];
    char VR[100];
    int flag[MAX_VERTEX_NUM];
    for(j=0;j<num;j++)
        flag[j]=0;
    printf("����ʹ�õڼ���ͼ��");
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
            printf("    	  1. CreateGraph       8. InsertVex\n");
            printf("    	  2. DestroyGraph      9. DeleteVex\n");
            printf("    	  3. LocateVex         10. InsertArc\n");
            printf("    	  4. GetVex            11. DeleteArc\n");
            printf("    	  5. PutVex            12. DFSTraverse\n");
            printf("    	  6. FirstAdjVex       13. BFSTraverse\n");
            printf("    	  7. NextAdjVex        14. Write\n");
            printf("    	  0. Exit              15. Read \n");
            printf("-------------------------------------------------\n");
            printf("    ��ѡ����Ĳ���[0~15]:");
            if(scanf("%d",&op)==0)
            {
                break;
            }
            if(flag[j] == 0 && op != 1){
                printf("ͼ������");
                system("pause");
                continue;
            }
            getchar();
            switch(op)
            {
            case 1:
                printf("�ֱ����붥������ͱߵ���Ŀ��\n");
                scanf("%d %d",&G[j].vexnum,&G[j].arcnum);
                getchar();
                if(G[j].vexnum != 0){
                    printf("�ֱ������������ֵ��\n");
                    for(i=0;i<G[j].vexnum;i++){
                        scanf("%c %d",&V[i].index,&V[i].data);
                        getchar();
                    }
                    if(G[j].vexnum >= 2){
                        printf("�ֱ���������ߵ��������㣺\n");
                        for(i=0;i<2*G[j].arcnum;i+=2){
                            scanf("%c %c",&VR[i],&VR[i+1]);
                            getchar();
                        }
                    }else{
                        printf("������С�����������������\n");
                    }
                }else{
                    printf("����һ����ͼ!\n");
                }
                printf("����ɹ�");
                if(CreateGraph(G[j],V,VR)==OK){
                    printf("ͼ�����ɹ���\n");
                    flag[j]=1;
                }
                else printf("ͼ����ʧ�ܣ�\n");
                system("pause");
                break;
            case 2:
                if(DestroyGraph(G[j])==OK){
                    printf("ͼ���ٳɹ���\n");
                    flag[j]=0;
                }
                else printf("ͼ����ʧ�ܣ�\n");
                system("pause");
                break;
            case 3:
                printf("������ҪѰ�ҵĽ��ؼ��֣�\n");
                scanf("%c",&v);
                non = LocateVex(G[j],v);
                if(non!=ERROR){
                    printf("���ҳɹ��������±�λ��Ϊ %d",non);
                }
                else printf("����ʧ�ܣ�\n");
                system("pause");
                break;
            case 4:
                printf("������ҪѰ�ҵĽ��ؼ��֣�\n");
                scanf("%c",&v);
                non = GetVex(G[j],v);
                if(non!=ERROR){
                    printf("��ö���ֵ�ɹ�������ֵΪ %d",non);
                }
                else printf("��ö���ֵʧ�ܣ�\n");
                system("pause");
                break;
            case 5:
                printf("������ҪѰ�ҵĽ��ؼ����Լ�Ҫ�����ֵ��\n");
                scanf("%c %d",&v,&value);
                if(PutVex(G[j],v,value)==ERROR)
                    printf("����ʧ�ܣ� \n");
                else printf("��ֵ�ɹ��� \n");
                system("pause");
                break;
            case 6:
                printf("������ҪѰ�ҵĽ��ؼ��֣�\n");
                scanf("%c",&v);
                non = FirstAdjVex(G[j],v);
                if(non == ERROR)
                    printf("����ʧ�ܣ� \n");
                else
                    printf("��һ�������ڸý���ֵ�� %c : %d \n",G[j].vertices[non].key.index,G[j].vertices[non].key.data);
                system("pause");
                break;
            case 7:
                printf("������ҪѰ���������ؼ��֣�\n");
                scanf("%c %c",&v,&w);
                non = NextAdjVex(G[j],v,w);
                if(non == ERROR)
                    printf("����ʧ�ܣ� \n");
                else
                    printf("%c : %d\n",G[j].vertices[non].key.index,G[j].vertices[non].key.data);
                system("pause");
                break;
            case 8:
                printf("������Ҫ����Ľ��ؼ����Լ�Ҫ�����ֵ��\n");
                scanf("%c %d",&v,&value);
                if(InsertVex(G[j],v,value)==OK)
                    printf("����ɹ���\n");
                else printf("����ʧ�ܣ� \n");
                system("pause");
                break;
            case 9:
                printf("������Ҫɾ���Ľ��ؼ��֣�\n");
                scanf("%c",&v);
                if(DeleteVex(G[j],v)==OK)
                    printf("ɾ���ɹ���\n");
                else printf("ɾ��ʧ�ܣ� \n");
                system("pause");
                break;
            case 10:
                printf("������Ҫ�����һ�����������ؼ��֣�\n");
                scanf("%c %c",&v,&w);
                if(InsertArc(G[j],v,w)==OK)
                    printf("����ɹ��� \n");
                else printf("����ʧ�ܣ� \n");
                system("pause");
                break;
            case 11:
                printf("������Ҫ�����һ�����������ؼ��֣�\n");
                scanf("%c %c",&v,&w);
                if(DeleteArc(G[j],v,w)==OK)
                    printf("ɾ���ɹ��� \n");
                else printf("ɾ��ʧ�ܣ� \n");
                system("pause");
                break;
            case 12:
                if(DFSTraverse(G[j])==OK)
                    printf("�����ɹ��� \n");
                else printf("����ʧ�ܣ� \n");
                system("pause");
                break;
            case 13:
                if(BFSTraverse(G[j])==OK)
                    printf("�����ɹ��� \n");
                else printf("����ʧ�ܣ� \n");
                system("pause");
                break;
            case 14:
                printf("�����ļ���: ");
                scanf("%s",filename);
                if(Write(G[j],fp,filename)==OK)
                    printf("�ļ�д��ɹ��� \n");
                else
                    printf("�ļ�д��ʧ�ܣ� \n");
                system("pause");
                break;
            case 15:
                printf("�����ļ���: ");
                scanf("%s",filename);
                if(Read(G[j],fp,filename)==OK)
                    printf("�ļ���ȡ�ɹ��� \n");
                else
                    printf("�ļ���ȡʧ�ܣ� \n");
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
}
