#include <iostream>
using namespace std;

class RMB {
private:
	double yuan, jf;
public:
	RMB(double, double);
	friend RMB operator+(RMB& a, RMB& b);
    friend RMB operator-(RMB& a, RMB& b);
	friend istream &operator>>(istream &is, RMB &t);
    friend ostream &operator<<(ostream &os, RMB &t);
	friend class Account; 
};

RMB::RMB(double y = 0.0, double j = 0.0):yuan(y), jf(j){}
RMB operator+(RMB& a, RMB& b) {
    RMB t;
    t.yuan = a.yuan + b.yuan;
    t.jf = a.jf + b.jf;
    if (t.jf >= 100) {
    	t.yuan++;
    	t.jf -= 100;
    }
    return t;
}
RMB operator-(RMB& a, RMB& b) {
    RMB t;
    t.yuan = a.yuan - b.yuan;
    t.jf = a.jf - b.jf;
    if (t.jf < 0) {
    	t.yuan--;
    	t.jf += 100;
    }
    return t;
}

istream& operator>>(istream &is, RMB &r) {
	cout << "��������:";
	cin >> r.yuan >> r.jf;
    return is;
}

ostream& operator<<(ostream &os, RMB &r) {
    cout << "���:" << r.yuan;
    if (r.jf == 0) return os;
	if (r.jf != 0) cout << ".";
	if (r.jf < 10) cout << "0";
	cout << r.jf;
    return os;
}

class Account{
private:
	string id, name; 
	RMB r;
public:
	void addMoney(RMB&);
	void subMoney(RMB&);
	bool check(Account&);
	friend istream &operator>>(istream &is, Account &t);
    friend ostream &operator<<(ostream &os, Account &t);
};

bool Account::check(Account& n) {
	if (this->id == n.id && this->name  == n.name)
		return true;
	else
		return false;
}

void Account::addMoney(RMB& t) {
	this->r = this->r + t;
	cout << "���ɹ�" << endl;
}

void Account::subMoney(RMB& t) {
	double has = this->r.yuan * 100 + this->r.jf;
	double cut = t.yuan * 100 + t.jf;
	if (has >= cut) {
		this->r = this->r - t;
		cout << this->r;
	} else {
		cout << "����" << endl;
	}
}

istream& operator>>(istream &is, Account &a) {
	cout << "�����뿨��:"; cin >> a.id;
	cout << "����������:"; cin >> a.name;
	return is;
}

ostream& operator<<(ostream &os, Account &a) {
    cout << "����: " << a.id << "\t";
	cout << "����: " << a.name << "\t"; 
	cout << a.r << endl; 
    return os;
}

void welcome() {
	cout << "**********��ӭ����**********" << endl;
	cout << "1.��� 2.ȡ�� 3.��ѯ 4.�˳� " << endl; 
	cout << "****************************" << endl;
}

int main()
{
	Account acc[100];
	int count = 1;
	while (true) {
		Account newacc;
		cin >> newacc;
		int index = 0;
		for (int i=1; i<=count; i++) {
			if (acc[i].check(newacc)){
				index = i;
			}
		}
		if (index == 0) {
			index = count; count++;
			acc[index] = newacc;
			cout << "�˺Ų�����,���½��˺�" << endl;
		} 
		welcome();
		while (true) {
			cout << "��ѡ��: ";
			int k; cin >> k;
			switch (k) {
				case 1:{
					RMB t;
					cin >> t;
					acc[index].addMoney(t);
					break;
				}
				case 2:{
					RMB t;
					cin >> t;
					acc[index].subMoney(t);
					break; 
				}
				case 3:{
					cout << acc[index]; 
					break;
				}
				case 4:{
					goto end; 
				}
				default: break; 
			}
			cout << endl;
		}
		end:
		cout << endl;
	}
	return 0;
}
