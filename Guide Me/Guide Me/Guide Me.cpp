#include"Graph_DFS.h"

int main()
{

	string source, destination;

	vector<pair<string, int>> list_Of_Transportation;

	Graph country;
	for (int i = 1; i <= 5; i++)
	{
		cin >> source >> destination;
		country.AddToGraph(source, destination, list_Of_Transportation);
	}

	country.BFS("cairo", "benisuef");


}