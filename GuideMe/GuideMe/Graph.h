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
#include<fstream> // For file operations
#include<sstream>
#define transportations set<pair<int, string>>

using namespace std;



class Graph
{
public:
	map<string, bool> visited;
	map<pair<int, string>, bool> used_vehicle;
	//            source           destination   vector of pair(transportaion,cost)
	unordered_map<string, list <pair<string, transportations>>> graph;

	//set to store nodes and counter to calculate number of insertions
	set<string> nodes;
	int edgecount = 0;

	
public:
	Graph();

	void AddToGraph(string, string, transportations);

	void DFS(string, string, vector<string>&, vector<vector<string>>&);

	vector<vector<string>> BFS(string, string);

	void BFS_Traverse(string source);

	void DFS_Traverse(string);

	/*void find_lowest_cost(string, string);*/

	transportations findWeight(string, string);

	void displayAllPathsBFS(string, string,int);

	void displayAllPathsDFS(string, string, int);

	void checkCompleteness();

	void loadTheGraph();

	void saveTheGraph();

	void getAllTransportation(string, string, vector<string>&, int, vector<string>,int,int, set<pair<int, vector<string>>>&);

/*	vector<pair<int, string>>getTransportationList(string, string)*/;

	void Add(string, string, transportations);

	void Update(string, string, pair<int,string>);

	void DeleteForUpdate(string, string, string,int);

	void Delete(string, string);

	void displayNeighborCities(string);

	void displayAllCities(string);

};

