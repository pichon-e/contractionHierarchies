#include <iostream>
#include <string>
#include <stdlib.h>
#include <vector>
#include <iomanip> 

#include "route.hh"

using namespace std;

Route::Route() {}

Route::~Route() {}

int Route::getSpeed() {
	return _speed;
}

int	Route::getPriority() { 
	return _priority; 
}

bool Route::isOneway() { 
	return _oneway; 
}

std::vector<std::pair<double, double> > Route::getPoints() {
	return _points;
}

void Route::setSpeed(string speed) { 
	_speed = atoi(speed.c_str());
}

void Route::setPriority(string priority) { 
	_priority = atoi(priority.c_str());
}

void Route::setOneway(string oneway) {
	if (oneway == "1")
		_oneway = true;
	else
		_oneway = false;
}

void Route::addPoint(string lng, string lat) { 
	_points.push_back(std::make_pair(atof(lng.c_str()), atof(lat.c_str()))); 
}

void Route::print() {
	cout << "speed : " << getSpeed() << endl;
	cout << "priority : " << getPriority() << endl;
	cout << "oneway : " << isOneway() << endl;
	cout << "------ Points ------" << endl;
	 for (std::vector<std::pair<double, double> >::iterator it = _points.begin() ; it != _points.end(); ++it) {
    	cout << "lng : " << setprecision (4) << fixed <<  it->first;
    	cout << " lat : " << setprecision (4) << fixed <<  it->second << endl;
    }
    cout << endl;
}