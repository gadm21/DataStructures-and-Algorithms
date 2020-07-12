
#include <bits/stdc++.h>
using namespace std; 


template < typename T>
class ArithCoding{
private : 
    vector<T> sequence ; 
    map< T, pair<double, double> > dict ; 
public :
        ArithCoding ( vector<T> seq, map<T, pair<double, double> > dict) : sequence(seq) , dict(dict){}
        pair<double,double> do_it(){
            pair<double, double> current_interval = make_pair(0.,1.);

            for (auto s : sequence ){
                assert ( dict.find(s) != dict.end());

                auto new_interval = dict[s];


                double diff = current_interval.second - current_interval.first ;
                current_interval.second = current_interval.first + (diff * new_interval.second);
                current_interval.first += ( diff * new_interval.first) ;

                //cout<<"after:"<<s<<"  interval is:"<<current_interval.first<<", "<<current_interval.second<<endl;
                
            }
            return current_interval;       
        }

};


void fill_map(map<string, pair<double,double> > & m){
    //m.insert(make_pair("a1", make_pair(0.,0.2)));
    m["a1"] = make_pair(0.,0.2);
    m["a2"] = make_pair(0.2,0.4);
    m["a3"] = make_pair(0.4,0.8);
    m["a4"] = make_pair(0.8,1);
}

int main(){
    map<string, pair<double, double> > m ;
    fill_map(m);
    vector<string> seq = {"a1","a2","a3", "a3", "a4"};

    ArithCoding<string> a(seq, m);
    pair<double, double> answer = a.do_it();
    cout<<"interval:"<<answer.first<<" "<<answer.second<<endl;

    return 0 ;
}