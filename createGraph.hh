#ifndef GRAPH_H
#define GRAPH_H

#include <iostream>
#include <set>
#include <map>
#include <utility>

#include "route.hh"

void createGraph(std::set<std::pair<double, double> > &, std::map<std::pair<double, double>, int> &, std::map<int, Route>);
double getDistance(std::pair<double, double>, std::pair<double, double>);
#endif