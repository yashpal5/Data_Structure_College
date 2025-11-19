import java.util.Scanner;
import java.util.Stack;

public class Lab5_Postfix {

    static int evaluate(String exp) {
        Stack<Integer> st = new Stack<>();

        for (char c : exp.toCharArray()) {
            if (Character.isDigit(c)) st.push(c - '0');
            else {
                int b = st.pop(), a = st.pop();
                switch (c) {
                    case '+': st.push(a + b); break;
                    case '-': st.push(a - b); break;
                    case '*': st.push(a * b); break;
                    case '/': st.push(a / b); break;
                }
            }
        }
        return st.pop();
    }
    @SuppressWarnings("resource")
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        System.out.print("Enter Postfix Expression: ");
        String exp = sc.next();
        System.out.println("Result: " + evaluate(exp));
    }
}
