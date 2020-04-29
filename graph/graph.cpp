#include<iostream>
#include<list>
using namespace std;

class graph
{
private:
	int num_ver;
	int matrix[20][20];
	bool visited[400];
public:
	graph(int vert)
	{
		this->num_ver = vert;
		for(int i=0;i<vert;i++)
		{
			for(int j=0;j<vert;j++)
			{
				this->matrix[i][j] = 0;
			}
		}
		for(int i=0;i<vert*vert;i++)
                {
			visited[i] = false;
                }

	}
	void clearvis()
	{
		for(int i=0;i<num_ver*num_ver;i++)
                {
                        visited[i] = false;
                }

	}

	void display()
	{
		cout<<"_|";
		for(int i = 0;i<num_ver;i++)
		{
			cout<<i<<" ";
		}
		cout<<endl;
		for(int i=0;i<num_ver;i++)
                {
			cout<<i<<"|";
                        for(int j=0;j<num_ver;j++)
                        {
                                cout<<this->matrix[i][j]<<" ";
                        }
			cout<<endl;
                }

	}

	void add_edge(int row,int col);
	void remove_edge(int row,int col);
	void DFS(int start);
};

int main()
{
	cout<<"---This Program Is only for directed graph---"<<endl;
	cout<<"Enter the Number of vertices : "<<endl;
	int vertices;
	cin>>vertices;
	graph g1(vertices);
	cout<<"Your Current Graph : "<<endl;
	g1.display();
label:
	cout<<"Opertions :-"<<endl;
	cout<<"1. Add Edge."<<endl;
	cout<<"2. Remove Edge."<<endl;
	cout<<"3. DFS."<<endl;
	cout<<"4. BFS."<<endl;
	cout<<"5. Display."<<endl;
	cout<<"6. Exit."<<endl;
	cout<<"Enter Operation Number."<<endl;
	int opt,row,col;
	cin>>opt;
	switch(opt)
	{
		case 1:
			cout<<"Enter Vertices in which you want edge : (origin terminal)"<<endl;
			cin>>row;
			cin>>col;
			g1.add_edge(row,col);
			g1.display();
			break;
		case 2:
			cout<<"Enter Vertices from which you want to remove edge : (origin terminal)"<<endl;
                        cin>>row;
                        cin>>col;
                        g1.remove_edge(row,col);
			g1.display();
			break;
		case 3:
			cout<<"DFS : ";
			g1.DFS(0);
			g1.clearvis();
			break;
		/*
		case 4:
			cout<<"BFS : ";
			g1.BFS(0);
			g1.print_bfs();
			g1.clearvis();
			break;
			*/
		case 5:
			g1.display();
			break;
		case 6:
			goto label2;
			break;
	}
	goto label;
label2:
	cout<<"Thanks for using."<<endl;
	return 0;
}

void graph :: add_edge(int row,int col)
{
	if(matrix[row][col] == 0)
	{
		matrix[row][col] = 1;
	}
	else
	{
		cout<<"An directed Edge already exists."<<endl;
	}
}

void graph :: remove_edge(int row,int col)
{
	if(matrix[row][col] == 1)
	{
		matrix[row][col] = 0;
	}
	else
	{
		cout<<"No edge Exists."<<endl;
	}
}

void graph :: DFS(int start)
{
    cout << start << " ";
    visited[start] = true;
    for (int i = 0; i < num_ver; i++) 
    {
        if (matrix[start][i] == 1 && (!visited[i]))
	{
            DFS(i);
        }
    }
}
