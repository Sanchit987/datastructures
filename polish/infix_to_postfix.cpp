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

string infix_to_postfix(string exp);

int main()
{
    string exp;
    cout<<"Enter the Expression "<<endl;
    getline(cin,exp);
    string required = infix_to_postfix(exp);
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

string infix_to_postfix(string exp)
{
    int x;
    string y;
    stack abc;
    exp.push_back(')');
    abc.push('(');
    for(int i = 0;i<exp.length();i++)
    {
        if((exp.at(i) >= 'a'&& exp.at(i)<='z') || (exp.at(i) >= 'A'&& exp.at(i)<= 'Z') || (exp.at(i) >= '0'&& exp.at(i)<= '9'))
        {
            y.push_back(exp.at(i));
        }
        else if(exp.at(i) == '(')
        {
            abc.push('(');
        }
        else if((exp.at(i) == '+')||(exp.at(i) == '-')||(exp.at(i) == '/')||(exp.at(i) == '*'))
        {
            int precedence_exp;
            int precedence_sta;
            switch(exp.at(i))
            {
            case '(':
                precedence_exp = 6;
                break;
            case '/':
                precedence_exp = 5;
                break;
            case '*':
                precedence_exp = 4;
                break;
            case '+':
                precedence_exp = 3;
                break;
            case '-':
                precedence_exp = 2;
                break;
            }
            switch(abc.top_ele())
            {
            case '(':
                precedence_sta = 6;
                break;
            case '/':
                precedence_sta = 5;
                break;
            case '*':
                precedence_sta = 4;
                break;
            case '+':
                precedence_sta = 3;
                break;
            case '-':
                precedence_sta = 2;
                break;
            }
            while(precedence_sta >= precedence_exp && abc.top != 0)
            {   if(abc.top_ele() != '(' && abc.top_ele() != ')')
                {
                    y.push_back(abc.pop());
                }
                else
                {
                    abc.pop();
                }
                switch(abc.top_ele())
                {
                case '(':
                    precedence_sta = 6;
                    break;
                case '/':
                    precedence_sta = 5;
                    break;
                case '*':
                    precedence_sta = 4;
                    break;
                case '+':
                    precedence_sta = 3;
                    break;
                case '-':
                    precedence_sta = 2;
                    break;
            }
            }
            if(exp.at(i) != '(' || exp.at(i) != ')')
            {
                abc.push(exp.at(i));
            }
        }
        else if(exp.at(i) == ')')
        {
            while(abc.top_ele() != '(' && abc.top != -1)
            {
                if(abc.top_ele() != '(' && abc.top_ele() != ')')
                {
                    y.push_back(abc.pop());
                }
            }
        }
    }
    return y;
}
