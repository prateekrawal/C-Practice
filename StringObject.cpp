
#include <iostream>
using namespace std;
#include <cstring>
class StrCnt
{
private:
	int count;
	char* str;
	friend class String;
	StrCnt(char* s)
	{
		int len=strlen(s);
		str=new char[len+1];
		strcpy(str,s);
		count=1;
	}
	~StrCnt()
	{
		delete [] str;
	}
};
class String
{
private:
	StrCnt* ptr;
public:
	String()
	{
		ptr=new StrCnt("NULL");
	}
	String(char* s)
	{
		ptr=new StrCnt(s);
	}
	String(String& s)//Copy constructor
	{
		ptr=s.ptr;
		(ptr->count)++;
	}
	~String()
	{
		if(ptr->count == 1)
			delete ptr;
		else
			(ptr->count)--;
	}
	void display()
	{
		cout<<ptr->str<<endl;
		cout<<"Address is "<<ptr<<endl;
	}
	void operator =(String& S) //assign the string
	{
		ptr=S.ptr;
		(ptr->count)++;

	}
};
int main()
{
	char abc[]="hey thsi is Mike Ross\n";
	String s1(abc);
	cout<<"String 1 is \n";s1.display();
	String s2;
	s2=s1;
	cout<<"String s2 is \n"; s2.display();
	String s3(s2);
	cout<<"String s3 is \n"; s3.display();
	return 0;
}