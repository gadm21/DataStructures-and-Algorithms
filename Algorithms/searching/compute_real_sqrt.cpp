/** 
probelm can be found in "Adnan Aziz, Tsung-Hsien Lee, Amit Prakash-Elements of Programming Interviews in Java.
The Insiders’ Guide-CreateSpace Independent Publishing Platform (2016)" book  - chapter 12 - problem 5
 */

#include <bits/stdc++.h>
using namespace std;

double compute_real_sqrt(double x, double tolerance){

    double first= (x<1.0)? x: 0;
    double last= (x<1.0)? 1: x;
 
 
    while(abs(last- first)> tolerance){
        double mid= first+ (last- first)/2;
        double midsquared= mid*mid;
        //the book solution used diff= (midsquared-x)/x but I doin't know why
        //it says: normalization for precision problems
        double diff= (midsquared-x);  
        if(diff> tolerance) last= mid;
        else if((diff<x && x<1.0) || (diff<0 && x>1.0)) first= mid;
        else return mid;
    }
    return last;
}

int main(){
    cout<<compute_real_sqrt(0.25, 0.00000001);
}