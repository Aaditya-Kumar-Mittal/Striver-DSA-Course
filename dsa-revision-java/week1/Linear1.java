
public class Linear1 {

    static void linearTime() {
        int array[] = {1, 2, 3, 4, 5, 6, 7, 8, 9};

        // Timne grows proportionally as the size of the input grows
        
        for (int i = 0; i < array.length; i++) {
            System.out.print(i + 1 + " time" + " ----> "); // O(n)
            System.out.println(array[i]); // O(n)
        }
    }

    public static void main(String[] args) {
        linearTime();
    }
}
