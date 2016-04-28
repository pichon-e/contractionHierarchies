#include <string>
#include <cstring>
#include <sstream>
#include <fstream>
#include <iostream>
#include <set>
#include <map>
#include <utility>

#include "graph.hh"
using namespace std;

#define _CRT_SECURE_NO_WARNINGS // Hello, strtok

const char* const CSV_DELIMITER = ",";
const int MAX_BUFF_LINE = 12000;
const int MAX_ELEM = 6000;

int main(int ac, char* av[])
{

	std::set<std::pair<double, double> > store; // Every points
	std::map<std::pair<double, double> , int> nodes; // Usefull nodes

	createGraph(store, nodes, 42, 42);

	double dist = getDistance(make_pair(88.89, -77.03), make_pair(38.89, -57.04));
	cout << "Result : " << dist << endl;

	if (ac == 2)
	{
	    ifstream  data(av[1]);
		string line;
        while(getline(data,line))
        {
            stringstream lineStream(line);
            string cell;
            while(getline(lineStream,cell,','))
            {
                cout  << cell << endl;
            }
        }
	}
	else
        return 1;
   	return 0;
}
