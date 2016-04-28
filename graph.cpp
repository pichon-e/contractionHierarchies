#include "graph.hh"

using namespace std;

void createGraph(set<pair<double, double> > store, map<pair<double, double>, int> nodes, double longi, double lat)
{
	int j = 0;
	map<pair<double, double>, int>::iterator it = nodes.find(make_pair(longi, lat));
	
	for (int i = 0; i < store.size() ; i++)
	{
		if(!store.insert(make_pair(longi, lat)).second && it == nodes.end()) { // If the intersection is not already set
			nodes.insert(make_pair(make_pair(longi, lat), j)); // If a pair already exists, it's an intersection
			j++;
		}
		i++;
	}
}
