#include <algorithm>
#include <cstdint>
#include <iostream>
#include <vector>
#include <queue>

using std::cin;
using std::cout;
using std::vector;
using std::pair;
using std::queue;
using std::reverse;
using std::sort;

struct edge {
    int32_t dst;
    bool dst_stable;

    edge (int32_t dst, bool dst_stable) : dst(dst), dst_stable(dst_stable) {}
};
struct possible_path {
    bool possible;
    vector<int32_t> path;
};

void add_edge(int32_t x, int32_t y, vector<vector<int32_t>>& adj) {
    adj[x].push_back(y);
}

void get_neighbours(int32_t node, bool is_stable, vector<vector<int32_t>>& adj, vector<edge>& neighbours) {
    neighbours.clear();

    for (int32_t i = 0; i < adj[node].size(); i++) {
        int32_t neighbour = adj[node][i];
        neighbours.emplace_back(neighbour, !is_stable);
    }

    if (!neighbours.empty()) {
        sort(neighbours.begin(), neighbours.end(), [](const edge& a, const edge& b) {
            return a.dst < b.dst;
        });
    }
}

bool is_cyclic_helper(int32_t node, bool is_stable, vector<int8_t>& state, vector<vector<int32_t>>& adj_t, vector<edge>& neighbours) {
    int32_t state_i  = node * 2 + (is_stable ? 0 : 1);

    state[state_i] = 1;

    get_neighbours(node, is_stable, adj_t, neighbours);

    for (edge& e : neighbours) {
        int32_t next_state_i = e.dst * 2 + (e.dst_stable ? 0 : 1);
        if (state[next_state_i] == 1) {
            return true;
        }
        if (state[next_state_i] == 0 && is_cyclic_helper(e.dst, e.dst_stable, state, adj_t, neighbours)) {
            return true;
        }
    }
    state[state_i] = 2;
    return false;
}

bool is_cyclic(vector<vector<int32_t>>& adj, int32_t vertices_qty) {
    vector<int8_t> state(vertices_qty * 2);
    vector<edge> neighbours;

    for (int32_t i = 0; i < vertices_qty; i++) {
        if (state[i * 2] == 0 &&
            is_cyclic_helper(i, true, state, adj, neighbours)) {
            return true;
            }
        if (state[i * 2 + 1] == 0 &&
            is_cyclic_helper(i, false, state, adj, neighbours)) {
            return true;
            }
    }
    return false;
}

possible_path stable_path(int32_t start, vector<vector<int32_t>>& adj, int32_t vertices_qty) {
    queue<pair<int32_t, bool>> q;
    vector<int32_t> parent(vertices_qty * 2);
    vector<int32_t> dist(vertices_qty * 2);
    vector<edge> neighbours;

    for (int32_t i = 0; i < vertices_qty * 2; i++) {
        parent[i] = -1;
        dist[i] = -1;
    }

    q.push({start, true});
    dist[start * 2] = 0;

    while (!q.empty()) {
        auto [node, is_stable] = q.front();
        q.pop();
        int32_t state_i = node * 2 + (is_stable ? 0 : 1);

        get_neighbours(node, is_stable, adj, neighbours);

        for (edge& e : neighbours) {
            int32_t next_state_i = e.dst * 2 + (e.dst_stable ? 0 : 1);
            if (dist[next_state_i] == -1) {
                dist[next_state_i] = dist[state_i] + 1;
                parent[next_state_i] = state_i;
                q.push({e.dst, e.dst_stable});
            }
        }
    }

    int32_t last_stable = -1;
    for (int32_t i = 0; i < vertices_qty; i++) {
        if (adj[i].empty() && dist[i * 2] != -1) {
            if (last_stable == -1 || dist[i * 2] < dist[last_stable]) {
                last_stable = i * 2;
            }
        }
    }

    if (last_stable == -1) {
        return {false, {}};
    }

    vector<int32_t> path;
    int32_t node = last_stable;
    while (node != -1) {
        path.push_back(node / 2);
        node = parent[node];
    }


    return {true, path};
}

int32_t main() {
    std::ios_base::sync_with_stdio(false);
    std::cout.tie(nullptr);
    std::cin.tie(nullptr);

    int32_t t;
    cin >> t;

   for (int32_t i = 0; i < t; i++) {
        int32_t vertices_qty, edges_qty, start;
        cin >> vertices_qty >> edges_qty >> start;

        vector<vector<int32_t>> adj(vertices_qty);

        for (int32_t i = 0; i < edges_qty; i++) {
            int32_t x, y;
            cin >> x >> y;
            add_edge(x, y, adj);
        }

        auto [possible, path] = stable_path(start, adj, vertices_qty);
        if (!possible) {
            if (is_cyclic(adj, vertices_qty)) {
                cout << "PETLA\n";
            } else {
                cout << "NIE\n";
            };
        } else {
            cout << "TAK\n";
            for (int32_t i = path.size() - 1; i >= 0; i--) {
                cout << path[i] << " ";
            }
            cout << "\n";
        }
    }

    return 0;
}