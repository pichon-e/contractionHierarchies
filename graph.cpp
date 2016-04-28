#include "graph.hh"
#include <math.h>

#define R 6371.0088

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

void degToRad(pair<double, double>& source, pair<double, double>& dest)
{
	source.first = source.first * M_PI / 180;
	source.second = source.second * M_PI / 180;
	dest.first = dest.first * M_PI / 180;
	dest.second = dest.second * M_PI / 180;
}

double getDistance(pair<double, double> source, pair<double, double> dest)
{
	degToRad(source, dest);

	double dlon = dest.second - source.second;
	double dlat = dest.first - source.first;
	double a = pow(sin(dlat/2.0), 2.0) + cos(source.first) * cos(dest.first) * pow(sin(dlon/2.0), 2.0);
	double c = asin(sqrt(a));
	double d = 2.0 * R * c;

	return d;
}