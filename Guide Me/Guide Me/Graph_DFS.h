#pragma once
#include<string>
#include <iostream>
#include <stack>
#include <unordered_map>
#include <map>
#include <list>
#include <vector>

using namespace std;

class Graph_DFS
{
	public:
	map<string, bool> visited;
	//            source           destination   vector of pair(transportaion,cost)
	unordered_map<string, list <pair<string, vector<pair<string, int>>>>> graph;
	public:
	Graph_DFS();

	void AddToGraph(string source, string destination, vector<pair<string, int>> list_Of_Transportation);
	
	void DFS(string);
};


