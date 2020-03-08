#include<iostream>
using namespace std;
void ins_beg(int (&arr)[100],int &n);
void ins_end(int (&arr)[100],int &n);
void ins_ith(int (&arr)[100],int &n);
void del_beg(int (&arr)[100],int &n);
void del_end(int (&arr)[100],int &n);
void del_ith(int (&arr)[100],int &n);
void del_spec(int (&arr)[100],int &n);
int linear_search(int (&arr)[100],int &n);
void bubble_sort(int (&arr)[100],int &n);
void selection_sort(int (&arr)[100],int &n);

main()
{
	int arr[100];
	int pos=0;
	cout<<"Enter the number of elements to be entered : "<<endl;
	int n;
	cin>>n;
	cout<<"Enter Elements one by one : "<<endl;
	for(int i=0;i<n;i++)
	{
	cin>>arr[i];
	}
	beg:
	int number;
	cout<<"1. insert element at begining."<<endl;
	cout<<"2. insert element at End."<<endl;
	cout<<"3. insert element at i th position."<<endl;
	cout<<"4. delete element at begining."<<endl;
	cout<<"5. delete element at End."<<endl;
	cout<<"6. delete element at i th position."<<endl;
	cout<<"7. Search an Element."<<endl;
	cout<<"8. delete a particular element from list."<<endl;
	cout<<"9. Bubble sort."<<endl;
	cout<<"10. Selection Sort."<<endl;
	cout<<"11. Display."<<endl;
	cout<<"** Enter number of the command you want to execute **"<<endl;
	cin>>number;
	switch(number)
	{
		case 1:
			ins_beg(arr,n);
			break;
		case 2:
			ins_end(arr,n);
			break;
		case 3:
			ins_ith(arr,n);
			break;
		case 4:
			del_beg(arr,n);
			break;
		case 5:
			del_end(arr,n);
			break;
		case 6:
			del_ith(arr,n);
			break;
		case 7:
			pos = linear_search(arr,n);
			cout<<"Position is : "<<pos<<endl;
			break;
		case 8:
			del_spec(arr,n);
			break;
		case 9:
			bubble_sort(arr,n);
			break;
		case 10:
			selection_sort(arr,n);
			break;
		case 11:
			for(int i = 0;i<n;i++)
			{
				cout<<arr[i]<<" ";
			}
			cout<<endl;
			break;
		}
		cout<<"Are Your Updations Over ? (y or n) "<<endl;
		char ch;
		cin>>ch;
		if(ch=='y' or ch=='Y')
		{
			cout<<"Bye-Bye";
		}
		else
		{
			goto beg;
		}
}

void ins_beg(int (&arr)[100],int &n)
{
	cout<<"Enter Element to be inserted at begining : "<<endl;
	n= n+1;
	int number_entered;
	cin>>number_entered;
	for(int i = n-1;i>=0;i--)
	{
		if(i !=0 )
		{
			arr[i] = arr[i-1];
		}
		else
		{
			arr[0] = number_entered;
		}
	}
}

void ins_end(int (&arr)[100],int &n)
{
	cout<<"Enter Element to be inserted at end : "<<endl;
	n = n+1;
	int number_entered;
	cin>>number_entered;
	arr[n-1] = number_entered;
}

void ins_ith(int (&arr)[100],int &n)
{
	int pos;
	cout<<"Enter the position : "<<endl;
	cin>>pos;
	if(pos == 0)
	{
		ins_beg(arr,n);
	}
	else
	{
		if(pos == n-1)
		{
			ins_end(arr,n);
		}
		else
		{
			cout<<"Enter Element to be inserted : "<<endl;
			n = n+1;
			int number_entered;
			cin>>number_entered;
			for(int i = n-1;i>=pos;i--)
			{
				if(i !=pos )
				{
					arr[i] = arr[i-1];
				}
				else
				{
					arr[pos] = number_entered;
				}
			}
		}
	}
}



void del_beg(int (&arr)[100],int &n)
{
	for(int i = 0;i<n;i++)
	{
		if(i!= n-1)
		{
			arr[i]=arr[i+1];
		}
	}
	n = n-1;
	cout<<"Deleted"<<endl;
}



void del_end(int (&arr)[100],int &n)
{
	n = n-1;
	cout<<"Deleted"<<endl;
}


void del_ith(int (&arr)[100],int &n)
{
	int pos;
	cout<<"Enter the position : "<<endl;
	cin>>pos;
	if(pos == 0)
	{
		del_beg(arr,n);
	}
	else
	{
		if(pos == n-1)
		{
			del_end(arr,n);
		}
		else
		{
			for(int i = pos;i<n;i++)
			{
				if(i!= n-1)
				{
					arr[i]=arr[i+1];
				}
			}
			cout<<endl<<"Deleted"<<endl;
			n = n-1;
		}
	}
}


int linear_search(int (&arr)[100],int &n)
{
	int number;
	int pos=0;
	cout<<"Enter Number To Be Searched : "<<endl;
	cin>>number;
	for(int i =0;i<n;i++)
	{
		if(arr[i] == number)
		{
			pos = i;
			break;
		}
	}
	return pos;
}


void del_spec(int (&arr)[100],int &n)
{
	int number;
	int pos=0;
	cout<<"Enter Number To Be Deleted : "<<endl;
	cin>>number;
	for(int i =0;i<n;i++)
	{
		if(arr[i] == number)
		{
			pos = i;
		break;
		}
	}
	if(pos == 0)
	{
		del_beg(arr,n);
	}
	else
	{
		if(pos == n-1)
		{
			del_end(arr,n);
		}
		else
		{
			for(int i = pos;i<n;i++)
			{
				if(i!= n-1)
				{
					arr[i]=arr[i+1];
				}
			}
			cout<<endl<<"Deleted"<<endl;
			n = n-1;
		}
	}
}

void bubble_sort(int (&arr)[100],int &n)
{
	int len;
	len = n-1;
	for(int j=len;j>0;j--)
	{
		for(int i=0;i<j;i++)
		{
			if(arr[i]>arr[i+1])
			{
				swap(arr[i],arr[i+1]);
			}
		}
	}
}


void selection_sort(int (&arr)[100],int &n)
{
	int mini = 0;
	for(int j = 0;j<n;j++)
	{
		mini = j;
		for(int i = j+1;i<n;i++)
		{
			if(arr[mini]>arr[i])
			{
				mini = i;
			}
		}
		swap(arr[j],arr[mini]);
	}
	cout<<"Selection Sort Has been Executed.";
}
