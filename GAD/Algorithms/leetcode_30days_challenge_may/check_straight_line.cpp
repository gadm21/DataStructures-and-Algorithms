
#include <bits/stdc++.h>
using namespace std;


class Solution{
public:

    bool get_slope(vector<int> coords1, vector<int> coords2, double & slope){
        if(coords2[0]==coords1[0]) return false;
        double sub_y = (coords2[1]-coords1[1]);
        double sub_x = (coords2[0]-coords1[0]);
        double s = sub_y/sub_x;
        //cout<<sub_y<<"  "<<sub_x<<"  "<<s<<endl;
        slope = s;

        return true;
    }
    bool different_slopes(double slope1, double slope2){
        bool diff = abs(slope1-slope2) > 0.001;
        return diff;
    }
    bool checkStraightLine(vector<vector<int> > & coordinates){
        vector<int> coords1 = coordinates[0];
        vector<int> coords2 = coordinates[1];

        double slope = 0;
        bool valid = get_slope(coords1, coords2, slope) ;
        //cout<<valid<<" "<<slope<<endl;
        for(int i=2; i< coordinates.size(); i++){
            double new_slope = 0;
            bool new_valid = get_slope(coordinates[i], coordinates[i-1], new_slope);
            bool corrupt = (valid != new_valid) || different_slopes(slope, new_slope);
            //cout<<new_valid<<"  "<<new_slope<<" "<<corrupt<<endl;
            if (corrupt) return false;
        }
        return true;
    }
};



int main(){
    
    vector<int> c0 = {-4,-3};
    vector<int> c1 = {1,0};
    vector<int> c2 = {3,-1};
    vector<int> c3 = {0,-1};
    vector<int> c4 = {-5,2};
    

    vector< vector<int> > coords = {c0, c1, c2, c3,c4};

    Solution sol; 
    cout<<sol.checkStraightLine(coords);
}