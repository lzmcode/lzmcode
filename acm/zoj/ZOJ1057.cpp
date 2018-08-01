# include<stdio.h>
# include<string.h>
int main(){
    bool first = true;
    int n,i;
    int a[20],b[20];
    while(scanf("%d",&n) && n){
        if(!first) puts("");
        for(i=0; i<n; i++)
            scanf("%d", &a[i]);
        for(i=0; i<n; i++)
            scanf("%d", &b[i]);
        int suma =0 ,sumb=0;
        for(i=0; i<n; i++){
            if(a[i]==1 && b[i]==2){
                suma += 6;
                continue;
            }
            if(a[i] ==2 && b[i]==1){
                sumb += 6;
                continue;
            }
            if(a[i]==b[i]) continue;
            if(a[i] - b[i] == 1){
                sumb += (a[i]+b[i]);
                continue;
            }
            if(b[i] - a[i] == 1){
                suma += (a[i]+b[i]);
                continue;
            }
            if(a[i]>b[i]) suma += a[i];
            if(b[i]>a[i]) sumb += b[i];
        }
        printf("A has %d points. B has %d points.\n",suma,sumb);
        first = false;
    }
    return 0;
}
