#include "node.h"
#include <iostream>
#include "graph.h"
int main(int argc, char *argv[])
{
    /*Node* n1 = new Node("node1");
	Node* n2 = new Node("node2");
	Node* n3 = new Node("node3");
	Node* n4 = new Node("node4");
	Node* n5 = new Node("node5");
	n1->AddNeighbor(n2,4);
	n1->AddNeighbor(n3,2);
	n1->AddNeighbor(n4,3);

	std::cout<<n1->GetLabel()<< std::endl;
	std::cout<<n1->IsNeighbor(n2)<<std::endl;
	std::cout<<n1->IsNeighbor(n5)<<std::endl;
	auto weightedneighbors = n1->GetWeightedNeighbors();
	for(auto&it: *weightedneighbors){
		std::cout<< it.first->GetLabel()<<std::endl<< it.second<<std::endl;
	}
	*/

	Graph graph;
	std::cout<<"Adding nodes to graph"<<std::endl;
	std::cout<<graph.AddNode(1, "node1")<<std::endl;
	std::cout<<graph.AddNode(2, "node2")<<std::endl;
	std::cout<<graph.AddNode(3, "node3")<<std::endl;
	std::cout<<graph.AddNode(4, "node4")<<std::endl;
	std::cout<<graph.AddNode(5, "node5")<<std::endl;

	std::cout<<"Adding nodes to graph"<<std::endl;
	std::cout<<graph.AddNodeConnection(1, {2,5.0})<<std::endl;
	std::cout<<graph.AddNodeConnection(1, {3,4.0})<<std::endl;
	std::cout<<graph.AddNodeConnection(1, {4,2.0})<<std::endl;
	return 0;

}
