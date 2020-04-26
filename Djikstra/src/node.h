#ifndef NODE_H
#define NODE_H

#include<string>
#include <unordered_map>

class Node {
public:
	Node(int x, int y, const char * label = "Unnamed")
		:m_X(x), m_Y(y), m_Label(label) {}

	Node(const char * label = "Unnamed")
		:m_X(0), m_Y(), m_Label(label) {}

	int GetX() const;
	int GetY() const;
	const char* GetLabel() const;
	
	bool AddNeighbor(const Node* node, float weight);
	bool AddNeighbor(std::pair<const Node*,float> &neighbor);
	bool RemoveNeighbor(const Node* node);

	std::unordered_map<const Node*, float>* GetWeightedNeighbors();
	bool IsNeighbor(const Node* node);
	bool SetFlag(const std::string flag_label, int flag);
	int GetFlag(const std::string flag_label) const;
	bool RemoveFlag(const std::string flag_label);

private:
	int m_X, m_Y;
	std::unordered_map<const Node*, float> m_WeightedNeighbors;
	std::unordered_map<const std::string, int> m_Flags;
	std::string m_Label;

};

#endif
