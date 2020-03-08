#include <bits/stdc++.h>
using namespace std;

int levenshtien_distance(string a, string b){
    if (a.length() == 0) return b.length();
    if (b.length() == 0) return a.length();

    return a[a.length()-1]==b[b.length()-1] ? 
        levenshtien_distance(a.substr(0, a.length()-1), b.substr(0, b.length()-1))
        :
        min(2+ levenshtien_distance(a.substr(0, a.length()-1), b.substr(0, b.length()-1)),
            min(1+ levenshtien_distance(a, b.substr(0, b.length()-1)),
                1+ levenshtien_distance(a.substr(0, a.length()-1), b)));



}

int main(){
    string a= "string";
    string b= "strfullng";
    cout<<levenshtien_distance(a, b)<<endl;
}