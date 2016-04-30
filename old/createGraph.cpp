#include "graph.hh"
#include "route.hh"
#include <math.h>

#define R 6371.0088

using namespace std;

void createGraph(set<pair<double, double> > & store, map<pair<double, double>, int> & nodes, map<int, Route> mapPoint)
{
	int j = 0;

	for (int i = 0; i < mapPoint.size() ; i++)
	{
		for (std::vector<std::pair<double, double> >::iterator it = mapPoint.find(i)->second.getPoints().begin() ; it != mapPoint.find(i)->second.getPoints().end(); ++it) {
			cout << it->second << endl;
			//mapPoint.find(i)->second.print();
				map<pair<double, double>, int>::iterator itMap = nodes.find(make_pair(it->first, it->second));
	
			if(!store.insert(make_pair(it->first, it->second)).second && itMap == nodes.end()) { // If the intersection is not already set
				nodes.insert(make_pair(make_pair(it->first, it->second), j)); // If a pair already exists, it's an intersection
				j++;
			}
		}
		i++;
	}
}

void degToRad(pair<double, double> & source, pair<double, double> & dest)
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