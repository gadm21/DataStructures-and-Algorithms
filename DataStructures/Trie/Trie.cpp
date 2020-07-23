
#include <bits/stdc++.h>
using namespace std;



class Trie{
private:
    int translate(char c){ return (int) c - 97;}
    Trie * found(char c){
        for(auto it : tries)
            if (it.first == c) return it.second;
        return nullptr;
    }

public:
    bool end_of_word = false;
    map<char, Trie *> tries;
    
    Trie() {}
    //~Trie(){  for(int i=0; i<tries.size(); i++) if (tries[i]) delete tries[i];}

    void insert(string word){
        if (word.length() == 1) end_of_word = true;
        if (word.empty()) return;
        char c = word[0];
        word = word.substr(1); 

        Trie *t = found(c);
        if (!t) tries[c] = new Trie();
        
        tries[c]->insert(word); 
    } 

    bool search(string word){
        char c = word[0];
        word = word.substr(1);
        Trie *t = found(c);
        if(! t) return false;
        if(word.empty()) return end_of_word;
        return tries[c]->search(word);
    }   

    bool startsWith(string prefix){
        char c = prefix[0];
        prefix = prefix.substr(1);
        Trie *t = found(c);

        if(!t) return false;
        if(prefix.empty()) return true;
        return tries[c]->startsWith(prefix);
    }
    
};




int main(){
    Trie t;
    t.insert("hello") ;
    t.insert("hellos");
    cout<<t.search("hell")<<endl;
    cout<<t.search("hello")<<endl;
    cout<<t.search("hellos")<<endl;
    cout<<endl;
    cout<<t.startsWith("hell")<<endl;
    cout<<t.startsWith("hello")<<endl;
    cout<<t.startsWith("hellos")<<endl;
    cout<<t.startsWith("e")<<endl;
}
