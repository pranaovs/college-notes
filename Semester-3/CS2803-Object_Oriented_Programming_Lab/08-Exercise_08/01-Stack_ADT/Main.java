public class Main {
    public static void main(String[] args) {
        Stack<Integer> stack = new ArrayStack<>(5);

        try {
            stack.push(10);
            stack.push(20);
            stack.push(30);
            System.out.println("Top element: " + stack.peek());
            System.out.println("Popped element: " + stack.pop());
            System.out.println("Top element after pop: " + stack.peek());

            // Uncomment to test exception
            // for (int i = 0; i < 6; i++) stack.push(i);

        } catch (StackOverflowException | StackUnderflowException e) {
            System.out.println("Error: " + e.getMessage());
        }
    }
}

