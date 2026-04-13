
import java.util.Scanner;

public class ReverseArray {

    public static void reverseArray(int arr[]) {

        int start = 0;
        int end = arr.length - 1;

        while (start <= end) {
            int temp = arr[start];
            arr[start] = arr[end];
            arr[end] = temp;
            start++;
            end--;
        }

    }

    public static void main(String[] args) {

        try (Scanner sc = new Scanner(System.in)) {
            System.out.println("Enter the size of the array : ");
            int n = sc.nextInt();

            int arr[] = new int[n];

            System.out.println("Enter the elements of the array : ");

            for (int i = 0; i < n; i++) {
                arr[i] = sc.nextInt();
            }

            System.out.println("Print the elements of the array (before reversing): ");

            for (int i = 0; i < n; i++) {
                System.out.print(arr[i] + " ");
            }

            System.out.println();

            System.out.println("Print the elements of the array (after reversing): ");

            reverseArray(arr);

            for (int i = 0; i < arr.length; i++) {
                System.out.print(arr[i] + " ");
            }
        }

    }
}
