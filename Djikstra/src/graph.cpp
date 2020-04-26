#include "graph.h"

bool Graph::AddNode(std::string& name){

	if (NodeExists(name))
		std::cerr <<" Node with the name "<<name<<" already exists\n";
	   
	try {
		Node *node = new Node(name.c_str());
		
		return m_Nodes.insert({name, node}).second;
		
	} catch (std::bad_alloc &b) {
		
		std::cerr << b.what()<< " Memory could new be allocated for Node"
				  << name << "\n";
		return false;
	}
}

bool Graph::DeleteNode(std::string &name){
	auto it = m_Nodes.find(name);
	if (it == m_Nodes.end()) {return false;}
	delete it->second;
	m_Nodes.erase(it);
	return true;
}

bool Graph::AddNodeConnection(const std::string& node_name,
							  std::unordered_map<const std::string,float>& neighbors){
	Node* node = GetNode(node_name);
	if (!node){
		std::cerr <<" Node does not exists in graph\n";
		return false;
	}
	for(auto neighbor : neighbors){
		Node* neighbor_node = GetNode(neighbor.first);
		if (!neighbor_node){
		std::cerr <<" neighbor does not exists in graph\n";
		return false;
		}
		AddNodeConnection(node, std::pair<const Node*,float>
						  (neighbor_node, neighbor.second));
	}
	return true;
}


bool Graph::AddNodeConnection(Node* node, std::unordered_map<const Node*,float>& neighbors){
	if (!NodeExists(node)){
		std::cerr <<" Node does not exists in graph\n";
		return false;
	}
	
	for(auto neighbor : neighbors){
		AddNodeConnection(node, neighbor);
	}
	return true;
}

bool Graph::AddNodeConnection(Node* node, std::pair<const Node*,float> neighbor){

	if (!NodeExists(node)){
	   std::cerr <<" Node does not exists in graph\n";
	   return false;
	}

	if (!NodeExists(neighbor.first)){
		std::cerr <<" neighbor does not exists in graph\n";
		return false;
	}
	node->AddNeighbor(neighbor);
	return true;
}

bool Graph::NodeExists(const std::string& node_name) const {
	return (m_Nodes.find(node_name) != m_Nodes.end());
	}	


bool Graph::NodeExists(const Node* node) const {
	for(auto it : m_Nodes){
		if (it.second == node)
			return true;
	}
	return false;
	
}	

Node* Graph::GetNode(const std::string nodename)const {
	auto it = m_Nodes.find(nodename);
	if (it == m_Nodes.end())
		return NULL;
	return it->second;
}


