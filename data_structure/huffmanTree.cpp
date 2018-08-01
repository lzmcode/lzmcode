#include <iostream>
#include <queue>
#include <vector>
#include <cstring>
#include <algorithm>
using namespace std;

#define NULLCHAR '*'
#define MAXBUFROW 1010
#define MAXBUFCOL 1010
 
typedef struct Node {  
    int freq;  
    char ch;  
    struct Node *lchild, *rchild;  
    Node():freq(0), ch(NULLCHAR), lchild(NULL), rchild(NULL){}  
}*HuffmanTree, *pNode;

class Cmp {  
public:  
    bool operator() (const pNode a, const pNode b) const {  
        return  a->freq > b->freq;
    }  
};

priority_queue<Node*, vector<Node*>, Cmp> pq;  
  
HuffmanTree createTree() {
    int N; cin >> N;
    for (int i = 0; i < N; ++i) {  
        char ch; int num;
        cin >> ch >> num;
        pNode node = new Node();  
        node->freq = num; 
        node->ch = ch;  
        pq.push(node);  
    }
    while (pq.size() > 1) {
        pNode l = pq.top(); pq.pop();  
        pNode r = pq.top(); pq.pop();  
        pNode root = new Node();  
        root->freq = l->freq + r->freq;  
        root->lchild = l;  
        root->rchild = r;  
        pq.push(root);  
    }
    HuffmanTree root = pq.top(); pq.pop();
    return root;
}  
  
struct DictNode {  
    int freq;   
    char ch;
    string code;
};

vector<DictNode> hCode;  
bool cmp(const DictNode &a , const DictNode &b) {  
    return a.freq > b.freq;
}

void recordCode(pNode p, string ans) {
    if (!p) return;
    if (p->ch != NULLCHAR) {  
        DictNode pn;
        pn.ch = p->ch; 
        pn.freq = p->freq;  
        pn.code = ans;
        hCode.push_back(pn);
        return;  
    }
    recordCode(p->lchild, ans + "0");  
    recordCode(p->rchild, ans + "1");  
    //delete p->lchild;  
    //delete p->rchild;  
}

inline void printCode() {
    for (int i = 0; i < hCode.size(); ++i) {  
        cout << hCode[i].ch << " " << hCode[i].freq << " " << hCode[i].code << endl;  
    }
}

void encode() {
    FILE *fin = fopen("ToBeTra.txt", "r");
    FILE *fout = fopen("CodeFill.txt", "w");
    cout << "ENCODE: "; 
    char ch;
    while (fscanf(fin, "%c", &ch) != EOF) {
        for (int i=0; i < hCode.size(); ++i) {
            if (hCode[i].ch == ch) {
                fprintf(fout, "%s", hCode[i].code.c_str());
                cout << hCode[i].code;
                continue;
            }
        }
    }
    cout << endl; 
    fclose(fin); fclose(fout);
}

void decode() {
    FILE *fin = fopen("CodeFill.txt", "r");
    FILE *fout = fopen("Textfile.txt", "w");
    cout << "DECODE: ";
    char ch; string key = "";
    while (fscanf(fin, "%c", &ch) != EOF) {
        key += ch;
        for (int i=0; i < hCode.size(); ++i) {
            if (hCode[i].code == key) {
                fprintf(fout, "%c", hCode[i].ch);
                cout << hCode[i].ch;
                key = "";
                continue;
            }
        }
    }
    fclose(fin); fclose(fout);
    cout << endl;
}

void buildBuf(pNode p, int rx, int ry, int rc, char buf[][MAXBUFCOL]) {
    int l = rx - rc;
    int r = rx + rc;
    if (p->ch != NULLCHAR)
        return;
    else {
        buf[ry][rx] = p->ch;
        if(p->lchild != NULL) {
            buf[ry + 1][rx - 1] = '/';
            if (p->lchild->ch != NULLCHAR) 
                buf[ry + 2][rx - 2] = p->lchild->ch;
        }
        if(p->rchild != NULL) {
            buf[ry + 1][rx + 1] = '\\';
            if (p->rchild->ch != NULLCHAR)
                buf[ry + 2][rx + 2] = p->rchild->ch;
        }
        buildBuf(p->lchild, l-1, ry+2, (rc>>1), buf);
        buildBuf(p->rchild, r+2, ry+2, (rc>>1), buf);
    }
}

void printTree(HuffmanTree ht) {
    char buf[MAXBUFROW][MAXBUFCOL];
    memset(buf, ' ', sizeof(buf));
    buildBuf(ht, 12, 0, 4, buf);
    int line = 0;
    for (int i=0; i<MAXBUFROW; i++) {
        int j = MAXBUFCOL-1;
        while (buf[i][j] == ' ' && j >= 0)
            j--;
        buf[i][j+1] = '\0';
        if (j <= -1) break;
        line++;
    }
    for (int i=0; i<line; i++) {
        cout << buf[i] << endl;
    }
}

int main()  
{
    freopen("rank.txt", "r", stdin);
    HuffmanTree ht = createTree();
    recordCode(ht, "");
    sort(hCode.begin(), hCode.end(), cmp);
    printCode();
    printTree(ht);
    encode();
    decode();
    return 0;  
}  
