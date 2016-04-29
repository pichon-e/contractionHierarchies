// In this graph, nodes are integers in 0..num_nodes-1, and arcs are also
// integers in 0..num_arcs-1. (in the order in which they're added)
// Thus, when you AddArc(4, 128), you implicitly declare the existence of
// at least 129 nodes (0..128).

#include <set>
#include <utility>
#include <vector>
#include <iostream>
#include <iterator>

#include "graph.h"

using namespace std;


set<int> Graph::getNodes() const {
  return _nodes;
}

vector<pair<int, int> > Graph::getArcs() const {
  return _arcs;
}

int Graph::AddArc(int from, int to) {
  	_arcs.push_back(make_pair(from, to));
  	AddNode(from);
  	AddNode(to);
    return NumArcs() - 1;
}  // Returns the arc index.

  // Optional: nodes are automatically added upon AddArc().
void Graph::AddNode(int node) {
  	_nodes.insert(node);
    if (node > _nodesCount)
      _nodesCount = node + 1;
}

int Graph::NumNodes() const {
  	return _nodesCount;
}

int Graph::NumArcs() const {
  	return getArcs().size();
}

  // Gets the tail ("from") and head ("to") of an arc.
int Graph::Tail(int arc) {
  return _arcs.at(arc).first;
}

int Graph::Head(int arc) {
  return _arcs.at(arc).second;
}

// Returns a list of all the arc indices whose Tail is "from".
const vector<int>& Graph::OutgoingArcs(int from) const {
  vector<int> *outgoing = new vector<int>();

  for (vector<pair<int, int>>::const_iterator it = _arcs.begin(); it != _arcs.end(); ++it) {
    if (it->first == from) {
      outgoing->push_back(distance(_arcs.begin(), it));
    }
  }
  return *outgoing;
}

// Returns a list of all the arc indices whose Head is "to".
const vector<int>& Graph::IncomingArcs(int to) const {
vector<int> *incoming = new vector<int>();

  for (vector<pair<int, int>>::const_iterator it = _arcs.begin(); it != _arcs.end(); ++it) {
    if (it->second == to) {
      incoming->push_back(distance(_arcs.begin(), it));
    }
  }
  return *incoming;
}