/** 
probelm can be found in "Adnan Aziz, Tsung-Hsien Lee, Amit Prakash-Elements of Programming Interviews in Java.
The Insiders’ Guide-CreateSpace Independent Publishing Platform (2016)" book  - chapter 12 - problem 2
 */

public static int search_first_occurance(int[] array, int k){
    int first= 0;
    int last= array.size()- 1;
    int index= -1;

    while(first<= last){
        int middle= first+ (last- first)/2;

        if(array[middle]> k) last= middle-1;
        else if(array[middle]< k) first= middle+ 1;
        else{
            index= middle;
            last= middle-1;
        }
    }
    return index;
}