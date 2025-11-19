import java.util.Scanner;

public class Lab2_TimeSpace {

    static long measureTime(int n) {
        long start = System.nanoTime();
        long sum = 0;
        for (int i = 0; i < n; i++) sum += i;
        long end = System.nanoTime();
        return end - start;
    }
    @SuppressWarnings("resource")
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        System.out.print("Enter n: ");
        int n = sc.nextInt();

        int[] arr = new int[n];

        long time = measureTime(n);
        long space = arr.length * 4;

        System.out.println("Time Taken (ns): " + time);
        System.out.println("Space Taken (bytes): " + space);
    }
}

