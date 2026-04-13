
import java.util.Scanner;

public class Quadratic1 {

    static void quadraticTime() {

        try (Scanner sc = new Scanner(System.in)) {
            System.out.println("Enter a number: ");
            int n = sc.nextInt();

            for (int i = 1; i <= n; i++) {
                for (int j = 1; j <= n; j++) {
                    System.out.println(i + " " + j); // O(n^2)
                }
            }
        }
    }

    public static void main(String[] args) {
        quadraticTime();

    }
}
