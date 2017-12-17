#include <cstdio>
#include <cstdlib> 
#include <cstring>
#include <cstring>
#include <fstream>
#include <iostream>
using namespace std;

typedef struct Node {
    string id, name;
    double math, chinese;
    struct Node *next;
}*LinkList, *pNode;
LinkList getEmptyList() {
    LinkList head = new Node;
    head->next = NULL;
    return head;
}
bool check(LinkList head, Node* t) {
    pNode p = head, q;
    while (p->next != NULL)
    {
        if (p->next->id == t->id &&
            p->next->name == t->name &&
            p->next->math == t->math &&
            p->next->chinese == t->chinese) {
            return true;
        }
        q = p->next;
        p = p->next;
    }
    return false;
} 
void printNode(Node* q){
    cout << q->id << "\t";
    cout << q->name << "\t";
    cout << q->math << "\t";
    cout << q->chinese << "\t";
    cout << (q->math + q->chinese) / 2  << "\t";   
    cout << endl;
} 
void init() {
    cout << "1.增加原始记录" << endl; //OK
    cout << "2.显示各种文件" << endl; //OK
    cout << "3.保存原始文件" << endl; //OK
    cout << "4.读取原始文件" << endl; //OK
    cout << "5.删除原始记录" << endl; //OK
    cout << "6.建立简明文件" << endl; //OK
    cout << "7.均不及格文件" << endl; //OK
    cout << "8.寻找链表记录" << endl; //OK
    cout << "9.结束程序运行" << endl; //OK
}
void printHead() {
    cout << "学号\t名字\t数学\t语文\t平均\n";
}
void addNode(LinkList head,pNode newNode) {
    newNode->next = head->next;
    head->next = newNode;
}
void showList(LinkList head) {
    ifstream infile("stud.dat");
    int count = 0;
    string id, name;
    double math, chinese;
    cout << "取文件...." << endl; 
    char c;
    infile >> id;
    while ((c=infile.get())!=EOF) {
        pNode p = new Node;
        infile >> name >> math >> chinese;
        p->id = id;
        p->name = name;
        p->math = math;
        p->chinese = chinese;
        infile >> id;
        printNode(p);
        count++;
    }
    cout << "取入" << count << "条记录。" << endl;
    infile.close();
}
void showSimpleList(LinkList head) {
    ifstream infile("studmean.dat");
    int count = 0;
    string name;
    double aver;
    cout << "取文件...." << endl; 
    char c;
    infile >> name;
    cout << "姓名\t平均\n";
    while ((c=infile.get())!=EOF) {
        infile >> aver;
        cout << name << "\t" <<aver << endl;
        infile >> name;
        count++;
    }
    cout << "取入" << count << "条记录。" << endl;
    infile.close();
}
void showFailedList(LinkList head) {
    ifstream infile("bad.dat");
    int count = 0;
    string id, name;
    double math, chinese;
    cout << "取文件...." << endl; 
    char c;
    infile >> id;
    while ((c=infile.get())!=EOF) {
        pNode p = new Node;
        infile >> name >> math >> chinese;
        p->id = id;
        p->name = name;
        p->math = math;
        p->chinese = chinese;
        infile >> id;
        printNode(p);
        count++;
    }
    cout << "取入" << count << "条记录。" << endl;
    infile.close();
}
void showUpList(LinkList head) {
    pNode p = head, q;
    double sum = 0.0;
    int count = 0;
    while (p->next != NULL) {
        sum += p->next->math;
        sum += p->next->chinese;
		q = p->next;
        p = p->next;
        count++;
    }
    p = head;
    double ave = sum / (double)count;
    while (p->next != NULL) {
        if (p->next->math + p->next->chinese >= ave) {
            printNode(p->next);
        }
        q = p->next;
        p = p->next;
    }
}
void showAll(LinkList LL) {
	cout << "选择要查看的文件类别" << endl;
	cout << "1.原文件" << endl;
	cout << "2.简明文件" << endl;
	cout << "3.均不及格文件" << endl;
	cout << "4.输出高于或等于平均成绩的学生" << endl;
	cout << endl;
	cout << "请选择1-4: ";
	int k;
	cin >> k;
	switch (k){
	    case 1:{
	        printHead();
	        showList(LL); 
	    	break;
	    }
	    case 2:{
	        cout << "名字\t平均\n";
	        showSimpleList(LL);
	    	break;
	    }
	    case 3:{
	        printHead();
	        showFailedList(LL);
	    	break;
	    }
	    case 4:{
	        printHead();
	        showUpList(LL);
	    	break;
	    }
	    default: break;
	}
}
void read(LinkList head) {
    ifstream infile("stud.dat");
    int count = 0;
    string id, name;
    int math, chinese;
    
    char c;
    infile >> id;
    while ((c=infile.get())!=EOF) {
        pNode p = new Node;
        infile >> name >> math >> chinese;
        p->id = id;
        p->name = name;
        p->math = math;
        p->chinese = chinese;
        infile >> id;
        if (!check(head, p)) {
            addNode(head, p);
        }
        count++;
    }
    cout << "取入" << count << "条记录。" << endl;
    infile.close();
}
void save(LinkList head) {
	//保存文件
	read(head);
	ofstream file;
	file.open("stud.dat");
	pNode p = head, q;
	int count = 0;
    while (p->next != NULL)
    {
        file << p->next->id << " " << p->next->name << " " << p->next->math << " "  << p->next->chinese << endl;
		q = p->next;
        p = p->next;
        count++;
    }
	cout << "保存" << count << "条记录。" << endl;
	file.close();
	/*
	FILE *fp = NULL;
	if((fp=fopen("stud1.dat","w"))==NULL) {
		printf("File cannot be opened/n");
		return;
	}
	else
		printf("存文件....\n");
	int count = 0;
	
	pNode p = head, q;
    while (p->next != NULL)
    {
        char* id;
        int len1 = p->next->id.length();
        id = new char[len1+1];
        strcpy(id, p->next->id.c_str());

        char* name;
        int len2 = p->next->name.length();
        name = new char[len2+1];
        strcpy(name, p->next->name.c_str());

        fprintf(fp, "%s %s ", id, name);
    	fprintf(fp, "%.0lf %.0lf\n", p->next->math, p->next->chinese);
		q = p->next;
        p = p->next;
        count++;
    }

	cout << "保存" << count << "条记录。" << endl;
	fclose(fp);*/
}
void del(LinkList head) {
	cout << "1.通过学号寻找" << endl;
	cout << "2.通过名字寻找" << endl;
	int k;
	cin >> k;
	bool flag = false;
	if (k == 1) {
		string id;
		cin >> id;
		pNode p = head, q;
	    while (p->next != NULL) {
	    	if (p->next->id == id) {
	    		if (!flag) {
					cout << "被删除记录如下" << endl;
					printHead();
					flag = true;
				}
	    		printNode(p->next);
				q = p->next;
				p->next = p->next->next;
                free(q);
				return;
            }
			q = p->next;
			p = p->next;
	    }
	}
	if (k == 2) {
		string name;
		cin >> name;
		pNode p = head, q;
	    while (p->next != NULL)
	    {
	    	if (p->next->name == name) {
	    		if (!flag) {
					cout << "被删除记录如下" << endl;
					printHead();
					flag = true;
				}
	    		printNode(p->next);
				q = p->next;
				p->next = p->next->next;
                free(q);
				return;
	    	}
			q = p->next;
			p = p->next;
	    }
	}
	if (!flag) cout << "该记录不存在" << endl; 
}
void saveSimple(LinkList head) {
    ofstream file;
	file.open("studmean.dat");
	int count = 0;
	pNode p = head, q;
    while (p->next != NULL)
    {
        file << p->next->name << " " << (p->next->math + p->next->chinese) / 2 << endl;
		q = p->next;
        p = p->next;
        count++;
    }
	cout << "保存" << count << "条记录。" << endl;
	file.close(); 
}
void saveBad(LinkList head) {
    ofstream file;
	file.open("bad.dat");
	int count = 0;
	pNode p = head, q;
    while (p->next != NULL)
    {
        if (p->next->math < 60 && p->next->chinese < 60) {
            file << p->next->id << " " << p->next->name << " " << p->next->math << " "  << p->next->chinese << endl;
            count++;
        }
        q = p->next;
        p = p->next;
    }
	cout << "保存" << count << "条记录。" << endl;
	file.close();
}
void search(LinkList head) {
	cout << "1.通过学号寻找" << endl;
	cout << "2.通过名字寻找" << endl;
	int k;
	cin >> k;
	bool flag = false;
	if (k == 1) {
		string id;
		cin >> id;
		pNode p = head, q;
	    while (p->next != NULL)
	    {
	    	if (p->next->id == id) {
	    		if (!flag) {
					cout << "找到记录如下" << endl;
					printHead();
					flag = true;
				}
	    		printNode(p->next);
	    	}
			q = p->next;
			p = p->next;
	    }
	}
	if (k == 2) {
		string name;
		cin >> name;
		pNode p = head, q;
	    while (p->next != NULL)
	    {
	    	if (p->next->name == name) {
	    		if (!flag) {
					cout << "找到记录如下" << endl;
					printHead();
					flag = true;
				}
	    		printNode(p->next);
	    	}
			q = p->next;
			p = p->next;
	    }
	}
	if (!flag) cout << "该记录不存在" << endl; 
}
int main()
{
	init();
	cout << endl;
	LinkList LL = getEmptyList();
	
    int cmd;
    while (true) {
        cout << "左边数字对应相应功能选择,请选择1-9: ";
        cin >> cmd;
		switch (cmd) {
            case 1:{
            	while (true) {
            		pNode p = new Node;
	            	cout << "学号: "; cin >> p->id;
	            	if (p->id == "0") break;
	            	cout << "名字: "; cin >> p->name;
	            	cout << "语文: "; cin >> p->math;
	            	cout << "数学: "; cin >> p->chinese;
	         		addNode(LL, p);
            	}
            	break;
            }
            case 2:{
				showAll(LL);
            	break;
            }
            case 3:{
            	save(LL);
            	break;
            }
            case 4:{
            	read(LL);
            	break;
            }
            case 5:{
                del(LL);
            	break;
            }
            case 6:{
                saveSimple(LL);
            	break;
            }
            case 7:{
                saveBad(LL);
            	break;
            }
            case 8:{
                search(LL); 
                break;
            }
            case 9:{
            	break;
            }
            default: break;
        }
        cout << endl; 
    }
    //fclose(stdin);
    return 0;
}

