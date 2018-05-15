#include <iostream>
#include <queue>
#include <cstring>
#include <vector>
#include <algorithm>
using namespace std;

#define ENDCHAR '('
#define NULLCHAR '#'

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
    int N;
    cin >> N;
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
  
struct PrintNode {  
    int freq;   
    char ch;
    string code;
};

vector<PrintNode> hCode;  
bool cmp(const PrintNode &a , const PrintNode &b) {  
    return a.freq > b.freq;
}

void recordCode(pNode p, string ans) {
    if (!p) return;
    if (p->ch != NULLCHAR) {  
        PrintNode pn;
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

inline void printAllCode() {
    for (int i = 0; i < hCode.size(); ++i) {  
        cout << hCode[i].ch << " " << hCode[i].freq << " " << hCode[i].code << endl;  
    }
}

void encode() {
    FILE *fin = fopen("ToBeTra.txt", "r");
    FILE *fout = fopen("CodeFill.txt", "w");
    char ch;
    while (fscanf(fin, "%c", &ch) != EOF) {
        for (int i=0; i < hCode.size(); ++i) {
            if (hCode[i].ch == ch) {
                fprintf(fout, "%s", hCode[i].code.c_str());
                continue;
            }
        }
    }
    fclose(fin); fclose(fout);
    cout << "Encode success" << endl;
}

void decode() {
    FILE *fin = fopen("CodeFill.txt", "r");
    FILE *fout = fopen("Textfile.txt", "w");
    char ch; string key = "";
    while (fscanf(fin, "%c", &ch) != EOF) {
        key += ch;
        for (int i=0; i < hCode.size(); ++i) {
            if (hCode[i].code == key) {
                fprintf(fout, "%c", hCode[i].ch);
                key = "";
                continue;
            }
        }
    }
    fclose(fin); fclose(fout);
    cout << "Decode success" << endl;
}

void print_tree(pNode p, int rx, int ry, int rc, char buf[][MAXBUFCOL]) {
    int l = rx - rc;
    int r = rx + rc;
    if (p->ch != NULLCHAR)
        return;
    else {
        buf[ry][rx] = p->ch;
        if(p->lchild != NULL) {
            buf[ry + 1][rx - 1]='/';
            if (p->lchild->ch != NULLCHAR) 
                buf[ry + 2][rx - 2] = p->lchild->ch;
        }
        if(p->rchild != NULL) {
            buf[ry + 1][rx + 1]='\\';
            if (p->rchild->ch != NULLCHAR)
                buf[ry + 2][rx + 2] = p->rchild->ch;
        }
        print_tree(p->lchild, l, ry+2, (rc>>1), buf);
        print_tree(p->rchild, r, ry+2, (rc>>1), buf);
    }
}

void printTree(HuffmanTree ht) {
    char buf[MAXBUFROW][MAXBUFCOL];
    for (int i=0; i<MAXBUFROW; i++) {
        for (int j=0; j<MAXBUFCOL; j++) {
            buf[i][j] = ' ';
        }
    }
    print_tree(ht, 8, 0, 4, buf);
    int line = 0;
    for (int i=0; i<MAXBUFROW; i++) {
        int j = MAXBUFCOL-1;
        while (buf[i][j] == ' ' && j >= 0)
            j--;
        if (j > -1) {
           buf[i][j+1] = ENDCHAR;
           line++;
           continue;
        }
        else
           break;
    }
    for (int i=0; i<line; i++) {
        for (int j=0; j<MAXBUFCOL; j++) {
            if (buf[i][j] != ENDCHAR)
                cout << buf[i][j];
            else
                break;
        }
        cout << endl;
    }
}

int main()  
{
    freopen("rank.txt", "r", stdin); 
    HuffmanTree ht = createTree();
    recordCode(ht, "");
    sort(hCode.begin(), hCode.end(), cmp);
    printAllCode();
    printTree(ht);
    encode();
    decode();
    return 0;  
}  
