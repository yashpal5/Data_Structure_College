import java.util.Scanner;

class Node {
    int data;
    Node next;
    Node(int d) { data = d; }
}

public class Lab3_LinkedList {

    Node head;

    void insertBeginning(int d) {
        Node n = new Node(d);
        n.next = head;
        head = n;
    }

    void insertEnd(int d) {
        Node n = new Node(d);
        if (head == null) { head = n; return; }
        Node t = head;
        while (t.next != null) t = t.next;
        t.next = n;
    }

    void delete(int val) {
        if (head == null) return;
        if (head.data == val) { head = head.next; return; }

        Node t = head;
        while (t.next != null && t.next.data != val) t = t.next;
        if (t.next != null) t.next = t.next.next;
    }

    void search(int val) {
        Node t = head;
        int pos = 0;
        while (t != null) {
            if (t.data == val) {
                System.out.println("Found at position " + pos);
                return;
            }
            pos++;
            t = t.next;
        }
        System.out.println("Not Found");
    }

    void display() {
        Node t = head;
        while (t != null) {
            System.out.print(t.data + " ");
            t = t.next;
        }
        System.out.println();
    }
    @SuppressWarnings("resource")
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        Lab3_LinkedList list = new Lab3_LinkedList();

        while (true) {
            System.out.println("\n1.Insert Beg 2.Insert End 3.Delete 4.Search 5.Display 6.Exit");
            int ch = sc.nextInt();

            switch (ch) {
                case 1: list.insertBeginning(sc.nextInt()); break;
                case 2: list.insertEnd(sc.nextInt()); break;
                case 3: list.delete(sc.nextInt()); break;
                case 4: list.search(sc.nextInt()); break;
                case 5: list.display(); break;
                case 6: return;
            }
        }
    }
}

