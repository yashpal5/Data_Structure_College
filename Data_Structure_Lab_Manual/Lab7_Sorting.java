import java.util.Arrays;
import java.util.Scanner;

public class Lab7_Sorting {

    static void bubble(int[] arr) {
        for (int i = 0; i < arr.length - 1; i++)
            for (int j = 0; j < arr.length - i - 1; j++)
                if (arr[j] > arr[j + 1]) {
                    int t = arr[j]; arr[j] = arr[j + 1]; arr[j + 1] = t;
                }
    }

    static void insertion(int[] arr) {
        for (int i = 1; i < arr.length; i++) {
            int key = arr[i], j = i - 1;
            while (j >= 0 && arr[j] > key) { arr[j + 1] = arr[j]; j--; }
            arr[j + 1] = key;
        }
    }

    static void selection(int[] arr) {
        for (int i = 0; i < arr.length - 1; i++) {
            int min = i;
            for (int j = i + 1; j < arr.length; j++)
                if (arr[j] < arr[min]) min = j;

            int t = arr[min]; arr[min] = arr[i]; arr[i] = t;
        }
    }
    @SuppressWarnings("resource")
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        int n;
        System.out.print("Enter n: ");
        n = sc.nextInt();
        int[] arr = new int[n];

        System.out.println("Enter elements:");
        for (int i = 0; i < n; i++) arr[i] = sc.nextInt();

        int[] a1 = arr.clone(), a2 = arr.clone(), a3 = arr.clone();

        bubble(a1);
        insertion(a2);
        selection(a3);

        System.out.println("Bubble: " + Arrays.toString(a1));
        System.out.println("Insertion: " + Arrays.toString(a2));
        System.out.println("Selection: " + Arrays.toString(a3));
    }
}
