#include <iostream>
#include <vector>
#include "prog.h"
#define N 9
using namespace std;

vector <Q> fillprog(){
    vector<Q> qbuff;Q buff;

    cout<<"fill i if_char to_i tochar position\n";
    int k=1;
    while(k!=0){
        cin>>buff.i>>buff.if_char>>buff.to_i>>buff.tochar>>buff.position;
        qbuff.push_back(buff);
        cout<<"add new one? 0 no";
        cin>>k;
    }
    return qbuff;
}

void show(vector<Q> test){
    for (int var = 0; var < test.size(); ++var) {
        cout<<"Q"<<test[var].i<<" "<<test[var].if_char<<"-> Q"<<test[var].to_i;
        cout<<" "<<test[var].tochar<<" ,"<<test[var].position<<"\n";
    }
}

string fillinput(){
    cout<<"fill intput\n";
    string ci;
    cin>>ci;
    string begin="*";
    string end="______________";
    string ret=begin+ci+end;
    cout<<"intput="<<ret;
    return ret;
}

string check(string input,vector<Q>buff,char alpabet[N]){

    bool is_correct= false;
    while(!is_correct) {
        for (int i = 0; i < input.length(); ++i) {
            is_correct = false;
            for (int j = 0; j < N; ++j) {
                if (input[i] == alpabet[j]) {
                    is_correct = true;
                }
            }
            if (!is_correct) {
                cout << "вы ввели входное слово неверно,сделайте еще раз\n";
                cin >> input;
            }

        }
    }




}

int main()
{
    string input,output;
    char alpabet[N]={'a','b','c','#','_','*','l','r','s'};
    vector<Q> program;


    program=fillprog();
    show(program);
    input=fillinput();
    input=check(input,program,alpabet);
    //output=myMT(program,input);


    return 0;
}
