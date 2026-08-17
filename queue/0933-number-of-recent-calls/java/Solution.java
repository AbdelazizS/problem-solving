import java.util.ArrayDeque;
import java.util.Queue;

class RecentCounter {
    private final Queue<Integer> recentCalls;

    public RecentCounter() {
        recentCalls = new ArrayDeque<>();
    }

    public int ping(int t) {
        recentCalls.offer(t);

        while (!recentCalls.isEmpty() && recentCalls.peek() < t - 3000) {
            recentCalls.poll();
        }

        return recentCalls.size();
    }
}
