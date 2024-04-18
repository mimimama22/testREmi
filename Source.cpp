#include "Node.h"


Node* getMinDistanceNode(std::vector<Node*> graph)
{
	int mindistance = INT32_MAX;
	Node* minNode = nullptr;

	for (Node* node : graph)
	{
		if(!node->getVisited() && node->getMinDistance() < mindistance)
		{
			mindistance = node->getMinDistance();
			minNode = node;
		}
	}
	return minNode;
}

void dijkstra(std::vector <Node*>& graph , Node* source)
{
	source->setMindistance(0);
	while(true)
	{
		Node * currentNode = getMinDistanceNode(graph);

		if (currentNode == nullptr) break;

		currentNode->setVisited(true);

		for (std::pair<Node* , int> & neighbors : currentNode->getNeighbors())
		{
			Node* neighborsNode = neighbors.first;
			int weight = neighbors.second;
			int distanceThroughU = currentNode->getMinDistance()+weight;

			if (distanceThroughU<neighborsNode->getMinDistance())
			{
				neighborsNode->setMindistance(distanceThroughU);
				neighborsNode->setPredecessor(currentNode);
			}
				
		}
		
	}

}

void printPath(Node* target) {
	if (target->getPredecessor() == nullptr) {
		std::cout << target->getName();
		return;
	}
	printPath(target->getPredecessor());
	std::cout << " -> " << target->getName();
}



int main()
{
	
	std::vector<Node* > graph;

	Node A("A");
	Node B("B");
	Node C("C");
	Node D("D");
	Node E("E");
	Node F("F");
	Node G("G");
	Node H("H");
	Node I("I");
	Node J("J");

	A.addNeighbors(&B, 85);
	A.addNeighbors(&C, 217);
	A.addNeighbors(&E, 173);

	B.addNeighbors(&F, 80);

	C.addNeighbors(&G, 186);
	C.addNeighbors(&H, 103); 

	D.addNeighbors(&H, 183);

	E.addNeighbors(&J, 502);

	F.addNeighbors(&I, 250);

	H.addNeighbors(&J, 167);

	I.addNeighbors(&J, 84);


	graph.emplace_back(&A);
	graph.emplace_back(&B);
	graph.emplace_back(&C);
	graph.emplace_back(&D);
	graph.emplace_back(&E);
	graph.emplace_back(&F);
	graph.emplace_back(&G);
	graph.emplace_back(&H);
	graph.emplace_back(&I);
	graph.emplace_back(&J);
	
	
	dijkstra( graph,&A);

	for (Node* node : graph)
	{
		std::cout << " la distance de A a "<<node->getName()<<" est de ";
		if (node->getMinDistance() == INT_MAX)
			std::cout<<"infinie \n";
		else
			std::cout<<node->getMinDistance();
		std::cout << " (path: ";
		printPath(node);
		std::cout<<")\n";
	}
	
	



	return 0;
}