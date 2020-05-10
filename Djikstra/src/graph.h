#ifndef GRAPH_H
#define GRAPH_H

#include <iostream>
#include <vector>
#include <unordered_map>
#include "node.h"

class Graph {
public:
	Graph(){};
	~Graph(){};
	inline const std::string GetName() const { return m_Name;}
	bool AddNode(unsigned int id, const std::string &name);
	bool DeleteNode(unsigned int id);

	bool AddNodeConnection(Node* node, const std::pair<const Node*,float>& neighbor);
	bool AddNodeConnection(unsigned int id, const std::pair<unsigned int ,float>& neighbor);
	bool AddNodeConnection(Node* node,
						   std::unordered_map<const Node*,float>& neighbors);
	bool AddNodeConnection(unsigned int id,
						   std::unordered_map<unsigned int, float>& neighbors);

	bool NodeExists(unsigned int id) const;
	bool NodeExists(const Node* node) const ;
	
private:
	std::string m_Name;
	std::unordered_map< unsigned int, Node*> m_Nodes;
	Node* GetNode(unsigned int id) const;	

};


#endif /* GRAPH_H */
