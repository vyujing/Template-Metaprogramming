#include <iostream>
using namespace std;

template<typename T>
struct has_virtual
{
	class A : public T
	{ virtual void foo(){} };
	static const bool value = (sizeof(T) == sizeof(A));
};

template<typename T> void foo(const T& a)
{
	if(has_virtual<T>::value)
		cout << "has virtual" << endl;
	else
		cout << "not has virtual" << endl;
}

class hasV
{
	virtual void foo(){}
};

class notHasV
{
	void foo(){};
};

int main()
{
	hasV v1;
	notHasV v2;

	foo(v1);
	foo(v2);
}

