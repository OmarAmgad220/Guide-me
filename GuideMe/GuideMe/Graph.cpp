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
	//use it to know number of distinct nodes
	nodes.insert(source);
	nodes.insert(destination);
	// each insertion in the graph counts as an edge
	edgecount++;
}
void Graph::checkCompleteness() {

	int numOfedges = nodes.size() * (nodes.size() - 1);
	numOfedges /= 2;

	if (numOfedges == edgecount) {
		cout << "the graph is complete" << '\n';
	}
	else {
		cout << "the graph isn't complete" << '\n';
	}

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

//void Graph::BFS2(string source, string destination)
//{
//	queue<string>queue_of_cities;
//	queue_of_cities.push(source);
//
//	while (!queue_of_cities.empty())
//	{
//		string current_city = queue_of_cities.front();
//		queue_of_cities.pop();
//
//		if (visited[current_city] == false)
//		{
//			visited[current_city] = true;
//			cout << current_city << endl;
//			for (auto it : graph[current_city])
//			{
//				if (visited[it.first] == false)
//				{
//					queue_of_cities.push(it.first);
//				}
//			}
//		}
//
//	}
//}


transportations Graph::findWeight(string source, string destination)
{
	for (auto neighbor : graph[source]) {
		if (neighbor.first == destination)
		{
			return neighbor.second;
		}
	}
}

void Graph::find_lowest_cost(string source, string destination){
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

		}
		cout << "Minimum cost: " << minimum_cost << endl;
		cout << "Chosen path: ";
		for (const auto& transport : sequence_of_transportations) {
			cout << transport << " -> ";
		}
		cout << destination << endl;


	}


}


bool isNotVisited(vector<string>path, string node)
{
	for (int i = 0; i < path.size(); i++)
		if (path[i] == node)
			return false;
	return true;

}

//all paths
vector<vector<string>> Graph::BFS(string source, string destination)
{
	vector<vector<string>>allPaths;

	queue<vector<string>>testPaths;

	//path to be inserted in all paths

	vector<string>path;
	path.push_back(source);

	testPaths.push(path);

	while (!testPaths.empty())
	{
		path = testPaths.front();
		testPaths.pop();

		string end = path[path.size() - 1];

		if (end == destination)
		{
			allPaths.push_back(path);
		}
		else
		{
			for (auto it : graph[end])
			{
				if (isNotVisited(path, it.first))
				{
					vector<string> newPath(path);
					newPath.push_back(it.first);
					testPaths.push(newPath);
				}
			}
		}

	}

	return allPaths;
}



//vector<pair<int, string>>Graph::getTransportationList(string node1, string node2)
//{
//	vector<pair<int, string>>List;
//	for (auto it : graph[node1])
//	{
//		if (it.first == node2)
//		{
//			auto tmp = it.second;
//			List.assign(tmp.begin(), tmp.end());
//			return List;
//		}
//	}
//
//}


//void Graph::getAllTransportation(string source, string destination, vector<string>& path, int idx, vector<string>route,int cost)
//{
//	vector<pair<int, string>>list;
//	if (source != destination)
//		list = getTransportationList(path[idx], path[idx + 1]);
//	route.push_back(source + '\t');
//	if (source == destination)
//	{
//		//dispaly each permutation
//		for (auto it : route)
//			cout << it<<'\t';
//		cout <<' ' << cost<< endl;
//		return;
//
//	}
//
//	for (int i = 0; i < list.size(); i++)
//	{
//		cost += list[i].first;
//		route.push_back(" (" + list[i].second + ") " + to_string(list[i].first));
//
//		getAllTransportation(path[idx + 1], destination, path, idx + 1, route,cost);
//		route.pop_back();
//		cost -= list[i].first;
//	}
//	return;
//}



