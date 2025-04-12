Question 1:

Correct Option: Option 1: ClassCastException
Question 2:

Correct Option: Option 1: A: 5 Default Constructor
Question 3:

Correct Option: Option 3: 300
Question 4:

Correct Option: Option 3: true false
Question 5:

Correct Option: Option 4: Abstract method should be implemented
Question 6:

Correct Option: Option 2: Hello World
Question 7:

Correct Option: Option 2: 20
Question 8:

Correct Option: Option 2: To encapsulate the client's request information
Question 9:

Correct Option: Option 1: true
Question 10:

Correct Option: Option 1: Prints "Instance Block Constructor" twice
    
//11(i)
import java.util.Scanner;

public class SnackBill {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int p = scanner.nextInt();
        int f = scanner.nextInt();
        int c = scanner.nextInt();
        if (p < 0 || f < 0 || c < 0) {
            System.out.println("Invalid input");
        } else {
            int totalCost = (p * 100) + (f * 20) + (c * 10);
            System.out.println("No of pizzas: " + p);
            System.out.println("No of puffs: " + f);
            System.out.println("No of cooldrinks: " + c);
            System.out.println(totalCost);
        }
        scanner.close();
    }
}
            
//13(i)
import java.util.*;

abstract class VowelPermCounter {
    public abstract int count(String s);
}

class VowelPermImpl extends VowelPermCounter {
    private final Map<Character, List<Character>> map = Map.of(
        'a', List.of('e'),
        'e', List.of('a', 'i'),
        'i', List.of('a', 'e', 'o', 'u'),
        'o', List.of('i', 'u'),
        'u', List.of('a')
    );

    @Override
    public int count(String s) {
        StringBuilder v = new StringBuilder();
        for (char c : s.toCharArray())
            if ("aeiou".indexOf(c) != -1) v.append(c);
        if (v.length() == 0) {
            System.out.println("Invalid input");
            return 0;
        }

        Set<String> perms = new HashSet<>();
        perm(v.toString().toCharArray(), 0, perms);

        int res = 0;
        for (String p : perms)
            if (isValid(p)) res++;
        return res;
    }

    private void perm(char[] a, int i, Set<String> set) {
        if (i == a.length) set.add(new String(a));
        else {
            for (int j = i; j < a.length; j++) {
                swap(a, i, j);
                perm(a, i + 1, set);
                swap(a, i, j);
            }
        }
    }

    private void swap(char[] a, int i, int j) {
        char t = a[i]; a[i] = a[j]; a[j] = t;
    }

    private boolean isValid(String s) {
        for (int i = 0; i < s.length() - 1; i++)
            if (!map.get(s.charAt(i)).contains(s.charAt(i + 1)))
                return false;
        return true;
    }
}

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        VowelPermCounter vpc = new VowelPermImpl();
        int out = vpc.count(sc.nextLine().trim());
        if (out != 0) System.out.println(out);
        sc.close();
    }
}

//16(i)
import java.util.*;

public class Main {
    // Returns true if s1 and s2 are "close"
    public static boolean areClose(String s1, String s2) {
        if (s1.length() != s2.length())
            return false;
        int[] a = new int[26], b = new int[26];
        for (int i = 0; i < s1.length(); i++) {
            a[s1.charAt(i) - 'A']++;
            b[s2.charAt(i) - 'A']++;
        }
        // Ensure both strings use the same set of characters
        for (int i = 0; i < 26; i++) {
            if ((a[i] == 0 && b[i] != 0) || (a[i] != 0 && b[i] == 0))
                return false;
        }
        Arrays.sort(a);
        Arrays.sort(b);
        return Arrays.equals(a, b);
    }
    
    public static void main(String[] args) {
        try {
            Scanner sc = new Scanner(System.in);
            String s1 = sc.nextLine().trim();
            String s2 = sc.nextLine().trim();
            System.out.println(areClose(s1, s2));
            sc.close();
        } catch (Exception e) {
            System.out.println("Error: " + e.getMessage());
        }
    }
}
//17(i)
import java.util.*;

class Car {
    String make, model;
    int year;
    double mileage, price;

