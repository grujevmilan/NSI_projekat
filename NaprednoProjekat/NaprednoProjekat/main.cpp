
#include <iostream>

using namespace std;

void foo(int)
{
	cout << "INFO: call foo(int)" << endl;
}

void foo(char*)
{
	cout << "INFO: call foo(char*)" << endl;
}

int main()
{
	foo(nullptr);
	foo(NULL);
	system("pause");
}