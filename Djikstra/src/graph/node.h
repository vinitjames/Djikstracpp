#ifndef NODE_H
#define NODE_H

#include<string>
#include<unordered_map>

class Node {
public:

	Node(const std::string&  label = "Unnamed")
		:m_Label(label) {}

	
	const char* GetLabel() const;
	bool AddNeighbor(const Node* node, float weight);
	bool AddNeighbor(const std::pair<const Node*,float>& neighbor);
	bool RemoveNeighbor(const Node* node);

	std::unordered_map<const Node*, float>* GetWeightedNeighbors() ;
	bool IsNeighbor(const Node* node);
	bool SetFlag(const std::string& flag_label, int flag);
	int GetFlag(const std::string& flag_label) const;
	bool RemoveFlag(const std::string& flag_label);

private:
	std::unordered_map<const Node*, float> m_WeightedNeighbors;
	std::unordered_map<std::string, int> m_Flags;
	std::string m_Label;

};

#endif
