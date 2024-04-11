#pragma once
#include <vector>
#include <iostream>

class Node
{
private:

	std:: string name;
	std::vector<std::pair<Node*,int>> neighbors;


public:

	Node();
	Node(std::string);
	Node(std::string,const std::vector<std::pair<Node*, int>> &);
	Node(std::string ,Node*, int);

	std::vector<std::pair<Node*, int>> getNeighbors();

	void addNeighbors(Node* , int);
	void addNeighbors(std::vector<std::pair<Node*, int>>);

	void showNeighbors();

	std::string getName()const;
	void setName(const std::string &);



};

