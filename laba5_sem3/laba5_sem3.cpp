#include <vector>
#include <iostream>
using namespace std;

struct numb {
public:
	int num1;
	int num2;
};
class PAIR {
public:
	int first = 0;
	int second = 0;
	virtual void add(numb a) = 0;
};

class Rational : PAIR {
public:
	Rational(const int& f, const int& s) {
		first = f;
		second = s;
	}
	Rational(numb a) {
		first = a.num1;
		second = a.num2;
	}
	void add(numb a) {
		int x, y;
		y = a.num2 * second / nod(a.num2, second);
		x = a.num1 * (y / a.num2) + first * (y / second);
		first = x;
		second = y;
	}
private:
	int nod(int a0, int b0) {
		int a = a0, b = b0;
		while (a % b != 0) {
			a %= b;
			swap(a, b);
		}
		return b;
	}
};

class Complex : PAIR {
public:
	Complex(const int& a, const int& b) {
		first = a;
		second = b;
	}
	void add(numb a) {
		first += a.num1;
		second += a.num2;
	}
};

int main()
{
	Rational r(1, 2);
	numb n;
	n.num1 = 2;
	n.num2 = 3;
	r.add(n);
	vector<PAIR*> vec;
}

