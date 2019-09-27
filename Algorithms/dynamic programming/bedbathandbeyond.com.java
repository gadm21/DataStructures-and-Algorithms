public static List<String> decompose_into_dictionary_words(String domain, Set<String> dictionary){
    int[] lastLength= new int[domain.length()];

    Arrays.fill(lastLength, -1);
    /**
    when the algorithm finishes, lastLength[i]!= -1* indicates
    domain.substring(0, i+1) has a valid decomposition, and the 
    length of the last string in the decomposition will be 
    lastLength[i]
    */

    for(int i=0; i< domain.length(); i++){
        //If domain.substring(0, i+1) is a valid word,
        //set lastLength[i] to the length of that word.
        if(dictionary.contains(domain.substring(0, i+1)))
            lastLength[i]= i+1;
    

        /**
        if lastLength[i]= -1 look for j<i such that domain.substring(0, j+1)
        has a valid decomposition and domain.substring(j+1, i+1) is a 
        dictionary word. If so, record the length of that word in lastLength[i]
        */
        if(lastLength[i]== -1)
            for(int j=0; j<i; j++)
                if(lastLength[j]!= -1 &&
                dictionary.contains(domain.substring(j+1, i+1)))
                    {lastLength[i]= i-j; break;}
    }
    List<String> decompositions= new ArrayList<>();
    if(lastLength[lastLength- 1]!= -1){
        //domain can be assembled by valid words
        int idx= domain.length()-1;
        while(idx>=0){
            decompositions.add(domain.substring(idx+1- lastLength[idx], idx+1));
            idx-= lastLength[idx];
        }
        collections.reverse(decompositions);
    }
    return decompositions;
}