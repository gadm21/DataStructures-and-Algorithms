#include <bits/stdc++.h>
using namespace std;

#define PI 3.14159265358979323846  /* pi */
#define RAD2DEG(x) (x*180./PI)
#define DEG2RAD(y) (y*PI/180)

#define find_x(deg) cos(DEG2RAD(deg))
#define find_y(deg) sin(DEG2RAD(deg))


#define deg(x, y) RAD2DEG(acos(x/sqrt(pow(x, 2)+ pow(y, 2))))

//#define cross_p(a, b) ((a.first*b.second)-(a.second*b.first))

float cross_p(pair<int, int> a, pair<int, int> b){
    return ((a.first*b.second)-(a.second*b.first));
}
void print_pair(pair<int, int> a, string s){
    cout<<s<<"  f:"<<a.first<<"  s:"<<a.second<<endl;
}
int main(){
    int t; cin>>t;
    for(int trip= 0; trip<t; trip++){

        int r, s, x, y; cin>>r>>s>>x>>y;

        float degree= deg(x, y);
        if(x<0) degree*=-1;
        float sec_degree= 360/s;

        cout<<"Trip: "<<trip+1<<" "<<degree/sec_degree<<endl;
    }
}


