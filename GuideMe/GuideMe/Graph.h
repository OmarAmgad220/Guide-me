#pragma once
#include<iostream>
#include<unordered_map>
#include<vector>
#include<list>
#include<string>
#include<map>
#include<stack>
#include<queue>
#include<set>
#define transportations set<pair<int, string>>

using namespace std;



class Graph
{
public:
	map<string, bool> visited;
	map<pair<int, string>, bool> used_vehicle;
	//            source           destination   vector of pair(transportaion,cost)
	unordered_map<string, list <pair<string, transportations>>> graph;
public:
	Graph();

	void AddToGraph(string, string, transportations);

	void DFS(string, string, vector<string>&, vector<vector<string>>&);

	void BFS(string, string);

	void find_lowest_cost(string, string);

	transportations findWeight(string, string);

	void tagroba(string, string);

};

