#include "Graph_DFS.h"

Graph_DFS::Graph_DFS()
{
}

void Graph_DFS::AddToGraph(string source, string destination, vector<pair<string, int>> list_Of_Transportation)
{
	graph[source].push_back(make_pair(destination, list_Of_Transportation));
	graph[destination].push_back(make_pair(source, list_Of_Transportation));
}

void Graph_DFS::DFS(string city)
{
	stack <string> stack_of_cities;
	stack_of_cities.push(city);

	while (!stack_of_cities.empty())
	{
		string n = stack_of_cities.top();
		stack_of_cities.pop();

		if (visited[n] != true) {

			visited[n] = true;
			
			cout << n<<endl;

			for (auto i = graph[n].begin() ; i != graph[n].end(); i++)
			{
				if (!visited[i->first])
				{
					stack_of_cities.push(i->first);
				}
			}
		}
	}
	
}



