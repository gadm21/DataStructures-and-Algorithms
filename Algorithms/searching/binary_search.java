public static int binary_search(int[] array, int k){
    int first= 0;
    int last= array.size()-1;

    while(first<= last){
        int middle= first+ (last- first)/2;

        if(array[middle]< k) first= middle+1;
        else if(array[middle]> k) last= middle- 1;
        else return middle;
    }

    return -1;
}