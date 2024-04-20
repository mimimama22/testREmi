#pragma once
#include <vector>
#include <iostream>

class Node
{
private:

	std:: string name;
	std::vector<std::pair<Node*,int>> neighbors;

	int minDisance = INT_MAX;
	bool visited = false;

	Node* predecessor = nullptr;


public:

	Node();
	Node(std::string);
	Node(std::string,const std::vector<std::pair<Node*, int>> &);
	Node(std::string ,Node*, int);

	std::vector<std::pair<Node*, int>> getNeighbors();

	void addNeighbors(Node* , int);
	void addNeighbors(std::vector<std::pair<Node*, int>>);

	void showNeighbors();

	std::string getName();
	void setName(const std::string &);

	int getMinDistance();
	void setMindistance(int);

	bool getVisited();
	void setVisited(bool);

	Node* getPredecessor();
	void setPredecessor(Node*);

};

