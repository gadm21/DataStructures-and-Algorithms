/** 
probelm can be found in "Adnan Aziz, Tsung-Hsien Lee, Amit Prakash-Elements of Programming Interviews in Java.
The Insiders’ Guide-CreateSpace Independent Publishing Platform (2016)" book  - chapter 17 - problem 8
 */

 public static int min_trianlge_path(List< List< Integer> > Triangle){
     if(Triangle.isEmpty()) return 0;

     List<Integer> prev_row= new ArrayList<>( triangle.get(0));


     for(int i=1; i< Triangle.size()-1; i++){
         List<Integer> curr_row= new ArrayList<>(triangle.get(i));
         curr_row.set(0, prev_row.get(0)+ curr_row.get(0));

         for(int j=1; j< curr_row.size()-1; j++) curr_row.set(j, curr_row.get(j)+ Math.max(prev_row.get(j), prev_row.get(j-1)));

         curr_row.set(curr_row.size()-1, curr_row.get(curr_row.size()-1)+ prev_row.get(prev_row.size()-1));
         prev_row= curr_row;
     }

     return Collections.min(prev_row);
 }