void Graph::getAllTransportation(string source, string destination, vector<string>& path, int idx, vector<string>route, int cost,int budget, set<pair<int, vector<string>>> &sortedCosts)
{
	transportations list;
	if (source != destination)
		list = findWeight(path[idx], path[idx + 1]);
	route.push_back(source );
	if (source == destination)
	{
		if(cost <= budget)
			sortedCosts.insert({ cost,route });
		//dispaly each permutation
		/*for (auto it : route)
			cout << it << '\t';
		cout << ' ' << cost << endl;*/
		return;

	}

	for (auto it: list)
	{
		cost += it.first;
		route.push_back("(" + it.second + ")");

		getAllTransportation(path[idx + 1], destination, path, idx + 1, route, cost,budget,sortedCosts);
		route.pop_back();
		cost -= it.first;
	}
	return;
}

void Graph::displayAllPathsBFS(string source, string destination,int budget)
{
	set<pair<int, vector<string>>> sortedCosts;
	vector<vector<string>>pathsToDisplay = BFS(source, destination);
	for (auto it1 : pathsToDisplay)
	{
		vector<string>tmp = it1;
		vector<string>route;
		getAllTransportation(tmp[0], tmp[tmp.size() - 1], tmp, 0, route,0,budget,sortedCosts);

	}
	for (auto it1 : sortedCosts)
	{
		for(auto it2 : it1.second)
		{
			cout << it2<<" ";
		}
		cout<<it1.first << endl;

	}


}

void Graph::displayAllPathsDFS(string source, string destination)
{
	vector<string> currentPath;
	vector<vector<string>> allPaths;
	DFS(source, destination, currentPath, allPaths);

	vector<vector<string>>pathsToDisplay = allPaths;
	for (auto it1 : pathsToDisplay)
	{
		vector<string>tmp = it1;
		vector<string>route;
	}
}

 void Graph ::loadTheGraph() {
	ifstream file("TransportationMap.txt");
	if (!file.is_open()) {
		cerr << "Error: Could not open file." << std::endl;
		return;
	}
	queue<queue<string>> LinesOfWords; // Vector to hold lines of words
	string line;
	while (getline(file, line)) {
		istringstream s(line);
		string word;
		queue<string> words; // Vector to hold words of a line
		// Extract words and store them in a vector
		while (s >> word) {
			words.push(word);
		}
		// Add the vector of words to the vector of lines
		LinesOfWords.push(words);
	}
	file.close();
	int edges = stoi(LinesOfWords.front().back()); // stoi convert string to int
	LinesOfWords.pop();
	while (edges --)
	{
		queue<string> Line = LinesOfWords.front();

		string source, destination;
		transportations tranportMethods;

		source = Line.front();
		Line.pop();
		if (Line.front() == "-")
		{
			Line.pop();
		}
		destination = Line.front();
		Line.pop();
		while (!Line.empty())
		{
			string tranportation = Line.front();
			Line.pop();
			int cost = stoi(Line.front());
			Line.pop();
			tranportMethods.insert({ cost,tranportation });
		}
		AddToGraph(source,destination,tranportMethods);
		LinesOfWords.pop();
	}
}

 void Graph::saveTheGraph() {
	 fstream myfile;
	 /*
	 iinsert a pair of sortand destination each timeand check if sourceand destination of this iteration are egual to the elements of the set
	 if so it goes for the nextiteradtion
	 */ 
	 set<pair<string, string>> sourceAndDestination;
	 //testing on another file rather than tansportation.txt
	 myfile.open("TransportationMap.txt", ios::out);
	 if (myfile.is_open()) {
		 myfile << edgecount << '\n';

		 for (auto edgeline : graph) {


			 for (auto neighbor : edgeline.second) {

				 bool dublicateedge=0;

				 for (auto duplicatechecker : sourceAndDestination) 
				 {
					 if (duplicatechecker.first == neighbor.first && duplicatechecker.second == edgeline.first) 
					 {
						 dublicateedge = 1;
					 }
						 
				 }
				 if (dublicateedge) {
					 continue;
				 }

				 string result = "";
				 result += edgeline.first + " - ";
				 result += neighbor.first;

				 sourceAndDestination.insert({ edgeline.first,neighbor.first });
				 for (auto transportation : neighbor.second) {
					 result += " " + transportation.second + " " +  to_string(transportation.first);
				 }
				 myfile << result << '\n';
			 }

		 }

	 }
	 myfile.close();
 }
