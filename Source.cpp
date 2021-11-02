#include <iostream>
#include <string>
using namespace std;

template <class T1, class T2>
class Base 
{    
protected:
	T1 value1;    
	T2 value2;    
public:
	Base() {}
	Base(T1 value1, T2 value2)
	{
		this->value1 = value1;
		this->value2 = value2;
	}
	void Print()
	{
		cout << "value 1: " << value1 << endl;
		cout << "value 2: " << value2 << endl;
	}
	~Base() {}
}; 
 
template <class T1, class T2, class T3, class T4>
class Child: public Base <T1 , T2>
{
private:
	T3 value3;
	T4 value4;
public:    
	Child(){}
	Child(T1 value1, T2 value2, T3 value3, T4 value4) : Base<T1, T2>(value1, value2)
	{
		this->value3 = value3;
		this->value4 = value4;
	}
	void Print2()
	{
		cout << "value 3: " << value3 << endl;
		cout << "value 4: " << value4 << endl;
	}
	~Child() {}
}; 

template <class T1, class T2, class T3, class T4, class T5, class T6>
class Child2 : public Child <T1, T2, T3, T4>
{
private:
	T5 value5;
	T6 value6;
public:
	Child2() {}
	Child2(T1 value1, T2 value2, T3 value3, T4 value4, T5 value5, T6 value6) : Child<T1, T2, T3, T4>(value1, value2, value3, value4) 
	{
		this->value5 = value5;
		this->value6 = value6;
	}
	void Print3()
	{
		cout << "value 5: " << value5 << endl;
		cout << "value 6: " << value6 << endl;
	}
	~Child2() {}
};

int main() {
	Child2 <int, float, double, bool, char, string> test(5, 4.77, 5.2453, true, 't', "wwww");
	test.Print();
	cout << endl;
	test.Print2();
	cout << endl;
	test.Print3();
    return 0;
}