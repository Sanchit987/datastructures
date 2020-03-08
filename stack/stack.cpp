#include <iostream>
#include <string>
#include <string.h>
using namespace std;
class stack
{
private:
	int top,len=100;
	char arr[100];
public:
	stack()
	{
		top=-1;
	}
	void push(char);
	char pop();
	void display();
	char top_val();
};

void ispalidrome();
void parenthesis_check(string abc);

int main()
{
	stack obj1;
	here:
	char ele;
	int c;
	string abc;
	cout<<"Enter the function you want to perform : "<<endl;
	cout<<"1. Push : "<<endl;
	cout<<"2. Pop : "<<endl;
	cout<<"3. Display : "<<endl;
	cout<<"4. Check palidrome : "<<endl;
	cout<<"5. parenthesis check : "<<endl;
	cin>>c;
	switch(c)
	{
		case 1:
			cout<<"Enter Element to be Pushed : "<<endl;
			cin>>ele;
			obj1.push(ele);
			break;
		case 2:
			obj1.pop();
			break;
		case 3:
			obj1.display();
			break;
		case 4:
			ispalidrome();
			break;
		case 5:
			cout<<"Enter the string : "<<endl;
			cin.ignore();
			getline(cin,abc);
			parenthesis_check(abc);
			break;
		default:
			goto exi;
	}
	char ch;
	cout<<"Want to perform anything else? (y/n)"<<endl;
	cin>>ch;
	if(ch == 'y' || ch == 'Y')
	{
		goto here;
	}
	exi:
	cout<<"Thanks for using"<<endl;
}

void stack :: push(char x)
{
	int check = top+1;
	try
	{
		if(check>=len-1)
		{
			throw top;
		}
		else
		{
			top++;
			arr[top]=x;
		}
	}
	catch(int)
	{
		cout<<"Stack Overflow"<<endl;
	}
}

char stack :: pop()
{
	int check = top-1;
	try
	{
		if(check<-1)
		{
			throw top;
		}
		else
		{
			top--;
			return arr[top+1];
		}
	}
	catch(int)
	{
		cout<<"Stack Underflow"<<endl;
	}
}

void stack :: display()
{
	cout<<"Element at "<<top<<" position is "<<arr[top]<<endl;
}

char stack :: top_val()
{
	return arr[top];
}

void ispalidrome()
{
	string str;
	cout<<"Enter string : "<<endl;
	cin>>str;
	int ln = str.length();
	stack st;
	int fir = ln/2;
	int flag = 1;
	if(ln%2 == 0)
	{
		for(int i=0;i<fir;i++)
		{
			st.push(str.at(i));
			flag++;
		}
		for(int i=fir;i<ln-1;i++)
		{
			if(str.at(i)==st.pop())
			{
				flag++;
				continue;
			}
			else
			{
				cout<<"Not a Palidrome"<<endl;
				break;
			}
		}
		if(flag==ln)
		{
			cout<<"String is a palidrome"<<endl;
		}
	}
	if(ln%2 != 0)
	{
		for(int i=0;i<fir+1;i++)
		{
			flag++;
			st.push(str.at(i));
		}
		for(int i=fir;i<=ln-1;i++)
		{
			flag++;
			if(str.at(i)==st.pop())
			{
				continue;
			}
			else
			{
				cout<<"Not a Palidrome"<<endl;
				break;
			}
		}
	}
	if(flag==ln+2)
	{
		cout<<"String is a palidrome"<<endl;
	}
}

void parenthesis_check(string abc)
{
	stack par_store;
	int n = abc.length();
	int c = 0;
	for(int i =0;i<n;i++)
	{
		if(abc.at(i) == '{')
		{
			par_store.push('{');
			c++;
			continue;
		}
		if(abc.at(i) == '}')
		{
			if(par_store.top_val() == '{')
			{
				par_store.pop();
				c--;
			}
		}
	}
	if(c == 0)
	{
		cout<<"No Error"<<endl;
	}
	else
	{
		cout<<"parenthesis Error"<<endl;
	}
}
