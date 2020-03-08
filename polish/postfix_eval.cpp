#include <iostream>
#include<string>

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
};

int postfix_eval(string post);

int main()
{
    string exp;
    cout<<"Enter the Expression "<<endl;
    getline(cin,exp);
    int required = postfix_eval(exp);
    cout<<required<<endl;
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

char stack :: top_ele()
{
    return arr[top];
}

int postfix_eval(string post)
{
    post.push_back(')');
    int i=0;
    stack numb;
    while(post.at(i) != ')')
    {
        if((post.at(i) >= '0'&& post.at(i)<= '9'))
        {
            numb.push(post.at(i));
        }
        else if((post.at(i) == '+')||(post.at(i) == '-')||(post.at(i) == '/')||(post.at(i) == '*'))
        {   int res;
            int a,b;
            numb.push(post.at(i));
            switch(numb.pop())
            {
                case '+':
                    a = numb.pop()-'0';
                    b = numb.pop()-'0';
                    res = a+b;
                    break;
                case '-':
                    a = numb.pop()-'0';
                    b = numb.pop()-'0';
                    res = a - b;
                    break;
                case '/':
                    a = numb.pop()-'0';
                    b = numb.pop()-'0';
                    res = a/b;
                    break;
                case '*':
                    a = numb.pop()-'0';
                    b = numb.pop()-'0';
                    res = a*b;
                    break;
            }
            numb.push(res);
        }
        i++;
    }
    int value = numb.pop();
    return value;
}


