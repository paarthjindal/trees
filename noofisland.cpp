// C++Program to count islands in boolean 2D matrix
#include <bits/stdc++.h>
using namespace std;

// A utility function to do DFS for a 2D
// boolean matrix. It only considers
// the 8 neighbours as adjacent vertices
void DFS(vector<vector<int>> &M, int i, int j, int ROW,
		int COL, int &count)
{

	// Base condition
	// if i less than 0 or j less than 0 or i greater than
	// ROW-1 or j greater than COL- or if M[i][j] != 1 then
	// we will simply return
	if (i < 0 || j < 0 || i > (ROW - 1) || j > (COL - 1) || M[i][j] != 1)
	{
		return;
	}

	if (M[i][j] == 1)
	{
		count++;
		M[i][j] = 0;
		DFS(M, i + 1, j, ROW, COL, count); // right side traversal
	 DFS(M, i - 1, j, ROW, COL, count); // left side traversal
	 DFS(M, i, j + 1, ROW, COL, count); // upward side traversal
		DFS(M, i, j - 1, ROW,
					 COL, count); // downward side traversal
	 DFS(M, i + 1, j + 1, ROW,	 COL, count); // upward-right side traversal
		DFS(M, i - 1, j - 1, ROW,
					 COL, count); // downward-left side traversal
		DFS(M, i + 1, j - 1, ROW,
					 COL, count); // downward-right side traversal
		DFS(M, i - 1, j + 1, ROW,
					 COL, count); // upward-left side traversal
		printf("%d\n", count);
	}
	return;
}
int maximum(int a, int b)
{
	if (a > b)
		return a;
	else
		return b;
}

int countIslands(vector<vector<int>> &M)
{
	int ROW = M.size();
	int COL = M[0].size();

    int count ;
	int max=0;
	for (int i = 0; i < ROW; i++)
	{
		for (int j = 0; j < COL; j++)
		{
			if (M[i][j] == 1)
			{
				 count = 0;

				 DFS(M, i, j, ROW, COL,count); // traversal starts
				printf("%d\n", count);
				max = maximum(count, max); // from current cell
			}
		}
	}
	return count;
}

// Driver Code
int main()
{
	vector<vector<int>> M = {{1, 1, 0, 0, 0},
							 {0, 1, 0, 0, 1},
							 {1, 0, 0, 1, 1},
							 {0, 0, 0, 0, 0},
							 {1, 0, 1, 0, 1}};

	cout << "Number of islands is: " << countIslands(M);
	return 0;
}

// This code is contributed by ajaymakvana.
// Code improved by Animesh Singh