#include "main.h"

class Solution {
public:
    class Edge
    {
    public:
        string id_;
        double cost_;
        Edge(string id, double cost) : id_(id), cost_(cost) {}
    };

    map<string, list<Edge>> makeGraph(vector<vector<string>>& equations, vector<double>& values)
    {
        map<string, list<Edge>> graph;
        for (int i = 0; i < equations.size(); ++i)
        {
            string src = equations[i][0];
            string des = equations[i][1];
            graph[src].push_back(Edge(des, values[i]));
            graph[des].push_back(Edge(src, 1.0 / values[i]));
        }
        return graph;
    }

    double solve_eq(string src, string des, map<string, list<Edge>> g, set<string> visited)
    {
        if (!g.count(src) && !g.count(des))
            return -1.0;

        if (src == des)
            return 1.0;


        visited.insert(src);

        for (Edge edge_ : g[src])
        {
            if (!visited.count(edge_.id_))
            {
                double res = solve_eq(edge_.id_, des, g, visited);
                if (res != -1.0)
                {
                    return res * edge_.cost_;
                }
            }

        }

        return -1.0;
    }


    vector<double> calcEquation(vector<vector<string>>& equations, vector<double>& values, vector<vector<string>>& queries) {
        // create a map for all possible outcomes with cost
        map<string, list<Edge>> graph = makeGraph(equations, values);
        vector<double> results;
        set<string> visited;
        for (int i = 0; i < queries.size(); ++i)
        {
            string src = queries[i][0];
            string des = queries[i][1];
            double answer = solve_eq(src, des, graph, visited);
            results.push_back(answer);
        }

        return results;




    }
};