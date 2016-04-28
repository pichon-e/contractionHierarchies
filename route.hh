#ifndef ROUTE_H
#define ROUTE_H

#include <iostream>
#include <string>
#include <vector>

class Route
{
	public:
		Route();
		~Route();

		// Getters
		int		getSpeed();
		int		getPriority();
		bool	isOneway();
		std::vector<std::pair<double, double> >	getPoints();

		// Setters
		void 	setSpeed(std::string);
		void	setPriority(std::string);
		void	setOneway(std::string);
		void	addPoint(std::string, std::string);

		void	print();

	private:
		int		_speed;
		int		_priority;
		bool	_oneway;
		std::vector<std::pair<double, double> >	_points;

};

#endif