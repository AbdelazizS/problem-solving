#include <queue>
using namespace std;

class RecentCounter {
private:
    queue<int> recentCalls;

public:
    RecentCounter() = default;

    int ping(int t) {
        recentCalls.push(t);

        while (!recentCalls.empty() && recentCalls.front() < t - 3000) {
            recentCalls.pop();
        }

        return static_cast<int>(recentCalls.size());
    }
};
