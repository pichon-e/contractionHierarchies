#include <iostream>
#include <map>
#include <stdlib.h>

using namespace std;

void parser(char *file) {
    map<int,Route> map;
	ifstream  data(file);
	string line;
    int j = 0;
    while(getline(data,line))
    {
        ++j;
        stringstream lineStream(line);
        string  cell;
        int     i = 0;
        int     nbPoint = 10;
        string  lng;
        string  lat;
        Route* r = new Route();
        while(i < (nbPoint * 2) + 4)
        {
            if (i == ((nbPoint * 2) + 3))
                getline(lineStream,cell,'\n');
            else
                getline(lineStream,cell,',');
            switch (i) {
                case 0:
                    break;
                case 1: 
                    r->setPriority(cell);
                    break;
                case 2:
                    r->setSpeed(cell);
                    break;
                case 3 :
                    break;
                case 4:
                    r->setOneway(cell);
                    break;
                case 5:
                    nbPoint = atoi(cell.c_str());
                    break;
                default:
                    lng = cell;
                    getline(lineStream,cell,',');
                    lat = cell;
                    r->addPoint(lng, lat);
                    break;
            }
            ++i;
        }
        // Add to the map
        map.insert(pair<int, Route>(j,*r));
        r->print();
    }   
}