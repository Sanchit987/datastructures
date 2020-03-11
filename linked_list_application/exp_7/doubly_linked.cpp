#include<iostream>
using namespace std;

struct node
{
	int usn,sem;
	long long int phno;
	string name,branch;
	struct node *left_link;
	struct node *right_link;
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
		void insertbeg();
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
	char action;
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
		case 1:x.insertbeg();
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
	cin>>action;
	if(action == 'y')
	{
		goto label;
	}
	return 0;
}

void linked_list :: insertbeg()
{
	int sem1,usn1;
	long long int phno1;
	string name1,branch1;
	cout<<"Enter Usn : "<<endl;
	cin>>usn1;
	cout<<"Enter name : "<<endl;
	cin>>name1;
	cout<<"Enter branch : "<<endl;
	cin>>branch1;
	cout<<"Enter semester : "<<endl;
	cin>>sem1;
	cout<<"Enter phone number : "<<endl;
	cin>>phno1;
	node *temp = new node;
	temp->usn = usn1;
	temp->phno = phno1;
	temp->sem = sem1;
	temp->name = name1;
	temp->branch = branch1;
	temp->right_link = start;
	temp->left_link = NULL;
	start = temp;
}

void linked_list :: display()
{
	node *temp = start;
	int i=0;
	while(temp != NULL)
	{
		cout<<"Element : "<<i<<endl;
		cout<<"-----------------"<<endl;
		cout<<"Usn : "<<temp->usn<<endl;
		cout<<"Name : "<<temp->name<<endl;
		cout<<"branch : "<<temp->branch<<endl;
		cout<<"Semester : "<<temp->sem<<endl;
		cout<<"Ph : "<<temp->phno<<endl;
		temp = temp->right_link;
		i++;
		cout<<"-----------------"<<endl;
	}
}

void linked_list :: insertend()
{
	int sem1,usn1;
	long long int phno1;
        string name1,branch1;
        cout<<"Enter Usn : "<<endl;
        cin>>usn1;
        cout<<"Enter name : "<<endl;
        cin>>name1;
        cout<<"Enter branch : "<<endl;
        cin>>branch1;
        cout<<"Enter semester : "<<endl;
        cin>>sem1;
        cout<<"Enter phone number : "<<endl;
        cin>>phno1;
	node *new_node = new node;
	new_node->usn = usn1;
	new_node->phno = phno1;
	new_node->name = name1;
	new_node->branch = branch1;
	new_node->sem = sem1;
	new_node->right_link = NULL;
	node *t = start;
	if(start == NULL)
        {
                start = new_node;
		new_node->left_link = NULL;
	}
	else{
		while(t->right_link != NULL)
		{
			t = t->right_link;
		}
		new_node->left_link = t;
		t->right_link = new_node;
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
                temp = temp->right_link;
        }
	cout<<cou<<endl;
}


void linked_list :: del_front()
{
	node *temp = start;
	if(temp != NULL)
	{
		start = temp->right_link;
		node *tempo = start;
		tempo->left_link = NULL;
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
	else if(temp->right_link == NULL)
	{
		start = NULL;
		delete temp;
	}
	else
	{
		node *temp2 = temp->right_link;
		while(temp2->right_link != NULL)
		{
			temp = temp->right_link;
			temp2 = temp2->right_link;
		}
		temp->right_link = NULL;
		delete temp2;
	}
}

void linked_list :: searching()
{
	int ele;
	cout<<"Enter the usn to be searched. "<<endl;
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
			if(temp->usn == ele)
			{
				cout<<"Element present at position : "<< pos<<endl;
				flag = true;
				break;
			}
			temp = temp->right_link;
		}
		if(!flag)
		{
			cout<<"Element not found."<<endl;
		}
	}
}
