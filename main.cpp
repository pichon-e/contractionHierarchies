#include <iostream>
#include <set>
#include <map>
#include <utility>

#include "graph.hh"

int main()
{
	std::set<std::pair<double, double> > store; // Every points
	std::map<std::pair<double, double> , int> nodes; // Usefull nodes

	createGraph(store, nodes, 42, 42);

	std::cout << "Hello World!" << std::endl;
	return 0;
}
  