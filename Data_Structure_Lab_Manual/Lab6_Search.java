import java.util.Scanner;

public class Lab6_Search {

    static int linear(int[] arr, int x) {
        for (int i = 0; i < arr.length; i++)
            if (arr[i] == x) return i;
        return -1;
    }

    static int binary(int[] arr, int x) {
        int l = 0, r = arr.length - 1;
        while (l <= r) {
            int mid = (l + r) / 2;
            if (arr[mid] == x) return mid;
            else if (arr[mid] < x) l = mid + 1;
            else r = mid - 1;
        }
        return -1;
    }
    @SuppressWarnings("resource")
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        int n;
        System.out.print("Enter size: ");
        n = sc.nextInt();
        int[] arr = new int[n];

        System.out.println("Enter sorted array:");
        for (int i = 0; i < n; i++) arr[i] = sc.nextInt();

        System.out.print("Find element: ");
        int x = sc.nextInt();

        System.out.println("Linear Search Index: " + linear(arr, x));
        System.out.println("Binary Search Index: " + binary(arr, x));
    }
}

