#include<iostream>
#include "graph.h"
#include "node.h"


class Djikstra
{
public:
	//! Default constructor
	Djikstra();
	//! Destructor
	virtual ~Djikstra() noexcept;
	bool RelaxEdge(Node* src, Node* dest, float weight);
	const Node* GetMinVertex(); 
	bool apply();
	


protected:
private:
	std::vector<Node> m_Path;
	VertexQueue queue;
};
