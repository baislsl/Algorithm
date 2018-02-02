package collection;


import java.util.*;

/**
 * Definition for a point.
 * class Point {
 * int x;
 * int y;
 * Point() { x = 0; y = 0; }
 * Point(int a, int b) { x = a; y = b; }
 * }
 */

class Point {
    int x, y;

    Point() {
        x = 0;
        y = 0;
    }

    Point(int x, int y) {
        this.x = x;
        this.y = y;
    }
}


class Solution {
    class Node {
        // Ax + By + C = 0
        // gcd(A, B, C) = 1
        // A >= 0
        //    ||  A == 0, B >= 0
        int A, B, C;
        Point p1, p2;

        Node(Point p1, Point p2) {
            this.p1 = this.p2;
            if (p1.x == p2.x) {
                A = 1;
                B = 0;
                C = -p1.x;
            } else {
                A = p1.y - p2.y;
                B = -(p1.x - p2.x);
                C = -A * p1.x - B * p1.y;
            }
            adjust();
        }

        private void adjust() {
            if (A == 0) {
                if (B < 0) {
                    B = -B;
                    C = -C;
                }
            } else if (A < 0) {
                A = -A;
                B = -B;
                C = -C;
            }
            int g = gcd(A, gcd(B, C));
            if (g != 0) {
                A /= g;
                B /= g;
                C /= g;
            }
        }

        private int gcd(int a, int b) {
            if (b == 0) return a;
            else return gcd(b, a % b);
        }

        @Override
        public int hashCode() {
            return A * B + C;
        }

        @Override
        public boolean equals(Object obj) {
            if (!(obj instanceof Node)) return false;
            Node node = (Node) obj;
            return node.A == this.A && node.B == this.B && node.C == this.C;
        }
    }

    private int inValue(int i) {
        return i * (i - 1) / 2;
    }

    public int maxPoints(Point[] points) {

        int[] pow = new int[points.length];
        for (int i = 0; i < pow.length; i++) {
            pow[i] = 0;
            for (int j = 0; j < points.length; j++) {
                if (points[i].x == points[j].x && points[i].y == points[j].y)
                    pow[i]++;
            }
        }

        ArrayList<Point> pointList = new ArrayList<>();
        ArrayList<Integer> powList = new ArrayList<>();
        for (int i = 0; i < points.length; i++) {
            boolean con = true;
            for (int j = 0; j < i; j++) {
                if (points[i].x == points[j].x && points[i].y == points[j].y)
                    con = false;
            }
            if (con) {
                pointList.add(points[i]);
                powList.add(pow[i]);
            }
        }
        if (pointList.size() <= 2) return points.length;
        Map<Node, Integer> map = new HashMap<>();
        for (int i = 0; i < pointList.size(); i++) {
            for (int j = i + 1; j < pointList.size(); j++) {
                Node node = new Node(pointList.get(i), pointList.get(j));
                int inc = powList.get(i) * powList.get(j);
                if (map.containsKey(node)) {
                    map.put(node, map.get(node) + inc);
                } else {
                    map.put(node, inc);
                }
            }

            Set<Node> nodeSet = new HashSet<>();
            int inl = inValue(powList.get(i));
            for (int j = 0; j < pointList.size(); j++) {
                if(j == i) continue;
                Node node = new Node(pointList.get(i), pointList.get(j));
                if(nodeSet.contains(node)) continue;
                map.put(node, map.get(node) + inl);
                nodeSet.add(node);
            }
        }

        int max = 0;
        for (Map.Entry<Node, Integer> e : map.entrySet()) {
            max = Math.max(max, e.getValue());
        }

        return 1 + (int) Math.sqrt(max * 2);
    }
}

public class _149MaxPointsonaLine {
}
