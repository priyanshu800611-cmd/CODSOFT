#include <iostream>
using namespace std;

char b[3][3];

void reset() {
    char k='1';
    for(int i=0;i<3;i++)
        for(int j=0;j<3;j++)
            b[i][j]=k++;
}

void show() {
    cout<<"\n";
    for(int i=0;i<3;i++) {
        for(int j=0;j<3;j++) {
            cout<<b[i][j];
            if(j<2) cout<<" | ";
        }
        cout<<"\n";
        if(i<2) cout<<"--+---+--\n";
    }
    cout<<"\n";
}

bool win(char p) {
    for(int i=0;i<3;i++) {
        if(b[i][0]==p && b[i][1]==p && b[i][2]==p) return true;
        if(b[0][i]==p && b[1][i]==p && b[2][i]==p) return true;
    }
    if(b[0][0]==p && b[1][1]==p && b[2][2]==p) return true;
    if(b[0][2]==p && b[1][1]==p && b[2][0]==p) return true;
    return false;
}

bool draw() {
    for(int i=0;i<3;i++)
        for(int j=0;j<3;j++)
            if(b[i][j]!='X' && b[i][j]!='O') return false;
    return true;
}

bool move(int pos,char p) {
    int r=(pos-1)/3, c=(pos-1)%3;
    if(pos<1||pos>9 || b[r][c]=='X'||b[r][c]=='O') return false;
    b[r][c]=p;
    return true;
}

int main() {
    char p, again;
    do {
        reset();
        p='X';
        bool over=false;
        show();
        while(!over) {
            int m;
            cout<<"Player "<<p<<" enter pos(1-9): ";
            cin>>m;
            if(!move(m,p)) { cout<<"Invalid!\n"; continue; }
            show();
            if(win(p)) { cout<<"Player "<<p<<" wins!\n"; over=true; }
            else if(draw()) { cout<<"Draw!\n"; over=true; }
            else p=(p=='X'?'O':'X');
        }
        cout<<"Play again? (y/n): ";
        cin>>again;
    } while(again=='y'||again=='Y');
    return 0;
}

