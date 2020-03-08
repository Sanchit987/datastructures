/* This programme illunstrates the concept of circular queue. It has a queue class defined with the member functions and data members.*/

#include<iostream>
using namespace std;

#define MAX 3 /*defines the length of the array.*/
class queue
{
	private:
		char arr[MAX];
		int front,rear ;
	public:
		queue()
		{
			front = -1;
			rear = -1;
		}
		void qinsert();
		void qdelete();
		void display();
		
};

int main()
{
	queue pq;
label:
	cout<<"What do you want to perform : "<<endl;
	cout<<"1. Insert an element : "<<endl;
	cout<<"2. Delete : "<<endl;
	cout<<"3. Display : "<<endl;
	int n;
	cin>>n;
	switch(n)
	{
		case 1:
			pq.qinsert();
			break;
		case 2:
			pq.qdelete();
			break;
		case 3:
			pq.display();
			break;
	}
	cout<<"Do you want to perform any other operation?(y/n)"<<endl;
	char conti;
	cin>>conti;
	if(conti == 'y' || conti == 'Y')
	{
		goto label;
	}
}

void queue :: qinsert()
{
	char item;
	cout<<"Enter the character Element : "<<endl;
	cin>>item;
	if ((front == 0 && rear == MAX-1) || (front == MAX+1))
	{
		cout<<"Overflow : Element can't be added."<<endl;
		return;
	}
	if (front == -1)
	{
		front = 0;
		rear = 0;
	} 
	else
       	{
		if (rear == MAX - 1)
			rear = 0;
		else
			rear = rear + 1;
	}
	arr[rear] = item;
}


void queue :: display()
{
	int f = front, r = rear;
	if (front == -1)
	{
		cout<<"Queue is empty."<<endl;
		return;
	}
	cout<<"Queue elements are : \n ";
	if (f <= r)
        {
		while (f <= r)
		{
			cout<<arr[f]<<" ";
			f++;
		}
	}
       	else
       	{
		while (f <= MAX - 1)
	       	{
			cout<<arr[f]<<" ";
			f++;
		}
		f = 0;
		while (f <= r) 
		{
			cout<<arr[f]<<" ";
			f++;
		}
	}
	cout<<endl;
}


void queue :: qdelete()
{
	char ele;
	if (front == -1)
	{
		cout<<"Uderflow : Element cant be deleted."<<endl;
		return ;
	}
	ele = arr[front];
	cout<<"Element : "<<ele<<endl;
	if (front == rear) {
		front = -1;
		rear = -1;
	}
	else
	{
		if (front == MAX - 1)
			front = 0;
		else
			front = front + 1;
	}
}
