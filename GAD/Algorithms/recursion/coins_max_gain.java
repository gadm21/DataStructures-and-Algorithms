/** 
probelm can be found in "Adnan Aziz, Tsung-Hsien Lee, Amit Prakash-Elements of Programming Interviews in Java.
The Insiders’ Guide-CreateSpace Independent Publishing Platform (2016)" book  - chapter 17 - problem 9
 */

public static int pick_coins(List<Integer> coins){
    return compute_max_revenue_R(coins, 0, coins.size()-1, new int[coins.size()][coins.size()]);
}

private compute_max_revenue_R(List<Integer> coins, int a, int b, int[][] max_revenue){
    if(a>b) return 0; //no coins left

    if(max_revenue[a][b]==0){
        int max_revenue_A= coins.get(a)+
            Math.min(compute_max_revenue_R(coins, a+2, b, max_revenue),
            compute_max_revenue_R(coins, a+1, b-1, max_revenue));
        int max_revenue_B= coins.get(b)+
            Math.min(compute_max_revenue_R(coins, a, b-2, max_revenue),
            compute_max_revenue_R(coins, a+1, b-1, max_revenue));
        
        max_revenue[a][b]= Math.max(max_revenue_A, max_revenue_B);
    }

    return max_revenue[a][b];
}