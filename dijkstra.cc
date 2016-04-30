#include <limits>
#include <iostream>
#include <queue>
#include "graph.h"
#include "dijkstra.h"

using namespace std;


Dijkstra::Dijkstra(const Graph* graph, const vector<double>* arc_lengths) : graph_(*graph), arc_lengths_(*arc_lengths)
{

}

void Dijkstra::Run(int source) {
	distance_.clear();

	for (int i = 0; i < graph_.NumNodes(); i++) {
		if (i != source)
			distance_.push_back(std::numeric_limits<double>::infinity());
		else
			distance_.push_back(0);
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
			//cout << "current : " << current.node << " node attegnable : " << graph_.Head(*it) << endl;
			if (graph_.Head(*it) != current.node && graph_.Head(*it) != prev.node) {
				//cout << "---> newItem - node : " << graph_.Head(*it) << " - distance : " << arc_lengths_[*it] << endl;
				//cout << "old distance " << distance_[graph_.Head(*it)] << " prev node : " <<  distance_[prev.node] << " - arc_lengths_ : " << arc_lengths_[*it] << endl;
				if (distance_[graph_.Head(*it)] > distance_[current.node] + arc_lengths_[*it]) {
					newItem.node = graph_.Head(*it);
					newItem.distance = distance_[current.node] + arc_lengths_[*it];
					pq_.push(newItem);
					distance_[graph_.Head(*it)] = distance_[current.node] + arc_lengths_[*it];
				}
				
			}
		}
		//printStack();
		prev.node = current.node;
		prev.distance = current.distance;
	}	
	cout << "result " << "[" <<  distance_[0] << ", " <<  distance_[1] << ", "<<  distance_[2] << ", "<<  distance_[3] << ", "<<  distance_[4] << ", "<<  distance_[5] << "]" << endl;	

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

void Dijkstra::RunRec(int source, int prev) {
	std::vector<int> tmp = graph_.OutgoingArcs(source);
		for (std::vector<int>::iterator it = tmp.begin(); it != tmp.end(); ++it) {

		cout << "num --> " << source << " - " << graph_.Head(*it) << endl;
		if (graph_.Head(*it) != prev && graph_.Head(*it) != source) {
			//distance_[graph_.Head(*it)] = arc_lengths_[*it];
			DijkstraState test;
			test.node = *it;
			test.distance = arc_lengths_[*it];
			pq_.push(test);
			RunRec(graph_.Head(*it), source);
		}
		//placement en fonction de la distance
	}
}

  // "Read" API, after a dijkstra run has completed.
const vector<double>& Dijkstra::Distances() const {


	return distance_;
}  // Infinity if not reached.

// const vector<int>& Dijkstra::ParentArcs() const {

// }    // -1 if not reached.

// vector<int> Dijkstra::ArcPathFromSourceTo(int node) const {}