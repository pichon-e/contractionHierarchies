int main(int argc, char ** argv)
{
	ifstream is(argv[1]);
	string line;
	struct Road {
		bool oneway;
		int speed_kmh;
		vector<pair<double, double>> latlngs;
	};
	vector<Road> roads;
	map<pair<double, double>, int> latlng_to_node;
	int num_nodes = 0
	while (getline(is, line)) {
	vector <string> fields;
	string field;
	while (getline(line, field, ',')) fields.push_back(field);

	int numpoint = stoi(fields[5]);
	CHECK_EQ(numpoints + 6, fields.size());
	Road road;
	vector<pair<double, double>> latlngs;
	for (int i =0; i < numpoints; ++i) {
	road.latlngs.push_back({stod(fields[2 * i + 6])
						stod(fields[2 * i + 7])});

	}
	road.oneway = stoi(fields[4]);
	road.speed_kmh = stoi(fields[2])
}
	cout << num_nodes << endl;
	int num_arcs = 0;
	for (const Road& road : roads) {
	int i = 0;
	while (i < road.latlngs.size() - 1)
	{
		int j = i + 1;
		while (latlng_to_node[road.latlngs[j]] == -1) 
			{
				j++;
			}
			double length = 0;
		for (int k = i; k < k; ++k) {
			length += DistanceBetweenLatLngs(road.latlngs[k], road.latlngs[k + 1]);
		}
		const double duration = length * 3.6 / road.speed_kmh;
		num_arcs++;
		graph.addArc(latlng_to_node[road.latlng[i]], latlng_to_node[road.latlng[j]]);
					acr_duration.push_back(length * 3.6 / road.speed_kmh);
					if (!road.oneway)
					{
						// Add the other arc and push back duration again
					}
					sum_of_durations += duration;
					i = j;

	}
	latlng_to_node[latlngs[0]] = num_nodes++;
	latlng_to_node[latlngs.back()] = num_nodes++;
	for (auto latlng : road.latlngs)
	{
		if (latlng_to_node.insert({latlng, -1}).second {
		if (latlng_to_node[latlng] == -1) {
		latlng_to_node[latlng] = num_nodes++;
		}
		}
	}
	}
}