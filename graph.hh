#ifndef GRAPH_H
#define GRAPH_H

#include <iostream>
#include <set>
#include <map>
#include <utility>

void createGraph(std::set<std::pair<double, double> >, std::map<std::pair<double, double>, int>, double, double);
double getDistance(std::pair<double, double>, std::pair<double, double>);

#endif