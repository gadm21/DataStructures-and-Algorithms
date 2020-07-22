
#include <bits/stdc++.h>
using namespace std;

class Job{
    public:
    int id, s, e;
    Job(){}
    Job(int ID, int S, int E){
        id= ID;
        s = S;
        e = E;
    }
    void print(){
        cout<<id<< "   "<<s<<" "<<e<<endl;
    }
};

bool sorting_jobs(Job a, Job b){
    return a.s < b.s;
}

void print_jobs(vector<Job> jobs){
    for (int i=0; i<jobs.size(); i++) jobs[i].print();
}

string solve(vector<Job> jobs){
    string result = "" ;
    sort(jobs.begin(), jobs.end(), sorting_jobs);
    
    bool cameron = false;
    bool jamie = false;
    
    Job c_job;
    Job j_job;


    for(int j=0; j<jobs.size(); j++){
        
        if(cameron){
            
            if (c_job.e <= jobs[j].s){
                c_job = jobs[j];
                result += 'C';

            }else{

                if(jamie){

                    if (j_job.e <= jobs[j].s){
                        j_job = jobs[j];
                        result += 'J';

                    }else return "IMPOSSIBLE";
                    
                }else{
                    jamie = true ;
                    j_job = jobs[j];
                    result += 'J';
                }
            }
        }else{
            cameron = true ;
            c_job = jobs[j];
            result += 'C';
        }
    }

    string final_result("", result.length());
    for (int i=0; i<result.length(); i++){
        int index= jobs[i].id;
        final_result[index] = result[i];
    }

    return final_result;
    


    return result;

}

int main(){
    int T; cin>>T;
    for (int t=1 ; t<=T; t++){
        int N; cin>>N;
        vector< Job> jobs;
        for(int n=0; n<N; n++){
            int s, e; cin>>s>>e;
            jobs.push_back(Job(n, s, e));
        }
        string result = solve(jobs);
        cout<<"Case #"<<t<<": "<<result<<endl;
    }
}