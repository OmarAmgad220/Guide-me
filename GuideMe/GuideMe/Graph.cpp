#include "Graph.h"
#include<iostream>

using namespace std;


Graph::Graph()
{
}

void Graph::AddToGraph(string source, string destination, transportations list_Of_Transportation)
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

void Graph::find_lowest_cost(string source, string destination)
{
	vector<string> currentPath;
	vector<vector<string>> allPaths;
	DFS(source, destination, currentPath, allPaths);

	double minimum_cost = numeric_limits<double>::infinity();//  assigns +ve infinte number for total cost
	vector<string> sequence_of_transportations; 

	if (allPaths.empty()) {
		cout << "No path found from " << source << " to " << destination << endl;
	}
	else {
		for (const auto& path : allPaths) {
			double path_cost = 0;
			vector<string> path_transports;

			int path_size = path.size() - 1;

			for (int i = 0; i < path_size; ++i) {
				const string& current_city = path[i];
				const string& next_city = path[i + 1];

				// Find the minimum cost transportation from current_city to next_city
				double min_transport_cost = numeric_limits<double>::infinity(); // assigns +ve infinte number for each transportation cost
				string chosen_transport;

				for (const auto& neighbor : graph[current_city]) { // list --> { destination, {int, string} } 
					                  // destination  
					if (neighbor.first == next_city) { 

						
						
						for (const auto& transport : neighbor.second) { // carries {int, transportation}
							if (transport.first < min_transport_cost) {
								min_transport_cost = transport.first;
								chosen_transport = transport.second;
							}
						}
					}
				}

				// Add the chosen transportation of a certain edge and its cost to the path
				path_cost += min_transport_cost;
				path_transports.push_back(chosen_transport);
			}

			// Update the suitable path if the current path has a lower cost
			if (path_cost < minimum_cost) {
				minimum_cost = path_cost;
				sequence_of_transportations = path_transports;
			}
		}

		cout << "Minimum cost: " << minimum_cost << endl;
		cout << "Chosen path: ";
		for (const auto& transport : sequence_of_transportations) {
			cout << transport << " -> ";
		}
		cout << destination << endl;
	}

	
}

transportations Graph::findWeight(string source, string destination)
{
	for (auto neighbor : graph[source]) {
		if (neighbor.first == destination)
		{
			return neighbor.second;
		}
	}
}

void Graph::tagroba(string source, string destination)
{
	vector<string> currentPath;
	vector<vector<string>> allPaths;
	DFS(source, destination, currentPath, allPaths);

	double minimum_cost = numeric_limits<double>::infinity();//  assigns +ve infinte number for total cost
	vector<string> sequence_of_transportations;

	vector<pair<int, vector<string>>> wtf;

	

	if (allPaths.empty()) {
		cout << "No path found from " << source << " to " << destination << endl;
	}
	else {
		for (const auto& path : allPaths) {
			double path_cost = 0;
			vector<string> path_transports;

			int path_size = path.size() - 1;

			for (int i = 0; i < path_size; ++i) {
				const string& current_city = path[i];
				const string& next_city = path[i + 1];

				// Find the minimum cost transportation from current_city to next_city
				double min_transport_cost = numeric_limits<double>::infinity(); // assigns +ve infinte number for each transportation cost
				string chosen_transport;

				for (const auto& neighbor : graph[current_city]) { // list --> { destination, {int, string} } 
					// destination  
					if (neighbor.first == next_city) {



						for (const auto& transport : neighbor.second) { // carries {int, transportation}
							if (transport.first < min_transport_cost) {
								min_transport_cost = transport.first;
								chosen_transport = transport.second;
							}
						}
					}
				}

				// Add the chosen transportation of a certain edge and its cost to the path
				path_cost += min_transport_cost;
				path_transports.push_back(chosen_transport);
			}

			// Update the suitable path if the current path has a lower cost
			if (path_cost < minimum_cost) {
				minimum_cost = path_cost;
				sequence_of_transportations = path_transports;
			}
			for (auto& i : wtf) {
				if (i.first != path_cost && i.second != path_transports)
					wtf.push_back(make_pair(path_cost, path_transports));

			}
			cout << "Minimum cost: " << minimum_cost << endl;
			cout << "Chosen path: ";
			for (const auto& transport : sequence_of_transportations) {
				cout << transport << " -> ";
			}
			cout << destination << endl;

		}

		
	}


}
