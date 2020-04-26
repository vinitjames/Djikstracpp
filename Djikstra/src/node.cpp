#include "node.h"

const char* Node::GetLabel() const { 
	return m_Label.c_str(); 
}

int Node::GetX() const { 
	return m_X; 
}

int Node::GetY() const { 
	return m_Y; 
}

bool Node::AddNeighbor(std::pair<const Node*, float> &neighbor){
	return m_WeightedNeighbors.insert(neighbor).second;
}
	
bool Node::AddNeighbor(const Node* node_ptr, float weight) {
	return m_WeightedNeighbors.insert(std::pair<const Node*, 
		float>(node_ptr, weight)).second;
}

bool Node::RemoveNeighbor(const Node* node_ptr) {
	return m_WeightedNeighbors.erase(node_ptr);
}

std::unordered_map<const Node*, float>* Node::GetWeightedNeighbors(){
	return &m_WeightedNeighbors;
}

bool Node::IsNeighbor(const Node* node_ptr) {
	if (m_WeightedNeighbors.find(node_ptr) == m_WeightedNeighbors.end())
		return false;
	return true;
}

bool Node::SetFlag(const std::string flag_label, int flag) {
	return m_Flags.insert(std::pair<const std::string, 
		int>(flag_label, flag)).second;
}

int Node::GetFlag(const std::string flag_label) const{
	auto it = m_Flags.find(flag_label);
	if (it == m_Flags.end())
		return -1;
	return it->second;
}

bool Node::RemoveFlag(const std::string flag_label) {
	return m_Flags.erase(flag_label);
}
