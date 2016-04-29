#include <algorithm>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
#include <cmath>
#include <set>
#include <map>
using namespace std;

#include "base.h"

double DistanceBetweenLatLngs(pair<double, double> ll1, pair<double, double> ll2) {
  double lat1 = ll1.first;
  double lng1 = ll1.second;
  double lat2 = ll2.first;
  double lng2 = ll2.second;
  // Convert to radians...
  constexpr double kDegToRad = M_PI / 180;
  lat1 *= kDegToRad;
  lng1 *= kDegToRad;
  lat2 *= kDegToRad;
  lng2 *= kDegToRad;
  // https://en.wikipedia.org/wiki/Haversine_formula
  const double s1 = sin(0.5 * (lat2 - lat1));
  const double s2 = sin(0.5 * (lng2 - lng1));
  const double d = 2 * asin(sqrt(s1 * s1 + cos(lat1) * cos(lat2) * s2 * s2));
  // https://en.wikipedia.org/wiki/Earth_radius#Mean_radius
  constexpr double kMeanEarthRadiusMeters = 6371008.8;
  return kMeanEarthRadiusMeters * d;
}

class Graph {
  public:
    void AddArc(int i, int j) {}
};

struct RoadData {
  Graph graph;
  vector<double> arc_durations;
  map<pair<double, double>, int> latlng_to_node;
};

RoadData ParseCsvFile(string filename) {
  ifstream is(filename);
  string line;
  struct Road {
    bool oneway;
    int speed_kmh;
    vector<pair<double, double>> latlngs;
  };
  vector<Road> roads;
  while (getline(is, line)) {
    vector<string> fields;
    string field;
    istringstream is(line);
    while (getline(is, field, ',')) fields.push_back(field);
    int numpoints = stoi(fields[5]);
    CHECK_EQ(2 * numpoints + 6, fields.size()) << line;
    Road road;
    for (int i = 0; i < numpoints; ++i) {
      road.latlngs.push_back({stod(fields[2 * i + 6]),
                              stod(fields[2 * i + 7])});
    }
    road.oneway = stoi(fields[4]);
    road.speed_kmh = stoi(fields[2]);
    roads.push_back(road);
  }

  map<pair<double, double>, int> latlng_count;
  set<pair<double, double>> latlng_nodes;
  map<pair<double, double>, int> latlng_to_node;
  for (const Road& road : roads) {
    for (auto ll : road.latlngs) {
      if (++latlng_count[ll] > 1) latlng_nodes.insert(ll);
    }
    latlng_nodes.insert(road.latlngs[0]);
    latlng_nodes.insert(road.latlngs.back());
  }
  int num_nodes = 0;
  for (auto ll : latlng_nodes) latlng_to_node[ll] = num_nodes++;
  cout << num_nodes << endl;

  Graph graph;
  vector<double> arc_durations;
  for (const Road& road : roads) {
    int i = 0;
    while (i < road.latlngs.size() - 1) {
      int j = i + 1;
      while (latlng_nodes.count(road.latlngs[j]) == 0) j++;
      double length = 0;
      for (int k = i; k < j; ++k) {
        length += DistanceBetweenLatLngs(road.latlngs[k],
                                         road.latlngs[k + 1]);
      }
      const double duration = length * 3.6 / road.speed_kmh;
      graph.AddArc(latlng_to_node[road.latlngs[i]],
                  latlng_to_node[road.latlngs[j]]);
      arc_durations.push_back(duration);
      if (!road.oneway) {
        graph.AddArc(latlng_to_node[road.latlngs[j]],
                     latlng_to_node[road.latlngs[i]]);
        arc_durations.push_back(duration);
      }
      i = j;
    }
  }
  cout << arc_durations.size() << endl;
  cout << std::accumulate(arc_durations.begin(), arc_durations.end(), 0) << endl;

  RoadData data;
  data.graph = graph;
  data.latlng_to_node = latlng_to_node;
  data.arc_durations = arc_durations;
  return data;
}

int main(int argc, char** argv) {
  ParseCsvFile(argv[1]);
}

