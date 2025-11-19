import java.util.Scanner;

// ---------------- STACK USING ARRAY ----------------
class ArrayStack {
    int[] arr = new int[50];
    int top = -1;

    void push(int x) { arr[++top] = x; }
    int pop() { return (top == -1) ? -1 : arr[top--]; }
    boolean isEmpty() { return top == -1; }
}

// ---------------- STACK USING LINKED LIST ----------------
class SNode {
    int data;
    SNode next;
    SNode(int d) { data = d; }
}

class LinkedStack {
    SNode top;

    void push(int x) {
        SNode n = new SNode(x);
        n.next = top;
        top = n;
    }

    int pop() {
        if (top == null) return -1;
        int val = top.data;
        top = top.next;
        return val;
    }
}

// ---------------- QUEUE USING ARRAY ----------------
class ArrayQueue {
    int[] arr = new int[50];
    int front = 0, rear = -1;

    void enqueue(int x) { arr[++rear] = x; }
    int dequeue() { return (front > rear) ? -1 : arr[front++]; }
}

// ---------------- QUEUE USING LINKED LIST ----------------
class QNode {
    int data;
    QNode next;
    QNode(int d) { data = d; }
}

class LinkedQueue {
    QNode front, rear;

    void enqueue(int x) {
        QNode n = new QNode(x);
        if (rear == null) front = rear = n;
        else { rear.next = n; rear = n; }
    }

    int dequeue() {
        if (front == null) return -1;
        int v = front.data;
        front = front.next;
        if (front == null) rear = null;
        return v;
    }
}


// ------------------ MAIN PROGRAM ------------------
public class Lab4_StackQueue {
    @SuppressWarnings("resource")
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        ArrayStack as = new ArrayStack();
        LinkedStack ls = new LinkedStack();
        ArrayQueue aq = new ArrayQueue();
        LinkedQueue lq = new LinkedQueue();

        while (true) {
            System.out.println("\n1.Stack Array Push\n2.Stack Array Pop\n3.Stack LL Push\n4.Stack LL Pop");
            System.out.println("5.Queue Array Enq\n6.Queue Array Deq\n7.Queue LL Enq\n8.Queue LL Deq\n9.Exit");

            int ch = sc.nextInt();
            int val;

            switch (ch) {
                case 1: as.push(sc.nextInt()); break;
                case 2: System.out.println("Popped: " + as.pop()); break;
                case 3: ls.push(sc.nextInt()); break;
                case 4: System.out.println("Popped: " + ls.pop()); break;
                case 5: aq.enqueue(sc.nextInt()); break;
                case 6: System.out.println("Dequeued: " + aq.dequeue()); break;
                case 7: lq.enqueue(sc.nextInt()); break;
                case 8: System.out.println("Dequeued: " + lq.dequeue()); break;
                case 9: return;
            }
        }
    }
}
