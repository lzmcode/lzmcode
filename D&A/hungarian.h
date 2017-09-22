// ���㡢�ߵı�ž��� 0 ��ʼ
// �ڽӱ���

struct Edge
{
    int from;
    int to;
    int weight;

    Edge(int f, int t, int w):from(f), to(t), weight(w) {}
};

vector<int> G[__maxNodes]; /* G[i] �洢���� i �����ıߵı�� */
vector<Edge> edges;
typedef vector<int>::iterator iterator_t;
int num_nodes;
int num_left;
int num_right;
int num_edges;
int matching[__maxNodes]; /* �洢����� */
int check[__maxNodes];

bool dfs(int u)
{
    for (iterator_t i = G[u].begin(); i != G[u].end(); ++i) { // �� u ��ÿ���ڽӵ�
        int v = edges[*i].to;
        if (!check[v]) {     // Ҫ���ڽ���·��
            check[v] = true; // ���뽻��·
            if (matching[v] == -1 || dfs(matching[v])) {
                // �����δ�ǵ㣬˵������·Ϊ����·���򽻻�·���������سɹ�
                matching[v] = u;
                matching[u] = v;
                return true;
            }
        }
    }
    return false; // ����������·������ʧ��
}

int hungarian()
{
    int ans = 0;
    memset(matching, -1, sizeof(matching));
    for (int u=0; u < num_left; ++u) {
        if (matching[u] == -1) {
            memset(check, 0, sizeof(check));
            if (dfs(u))
                ++ans;
        }
    }
    return ans;
}
queue<int> Q;
int prev[__maxNodes];
int Hungarian()
{
    int ans = 0;
    memset(matching, -1, sizeof(matching));
    memset(check, -1, sizeof(check));
    for (int i=0; i<num_left; ++i) {
        if (matching[i] == -1) {
            while (!Q.empty()) Q.pop();
            Q.push(i);
            prev[i] = -1; // �� i Ϊ·�����
            bool flag = false; // ��δ�ҵ�����·
            while (!Q.empty() && !flag) {
                int u = Q.front();
                for (iterator_t ix = G[u].begin(); ix != G[u].end() && !flag; ++ix) {
                    int v = edges[*ix].to;
                    if (check[v] != i) {
                        check[v] = i;
                        Q.push(matching[v]);
                        if (matching[v] >= 0) { // �˵�Ϊƥ���
                            prev[matching[v]] = u;
                        } else { // �ҵ�δƥ��㣬����·��Ϊ����·
                            flag = true;
                            int d=u, e=v;
                            while (d != -1) {
                                int t = matching[d];
                                matching[d] = e;
                                matching[e] = d;
                                d = prev[d];
                                e = t;
                            }
                        }
                    }
                }
                Q.pop();
            }
            if (matching[i] != -1) ++ans;
        }
    }
    return ans;
}
