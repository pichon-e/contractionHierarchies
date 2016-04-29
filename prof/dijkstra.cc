#include <limits>
#include "graph.h"
#include "dijkstra.h"


Dijkstra::Dijkstra(const Graph* graph, const vector<double>* arc_lengths) {
	graph_ = *graph;
	arc_lengths_ = arc_lengths;
}

Dijkstra::~Dijkstra() {}

void Dijkstra::Run(int source) {
	for (int i = 0; i < arc_lengths_.size(); i++) {
		distance_[0] = std::numeric_limits<double>::max();
	}

	std::vector<int> tmp;

	for (std::vector<int>::iterator it = tmp.begin(); it != tmp.end(); ++it) {
		DijkstraState test;
		test.node = it;
		test.distance = arc_lengths_[it];
		if (distance_[it] > arc_lengths_[it])
			distance_[it] = arc_lengths_[it];
		// placement en fonction de la distance
		queue.push_back(test);
	}
}

  // "Read" API, after a dijkstra run has completed.
const vector<double>& Dijkstra::Distances() const {


	return distance_;
}  // Infinity if not reached.

// const vector<int>& Dijkstra::ParentArcs() const {

// }    // -1 if not reached.

// vector<int> Dijkstra::ArcPathFromSourceTo(int node) const {

}