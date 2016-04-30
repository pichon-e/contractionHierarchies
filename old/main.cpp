#include <string>
#include <cstring>
#include <sstream>
#include <fstream>
#include <iostream>
#include <map>
#include <utility>

#include "graph.hh"
#include "route.hh"
#include "parser.hh"

using namespace std;

int main(int ac, char* av[])
{
    set<pair<double, double> > store; // Every points
    map<pair<double, double> , int> nodes; // Usefull nodes
    map<int, Route> mapPoint;
    
   
    double dist = getDistance(make_pair(88.89, -77.03), make_pair(38.89, -57.04));

    if (ac == 2)
    {
        parser(av[1], mapPoint);
		createGraph(store, nodes, mapPoint);
    }
    else
        return 1;
    return 0;
}