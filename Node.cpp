#include "Node.h"

Node::Node() = default;

Node::Node(std::string n) 
{
	name = n;
} 


Node::Node(std::string na, const std::vector<std::pair<Node*, int>>& n)
{
	neighbors = n;
	name = na;
}



Node::Node(std::string na, Node* w, int n)
{
	addNeighbors(w, n);
	name = na;
}

std::vector<std::pair<Node*, int>> Node::getNeighbors()
{
	return neighbors;
}

void Node::addNeighbors(Node* w, int n)
{
	neighbors.push_back(std::pair<Node*, int>(w, n));
	w->neighbors.emplace_back(this, n);
}

void Node::addNeighbors(std::vector<std::pair<Node*, int >> n)
{
	for (std::pair<Node*, int> p : n)
	{
		neighbors.emplace_back(p);
		p.first->addNeighbors(this, p.second);
	}
}

void Node::showNeighbors()
{
	for (std::pair<Node*, int> p : neighbors)
	{
		std::cout << '(' << p.first->getName() << ")" << p.second << std::endl;
	}
}

std::string Node::getName() const
{
	return name;
}

void Node::setName(const std::string & N)
{
	name = N;
}

int Node::getMinDistance()
{
	return minDisance;
}

void Node::setMindistance(int m)
{
	minDisance = m;
}

bool Node::getVisited()
{
	return visited;
}

void Node::setVisited(bool v)
{
	visited = v;
}

Node* Node::getPredecessor()
{
	return predecessor;
}

void Node::setPredecessor(Node* p)
{
	predecessor = p;
}


