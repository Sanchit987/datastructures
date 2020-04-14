#include<iostream>
using namespace std;

struct node
{
	int info;
	struct node *left;
	struct node *right;
};

class tree
{
	public:
		node *root;
		tree()
		{
			root = NULL;
		}
		node* getroot()
		{
			return root;
		}
		void insert(int key, node* nroot);
		void creation(int x);
		void inorder(node * start);
		void postorder(node * start);
		void preorder(node * start);
		void search(node * start,int ele);
};

int main()
{
	tree abc;
label:
	int n,ele;
	cout << "1. Insert element into tree." << endl;
	cout << "2. Traverse the tree in In-order." << endl;
	cout << "3. Traverse the tree in Pre-order." << endl;
	cout << "4. Traverse the tree in Post-order." << endl;
	cout << "5. Search an element from the tree." << endl;
	cout << "6. Quit." << endl;

	cout << "Enter your choice: ";
	cin >> n;

	switch(n) {
		case 1:
			cout<< "Enter Element : "<<endl;
		       	cin>>ele;	
			abc.creation(ele);
			break;
		case 2:
			abc.inorder(abc.getroot());
		        cout<<endl;
			break;
		case 3:
                        abc.preorder(abc.getroot());
		        cout<<endl;
                        break;
		case 4:
                        abc.postorder(abc.getroot());
		        cout<<endl;
                        break;
		case 5:
			cout << "Enter the element you want to search from tree: ";
			cin >> ele;
			abc.search(abc.getroot(),ele);
			break;
		case 6:
			break;
		default:
			goto label;
	}
	char ch;
	cout<<"Do you want to continue?(y/n) : "<<endl;
	cin>>ch;
	if(ch == 'y' || ch == 'Y')
	{
		goto label;
	}
	return 0;
}

void tree :: creation(int x)
{
	if(root != NULL)
	{
		insert(x, root);
	}
	else
	{
		root = new node;
		root->info = x;
		root->left = NULL;
		root->right = NULL;
	}
}

void tree :: insert(int key, node *nroot)
{

	if(key < nroot->info)
	{
		if(nroot->left != NULL)
		{
			insert(key, nroot->left);
		}
		else
		{
			nroot->left = new node;
			nroot->left->info = key;
			nroot->left->left = NULL;
			nroot->left->right = NULL;
		}
	}
	else if(key > nroot->info)
	{
		if(nroot->right != NULL)
		{
			insert(key, nroot->right);
		}
		else
		{
			nroot->right = new node;
			nroot->right->info = key;
			nroot->right->right = NULL;
			nroot->right->left = NULL;
		}
	}

}

void tree :: inorder(node * start)
{
	if(start != NULL) {
		inorder(start->left);
		cout << start->info << "\t";
		inorder(start->right);
	}
}

void tree :: preorder(node * start)
{
        if(start != NULL) {
	    	cout<<start->info<<"\t";	
                preorder(start->left);
                preorder(start->right);
        }
}

void tree :: postorder(node * start)
{
        if(start != NULL) {
                postorder(start->left);
                postorder(start->right);
		cout << start->info << "\t";
        }
}

void tree :: search(node* start,int ele)
{
	if(start == NULL)
	{
		cout<<"Element Not found"<<endl;
		return;
	}
	if(start->info == ele)
	{
		cout<<"Element present"<<endl;
	}
	else
	{
		if(start->info > ele)
		{
			search(start->left,ele);
		}
		else
		{
			if(start->info < ele)
			{
				search(start->right,ele); 
			}
		}
	}
}
