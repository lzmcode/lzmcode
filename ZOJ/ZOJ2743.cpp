#include <bits/stdc++.h>
 
const int N = 100 + 5;
char str[N][N];
int H, W, h, w;
int ans;
 
bool check(int x, int y) {
    if (x < 1 || x > H || y < 1 || y > W || (x%2==0 && y==W) || str[x][y] == '@') return false;
    return true;
}
 
void DFS(int x, int y, char color, int &cnt) {
    if (!check (x, y)) {
        return ;
    }
    if (color != '@' && color != str[x][y]) {
        return ;
    }
    cnt++;
    str[x][y] = '@';
    DFS (x - 1, y, color, cnt);
    DFS (x + 1, y, color, cnt);
    DFS (x, y - 1, color, cnt);
    DFS (x, y + 1, color, cnt);
    if (x & 1) {
        DFS (x - 1, y - 1, color, cnt);
        DFS (x + 1, y - 1, color, cnt);
    } else {
        DFS (x - 1, y + 1, color, cnt);
        DFS (x + 1, y + 1, color, cnt);
    }
}
 
int main() {
    while (scanf ("%d%d%d%d", &H, &W, &h, &w) == 4) {
        for (int i=1; i<=H; ++i) {
            scanf ("%s", str[i] + 1);
            for (int j=1; j<=W; ++j) {
                if (str[i][j] == 'E') {
                    str[i][j] = '@';
                }
            }
        }
        int cnt = 0;
        DFS (h, w, str[h][w], cnt);
        int ans = cnt;
        if (ans < 3) {
            puts ("0");
            continue;
        }
        for (int i=1; i<=W; ++i) {
            DFS (1, i, '@', cnt);
        }
        for (int i=1; i<=H; ++i) {
            for (int j=1; j<=W; ++j) {
                if (i % 2 == 0 && j == W) continue;
                if (str[i][j] != '@') {
                    ans++;
                }
            }
        }
        printf ("%d\n", ans);
    }
 
    return 0;
}
