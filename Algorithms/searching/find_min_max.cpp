/** 
probelm can be found in "Adnan Aziz, Tsung-Hsien Lee, Amit Prakash-Elements of Programming Interviews in Java.
The Insiders’ Guide-CreateSpace Independent Publishing Platform (2016)" book  - chapter 12 - problem 7
 */

#include <bits/stdc++.h>
using namespace std;

class min_max{
public:
    int min, max;
    min_max(int mi, int ma){min= mi; max= ma;}
};

min_max find_min_max(vector<int> v){
    //since we return an object not a pointer, we don't have the option to check if v is empty 
    //and return some value that indicate so. So we'll only return a min_max with -1 for both value
    //which is a valid answer but that's the best we can do.
    if(v.empty()) return min_max(-1, -1);

    int min= v[0];
    int max= v[0];
    for(int i=1; i<v.size(); i++)
        if(v[i]> max) max= v[i];
        else if(v[i]< min) min= v[i];
    
    return min_max(min, max);
}

int main(){
    vector<int> v= {32,5,4 ,643, 12, 34,  1, -32, 0, 32423, 12};
    min_max m= find_min_max(v);
    cout<<m.min<<"  "<<m.max<<endl;
}