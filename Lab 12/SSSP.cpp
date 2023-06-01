#include <iostream>
#include <vector>
#include <limits>

using namespace std;

const int INF = numeric_limits<int>::max();

vector<int> dijkstra(const vector<vector<int>>& graph, int source) {
    int num_cities = graph.size();
    vector<int> distances(num_cities, INF);
    vector<bool> visited(num_cities, false);

    distances[source] = 0;

    for (int _ = 0; _ < num_cities; ++_) {
        int min_distance = INF;
        int min_vertex = -1;

        for (int v = 0; v < num_cities; ++v) {
            if (!visited[v] && distances[v] < min_distance) {
                min_distance = distances[v];
                min_vertex = v;
            }
        }

        visited[min_vertex] = true;

        for (int v = 0; v < num_cities; ++v) {
            if (!visited[v] && graph[min_vertex][v] != 0 &&
                distances[min_vertex] + graph[min_vertex][v] < distances[v]) {
                distances[v] = distances[min_vertex] + graph[min_vertex][v];
            }
        }
    }

    return distances;
}

int main() {
    vector<vector<int>> adjacency_matrix = {
        {0, 10, 0, 0, 15, 5},
        {10, 0, 10, 30, 0, 0},
        {0, 10, 0, 12, 5, 0},
        {0, 30, 12, 0, 0, 20},
        {15, 0, 5, 0, 0, 0},
        {5, 0, 0, 20, 0, 0}
    };

    int num_cities = adjacency_matrix.size();

    // Calculate shortest paths from each source city
    vector<vector<int>> shortest_paths;
    for (int source_city = 0; source_city < num_cities; ++source_city) {
        shortest_paths.push_back(dijkstra(adjacency_matrix, source_city));
    }

    // Print shortest paths from each source city to all other cities
    for (int source_city = 0; source_city < num_cities; ++source_city) {
        cout << "Shortest paths from City " << source_city << ":" << endl;
        for (int destination_city = 0; destination_city < num_cities; ++destination_city) {
            cout << "To City " << destination_city << ": " << shortest_paths[source_city][destination_city] << endl;
        }
        cout << endl;
    }

    // Calculate average time taken from each source city to other cities
    vector<double> average_times(num_cities);
    for (int i = 0; i < num_cities; ++i) {
        double sum = 0.0;
        for (int j = 0; j < num_cities; ++j) {
            if (i != j) {
                sum += shortest_paths[i][j];
            }
        }
        average_times[i] = sum / (num_cities - 1);
    }

    // Find the city with the smallest average time
    double smallest_average_time = INF;
    vector<int> best_cities;

    for (int i = 0; i < num_cities; ++i) {
        if (average_times[i] < smallest_average_time) {
            smallest_average_time = average_times[i];
            best_cities.clear();
            best_cities.push_back(i);
        } else if (average_times[i] == smallest_average_time) {
            best_cities.push_back(i);
        }
    }

    cout << "City/Cities with the smallest average time: ";
    for (int city : best_cities) {
        cout << city << " ";
    }
    cout << endl;

    cout << "Smallest average time: " << smallest_average_time << endl;

    return 0;
}

