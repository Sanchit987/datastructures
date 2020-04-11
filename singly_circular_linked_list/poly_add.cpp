#include<iostream>
using namespace std;

struct node
{
	int data;
	struct node *link;
};

class poly
{
private:
	int x,y,z;
	node *start;
public:
	poly()
	{
		x=0;
		y=0;
		z=0;
		start = NULL;
	}
	void insert_end(int data);
	void display();
	void get_data()
	{
		cout<<"Enter x y z :"<<endl;
		cin>>x>>y>>z;
	}
	void create_poly()
	{
		insert_end(x);
		insert_end(y);
		insert_end(z);
	}
	void adding(poly list1,poly list2)
	{
		this->x = list1.x + list2.x;
		this->y = list1.y + list2.y;
		this->z = list1.z + list2.z;
	}
	void result()
	{
		node *temp = start;
		int a = temp->data;
		temp=temp->link;
		int b = temp->data;
		temp=temp->link;
		int c = temp->data;
		cout<<a<<"x + "<<b<<"y + "<<c<<"z"<<endl;
	}
};

int main()
{
	poly list1,list2,list3;
	list1.get_data();
	list1.create_poly();
	list2.get_data();
	list2.create_poly();
	list3.adding(list1,list2);
	list3.create_poly();
	list3.result();
	return 0;
}

void poly :: insert_end(int ele)
{
	node *new_node = new node;
	new_node->data = ele;
	node *t = start;
	if(start == NULL)
        {
                start = new_node;
	}
	else{
		while(t->link != start)
		{
			t = t->link;
		}
		t->link = new_node;
	}
	new_node->link = start;
}

void poly :: display()
{
	node *temp = start;
	if(start != NULL)
	{
		do
		{
			cout<<temp->data<<endl;
			temp = temp->link;
		}while(temp != start);
	}
}
