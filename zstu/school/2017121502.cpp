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
    cout << "标题: " << title << endl
         << "书名: " << name << endl 
         << "日期: " << year << "-" << month << "-" << day << endl
		 << "价格: " << price << endl;
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
    cout << "页数: " << page << endl;
}

void init(){
    cout << "********对象初始化演示实例" << endl;
    cout << "1．普通对象初始化实例1(带参数的构造函数)" << endl;
    cout << "2．普通对象初始化实例2(用拷贝构造函数初始化)" << endl;
    cout << "3．派生类对象初始化实例(初始化列表)" << endl;
    cout << "4．子对象初始化实例（对象成员）" << endl;
    cout << "5．退出程序" << endl;
}
int main()
{
    init();
    while (true){
    	cout << endl;
    	int cmd;
		cout << "选择1-5: ";
		cin >> cmd;
		switch (cmd){
			case 1: {
				Publication p("一般出版物", "大众生活", 32.6, 2012, 5 ,13);
				p.display();
				break;
			}
			case 2: {
				Publication p1("一般出版物", "大众生活", 32.6, 2012, 5 ,13);
				Publication p2(p1);
				p2.display();
				break;
			}
			case 3:{
				Book b("计算机专业书籍", "C++面向对象程序设计", 42.5, 2012, 8, 12, 356);
				b.display();
				break;
			}
			case 4:{
				Publication p("计算机专业书籍", "C++面向对象程序设计", 42.5, 2012, 8, 12);
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
