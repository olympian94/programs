#include<iostream>
using namespace std;

int main(int argc, char const *argv[])
{
	int * p = new int;
	*p=3;
	cout<<p<<"  "<<*p<<endl;
	delete p;
	cout<<p<<"  "<<*p<<endl;
	return 0;
}