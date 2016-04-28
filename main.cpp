#include <string>
#include <cstring>
#include <sstream>
#include <fstream>
#include <iostream>
#include <map>
#include <utility>

#include "graph.hh"
#include "route.cpp"
#include "parser.cpp"

using namespace std;

int main(int ac, char* av[])
{
    std::set<std::pair<double, double> > store; // Every points
    std::map<std::pair<double, double> , int> nodes; // Usefull nodes
    
    createGraph(store, nodes, 42, 42);

    double dist = getDistance(make_pair(88.89, -77.03), make_pair(38.89, -57.04));
    cout << "Result : " << dist << endl;

    if (ac == 2)
        parser(av[1]);
    else
        return 1;
    return 0;
}