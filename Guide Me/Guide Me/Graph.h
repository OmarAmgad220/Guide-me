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
#define transportaions set<pair<int, string>>

using namespace std;

class Graph
{
public:
	map<string, bool> visited;
	//            source           destination   vector of pair(transportaion,cost)
	unordered_map<string, list <pair<string, transportaions>>> graph;
public:
	Graph();

	void AddToGraph(string,string,transportaions );

	void DFS(string, string, vector<string>&, vector<vector<string>>&);

	void BFS(string, string);


};
