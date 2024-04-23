#pragma once
#include<iostream>
#include<unordered_map>
#include<vector>
#include<list>
#include<string>
#include<map>
#include<stack>
#include<queue>

using namespace std;

struct transportaions
{
	vector<pair<string, int>> vehicle;

};



class Graph
{
public:
	map<string, bool> visited;
	//            source           destination   vector of pair(transportaion,cost)
	unordered_map<string, list <pair<string, vector<pair<string, int>>>>> graph;
public:
	Graph();

	void AddToGraph(string source, string destination, vector<pair<string, int>> list_Of_Transportation);

	void DFS(string);

	void BFS(string, string);


};
