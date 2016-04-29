#include <string>
#include <iostream>
#include <sstream>

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

    getline(line,lat1,',');
    getline(line,lng1, '>');
    getline(line,lat2,',');
    getline(line,lng2);

    cout << lat1 << "#" << lng1 << "###" << lat2 << "#" << lng2 << "#####"<< endl;
}
