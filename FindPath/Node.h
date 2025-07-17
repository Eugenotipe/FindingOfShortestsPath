#pragma once

#include <vector>
#include <functional>
#include <string>

struct Node
{
private:
	const int number;
	bool examine;
	int shortedSequence;
	std::vector<std::reference_wrapper<Node>> neighbours;

public:
	Node(const int number);
	~Node();
	int getNumber() const;

	void setNeighbour(Node& neighbour);
	const std::string getSNeighbours() const;
	bool isExamine();
	int getShortedSequence();
	void setShortedSequence(int& currentSequence);
	void explored();
	void unexplored();
	std::vector<std::reference_wrapper<Node>> getNeighbours();

	bool operator== (const Node& other);
};