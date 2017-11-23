#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
const int maxn = 110;
const int score[5][5] = { { 5, -1, -2, -1, -3 },
						  { -1, 5, -3, -2, -4 },
						  { -2, -3, 5, -2, -2 },
						  { -1, -2, -2, 5, -1 },
						  {-3, -4, -2, -1, 0 }
						};
char str1[maxn], str2[maxn];
int gene[maxn][maxn], Map[128];

inline int max3(int a, int b, int c)
{
	return max(max(a, b), c);
}

int main()
{
	int T, len1, len2;
	Map['A'] = 0; Map['C'] = 1; Map['G'] = 2; Map['T'] = 3; Map['-'] = 4;
	scanf("%d", &T);
	while(T--) {
        scanf("%d%s%d%s", &len1, str1, &len2, str2);
        gene[0][0] = 0;
        for(int i=1; i<=len2; i++)
			gene[0][i] = gene[0][i-1] + score[4][Map[str2[i-1]]];
		for(int i=1; i<=len1; i++)
			gene[i][0] = gene[i-1][0] + score[Map[str1[i-1]]][4];
        for(int i=1; i<=len1; i++)
			for(int j=1; j<=len2; j++) {
				gene[i][j] = max3(gene[i-1][j] + score[Map[str1[i-1]]][4],
                    gene[i][j-1] + score[4][Map[str2[j-1]]],
                    gene[i-1][j-1] + score[Map[str1[i-1]]][Map[str2[j-1]]]);
			}
        printf("%d\n", gene[len1][len2]);
	}
    return 0;
}

