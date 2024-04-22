#include <iostream>
#include"Graph_DFS.h"
using namespace std;

int main()
{

	string source, destination;

	vector<pair<string, int>> list_Of_Transportation;

	Graph_DFS g;
	for (int i = 1; i <= 5; i++)
	{
		cin >> source >> destination;
		g.AddToGraph(source, destination, list_Of_Transportation);
	}

	g.DFS("Dahab");


}