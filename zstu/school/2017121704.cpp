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
    cout << "1.����ԭʼ��¼" << endl; //OK
    cout << "2.��ʾ�����ļ�" << endl; //OK
    cout << "3.����ԭʼ�ļ�" << endl; //OK
    cout << "4.��ȡԭʼ�ļ�" << endl; //OK
    cout << "5.ɾ��ԭʼ��¼" << endl; //OK
    cout << "6.���������ļ�" << endl; //OK
    cout << "7.���������ļ�" << endl; //OK
    cout << "8.Ѱ�������¼" << endl; //OK
    cout << "9.������������" << endl; //OK
}
void printHead() {
    cout << "ѧ��\t����\t��ѧ\t����\tƽ��\n";
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
    cout << "ȡ�ļ�...." << endl; 
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
    cout << "ȡ��" << count << "����¼��" << endl;
    infile.close();
}
void showSimpleList(LinkList head) {
    ifstream infile("studmean.dat");
    int count = 0;
    string name;
    double aver;
    cout << "ȡ�ļ�...." << endl; 
    char c;
    infile >> name;
    cout << "����\tƽ��\n";
    while ((c=infile.get())!=EOF) {
        infile >> aver;
        cout << name << "\t" <<aver << endl;
        infile >> name;
        count++;
    }
    cout << "ȡ��" << count << "����¼��" << endl;
    infile.close();
}
void showFailedList(LinkList head) {
    ifstream infile("bad.dat");
    int count = 0;
    string id, name;
    double math, chinese;
    cout << "ȡ�ļ�...." << endl; 
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
    cout << "ȡ��" << count << "����¼��" << endl;
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
	cout << "ѡ��Ҫ�鿴���ļ����" << endl;
	cout << "1.ԭ�ļ�" << endl;
	cout << "2.�����ļ�" << endl;
	cout << "3.���������ļ�" << endl;
	cout << "4.������ڻ����ƽ���ɼ���ѧ��" << endl;
	cout << endl;
	cout << "��ѡ��1-4: ";
	int k;
	cin >> k;
	switch (k){
	    case 1:{
	        printHead();
	        showList(LL); 
	    	break;
	    }
	    case 2:{
	        cout << "����\tƽ��\n";
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
    cout << "ȡ��" << count << "����¼��" << endl;
    infile.close();
}
void save(LinkList head) {
	//�����ļ�
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
	cout << "����" << count << "����¼��" << endl;
	file.close();
	/*
	FILE *fp = NULL;
	if((fp=fopen("stud1.dat","w"))==NULL) {
		printf("File cannot be opened/n");
		return;
	}
	else
		printf("���ļ�....\n");
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

	cout << "����" << count << "����¼��" << endl;
	fclose(fp);*/
}
void del(LinkList head) {
	cout << "1.ͨ��ѧ��Ѱ��" << endl;
	cout << "2.ͨ������Ѱ��" << endl;
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
					cout << "��ɾ����¼����" << endl;
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
					cout << "��ɾ����¼����" << endl;
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
	if (!flag) cout << "�ü�¼������" << endl; 
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
	cout << "����" << count << "����¼��" << endl;
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
	cout << "����" << count << "����¼��" << endl;
	file.close();
}
void search(LinkList head) {
	cout << "1.ͨ��ѧ��Ѱ��" << endl;
	cout << "2.ͨ������Ѱ��" << endl;
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
					cout << "�ҵ���¼����" << endl;
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
					cout << "�ҵ���¼����" << endl;
					printHead();
					flag = true;
				}
	    		printNode(p->next);
	    	}
			q = p->next;
			p = p->next;
	    }
	}
	if (!flag) cout << "�ü�¼������" << endl; 
}
int main()
{
	init();
	cout << endl;
	LinkList LL = getEmptyList();
	
    int cmd;
    while (true) {
        cout << "������ֶ�Ӧ��Ӧ����ѡ��,��ѡ��1-9: ";
        cin >> cmd;
		switch (cmd) {
            case 1:{
            	while (true) {
            		pNode p = new Node;
	            	cout << "ѧ��: "; cin >> p->id;
	            	if (p->id == "0") break;
	            	cout << "����: "; cin >> p->name;
	            	cout << "����: "; cin >> p->math;
	            	cout << "��ѧ: "; cin >> p->chinese;
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

