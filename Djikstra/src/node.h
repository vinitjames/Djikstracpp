#pragma once
#include<string>
#include <map>

class Node {
public:
	Node(int x, int y, const char * label = "Unnamed")
		:m_X(x), m_Y(y), m_Label(label) {}

	int GetX() const;
	int GetY() const;
	const char* GetLabel() const;
	bool AddNeighbor(const Node* node, float weight);
	bool RemoveNeighbor(const Node* node);
	std::map<const Node*, float>* GetWeightedNeighbors();
	bool IsNeighbor(const Node* node);
	bool SetFlag(const std::string flag_label, int flag);
	int GetFlag(const std::string flag_label) const;
	bool RemoveFlag(const std::string flag_label);

private:
	int m_X, m_Y;
	std::map<const Node*, float> m_WeightedNeighbors;
	std::map<const std::string, int> m_Flags;
	std::string m_Label;

};