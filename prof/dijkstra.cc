#include <limits>
#include <iostream>
#include "graph.h"
#include "dijkstra.h"

using namespace std;


Dijkstra::Dijkstra(const Graph* graph, const vector<double>* arc_lengths) : graph_(*graph), arc_lengths_(*arc_lengths)
{

}

void Dijkstra::Run(int source) {
	distance_.clear();
	for (int i = 0; i < graph_.NumNodes(); i++) {
		distance_.push_back(std::numeric_limits<double>::infinity());
	}
		std::vector<int> tmp = graph_.OutgoingArcs(source);

	for (std::vector<int>::iterator it = tmp.begin(); it != tmp.end(); ++it) {
		// DijkstraState test;
		// test.node = *it;
		// test.distance = arc_lengths_[*it];
		if (distance_[graph_.Head(*it) ] > arc_lengths_[*it]) {
			distance_[graph_.Head(*it)] = arc_lengths_[*it];
					cout << "num : " << graph_.Head(*it) << endl;
			RunRec(graph_.Head(*it), source);
		}
		// placement en fonction de la distance
		//pq_.push(test);
	}
}

void Dijkstra::RunRec(int source, int prev) {
	std::vector<int> tmp = graph_.OutgoingArcs(source);
		for (std::vector<int>::iterator it = tmp.begin(); it != tmp.end(); ++it) {
		// DijkstraState test;
		// test.node = *it;
		// test.distance = arc_lengths_[*it];
		cout << "num --> " << source << " - " << graph_.Head(*it) << endl;
		if (graph_.Head(*it) != prev && graph_.Head(*it) != source &&  distance_[graph_.Head(*it) ] > arc_lengths_[*it]) {
			distance_[graph_.Head(*it)] = arc_lengths_[*it];
			RunRec(graph_.Head(*it), source);
		}
		// placement en fonction de la distance
		//pq_.push(test);
	}
}

  // "Read" API, after a dijkstra run has completed.
const vector<double>& Dijkstra::Distances() const {


	return distance_;
}  // Infinity if not reached.

// const vector<int>& Dijkstra::ParentArcs() const {

// }    // -1 if not reached.

// vector<int> Dijkstra::ArcPathFromSourceTo(int node) const {}