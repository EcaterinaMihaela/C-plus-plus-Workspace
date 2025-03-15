#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

// Functie pentru a efectua BFS si a calcula distantele
pair<int, int> bfs(int start, const vector<vector<int>>& graph) {
    int n = graph.size();
    vector<int> dist(n, -1);
    queue<int> q;

    dist[start] = 0;
    q.push(start);

    int farthest_node = start;
    while (!q.empty()) {
        int node = q.front();
        q.pop();

        for (int neighbor : graph[node]) {
            if (dist[neighbor] == -1) {
                dist[neighbor] = dist[node] + 1;
                q.push(neighbor);
                if (dist[neighbor] > dist[farthest_node]) {
                    farthest_node = neighbor;
                }
            }
        }
    }

    return { farthest_node, dist[farthest_node] };
}

// Functie pentru a calcula diametrul unui graf
int calculate_diameter(const vector<vector<int>>& graph) {
    pair<int, int> p1 = bfs(1, graph);  // Primul BFS
    pair<int, int> p2 = bfs(p1.first, graph);  // Al doilea BFS
    return p2.second;
}

int main() {
    int n;
    cin >> n;

    vector<int> diameters(n); // Diametrele fiecarui paianjen

    for (int i = 0; i < n; ++i) {
        int ni;
        cin >> ni;

        vector<vector<int>> graph(ni + 1);
        for (int j = 0; j < ni - 1; ++j) {
            int u, v;
            cin >> u >> v;
            graph[u].push_back(v);
            graph[v].push_back(u);
        }

        diameters[i] = calculate_diameter(graph);
    }

    // Sortam diametrele in ordine descrescatoare
    sort(diameters.rbegin(), diameters.rend());

    // Lungimea maxima a constructiei
    int max_length = diameters[0];
    if (n > 1) {
        max_length += diameters[1] + 1;
    }

    cout << max_length << endl;

    return 0;
}
