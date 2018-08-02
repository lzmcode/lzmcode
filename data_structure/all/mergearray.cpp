#include <iostream>
#include <stdio.h>
using namespace std;
typedef long long ll;
int n, arr[100010], tmp[100010];
//�鲢���򣬹����� ͳ��������
ll merge(int start, int mid, int end){
    ll cnt = 0;
    int i = start, j = mid+1, k = 0;
    while( i<=mid && j<= end){
        //��С��������
        if(arr[i] > arr[j]){
            cnt += (j-mid); //���ϱ��ε��������
            tmp[k++] = arr[j++];
        }else{
            tmp[k++] = arr[i++];
        }
    }
    while(i<=mid) tmp[k++] = arr[i++];
    while(j<=end) tmp[k++] = arr[j++];
    //����ʱ�������ĺ�����������¸��Ƶ�a��
    for(int i=0; i<k; i++) arr[start+i] = tmp[i];
    return cnt;
}
ll inversePairs(int start, int end){
    ll cnt = 0;
    if(start < end){
        int mid = (start + end)/2;
        cnt += inversePairs(start, mid); //��벿�� ���������
        cnt += inversePairs(mid+1, end); //�Ұ벿��
        cnt += merge(start, mid, end); //�ϲ������֣�����������
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
