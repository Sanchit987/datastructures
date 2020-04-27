#include<iostream>
using namespace std;

void bubble_sort(int (&arr)[100],int n);
void selection_sort(int (&arr)[100],int n);
void insertion_sort(int (&arr)[100],int n);
void quick_sort(int (&arr)[100],int low,int high);
int quick(int (&arr)[100],int low,int high);
void swap(int *a,int *b);
void display(int (&arr)[100],int n);

int main()
{
label1:
	int arr[100],n;
	cout<<"Enter the number of elements or (-1) to exit. :"<<endl;
	cin>>n;
	if(n == -1)
	{
		goto label2;
	}
	for(int i = 0;i<n;i++)
	{
		cout<<"Enter element No. "<<i<<" : ";
		cin>>arr[i];
	}
	cout<<endl;
	cout<<"Which Sorting would you like to preffer : "<<endl;
	int choice;
	cout<<"1. Bubble Sort."<<endl;
	cout<<"2. Selection Sort."<<endl;
	cout<<"3. Insertion Sort."<<endl;
	cout<<"4. Quick Sort."<<endl;
	cout<<"7. Exit."<<endl;
	cin>>choice;
	switch(choice)
	{
		case 1:
			bubble_sort(arr,n);
			break;
		case 2:
			selection_sort(arr,n);
			break;
		case 3:
			insertion_sort(arr,n);
			break;
		case 4:
			quick_sort(arr,0,n-1);
			display(arr,n);
			break;
		case 7:
			goto label2;
			break;
		default:
			goto label1;
	}
	goto label1;
label2:
	cout<<"Thanks for using."<<endl;
}

void bubble_sort(int (&arr)[100],int n)
{
	int lm = n;
	for(int i=0;i<lm;i++)
	{
		for(int j = 1;j<n;j++)
		{
			if(arr[j-1]>arr[j])
			{
				int temp = arr[j-1];
				arr[j-1] = arr[j];
				arr[j] = temp;
			}
		}
		n--;
	}
	display(arr,lm);
}

void selection_sort(int (&arr)[100],int n)
{
	for(int i=0;i<n-1;i++)
	{
		int min = i;
		for(int j=i+1;j<n;j++)
		{
			if(arr[j]<arr[min])
			{
				min = j;
			}
			if(min != i)
			{
				int temp = arr[i];
				arr[i] = arr[min];
				arr[min] = temp;
			}
		}
	}
	display(arr,n);
}

void insertion_sort(int (&arr)[100],int n)
{
	for(int i = 1;i<n;i++)
	{
		int temp = arr[i];
		int j = i-1;
		while(j>=0 && arr[j]>temp)
		{
			arr[j+1] = arr[j];
			j--;
		}
		arr[j+1] = temp;
	}
	display(arr,n);
}

void quick_sort(int (&arr)[100],int low,int high)
{
	if(low<high)
	{
		int position = quick(arr,low,high);
		quick_sort(arr,low,position-1);
		quick_sort(arr,position+1,high);
	}
}

int quick(int (&arr)[100],int low,int high)
{
	int pivot = arr[high];
	int i = low-1;

	for(int j = low;j<high;j++)
	{
		if(arr[j]<pivot)
		{
			i++;
			swap(arr[i],arr[j]);
		}
	}
	swap(arr[i+1],arr[high]);
	return (i+1);
}

void swap(int &a,int &b)
{
	int temp = a;
	a = b;
	b = temp;
}

void display(int (&arr)[100],int n)
{
	cout<<"Sorted Array : "<<endl;
	for(int i = 0;i<n;i++)
	{
		cout<<arr[i]<<" ";
	}
	cout<<endl;
}
