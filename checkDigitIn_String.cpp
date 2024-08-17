#include <iostream>
using namespace std;
int main() {
    string str = "12uy3yppped6";
    
        // int num = stoi(str);
        // std::cout << num << std::endl; // Outputs: 12
    int count = 0;
    string a = "a3li23";
    for(int i=0;i<a.length();i++){
        if(isdigit(a[i])){
            count++;
        }
    }
    cout<<count;
    return 0;
}
