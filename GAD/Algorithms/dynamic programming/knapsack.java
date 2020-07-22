private static class Item{
    public Integer weight, value;
    public Item(Integer w, Integer v){
        this.weight= w;
        this.value= v;
    }
}

public static int optimum_subject_to_capacity(List<Item> items, int capacity){
    //the last cell in the matrix holds the answer
    int[][] DP= new int[items.size()][capacity+1];
    for(int[] item: DP) Array.fill(item, -1);

    return optimum_subject_to_item_and_capacity(items, items.size() -1, capacity, DP);
}

/**returns the optimum value when we're choosing from K items and have a capacity of available_capacity */
private static int optimum_subject_to_item_and_capacity(List<Item> items, int item_index, int available_capacity, int[][] DP){
    if(item_index<0) return 0;

    if(DP[item_index][available_capacity]==-1){
        int without_current_item=
            optimum_subject_to_item_and_capacity(items, item_index-1, available_capacity, DP);
        int with_current_item= 
            available_capacity< items.get(item_index).weight 
            ? 0
            : items.get(item_index).value+ optimum_subject_to_item_and_capacity(items, item_index-1, available_capacity- items.get(item_index).weight, DP);
        
        DP[item_index][available_capacity]= Math.max(without_current_item, with_current_item);
    }
    return DP[item_index][available_capacity];
}