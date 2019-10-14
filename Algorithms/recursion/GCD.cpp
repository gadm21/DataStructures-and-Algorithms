/** 
probelm can be found in "Adnan Aziz, Tsung-Hsien Lee, Amit Prakash-Elements of Programming Interviews in Java.
The Insiders’ Guide-CreateSpace Independent Publishing Platform (2016)" book  - chapter 16 
- in the "recursion boot camp " section.
 */

#include <bits/stdc++.h>
using namespace std;

int GCD(int y, int x){ return (y==0 ? x : GCD(x%y, y));}

int main(){
    cout<<GCD(12, 14)<<endl;
}