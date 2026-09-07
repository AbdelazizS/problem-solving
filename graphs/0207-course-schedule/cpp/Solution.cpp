#include <vector>
#include <queue>
using namespace std;

class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> graph(numCourses);
        vector<int> inDegree(numCourses, 0);

        for (auto& pre : prerequisites) {
            int course = pre[0];
            int prereq = pre[1];
            graph[prereq].push_back(course);
            inDegree[course]++;
        }

        queue<int> q;
        for (int i = 0; i < numCourses; i++) {
            if (inDegree[i] == 0) q.push(i);
        }

        int visited = 0;
        while (!q.empty()) {
            int course = q.front();
            q.pop();
            visited++;

            for (int next : graph[course]) {
                inDegree[next]--;
                if (inDegree[next] == 0) q.push(next);
            }
        }

        return visited == numCourses;
    }
};
