#include "Graph_DFS.h"

Graph::Graph()
{
}

void Graph::AddToGraph(string source, string destination, vector<pair<string, int>> list_Of_Transportation)
{
	graph[source].push_back(make_pair(destination, list_Of_Transportation));
	graph[destination].push_back(make_pair(source, list_Of_Transportation));
}

void Graph::DFS(string city)
{
	visited[city] = true;
	cout << city << endl;

	for (auto i = graph[city].begin(); i != graph[city].end(); i++)
	{
		if (!visited[i->first])
		{
			DFS(i->first);
		}
	}

}

void Graph::BFS(string source, string destination)
{
	queue<string>queue_of_cities;
	queue_of_cities.push(source);

	while (!queue_of_cities.empty())
	{
		string current_city = queue_of_cities.front();
		queue_of_cities.pop();

		if (visited[current_city] == false)
		{
			visited[current_city] = true;
			cout << current_city << endl;
			for (pair<string, vector<pair<string, int>>> it : graph[current_city])
			{
				if (visited[it.first] == false)
				{
					queue_of_cities.push(it.first);
				}
			}
		}

	}
}