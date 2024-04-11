#include "Node.h"





int main()
{
	
	std::vector<Node*> graph;

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

	for (Node* n : graph)
	{
		n->showNeighbors();
		std::cout << std::endl;
	}




	return 0;
}