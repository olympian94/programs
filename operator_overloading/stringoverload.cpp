#include<iostream>
using namespace std;
/*

const char * const means pointer as well as the data the pointer pointed to, are both const!

const char * means only the data the pointer pointed to, is const. pointer itself however is not const.

Example.

const char *p = "Nawaz";
p[2] = 'S'; //error, changing the const data!
p="Sarfaraz"; //okay, changing the non-const pointer. 

const char * const p = "Nawaz";
p[2] = 'S'; //error, changing the const data!
p="Sarfaraz"; //error, changing the const pointer. 

*/
char * operator +(char *str1,char *str2);
int main()
{
	char str1[]="Abhishek";
	char str2[]="Tiwari";
	char *s1, s2;
	s1=str1;
	s2=str2;
	cout<<endl<<str1+str2;
	cout<<endl<<str1;
	cout<<endl<<str2;
}
char* operator+(char*str1,char*str2)
{
	char temp[sizeof(str1)+sizeof(str2)];
	int l=0;
	for(int j=0; str1[j]!=NULL; j++)
		temp[l++]=str1[j];
	for(int j=0; str1[j]!=NULL; j++)
		temp[l++]=str1[j];
	return temp;
}

