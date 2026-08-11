class Solution {
public:
    vector<vector<int>> graph;
    vector<int> res;
    unordered_set<int> visited;
    unordered_set<int> path; // path will keep track on current path

    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        // create graph
        graph = vector<vector<int>>(numCourses);
        for (const auto& p : prerequisites) {
            graph[p[0]].push_back(p[1]); // p[1] should live after p[0]
        }

        for (int i = 0; i < numCourses; ++i)
            if(!dfs(i)) return {};

        return res;
    }
private:
    bool dfs(int course) {
        if (visited.count(course)) {
            return true; // skip if visited
        }

        if (path.count(course)) {
            res = {};
            return false; // return false if cyclical path
        } else path.insert(course);

        // loop over all it's neighbors before inserting itself
        // and stop when encounter cyclical path
        for (const int& neighbor : graph[course])
            if (!dfs(neighbor)) return false;

        res.push_back(course);
        visited.insert(course);
        path.erase(course);

        return true;
    }
};
