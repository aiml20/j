mport java.util.*;

public class LexSmallestString {
    static int[] parent;

    static int find(int x) {
        if (parent[x] != x)
            parent[x] = find(parent[x]);
        return parent[x];
    }

    static void union(int x, int y) {
        int px = find(x);
        int py = find(y);
        if (px != py)
            parent[px] = py;
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        String str = sc.nextLine();
        int n = sc.nextInt();
        char[] s = str.toCharArray();
        int len = s.length;

        parent = new int[len];
        for (int i = 0; i < len; i++) parent[i] = i;

        for (int i = 0; i < n; i++) {
            int a = sc.nextInt();
            int b = sc.nextInt();
            union(a, b);
        }

        // Group characters by root parent manually
        for (int i = 0; i < len; i++) {
            for (int j = i + 1; j < len; j++) {
                if (find(i) == find(j) && s[i] > s[j]) {
                    // Swap to make lexicographically smaller
                    char temp = s[i];
                    s[i] = s[j];
                    s[j] = temp;
                }
            }
        }

        System.out.println(new String(s));
    }
}
