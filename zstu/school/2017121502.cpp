#include <iostream>
#include <cstring>
using namespace std;

class Publication{
public:
    string title;
    string name;
    double price;
    int year, month, day; //date
    
    Publication();
    Publication(string, string, double, int, int, int);
    Publication(const Publication&);
    void display();
};
Publication::Publication(){}
Publication::Publication(string t, string n, double p, int y, int m, int d){
	title = t; name = n; price = p;
	year = y; month = m; day = d;
}
Publication::Publication(const Publication& p) {
	title = p.title;
	name = p.name;
	price = p.price;
	year = p.year;
	month = p.month;
	day = p.day;
} 

void Publication::display(){
    cout << "����: " << title << endl
         << "����: " << name << endl 
         << "����: " << year << "-" << month << "-" << day << endl
		 << "�۸�: " << price << endl;
}

class Book:private Publication{
private:
    int page;
public:
    Book();
    Book(Publication&, int);
    Book(string, string, double, int, int, int, int);
    void display();
};
Book::Book(){}
Book::Book(string t, string n, double p, int y, int m, int d, int bp):
    Publication(t, n, p, y, m, d),page(bp){}
Book::Book(Publication &p, int ip) {
	title = p.title; name = p.name;	price = p.price;
	year = p.year; month = p.month;	day = p.day;
	page = ip;
}

void Book::display(){
    Publication::display();
    cout << "ҳ��: " << page << endl;
}

void init(){
    cout << "********�����ʼ����ʾʵ��" << endl;
    cout << "1����ͨ�����ʼ��ʵ��1(�������Ĺ��캯��)" << endl;
    cout << "2����ͨ�����ʼ��ʵ��2(�ÿ������캯����ʼ��)" << endl;
    cout << "3������������ʼ��ʵ��(��ʼ���б�)" << endl;
    cout << "4���Ӷ����ʼ��ʵ���������Ա��" << endl;
    cout << "5���˳�����" << endl;
}
int main()
{
    init();
    while (true){
    	cout << endl;
    	int cmd;
		cout << "ѡ��1-5: ";
		cin >> cmd;
		switch (cmd){
			case 1: {
				Publication p("һ�������", "��������", 32.6, 2012, 5 ,13);
				p.display();
				break;
			}
			case 2: {
				Publication p1("һ�������", "��������", 32.6, 2012, 5 ,13);
				Publication p2(p1);
				p2.display();
				break;
			}
			case 3:{
				Book b("�����רҵ�鼮", "C++�������������", 42.5, 2012, 8, 12, 356);
				b.display();
				break;
			}
			case 4:{
				Publication p("�����רҵ�鼮", "C++�������������", 42.5, 2012, 8, 12);
				Book b(p, 356);
				b.display();
				break;
			}
			case 5:{
				return 0;
				break;
			}
			default:
				break;
		}
    }
    return 0;
}
