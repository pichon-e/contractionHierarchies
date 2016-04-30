#ifndef DIJKSTRA_H
#define DIJKSTRA_H

#include <queue>

using namespace std;

struct DijkstraState {
  int node;
  double distance;
  bool operator<(const DijkstraState& other) const {
    return (this->distance < other.distance);
  }
};

class Dijkstra {
 public:
  // "graph" and "arc_lengths" aren't copied.
  Dijkstra(const Graph* graph, const vector<double>* arc_lengths); 

  void Run(int source);

  // "Read" API, after a dijkstra run has completed.
  const vector<double>& Distances() const;  // Infinity if not reached.
  const vector<int>& ParentArcs() const;    // -1 if not reached.
  vector<int> ArcPathFromSourceTo(int node) const;

  void RunRec(int, int);
  void printStack();

 private:
  const Graph& graph_;
  const vector<double>& arc_lengths_;
  vector<pair<double, vector<pair<double, pair<double, double> > > > > distance_;
  vector<int> parent_arc_;
  priority_queue<DijkstraState> pq_;
};

#endif