    Car(String make, String model, int year, double mileage, double price) {
        if (model.isEmpty() || year <= 1885 || mileage < 0 || price <= 0)
            throw new IllegalArgumentException();
        this.make = make; this.model = model;
        this.year = year; this.mileage = mileage;
        this.price = price;
    }

    double totalCost(int days) {
        return price * days;
    }

    void printDetails() {
        System.out.printf("Make: %s, Model: %s, Year: %d, Mileage: %.2f, Rental Price: %.2f, Total Rental Cost for 5 days: %.2f\n",
                make, model, year, mileage, price, totalCost(5));
    }
}

public class Main {
    public static void main(String[] args) {
        try {
            Scanner sc = new Scanner(System.in);
            int n = Integer.parseInt(sc.nextLine());
            if (n <= 0) throw new Exception();
            for (int i = 0; i < n; i++) {
                String[] p = sc.nextLine().split(" ");
                if (p.length != 5) throw new Exception();
                Car c = new Car(p[0], p[1], Integer.parseInt(p[2]), Double.parseDouble(p[3]), Double.parseDouble(p[4]));
                c.printDetails();
            }
        } catch (Exception e) {
            System.out.println("Invalid input");
        }
    }
}

//17(ii)
    
import java.util.*;

class Cart {
    double total = 0;

    void add(int p) { if (p < 0) throw new IllegalArgumentException(); total += p; }
    void add(float p) { if (p < 0) throw new IllegalArgumentException(); total += p; }
    void add(String p) {
        p = p.replaceAll("\"", "");
        double val = Double.parseDouble(p);
        if (val < 0) throw new IllegalArgumentException();
        total += val;
    }
}

public class Main {
    public static void main(String[] args) {
        try {
            Scanner sc = new Scanner(System.in);
            Cart c = new Cart();
            c.add(Integer.parseInt(sc.nextLine().trim()));
            c.add(Float.parseFloat(sc.nextLine().trim()));
            c.add(sc.nextLine().trim());
            System.out.printf("%.2f", c.total);
        } catch (Exception e) {
            System.out.println("Invalid input");
        }
    }
}
        
//19(i)
import java.util.*;

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        try {
            int m = sc.nextInt(), n = sc.nextInt();
            if (m < 0 || n < 0) {
                System.out.println("Invalid input");
                return;
            }
            int[][] mat = new int[m][n];
            for (int i = 0; i < m; i++)
                for (int j = 0; j < n; j++)
                    mat[i][j] = sc.nextInt();

            int max = 0;
            int[][] dp = new int[m][n];
            for (int i = 0; i < m; i++) {
                for (int j = 0; j < n; j++) {
                    if (mat[i][j] == 1) {
                        if (i == 0 || j == 0)
                            dp[i][j] = 1;
                        else
                            dp[i][j] = Math.min(dp[i - 1][j], Math.min(dp[i][j - 1], dp[i - 1][j - 1])) + 1;
                        max = Math.max(max, dp[i][j]);
                    }
                }
            }
            System.out.println(max);
        } catch(Exception e) {
            System.out.println("Invalid input");
        } finally {
            sc.close();
        }
    }
}

//19(ii)
import java.util.*;

abstract class Product {
    double p;
    Product(double p) {
        if (p <= 0 || p >= 1e6) throw new IllegalArgumentException();
        this.p = p;
    }
    abstract double finalPrice();
}

class Electronics extends Product {
    Electronics(double p) { super(p); }
    double finalPrice() { return p * 0.9 * 1.18; }
}

class Clothing extends Product {
    Clothing(double p) { super(p); }
    double finalPrice() { return p * 0.8 * 1.12; }
}

class Grocery extends Product {
    Grocery(double p) { super(p); }
    double finalPrice() { return p * 0.95 * 1.05; }
}

public class Main {
    public static void main(String[] args) {
        try {
            Scanner s = new Scanner(System.in);
            String c = s.nextLine().trim().toLowerCase();
            double p = s.nextDouble();
            Product prod;
            switch (c) {
                case "electronics": prod = new Electronics(p); break;
                case "clothing": prod = new Clothing(p); break;
                case "grocery": prod = new Grocery(p); break;
                default: System.out.println("Invalid Product Category"); return;
            }
            System.out.printf("%.2f", prod.finalPrice());
        } catch (Exception e) {
            System.out.println("Invalid Input");
        }
    }
}
