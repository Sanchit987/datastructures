#include<iostream>
using namespace std;

void linear_search(int (&arr)[100],int &n);
int binary_search(int (&arr)[100],int start,int end,int ele);

int main()
{
label:
	int arr[100],n,choice,ele,element;
	cout<<"Enter Number of Elements to be Entered : "<<endl;
	cin>>n;
	cout<<"Which searching do you want to apply :- "<<endl;
	cout<<"1. Linear search."<<endl;
	cout<<"2. Binary Search."<<endl;
	cin>>choice;
	switch(choice)
	{
		case 1:
			cout<<"Enter List : "<<endl;
			for(int i = 0;i<n;i++)
			{
				cin>>arr[i];
			}
			linear_search(arr,n);
			break;
		case 2:
			cout<<"Enter Sorted List : "<<endl;
			for(int i = 0;i<n;i++)
			{
				cin>>arr[i];
			}
		        cout<<"Enter the Element to be searched : "<<endl;
		        cin>>ele;
			element = binary_search(arr,0,n-1,ele);
			if(element == -1)
			{
				cout<<"Element not found"<<endl;
			}
			else
			{
				cout<<"Element Found at "<<element<<endl;
			}
			break;
	}
	cout<<"Want to rerun Program?(y/n)"<<endl;
	char ch;
	cin>>ch;
	if(ch == 'Y' || ch == 'y')
	{
		goto label;
	}
	cout<<"Thanks For Using the Program."<<endl;
}

void linear_search(int (&arr)[100],int &n)
{
	int ele;
	cout<<"Enter the Element to be searched : "<<endl;
	cin>>ele;
	for(int i=0;i<n;i++)
	{
		if(ele == arr[i])
		{
			cout<<"Found at position : "<< i<<endl;
			return;
		}
	}
	cout<<"Element Not Found."<<endl;
}

int binary_search(int (&arr)[100],int start,int end,int ele)
{
	if(start <= end)
	{
		int mid = start + (end - 1)/2;
		
		if(arr[mid] == ele)
		{
			return mid;
		}
		if(arr[mid] > ele)
		{
			return binary_search(arr,start,mid,ele);
		}
		return binary_search(arr,mid,end,ele);
	}
	return -1;
}

