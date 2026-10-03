import java.util.*;
class Main {
    static Scanner scn = new Scanner(System.in);
    public static void maximumMatchings(String args[]) {
        int n=scn.nextInt();
        int[] arr1=new int[n];
        int[] arr2=new int[n];
        for(int i=0; i<arr1.length; i++) {
            arr1[i]=scn.nextInt();
        }
        for(int i=0; i<arr2.length; i++) {
            arr2[i]=scn.nextInt();
        }
        for(int i = 0;i < n;i++){
            arr2[i] -= arr1[i];
        }
        Arrays.sort(arr2);
        int num = 0;
        int ans = 0;
        for(int i = 0;i < n;i++){
            if(i > 0 && arr2[i] == arr2[i-1]){
                num++;
            }else{
                num = 1;
            }
            ans = Math.max(ans, num);
        }
        System.out.println(ans);
    }
}