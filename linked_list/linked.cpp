#include<iostream>
using namespace std;

struct node
{
	int info;
	struct node *link;
};

class linked_list
{
	private:
		node *start;
	public:
		linked_list()
		{
			start = NULL;
		}
		void insertbeg(int n);
		void display();
		void insertend();
		void count();
		void del_front();
		void del_end();
		void searching();
};

int main()
{
	linked_list x;
	label:
	cout<<"Enter The Command number you want to perform"<<endl;
	cout<<"0. Display. "<<endl;
	cout<<"1. Adding an element at beg. "<<endl;
	cout<<"2. Adding element at end. "<<endl;
	cout<<"3. Counting elements. "<<endl;
	cout<<"4. Deleting an element from front. "<<endl;
	cout<<"5. Delete from end. "<<endl;
	cout<<"6. Searching an element. "<<endl;
	int p;
	cin>>p;
	switch(p)
	{
		case 0:x.display();
		       break;
		case 1:cout<<"Enter the element to be inserted at beg : "<<endl;
		       int ele;
		       cin>>ele;
		       x.insertbeg(ele);
		       break;
		case 2:x.insertend();
		       break;
		case 3:x.count();
		       break;
		case 4:x.del_front();
		       break;
		case 5:x.del_end();
		       break;
		case 6:x.searching();
		       break;
	}
	cout<<"Do you wanna perform any other action?(y/n) : ";
	char action;
	cin>>action;
	if(action == 'y')
	{
		goto label;
	}
	return 0;
}

void linked_list :: insertbeg(int n)
{
	node *temp = new node;
	temp->info = n;
	temp->link = start;
	start = temp;
}

void linked_list :: display()
{
	node *temp = start;
	while(temp != NULL)
	{
		cout<<temp->info<<" ";
		temp = temp->link;
	}
}

void linked_list :: insertend()
{
	node *new_node = new node;
	cout<<"Enter the Element to be inserted at end : "<<endl;
	int ele;
	cin>>ele;
	new_node->info = ele;
	new_node->link = NULL;
	node *t = start;
	if(start == NULL)
        {
                start = new_node;
	}
	else{
		while(t->link != NULL)
		{
			t = t->link;
		}
		t->link = new_node;
	}
}

void linked_list :: count()
{
	int cou = 0;
        node *temp = start;
	cout<<"Number of elements are : ";
        while(temp != NULL)
        {
                cou++;
                temp = temp->link;
        }
	cout<<cou<<endl;
}

void linked_list :: del_front()
{
	node *temp = start;
	if(temp != NULL)
	{
		start = temp->link;
		delete temp;
	}
	else
	{
		cout<<"Linked list empty"<<endl;
	}
}

void linked_list :: del_end()
{
	node *temp = start;
	if(temp == NULL)
	{
		cout<<"List empty. "<<endl;
	}
	else if(temp->link == NULL)
	{
		start = NULL;
		delete temp;
	}
	else
	{
		node *temp2 = temp->link;
		while(temp2->link != NULL)
		{
			temp = temp->link;
			temp2 = temp2->link;
		}
		temp->link = NULL;
		delete temp2;
	}
}

void linked_list :: searching()
{
	int ele;
	cout<<"Enter the element to be searched. "<<endl;
	cin>>ele;
	node *temp = start;
	if(temp == NULL)
	{
		cout<<"List contains no element. "<<endl;
	}
	else
	{
		int pos = -1;
		bool flag = false;
		while(temp != NULL)
		{
			pos++;
			if(temp->info == ele)
			{
				cout<<"Element present at position : "<< pos<<endl;
				flag = true;
				break;
			}
			temp = temp->link;
		}
		if(!flag)
		{
			cout<<"Element not found."<<endl;
		}
	}
}
