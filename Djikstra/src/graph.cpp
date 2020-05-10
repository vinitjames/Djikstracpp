#include "graph.h"

bool Graph::AddNode(unsigned int id, const std::string& name){

	if (NodeExists(id))
		std::cerr <<" Node with the same id "<<id<<" already exists\n";
	   
	try {
		Node *node = new Node(name);
		return m_Nodes.insert(std::pair<unsigned int , Node*>(id, node)).second;
	} catch (std::bad_alloc &b) {
		std::cerr << b.what()<< " Memory could new be allocated for Node"
				  << name << "\n";
		return false;
	}
}

bool Graph::DeleteNode(unsigned int id){
	auto it = m_Nodes.find(id);
	if (it == m_Nodes.end()) {return false;}
	delete it->second;
	m_Nodes.erase(it);
	return true;
}

bool Graph::AddNodeConnection(unsigned int id,
							  std::unordered_map<unsigned int, float>& neighbors){
	
	for(auto &neighbor : neighbors){
		AddNodeConnection(id, neighbor);
	}
	return true;
}

bool Graph::AddNodeConnection(unsigned int id, const std::pair<unsigned int ,float>& neighbor){
	Node* node = GetNode(id);

	if (!node){
		std::cerr <<" Node does not exists in graph\n";
		return false;
	}
	
	Node* neighbor_node = GetNode(neighbor.first);
		if (!neighbor_node){
		std::cerr <<" neighbor does not exists in graph\n";
		return false;
		}
		
		AddNodeConnection(node, std::pair<const Node*,float>
						  (neighbor_node, neighbor.second));
		return true;
}

bool Graph::AddNodeConnection(Node* node, std::unordered_map<const Node*, float>& neighbors){
	
	for(auto& neighbor : neighbors){
		if (!AddNodeConnection(node, neighbor))
			return false;
	}
	return true;
}

bool Graph::AddNodeConnection(Node* node, const std::pair<const Node*,float>& neighbor){

	if (!node)
		return false;
	
	node->AddNeighbor(neighbor);
	return true;
}

bool Graph::NodeExists(unsigned int id) const {
	return (m_Nodes.find(id) != m_Nodes.end());
}	


bool Graph::NodeExists(const Node* node) const {
	for(auto it : m_Nodes){
		if (it.second == node)
			return true;
	}
	return false;
	
}	

Node* Graph::GetNode(unsigned int id) const {
	auto it = m_Nodes.find(id);
	if (it == m_Nodes.end())
		return NULL;
	return it->second;
}


