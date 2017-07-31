/* ����С��������prim�㷨 */  
  
#include <stdio.h>  
#include <string.h>  
  
#define MaxSize 20  
#define MAX 10000  
  
typedef char VertexType;  
  
//����ͼ ���ڽӾ����ʾ���ṹ  
typedef struct Graph {  
    VertexType ver[MaxSize+1];  
    int edg[MaxSize][MaxSize];  
}Graph;  
  
//�ڽӾ���ͼ�����ɺ���  
void CreateGraph( Graph *g )  
{  
    int i = 0;  
    int j = 0;  
    int VertexNum;  
    VertexType Ver;  
  
    printf("������ͼ�Ķ���:\n");  
    while( '\n' != (Ver=getchar()) )  
        g->ver[i++] = Ver;  
    g->ver[i] = '\0';  
  
    VertexNum = strlen(g->ver);  
    printf("��������Ӧ�ĵ��ڽӾ���:\n");  
    for( i=0; i<VertexNum; i++ )  
        for( j=0; j<VertexNum; j++ )  
            scanf("%d", &g->edg[i][j]);  
}  
  
//��ӡͼ�Ľ���ʶ�����ڽӾ���  
void PrintGraph( Graph g )  
{  
    int i, j;  
    int VertexNum = strlen(g.ver);  
    printf("ͼ�Ķ���Ϊ:\n");  
    for( i=0; i<VertexNum; i++ )  
        printf("%c ", g.ver[i]);  
    printf("\n");  
  
    printf("ͼ���ڽӾ���Ϊ:\n");  
    for( i=0; i<VertexNum; i++ ) {  
        for( j=0; j<VertexNum; j++ )  
            printf("%d ", g.edg[i][j]);  
        printf("\n");  
    }  
}  
  
//��ͼ�Ķ�����  
int CalVerNum( Graph g )  
{  
    return strlen(g.ver);  
}  
  
//�����ڽӵĶ���֮���Ȩֵ����ΪMAX  
void SetWeight( Graph *g )  
{  
    for( int i=0; i<CalVerNum(*g); i++ )  
        for( int j=0; j<CalVerNum(*g); j++ )  
            if( 0 == g->edg[i][j] )  
                g->edg[i][j] = MAX;  
}  
  
//����prim�㷨����С������  
void prim( Graph g, int VerNum, int *parent )  
{  
    int i, j, k;  
    int lowcost[MaxSize];  
    int closest[MaxSize], used[MaxSize];  
    int min;  
  
    for( i=0; i<VerNum; i++ ) {          //�Ը�������lowcost��closest���г�ʼ��  
        lowcost[i] = g.edg[0][i];  
        closest[i] = 0;  
        used[i] = 0;                    //used[i] == 0 ��ʾi������U�У���֮����V-U�С�  
        parent[i] = -1;  
    }  
  
    used[0] = 1;                        //��һ�������Ϊ0�Ķ������U�У�Ҳ��������������  
  
    for( i=0; i<VerNum-1; i++ ) {  
        j = 0;  
        min = MAX;  
  
        for( k=1; k<VerNum; k++ )        //�ҵ�V-U�е���U�ж�����ɵ���СȨֵ�ıߵĶ�����  
            if( (0==used[k]) && (lowcost[k]<min) ) {  
                min = lowcost[k];  
                j = k;  
            }  
  
        parent[j] = closest[j];  
  
        used[j] = 1;                    //��j�������U��  
  
        for( k=0; k<VerNum; k++ )        //����j�������U�У�����lowcost��closest�����е�Ԫ�أ����V-U�еĶ��㵽j�����Ȩֵ�Ƿ��j����U֮ǰ��lowcost�����Ԫ��С  
            if( (0==used[k]) && (g.edg[k][j]<lowcost[k]) ) {  
                lowcost[k] = g.edg[k][j];  
                closest[k] = j;         //closest���鱣�����U�е�V-U����СȨֵ�Ķ�����  
            }  
    }  
}  
  
//��ӡ��С�������ıߺ�MST��Ȩֵ  
void PrintMST( Graph g, int *parent )  
{  
    int VerNum = CalVerNum( g );  
    int weight = 0;  
    printf("MST�ı�Ϊ:\n");  
    for( int i=1; i<VerNum; i++ ) {       //VerNum-1����  
        printf("%c--%c\n", g.ver[parent[i]], g.ver[i] );  
        weight+=g.edg[parent[i]][i];  
    }  
    printf("MST��ȨֵΪ:%d\n", weight);  
}  
  
  
int main()  
{  
    Graph g;  
    int parent[20];  
  
    CreateGraph ( &g );  
    PrintGraph( g );  
      
    SetWeight( &g );  
  
    prim( g, CalVerNum(g), parent );  
    PrintMST( g, parent );  
  
    return 0;  
}  
