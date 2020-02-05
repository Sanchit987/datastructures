#include <iostream>
#include <string>

using namespace std;

class stack
{
private:
	int len=100;
	char arr[100];
public:
	int top;
	stack()
	{
		top=-1;
	}
	void push(char);
	char pop();
	void display();
	char top_ele();
	int _top();
};
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

char stack :: top_ele()
{
	return arr[top];
}

int stack :: _top()
{
	return top;
}

void tower(int n,char beg,char aux,char last)
{
	stack stn,stbeg,staux,stlast,stadd;
	char swp;
	int add;
one:
	if(n==1)
	{
		cout<<"Move disk "<<n<<" from "<<beg<<" to "<<last<<endl;
		goto four;
	}
two:
	stn.push(n);
	stbeg.push(beg);
	staux.push(aux);
	stlast.push(last);
	stadd.push(3);
	n--;
	beg=beg;
	swp=aux;
	aux=last;
	last=swp;
	goto one;
three:
	cout<<"Move disk "<<n<<" from "<<beg<<" to "<<last<<endl;
	stn.push(n);
	stbeg.push(beg);
	staux.push(aux);
	stlast.push(last);
	stadd.push(5);
	n--;
	swp=beg;
	beg=aux;
	aux=swp;
	last=last;
	goto one;
four:
	if(stbeg._top()==-1)
		return;
	n=stn.pop();
	beg=stbeg.pop();
	aux=staux.pop();
	last=stlast.pop();
	add=stadd.pop();
	if(add==3)
	{
		goto three;
	}
	else if(add==5)
	{
		goto four;
	}
}
int main()
{
	int n;
	cout<<"Enter the number of disks: ";
	cin>>n;
	tower(n,'A','B','C');
	return 0;
}
