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
    cout<<"Please enter the question:\n";
    getline(cin,s);
    qn<<s<<"\n";
    cout<<"Please enter the answer:\n";
    ofstream answer("teacher/answer"+str(i+1)+".txt");
    getline(cin,s);
    answer<<s<<"\n";
    cout<<"Please enter the marks for this question:\n";
    getline(cin,s);
    ofstream marks("teacher/marks"+str(i+1)+".txt");
    marks<<s<<"\n";
    
}