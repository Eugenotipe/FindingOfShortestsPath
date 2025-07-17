#include "ConsoleUtils.h"
#include "Map.h"
#include <iostream>
#include <windows.h>

int main()
{
	SetConsoleOutputCP(CP_UTF8);
	const int nodeAmount{std::stoi(ConsoleUtils::getInput("Введите количество населённых пунктов"))};
	Map map{*new Map(nodeAmount)};
	int start_node, end_node;

	while (true)
	{
		std::cout << "Введите номера двух соединённых городов (0 0 для того, чтобы закончить): ";
		std::cin >> start_node >> end_node;
		if (start_node == 0 && end_node == 0) break;

		if (start_node == end_node) continue;
		
		map.connectNodes(start_node, end_node);
	}
	
	std::cout << "Введите пункт отправления и пункт прибытия: ";
	std::cin >> start_node >> end_node;

	map.shortestPath(start_node, end_node);

	Node& last_node{ *map.getNode(end_node) };

	if (last_node.getShortedSequence() != INT_MAX)
	{
		std::cout << "\nНаикратчайший путь от " << start_node << " до " << end_node << ": " << last_node.getShortedSequence() << std::endl;
		map.printShortestPath();
	}
	else
	{
		std::cout << "Пути нет!";
	}

	return 0;
}