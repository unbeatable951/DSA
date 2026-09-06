class Solution {
public:

    int networkDelayTime(vector<vector<int>>& times,
                         int n, int k)
    {
        // Adjacency list
        // adj[u] = {v, weight}
        vector<vector<pair<int,int>>> adj(n + 1);

        for(auto edge : times)
        {
            int u = edge[0];
            int v = edge[1];
            int w = edge[2];

            adj[u].push_back({v, w});
        }

        // Distance from k to every node
        vector<int> dist(n + 1, INT_MAX);

        // Min heap
        // {distance, node}
        priority_queue<
            pair<int,int>,
            vector<pair<int,int>>,
            greater<pair<int,int>>
        > pq;

        // Starting node
        dist[k] = 0;
        pq.push({0, k});

        while(!pq.empty())
        {
            auto [d, node] = pq.top();
            pq.pop();

            // Ignore outdated entry
            if(d > dist[node])
                continue;

            // Explore neighbors
            for(auto [neigh, weight] : adj[node])
            {
                int newDist = d + weight;

                if(newDist < dist[neigh])
                {
                    dist[neigh] = newDist;

                    pq.push({newDist, neigh});
                }
            }
        }

        // Find maximum shortest distance
        int answer = 0;

        for(int i = 1; i <= n; i++)
        {
            if(dist[i] == INT_MAX)
                return -1;

            answer = max(answer, dist[i]);
        }

        return answer;
    }
};