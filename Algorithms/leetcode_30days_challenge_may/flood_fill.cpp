#include <bits/stdc++.h>
using namespace std;


class Solution{
private:
    vector<pair<int, int> > history;
public:

    bool valid(pair<int,int> point, vector<vector<int> > & image){
        return point.first >= 0 && point.second >= 0 && point.first < image.size() && point.second < image[0].size() && find(history.begin(), history.end(), point)!=history.end(); 
    }

    vector<pair<int,int> > get_good_neighbours(vector<vector<int> > & image, pair<int, int> point, int original_color){
        vector< vector<int> > offsets = {{0,1},{1,0},{-1,0},{0,-1}};
        vector<pair<int,int> > new_neighbours;
        for (auto offset : offsets){
            pair<int,int> new_point = make_pair(point.first + offset[0], point.second + offset[1]);
            if (! valid(new_point, image) || image[new_point.first][new_point.second] != original_color) continue ;
            new_neighbours.push_back(new_point);
            history.push_back(new_point);

        }
        return new_neighbours;
    }

    vector< vector<int> > floodFill(vector<vector<int> > & image, int sr, int sc, int newColor){
        int original_color = image[sr][sc];
        vector<pair<int,int> > neighbours;
        neighbours.push_back(make_pair(sr,sc));
        history.push_back(neighbours[0]);
        while(!neighbours.empty()){
            pair<int,int> point = neighbours.back(); 
            neighbours.pop_back();
            image[point.first][point.second] = newColor ;

            vector<pair<int, int> > new_neighbours = get_good_neighbours(image, point, original_color);
            neighbours.insert(neighbours.end(), new_neighbours.begin(), new_neighbours.end());
        }
        return image;
    }
};



void print_image(vector<vector<int> > & image){
    for(int i=0; i<image.size(); i++){
        vector<int> row = image[i];
        for(int j=0; j<row.size(); j++) cout<<row[j]<<" ";
        cout<<endl;
    }
    cout<<endl;
}
void print2(vector<vector<int> > & image){
    for(auto row : image){
        for(auto col : row) cout<<col<<" ";
        cout<<endl;
    }
    cout<<endl;
}



int main(){
    vector<vector<int> > image = {{0,0,0},{0,1,1}};
    int sr=1, sc=1, newColor=1;

    Solution sol;
    vector<vector<int> > image2 = sol.floodFill(image, sr, sc, newColor);

    print2(image2);
}