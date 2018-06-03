
import java.util.*;

class Recursion {
    
    static int minArrayIndex(int[] A, int p, int r){
        if(p == r){
            return r;
        }else {
            int m = (p+r)/2;
            int a = minArrayIndex(A, p, m);
            int b = minArrayIndex(A, m+1, r);
            if(Math.min(A[a],A[b]) == A[a]) return a;
            else return b;
        }
    }

    static int maxArrayIndex( int[] A, int p, int r){
        if(p == r){
            return r;
        }else {
            int m = (p+r)/2;
            int a = maxArrayIndex(A, p, m);
            int b = maxArrayIndex(A, m+1, r);
            if(Math.max(A[a],A[b]) == A[a]) return a;
            else return b;
        }
    }

    static void reverseArray1(int[] A, int p, int[] B){
        if(p == 0){
            return;
        }else{
            B[p-1] = A[A.length-p];
            reverseArray1(A, p-1, B);
        }
    }

    static void reverseArray2(int[] A, int p, int[] C){
        if(p == 0){
            return;
        }else{
            reverseArray2(A, p-1, C);
            C[p-1] = A[A.length-p];
        }
    }

    static void reverseArray3(int[] A, int x, int y){
        if(x == y){
            return;
        }else{
            int temp = A[x];
            A[x] = A[y];
            A[y] = temp;
            reverseArray3(A, x+1, y-1);
        }
    }

    public static void main(String[] args) {

        int[] A = { -1, 2, 6, 12, 9, 2, -5, -2, 8, 5, 7 };
        int[] B = new int[A.length];
        int[] C = new int[A.length];
        int minIndex = minArrayIndex(A, 0, A.length - 1);
        int maxIndex = maxArrayIndex(A, 0, A.length - 1);

        for (int x : A)
            System.out.print(x + " ");
        System.out.println();

        System.out.println("minIndex = " + minIndex);
        System.out.println("maxIndex = " + maxIndex);
        
        
        reverseArray1(A, A.length, B);
        for(int x: B) System.out.print(x+" ");
        System.out.println();
        
        reverseArray2(A, A.length, C);
        for(int x: C) System.out.print(x+" ");
        System.out.println();

        reverseArray3(A, 0, A.length-1);
        for(int x: A) System.out.print(x+" ");
        System.out.println();

    }
}