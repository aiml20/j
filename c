//11(i)
import java.util.*;

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int p = sc.nextInt(), f = sc.nextInt(), c = sc.nextInt();
        if (p < 0 || f < 0 || c < 0)
            System.out.println("Invalid input");
        else {
            int total = p * 100 + f * 20 + c * 10;
            System.out.println("No of pizzas: " + p);
            System.out.println("No of puffs: " + f);
            System.out.println("No of cooldrinks: " + c);
            System.out.println(total);
        }
    }
}
            
//13(i)
import java.util.*;
abstract class VowelPerm {
    abstract boolean isValid(String s);
}
public class Main extends VowelPerm {
    public boolean isValid(String s) {
        String v = s.replaceAll("[^aeiou]", "");
        if (v.isEmpty()) return false;
        for (int i = 0; i < v.length() - 1; i++) {
            char a = v.charAt(i), b = v.charAt(i + 1);
            if (a == 'a' && b != 'e') return false;
            if (a == 'e' && b != 'a' && b != 'i') return false;
            if (a == 'i' && b == 'i') return false;
            if (a == 'o' && b != 'i' && b != 'u') return false;
            if (a == 'u' && b != 'a') return false;
        }
        return true;
    }
    public static void main(String[] args) {
        String s = new Scanner(System.in).nextLine();
        Main obj = new Main();
        System.out.println(obj.isValid(s) ? 1 : "Invalid input");
    }
}
