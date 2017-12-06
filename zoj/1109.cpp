#include <cstdio>
#include <cstring> 
#include <cstdlib>
#include <iostream>
using namespace std;

typedef struct Node{
    char ch;
    char str[30];
    struct Node *next[30];
}*TireTree, *pNode;

TireTree getEmptyTree() {
    TireTree root = (pNode)malloc(sizeof(struct Node));
    for (int i=0; i<30; i++)
        root->next[i] = NULL;
    return root; 
}

void insert(TireTree root, char key[], char word[]) {
    if (key[0] == '\0') {
        //到达目标节点
        strcpy(root->str, word); 
    } else {
        char new[30];
        int keyLen = strlen(key);
        for (int i=1; i<keyLen; i++) {
            new[i-1] = key[i];
        } 
        cout << new << endl;
        insert(root->next[])
        new[keyLen - 1] = '\0';
    } 
}

int main()
{
    freopen("input.txt", "r", stdin);
    TireTree T = getEmptyTree();
    char s[100];
    while (true) {
        gets(s);
        if (s[0] == '\0') break;
        int strLen = strlen(s);
        char word[100], key[100];
        strcpy(word, "");
        strcpy(key, "");
        
        int i=0;
        for (i=0; i<strLen; i++) {
            if (s[i] != ' ') {
                word[i] = s[i];  
            } else {
                word[i] = '\0';
                break;   
            }
        }
        int count = strlen(word);
        for (i = count; i<strLen; i++)
            key[i-count-1] = s[i];
        key[strLen - count] = '\0';
        cout << word << "?:" << key << "?  " << endl;
        insert(T, key, word);
    }
    cout << "------------------\n";
    while (scanf("%s",&s) != EOF) {
        cout << s << endl;
    } 
    
    cout << T->str;
    return 0;
    fclose(stdin);
}













