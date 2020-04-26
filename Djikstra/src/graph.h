#ifndef GRAPH_H
#define GRAPH_H

#include <iostream>
#include <vector>
#include <unordered_map>
#include "node.h"

class Graph {
public:
	Graph();
	~Graph();
	inline const std::string GetName() const { return m_Name;}
	bool AddNode(std::string &name);
	bool DeleteNode(std::string &name);

	bool AddNodeConnection(Node* node, std::pair<const Node*,float> neighbor);
	bool AddNodeConnection(Node* node,
						   std::unordered_map<const Node*,float>& neighbors);
	bool AddNodeConnection(const std::string& node_name,
						   std::unordered_map<const std::string,float>& neighbors);

	bool NodeExists(const std::string& node_name) const;
	bool NodeExists(const Node* node) const ;
	
private:
	
	std::string m_Name;
	std::unordered_map<std::string, Node*> m_Nodes;
	Node* GetNode(const std::string) const;	

};


#endif /* GRAPH_H */
