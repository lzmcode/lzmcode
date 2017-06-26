#include<stdio.h>  
//n��ʾ��Ϸ�Ĵ�С��nС�ڵ���5   
int n;  
//���ÿһ������  
int element[25][4];  
//ÿ��״̬  
int state[25];  
//��ŵĽ��  
int result[25];   
//״̬�ĸ���  
int q;   
//��ʼ��  
void initial()  
{  
    int i,j;  
    for(i=0;i<25;i++)  
    {  
        for(j=0;j<4;j++)  
        {  
            element[i][j]=0;  
        }  
        state[i]=0;   
        result[i]=0;  
    }   
    q=0;  
}   
//������iposλ   
int backtrack(int ipos)  
{  
     int i;  
     if(ipos==n*n)  
     {  
         return 1;  
     }  
     else  
     {  
         //��iposλ��ÿ��״̬��һ��  
         for(i=0;i<q;i++)  
         {  
            if(state[i]==0)  
            {  
               continue;   
            }   
            else  
            {  
               //�ж��ܷ����Ҫ��  
               if(ipos>=n)  
               {  
                     if(element[result[ipos-n]][2]!=element[i][0])  
                     {  
                            continue;  
                     }  
               }   
               if(ipos%n!=0)  
               {  
                      if(element[result[ipos-1]][1]!=element[i][3])  
                      {  
                             continue;  
                      }  
               }  
               state[i]--;   
               result[ipos]=i;  
               if(backtrack(ipos+1)==1)  
                    return 1;  
               state[i]++;  
            }    
         }   
     }  
     return 0;  
}  
int main()  
{  
    int i,j,index;  
    index=0;  
    int top,right,bottom,left;  
    scanf("%d",&n);  
    while(n)  
    {  
          initial();  
          index++;  
          for(i=0;i<n*n;i++)  
          {  
             scanf("%d %d %d %d",&top,&right,&bottom,&left);  
               
             for(j=0;j<q;j++)  
             {  
                  if(element[j][0]==top&&element[j][1]==right&&element[j][2]==bottom&&element[j][3]==left)  
                  {  
                           state[j]++;    
                           break;  
                  }  
             }  
             if(j==q)  
             {  
                  element[q][0]=top;  
                  element[q][1]=right;  
                  element[q][2]=bottom;  
                  element[q][3]=left;  
                  state[q]=1;  
                  q++;   
             }  
          }  
          //���յģ�����ÿ�����֮��Ҫ�пհ���  
          if(index>1)  
          {  
             printf("\n");   
          }   
          printf("Game %d: ",index);  
          if(backtrack(0))  
          {  
             printf("Possible\n");   
          }  
          else  
          {  
             printf("Impossible\n");   
          }  
          scanf("%d",&n);  
    }  
   
    //system("pause");  
    return 0;   
}  
