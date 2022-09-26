#include "Moneydll.h"
#include <iostream>
#include <string>
using namespace std;

namespace Moneylib {

	Money::Money(long h, unsigned short k)	//	�������� ������� (������)
	{
		hrn = h;
		kop = k;
		cout << "\n���: " << h << endl;
		cout << "���: " << k << endl;
		if (k >= 100) {
			while (k >= 100) {
				k -= 100;
				h++;
			}
		}
	}

	Money::Money()	//	����������� �� ����������
	{
		hrn = 0;
		kop = 0;
	}

	Money Money::Read()
	{
		cout << "\n���: ";
		cin >> this->hrn;
		cout << "���: ";
		cin >> this->kop;
		if (this->kop >= 100) {
			while (this->kop >= 100) {
				this->kop -= 100;
				this->hrn++;
			}
		}
		else return *this;
	}

	string Money::toString()
	{
		string res(to_string(hrn) + "." + to_string(kop));	//	�'������ ����� � ��������
		return res;
	}

	Money Money::operator+(Money obj)
	{
		Money tmp;
		tmp.hrn = hrn + obj.hrn;
		tmp.kop = kop + obj.kop;
		while (tmp.kop >= 100) {
			tmp.kop -= 100;
			tmp.hrn++;
		}
		cout << "\n����: " << tmp.hrn << "." << tmp.kop << endl;

		return tmp;
	}

	void Money::Display()
	{
		cout << "\n�������: " << toString() << " ���." << endl;
	}

	double operator-(Money obj1, Money obj2)
	{
		string a = to_string(obj1.hrn) + "." + to_string(obj1.kop);
		string b = to_string(obj2.hrn) + "." + to_string(obj2.kop);
		double c = stod(a);
		double d = stod(b);
		cout << "\nг�����: " << c - d << " ���." << endl;
		return c - d;
	}

	double operator*(Money obj1, Money obj2)
	{
		string a = to_string(obj1.hrn) + "." + to_string(obj1.kop);
		string b = to_string(obj2.hrn) + "." + to_string(obj2.kop);
		double c = stod(a);
		double d = stod(b);
		cout << "\n��������: " << c * d << " ���." << endl;
		return c * d;
	}

	double operator/(Money obj1, Money obj2)
	{
		string a = to_string(obj1.hrn) + "." + to_string(obj1.kop);
		string b = to_string(obj2.hrn) + "." + to_string(obj2.kop);
		double c = stod(a);
		double d = stod(b);
		if (d != 0) {
			cout << "\nĳ�����: " << c / d << " ���." << endl;
			return c / d;
		}
		else {
			cout << "\nĳ����� �� 0 ���������." << endl;
			return -1;
		}
	}


	bool operator==(Money obj1, Money obj2)
	{
		if (obj1.hrn == obj2.hrn && obj1.kop == obj2.kop) {
			cout << "\n���������: " << obj1.hrn << "." << obj1.kop << " ������� " << obj2.hrn << "." << obj2.kop << endl;
			return true;
		}
		else {
			cout << "\n���������: " << obj1.hrn << "." << obj1.kop << " �� ������� " << obj2.hrn << "." << obj2.kop << endl;
			return false;
		}
	}
}