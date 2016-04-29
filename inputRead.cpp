#include <string>
#include <iostream>
#include <sstream>
#include <algorithm>

using namespace std;

string inputRead()
{
	string line;
        if(std::getline(cin, line))
            return line;
    return 0;
}

void inputParse()
{
    string line;
    string lat1;
    string lng1;
    string lat2;
    string lng2;

    line = regex_replace(inputRead(), regex("\->"), ">");

    stringstream lstream(line);
    getline(lstream,lat1,',');
    getline(lstream,lng1, '>');
    getline(lstream,lat2,',');
    getline(lstream,lng2);

    cout << lat1 << "#" << lng1 << "###" << lat2 << "#" << lng2 << "#####"<< endl;
}
