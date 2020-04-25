#pragma once
#include <iostream>
#include <vector>

namespace Djikstra {
	class Graph {
	public:
		Graph();
		~Graph();
		inline const std::string GetName() const { return m_Name;}
	private:
		std::string m_Name;
		std::vector<int> nodes;

	};
}