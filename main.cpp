#include <iostream>
#include <set>
#include <map>

using namespace std;

void createGraph(set<pair<double, double> > store, map<set<pair<double, double> >, int> nodes, double longi, double lat)
{
	int j = 0;
	for (int i = 0; i < store.size() ; i++)
	{
		if(!store.insert(pair<double, double>(longi, lat)).second) {   
			nodes.insert(pair<set<pair<double, double> >, int>(store, j)); // If a pair already exists, it's an intersection
			j++;
		}
		i++;
	}
}

int main()
{
	std::set<pair<double, double> > store; // Every points
	std::map<set<pair<double, double> >, int> nodes; // Usefull nodes

	createGraph(store, nodes, 42, 42);

	cout << "Hello World!" << endl;
	return 0;
}
  