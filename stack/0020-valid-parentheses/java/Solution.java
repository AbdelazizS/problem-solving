import java.util.ArrayDeque;
import java.util.Deque;

class Solution {
    public boolean isValid(String s) {
        Deque<Character> stack = new ArrayDeque<>();

        for (char c : s.toCharArray()) {
            if (c == '(' || c == '{' || c == '[') {
                stack.push(c);
            } else {
                if (stack.isEmpty()) return false;

                char top = stack.pop();
                boolean matches = (c == ')' && top == '(') ||
                                   (c == '}' && top == '{') ||
                                   (c == ']' && top == '[');
                if (!matches) return false;
            }
        }

        return stack.isEmpty();
    }
}
