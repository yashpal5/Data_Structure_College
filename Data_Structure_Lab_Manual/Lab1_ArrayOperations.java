import java.util.Scanner;

public class Lab1_ArrayOperations {

    static int[] arr = new int[100];
    static int n = 0;

    static void insert(int pos, int val) {
        if (pos < 0 || pos > n) {
            System.out.println("Invalid Position!");
            return;
        }
        for (int i = n; i > pos; i--)
            arr[i] = arr[i - 1];
        arr[pos] = val;
        n++;
        System.out.println("Inserted Successfully.");
    }

    static void delete(int pos) {
        if (pos < 0 || pos >= n) {
            System.out.println("Invalid Position!");
            return;
        }
        for (int i = pos; i < n - 1; i++)
            arr[i] = arr[i + 1];
        n--;
        System.out.println("Deleted Successfully.");
    }

    static void append(int val) {
        arr[n++] = val;
        System.out.println("Appended Successfully.");
    }

    static void display() {
        System.out.print("Array: ");
        for (int i = 0; i < n; i++)
            System.out.print(arr[i] + " ");
        System.out.println();
    }
    @SuppressWarnings("resource")
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        System.out.print("Enter initial size: ");
        n = sc.nextInt();
        System.out.println("Enter " + n + " elements:");

        for (int i = 0; i < n; i++)
            arr[i] = sc.nextInt();

        while (true) {
            System.out.println("\n1.Insert 2.Delete 3.Append 4.Display 5.Exit");
            int ch = sc.nextInt();

            switch (ch) {
                case 1:
                    System.out.print("Position & Value: ");
                    insert(sc.nextInt(), sc.nextInt());
                    break;
                case 2:
                    System.out.print("Position: ");
                    delete(sc.nextInt());
                    break;
                case 3:
                    System.out.print("Value: ");
                    append(sc.nextInt());
                    break;
                case 4:
                    display();
                    break;
                case 5:
                    return;
            }
        }
    }
}
