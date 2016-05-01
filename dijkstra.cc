#include <limits>
#include <iostream>
#include <queue>
#include "graph.h"
#include "dijkstra.h"

using namespace std;


Dijkstra::Dijkstra(const Graph* graph, const vector<double>* arc_lengths) : graph_(*graph), arc_lengths_(*arc_lengths)
{

}

void Dijkstra::Run(int source, int dest) {
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
		//cout << "current --> node : " << current.node << " - distance : " << current.distance << endl;
		tmp.clear();
		tmp = graph_.OutgoingArcs(current.node);
		pq_.pop();
		for (std::vector<int>::iterator it = tmp.begin(); it != tmp.end(); ++it) {
			// remplacer la distance par *it (position de la node) pour savoir si on boucle avec isAlreadyUsed(*it, distance_[graph_.Head(*it)].second)
			if (graph_.Head(*it) != current.node && graph_.Head(*it) != prev.node && !isAlreadyUsed(*it, distance_[graph_.Head(*it)].second)) {
			//cout << "current : " << current.node << " node attegnable : " << graph_.Head(*it) << endl;
				//cout << "---> newItem - node : " << graph_.Head(*it) << " - distance : " << arc_lengths_[*it] << endl;
				//cout << "old distance " << distance_[graph_.Head(*it)] << " prev node : " <<  distance_[prev.node] << " - arc_lengths_ : " << arc_lengths_[*it] << endl;
				//cout << "first " << current.node << " - " <<  prev.node << endl;
				if (distance_[graph_.Head(*it)].first > distance_[current.node].first + arc_lengths_[*it]) {
				//cout << "second " <<  distance_[graph_.Head(*it)].first << " - " <<  distance_[current.node].first + arc_lengths_[*it] << endl;

					newItem.node = graph_.Head(*it);
					newItem.distance = distance_[current.node].first + arc_lengths_[*it];
					pq_.push(newItem);
					distance_[graph_.Head(*it)].first = distance_[current.node].first + arc_lengths_[*it];
					if (!distance_[graph_.Head(*it)].second.empty()) {
						//cout << graph_.Head(*it) << "au moins un élément" << endl;
						if (distance_[graph_.Head(*it)].second.back().first > arc_lengths_[*it]) {
							distance_[graph_.Head(*it)].second = distance_[current.node].second;
							distance_[graph_.Head(*it)].second.push_back(make_pair(arc_lengths_[*it], make_pair(graph_.Tail(*it), graph_.Head(*it))));
						}
					}
					else {
						//cout << graph_.Head(*it) << "empty" << endl;
						if (current.node != source)
							distance_[graph_.Head(*it)].second = distance_[current.node].second;
						distance_[graph_.Head(*it)].second.push_back(make_pair(arc_lengths_[*it], make_pair(graph_.Tail(*it), graph_.Head(*it))));
					}
				}
				
			}
		}
		//printStack();
		prev.node = current.node;
		prev.distance = current.distance;
	}
	int ind = 0;
	double sec = 0;
	for (vector<pair<double, pair<double, double> > >::iterator it2 = distance_[dest].second.begin(); it2 != distance_[dest].second.end(); ++it2) {
		//cout << "node : " << it2->second.first << " -> " << it2->second.second << " en : " << it2->first << "sec." << endl;
		sec += it2->first;
	}
	cout << sec << " secondes" << endl;
	cerr << "\n----- chemin pour aller à " << ind++ << "-----" << endl;

	for (vector<pair<double, pair<double, double> > >::iterator it2 = distance_[dest].second.begin(); it2 != distance_[dest].second.end(); ++it2) {
		cerr << "node : " << it2->second.first << " -> " << it2->second.second << " en : " << it2->first << "sec." << endl;
		sec += it2->first;
	}
}

bool Dijkstra::isAlreadyUsed(int index, vector<pair<double, pair<double, double> > > vec) {
	for (vector<pair<double, pair<double, double> > >::iterator it = vec.begin(); it != vec.end(); ++it){
		if (it->first == index)
			return true;
	}
	return false;
}

void Dijkstra::printStack() {
  	
  	priority_queue<DijkstraState> tmp = pq_;

  	cout << "\n---- START ----" << endl;

	while (!tmp.empty())
	{
		DijkstraState test = tmp.top();
		cout << "{" << test.node << ", " << test.distance << "}" << endl;
		tmp.pop();
	}

  	cout << "---- END ----\n" << endl;
}

  // "Read" API, after a dijkstra run has completed.
const vector<double>& Dijkstra::Distances() const {

	vector<double> *tmp = new vector<double>();

	for (vector<pair<double, vector<pair<double, pair<double, double> > > > >::const_iterator it = distance_.begin(); it != distance_.end(); ++it) {
		tmp->push_back(it->first);
	}
	
	cout << "result " << "[" <<  (*tmp)[0] << ", " <<  (*tmp)[1] << ", "<<  (*tmp)[2] << ", "<<  (*tmp)[3] << ", "<<  (*tmp)[4] << ", "<<  (*tmp)[5] << "]" << endl;	

 	return *tmp;
}  // Infinity if not reached.

// const vector<int>& Dijkstra::ParentArcs() const {

// }    // -1 if not reached.

// vector<int> Dijkstra::ArcPathFromSourceTo(int node) const {}