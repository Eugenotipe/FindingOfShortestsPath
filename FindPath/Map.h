#pragma once

#include "Node.h"
#include <vector>

class Map
{
private:
	const int nodeAmount;

	std::vector<Node> nodes;
	std::string path;
	std::vector<std::string> shortestPathString;

public:
	Map(const int nodeAmount);
	~Map();

	std::vector<Node>::iterator getNode(int& number);

	void connectNodes(int& start_node, int& end_node);

	void printMap();

	bool shortestPath(int start_node_number, int end_node_number, int distance=0);

	void printShortestPath();
};