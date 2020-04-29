#include<iostream>
using namespace std;

void bubble_sort(int (&arr)[100],int n);

void selection_sort(int (&arr)[100],int n);

void insertion_sort(int (&arr)[100],int n);

void quick_sort(int (&arr)[100],int low,int high);
int quick(int (&arr)[100],int low,int high);
void swap(int *a,int *b);

void radixsort(int (&arr)[100], int n);

void merge_sort(int (&arr)[100],int low,int high);
void merge(int (&arr)[100],int low,int mid,int high);

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
	cout<<"5. Merge Sort."<<endl;
	cout<<"6. Radix Sort."<<endl;
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
		case 5:
			merge_sort(arr,0,n);
			display(arr,n);
			break;
		case 6:
                        radixsort(arr,n);
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

int getMax(int arr[], int n)
{
    int mx = arr[0];
    for (int i = 1; i < n; i++)
        if (arr[i] > mx)
            mx = arr[i];
    return mx;
}


void countSort(int arr[], int n, int exp)
{
    int output[n];
    int i, count[10] = {0};


    for (i = 0; i < n; i++)
        count[ (arr[i]/exp)%10 ]++;

      for (i = 1; i < 10; i++)
        count[i] += count[i - 1];

      for (i = n - 1; i >= 0; i--)
    {
        output[count[ (arr[i]/exp)%10 ] - 1] = arr[i];
        count[ (arr[i]/exp)%10 ]--;
    }

    for (i = 0; i < n; i++)
        arr[i] = output[i];
}

void radixsort(int (&arr)[100], int n)
{

    int m = getMax(arr, n);
    for (int exp = 1; m/exp > 0; exp *= 10)
        countSort(arr, n, exp);
}


void merge_sort(int (&arr)[100],int low,int high)
{
	if(low<high)
	{
		int mid = low+(high-low)/2;
		merge_sort(arr,low,mid);
		merge_sort(arr,mid+1,high);

		merge(arr,low,mid,high);
	}
}

void merge(int (&arr)[100],int low,int mid,int high)
{
	int i,j,k;
	int n1 = mid-low+1;
	int n2 = high-mid;

	int l1[n1],l2[n2];

	for(i = 0;i<n1;i++)
	{
		l1[i] = arr[low+i];
	}

	for(j = 0;j<n2;j++)
	{
		l2[j] = arr[mid + j + 1];
	}

	i = 0;
	j = 0;
	k = low;
	while(i<n1 && j<n2)
	{
		if(l1[i] <= l2[j])
		{
			arr[k] = l1[i];
			i++;
		}
		else
		{
			arr[k] = l2[j];
			j++;
		}
		k++;
	}

	while(i<n1)
	{
		arr[k] = l1[i];
		i++;
		k++;
	}

	while(j<n2)
	{
		arr[k] = l2[j];
		j++;
		k++;
	}
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
