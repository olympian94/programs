#include<iostream>
using namespace std;
class complex
{
	private:
	double real, img;
	public:
	complex()
	{
		real=0;
		img=0;
	}
	void complex_set(double r, double i)
	{
		real=r; img=i;
	}	
	void complex_print()
	{
		cout<<endl<<real<<","<<img;
		cout<<endl;
	}
	complex operator +(complex c2);
	complex operator -(complex c2);		

	double getReal()
	{	return real;
	}
	double getImg()
	{	return img;
	}
};

complex complex:: operator +(complex c2)
{
	complex temp;
	temp.complex_set(this->getReal()+c2.getReal(),this->getImg()+c2.getImg());
	return temp;
}

complex complex:: operator -(complex c2)
{
	complex temp;
	temp.complex_set(this->getReal()-c2.getReal(),this->getImg()-c2.getImg());
	return temp;
}

int main()
{
	complex a, b, c;
	a.complex_set(1.5,1.5);
	b.complex_set(2.5,2.5);
	(a+a+b+b).complex_print();
	(a-b).complex_print();
	return 0;
}

