#include <bits/stdc++.h>
using namespace std;

class job{
    public:
    int id, deadline, profit;
    job(int i, int d, int p){
        id= i;
        deadline= d;
        profit= p;
    }
};

bool sort_jobs(job a, job b){
    return a.deadline < b.deadline;
}

void print_jobs(vector<job> v){
    for (int i=0; i< v.size(); i++) cout<<v[i].deadline<<" "<<v[i].profit<<endl;
    cout<<endl;
}

vector<job> solve(vector<job> v){
    
    int current_time =0;
    vector<job> result;
    for (int i=0; i<v.size(); i++){
        //cout<<"time:"<<current_time<<" deadline:"<<v[i].deadline<<" profit:"<<v[i].profit<<endl;
        job j= v[i];
        if(j.deadline <= current_time){
            //cout<<"if"<<endl;
            int smallest_profit= j.profit, index= -1;
            for (int ii= 0; ii<result.size(); ii++)
                if (result[ii].profit <= smallest_profit){
                    smallest_profit = result[ii].profit;
                    index= ii;
                }
            if (index != -1) result[index]= j;
            //cout<<"index:"<<index<<endl;
        }else{
            //cout<<"else"<<endl;
            current_time++;
            result.push_back(j);
        }
    }
    return result;
}

int summ(vector<job> v){
    int sum=0;
    for (int i=0; i< v.size(); i++) sum+= v[i].profit;
    return sum;
}

int main(){
    int t; cin>>t;
    while(t--){
        vector<job> j;
        int n; cin>>n;
        while(n--){
            int i, d, p; cin>>i>>d>>p;
            j.push_back(job(i, d, p));
        }
        
        sort(j.begin(), j.end(), sort_jobs);
        vector<job> result= solve(j);
        //print_jobs(result);
        int time= result.size();
        int sum= summ(result);
        cout<<time<<" "<<sum<<endl;
    }
}