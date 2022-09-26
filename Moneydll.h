#ifdef MONEYDLL_EXPORTS
#define MONEYDLL_API __declspec(dllexport)
#else
#define MONEYDLL_API __declspec(dllimport)
#endif

#pragma once
#include <string>
using namespace std;

namespace Moneylib {
	class Money {
		long hrn;	//	Гривні
		unsigned short kop;	//	Копійки

	public:
		MONEYDLL_API Money();
		MONEYDLL_API Money Read();	//	Введення з клавіатури
		MONEYDLL_API Money(long h, unsigned short k);
		MONEYDLL_API void Display();
		MONEYDLL_API string toString();	//	Перетворення на рядок
		MONEYDLL_API Money operator+(Money obj);
		MONEYDLL_API friend double operator-(Money obj1, Money obj2);
		MONEYDLL_API friend double operator*(Money obj1, Money obj2);
		MONEYDLL_API friend double operator/(Money obj1, Money obj2);
		MONEYDLL_API friend bool operator==(Money obj1, Money obj2);
	};
}