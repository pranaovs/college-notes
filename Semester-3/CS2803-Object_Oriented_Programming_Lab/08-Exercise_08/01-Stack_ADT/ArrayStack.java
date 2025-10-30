public class ArrayStack<T> implements Stack<T> {
    private final T[] stack;
    private int top;

    @SuppressWarnings("unchecked")
    public ArrayStack(int capacity) {
        stack = (T[]) new Object[capacity];
        top = -1;
    }

    @Override
    public void push(T item) throws StackOverflowException {
        if (isFull()) {
            throw new StackOverflowException("Stack overflow: cannot push, stack is full");
        }
        stack[++top] = item;
    }

    @Override
    public T pop() throws StackUnderflowException {
        if (isEmpty()) {
            throw new StackUnderflowException("Stack underflow: cannot pop, stack is empty");
        }
        return stack[top--];
    }

    @Override
    public T peek() throws StackUnderflowException {
        if (isEmpty()) {
            throw new StackUnderflowException("Stack is empty: nothing to peek");
        }
        return stack[top];
    }

    @Override
    public boolean isEmpty() {
        return top == -1;
    }

    @Override
    public boolean isFull() {
        return top == stack.length - 1;
    }
}

