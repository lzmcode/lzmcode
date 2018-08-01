#include<stdlib.h>     
#include<stdio.h>     
   
struct WOOD    
{    
   int length, weight, visited;    
};    
   
int cmp(const void * A, const void *B)    
{    
   if((*(WOOD*)A).length<(*(WOOD*)B).length)    
      return -1;    
   else if((*(WOOD*)A).length>(*(WOOD*)B).length)    
      return 1;    
   else return ((*(WOOD*)A).weight-(*(WOOD*)B).weight);    
}    
   
int main()    
{    
   WOOD wood[5001];    
   int cases, woods, i, j, nextstart, totaltime, temp, found, visited;    
   scanf("%d",&cases);    
   for(i=0; i<cases; ++i)    
   {    
      scanf("%d", &woods);    
      for(j=0; j<woods; ++j)    
      {    
         scanf("%d%d", &wood[j].length, &wood[j].weight);    
         wood[j].visited = 0;    
      }    
      qsort(wood, woods, sizeof(WOOD), cmp);    
      visited = found = totaltime = nextstart = 0;    
      wood[woods].weight = -1;    
      while(visited<woods)    
      {    
         temp = wood[nextstart].weight;    
         found = 0;    
         for(j=nextstart; j<woods; ++j)    
         {    
            if(wood[j].visited == 1) continue;    
              
            if(wood[j].weight<temp)    
            {    
               if(!found)    
               {    
                  nextstart = j;    
                  found = 1;    
               }    
            }    
            else    
            {    
               wood[j].visited = 1;    
               temp = wood[j].weight;    
               visited++;    
            }    
         }    
         totaltime++;    
      }    
      printf("%d\n",totaltime);    
   }    
   return 0;    
}
