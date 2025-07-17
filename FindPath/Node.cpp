#include "Node.h"
#include <climits>

Node::Node(const int number) :
	number(number),
	examine(false),
	shortedSequence(INT_MAX) { }

Node::~Node() 
{
	neighbours.clear();
}

int Node::getNumber() const
{
	return number;
}

void Node::setNeighbour(Node& neighbour)
{
	neighbours.push_back(std::ref(neighbour));
}

const std::string Node::getSNeighbours() const
{
	std::string sneighbours{""};
	for (const Node& node : neighbours)
	{
		sneighbours += std::to_string(node.getNumber());
		sneighbours += " ";
	}

	return sneighbours;
}

bool Node::isExamine()
{
	return examine;
}

void Node::explored()
{
	if (!examine) examine = true;
}

void Node::unexplored()
{
	if (examine) examine = false;
}

int Node::getShortedSequence()
{
	return shortedSequence;
}

void Node::setShortedSequence(int& currentSequence)
{
	shortedSequence = currentSequence;
}

std::vector<std::reference_wrapper<Node>> Node::getNeighbours()
{
	return neighbours;
}

bool Node::operator== (const Node& other)
{
	return getNumber() == other.getNumber();
}