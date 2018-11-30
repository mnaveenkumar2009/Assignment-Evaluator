#include <bits/stdc++.h>
#define f(i,n) for(i=0;i<n;i++)
#define ll long long
using namespace std;

string str(ll i){
    string s;
    s.push_back('0'+i);
    return s;
}
int main(){
    string s;
    int n,i;
    
    ifstream ans("student/answer.txt");
    int cur=0,precur=-1;
    ofstream writing("student/answer"+str(cur)+".txt");
    while(getline(ans,s)){
        
        if(s[0]>='1'&&s[0]<='9'){
            // cout<<s<<'\n';
            cur=s[0]-'0'-1;
            f(i,s.length()){
                if(!((s[i]>='1'&&s[i]<='9')||s[i]==' '))
                    break;
            }
            while(s[i]==' '){
                i++;
                if(i==s.length())break;
            }
            s=s.substr(i+1,s.length()-1-i);
            // cout<<s<<'\n';
        }
        if(cur!=precur){
            writing.close();
            writing.open("student/answer"+str(cur)+".txt",std::ofstream::out |std::ofstream::trunc);
        }
        precur=cur;
        writing<<s<<'\n';
    }
}