#include <limits>
#include <iostream>
#include <queue>
#include <map>
#include "graph.h"
#include "dijkstra.h"

using namespace std;


Dijkstra::Dijkstra(const Graph* graph, const vector<double>* arc_lengths) : graph_(*graph), arc_lengths_(*arc_lengths)
{

}

void Dijkstra::Run(int source, int dest, map<pair<double, double>, int> all) {
	distance_.clear();

	for (int i = 0; i < graph_.NumNodes(); i++) {
		vector<pair<double, pair<double, double> > > test;
		if (i != source)
			distance_.push_back(make_pair(std::numeric_limits<double>::infinity(), test));
		else
			distance_.push_back(make_pair(0, test));
	}


	DijkstraState current;
	DijkstraState prev;
	DijkstraState newItem;
	DijkstraState SourceItem;
	std::vector<int> tmp;

	prev.node = -1;

	SourceItem.node = source;
	SourceItem.distance = 0;
	
	pq_.push(SourceItem);

	int j = 0;

	while (!pq_.empty() )
	{
		current = pq_.top();
		tmp.clear();
		tmp = graph_.OutgoingArcs(current.node);
		pq_.pop();
		for (std::vector<int>::iterator it = tmp.begin(); it != tmp.end(); ++it) {
			if (graph_.Head(*it) != current.node && graph_.Head(*it) != prev.node && !isAlreadyUsed(*it, distance_[graph_.Head(*it)].second)) {
				if (distance_[graph_.Head(*it)].first > distance_[current.node].first + arc_lengths_[*it]) {
					newItem.node = graph_.Head(*it);
					newItem.distance = distance_[current.node].first + arc_lengths_[*it];
					pq_.push(newItem);
					distance_[graph_.Head(*it)].first = distance_[current.node].first + arc_lengths_[*it];
					if (!distance_[graph_.Head(*it)].second.empty()) {
						if (distance_[graph_.Head(*it)].second.back().first > arc_lengths_[*it]) {
							distance_[graph_.Head(*it)].second = distance_[current.node].second;
							distance_[graph_.Head(*it)].second.push_back(make_pair(arc_lengths_[*it], make_pair(graph_.Tail(*it), graph_.Head(*it))));
						}
					}
					else {
						if (current.node != source)
							distance_[graph_.Head(*it)].second = distance_[current.node].second;
						distance_[graph_.Head(*it)].second.push_back(make_pair(arc_lengths_[*it], make_pair(graph_.Tail(*it), graph_.Head(*it))));
					}
				}
				
			}
		}
		prev.node = current.node;
		prev.distance = current.distance;
	}
	int ind = 0;
	double sec = 0;
	for (vector<pair<double, pair<double, double> > >::iterator it2 = distance_[dest].second.begin(); it2 != distance_[dest].second.end(); ++it2) {
		sec += it2->first;
	}
	map<int, pair<double, double>> reversed;

	for (map<pair<double, double>, int>::iterator it = all.begin(); it != all.end(); ++it)
    	reversed[it->second] = it->first;
    j = 0;

	cout << sec << " seconds" << endl;
	cerr << "----- PATH from " << source << " to " << dest << " -----" << endl;

	for (vector<pair<double, pair<double, double> > >::iterator it2 = distance_[dest].second.begin(); it2 != distance_[dest].second.end(); ++it2) {
		cerr << "node : " << it2->second.first << " (" << reversed.find(it2->second.first)->second.first << ";" << reversed.find(it2->second.first)->second.second << ") -> " << it2->second.second << " (" << reversed.find(it2->second.second)->second.first << ";" << reversed.find(it2->second.second)->second.second << ") in : " << it2->first << "sec." << endl;
		j++;
	}
	cerr << "Path total time " << sec << " seconds" << endl;
}

bool Dijkstra::isAlreadyUsed(int index, vector<pair<double, pair<double, double> > > vec) {
	for (vector<pair<double, pair<double, double> > >::iterator it = vec.begin(); it != vec.end(); ++it){
		if (it->first == index)
			return true;
	}
	return false;
}

const vector<double>& Dijkstra::Distances() const {

	vector<double> *tmp = new vector<double>();

	for (vector<pair<double, vector<pair<double, pair<double, double> > > > >::const_iterator it = distance_.begin(); it != distance_.end(); ++it) {
		tmp->push_back(it->first);
	}
	
	cout << "result " << "[" <<  (*tmp)[0] << ", " <<  (*tmp)[1] << ", "<<  (*tmp)[2] << ", "<<  (*tmp)[3] << ", "<<  (*tmp)[4] << ", "<<  (*tmp)[5] << "]" << endl;	

 	return *tmp;
} 