#include <iostream>
#include <stdio.h>
using namespace std;
typedef long long ll;
int n, arr[100010], tmp[100010];
//归并排序，过程中 统计逆序数
ll merge(int start, int mid, int end){
    ll cnt = 0;
    int i = start, j = mid+1, k = 0;
    while( i<=mid && j<= end){
        //从小到大排序
        if(arr[i] > arr[j]){
            cnt += (j-mid); //加上本次的逆序对数
            tmp[k++] = arr[j++];
        }else{
            tmp[k++] = arr[i++];
        }
    }
    while(i<=mid) tmp[k++] = arr[i++];
    while(j<=end) tmp[k++] = arr[j++];
    //将临时数组中拍好序的数，重新复制到a中
    for(int i=0; i<k; i++) arr[start+i] = tmp[i];
    return cnt;
}
ll inversePairs(int start, int end){
    ll cnt = 0;
    if(start < end){
        int mid = (start + end)/2;
        cnt += inversePairs(start, mid); //左半部分 逆序对数量
        cnt += inversePairs(mid+1, end); //右半部分
        cnt += merge(start, mid, end); //合并两部分，并计算数量
    }
    return cnt;
}
int main() {
    //freopen("in.txt", "r", stdin);
    while( scanf("%d", &n) != EOF){
        for(int i=0; i<n; i++) scanf("%d", &arr[i]);
        ll ans = inversePairs(0, n-1);
        printf("%lld\n",ans);
    }
    return 0;
}
