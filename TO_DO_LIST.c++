#include <iostream>
#include <vector>
#include <string>
using namespace std;

struct Task {
    string name;
    bool done;
};

void show(vector<Task> &list) {
    if(list.empty()) { cout<<"No tasks\n"; return; }
    for(int i=0;i<list.size();i++) {
        cout<<i+1<<". "<<list[i].name<<" ["<<(list[i].done?"Done":"Pending")<<"]\n";
    }
}

int main() {
    vector<Task> list;
    int opt;
    do {
        cout<<"\n1.Add  2.View  3.Remove  4.Mark as done  5.Clear  6.Exit\n";
        cout<<"Choose: "; 
        cin>>opt; cin.ignore();

        if(opt==1) {
            string t;
            cout<<"Enter task: ";
            getline(cin,t);
            list.push_back({t,false});
        }
        else if(opt==2) show(list);
        else if(opt==3) {
            int n; cout<<"Task no: "; cin>>n;
            if(n>=1 && n<=list.size()) list.erase(list.begin()+n-1);
            else cout<<"Invalid\n";
        }
        else if(opt==4) {
            int n; cout<<"Task no: "; cin>>n;
            if(n>=1 && n<=list.size()) list[n-1].done=true;
            else cout<<"Invalid\n";
        }
        else if(opt==5) list.clear();
    } while(opt!=6);

    return 0;
}
