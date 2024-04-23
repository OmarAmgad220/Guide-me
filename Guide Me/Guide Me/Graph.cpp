#include "Graph.h"

Graph::Graph()
{
}

void Graph::AddToGraph(string source, string destination, transportaions list_Of_Transportation)
{
	graph[source].push_back(make_pair(destination, list_Of_Transportation));
	graph[destination].push_back(make_pair(source, list_Of_Transportation));
}

void Graph::DFS(string source, string destination, vector<string>& currentPath, vector<vector<string>>& allPaths)
{
	visited[source] = true;
	currentPath.push_back(source);

	if (source == destination) {
		allPaths.push_back(currentPath);
	}
	else {
		for (auto neighbor : graph[source]) {
			string nextCity = neighbor.first;
			if (!visited[nextCity]) {
				DFS(nextCity, destination, currentPath, allPaths);
			}
		}
	}

	visited[source] = false;
	currentPath.pop_back();
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
			for (auto it : graph[current_city])
			{
				if (visited[it.first] == false)
				{
					queue_of_cities.push(it.first);
				}
			}
		}

	}
}