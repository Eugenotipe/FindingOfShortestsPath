#include "Map.h"
#include "LogManager.h"

#include <vector>
#include <iostream>

Map::Map(const int nodeAmount) : nodeAmount(nodeAmount) 
{
	for (int i{ 1 }; i <= nodeAmount; i++)
	{
		nodes.push_back(*new Node(i));
	}
}

Map::~Map()
{
	nodes.clear();
}

std::vector<Node>::iterator Map::getNode(int& desiredNumber)
{
	return std::find_if(nodes.begin(), nodes.end(), [desiredNumber](Node& node) { return node.getNumber() == desiredNumber; });
}

void Map::connectNodes(int& start_node_number, int& end_node_number)
{
	auto start_node{ getNode(start_node_number) };
	auto end_node{ getNode(end_node_number) };
	if (start_node == nodes.end() || end_node == nodes.end())
	{
		std::cerr << "Couldn't find needed node!" << std::endl;
		return;
	}
	start_node->setNeighbour(*end_node);
	end_node->setNeighbour(*start_node);
}

void Map::printMap()
{
	std::cout << "\n === Существующие дороги ===" << std::endl;
	for(Node& node : nodes)
	{
		std::string node_neighbours{node.getSNeighbours()};
		std::cout << node.getNumber() << " имеет соседей: " << node_neighbours << std::endl;
	}
}

bool Map::shortestPath(int start_node_number, int end_node_number, int distance)
{
	Node& start_node{ *Map::getNode(start_node_number) };
	Node& end_node{ *Map::getNode(end_node_number) };

	LogManager::goToLog(start_node);

	if (start_node == end_node) {
		LogManager::log("End node was reached!");
		std::string cur_path{ path + '-' + std::to_string(end_node.getNumber()) };

		if (start_node.getShortedSequence() > distance)
		{
			start_node.setShortedSequence(distance);
			shortestPathString.clear();
			shortestPathString.push_back(cur_path);
			LogManager::log("Path vector was cleared!");
		}
		else if (start_node.getShortedSequence() == distance)
		{
			shortestPathString.push_back(cur_path);
			LogManager::log("Add new path to vector!");
		}

		LogManager::log("Возможный путь: " + cur_path);
		return true;
	}

	if (start_node.isExamine()) {
		LogManager::log("Node number " + std::to_string(start_node.getNumber()) + " is already examine!");
		return false;
	}

	if (start_node.getShortedSequence() <= distance) {
		LogManager::log("Node weight is lower than distance!");
		return false;
	}
	else start_node.setShortedSequence(distance);

	start_node.explored();
	if (distance == 0) 
	{
		path = std::to_string(start_node.getNumber());
	}
	else
	{
		path += "-" + std::to_string(start_node.getNumber());
	}
	for (Node& next_node : start_node.getNeighbours())
	{
		if (shortestPath(next_node.getNumber(), end_node_number, distance + 1))
			break;
	}
//	LogManager::log("Length of the path string: " + std::to_string(path.length()));
	if (distance == 0)
	{
		path.erase();
	}
	else
	{
		path.erase(path.find_last_of('-'));
	}
	start_node.unexplored();

	LogManager::goBackLog(start_node);

	return false;
}

void Map::printShortestPath()
{
	std::cout << "\n === Возможные наикратчайшие пути ===\n";
	for (std::string onePath : shortestPathString)
	{
		std::cout << onePath << std::endl;
	}
}