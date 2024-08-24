#include<iostream>
#include<unordered_map>
#include<map>
using namespace std;

int main(){

    map<string,int> m;
    pair<string,int> s = make_pair("ali",3);
    m.insert(s);

    pair<string,int> p("Laiba",1);
    m.insert(p);

    m["Summaiya"] = 5;

    cout<<m["Laiba"]<<endl;
    cout<<m.at("ali")<<endl;

    // cout<<m.at("Yaar")<<endl;  // not working
    cout<<m["Yaar"]<<endl;
    cout<<m.at("Yaar")<<endl;  // working


    //count use to check key is avaible or not
    cout<<m.count("ali")<<endl;
    cout<<m.count("Iza")<<endl;


    cout<<"Size : "<<m.size()<<endl;
    m.erase("Yaar");
    cout<<"Size : "<<m.size()<<endl;

    //Output of all elements in map Or you said Traversal

    for(auto i:m){
        cout<<i.first<<" : "<<i.second<<endl;
    }

    cout<<endl<<endl;
    map<string,int> :: iterator it = m.begin();
    while(it != m.end()){
        cout<<it->first<<" : "<<it->second<<endl;
        it++;
    }

    m["Laiba"]++;
    cout<<m.at("Laiba")<<endl;
    cout<<m["Laiba"]<<endl;

return 0;
}