#include <iostream>
#include <vector>
using namespace std;


struct Q{
    string i;
    char if_char;
    string to_i;
    char to_char;
    char position;//L left,S s,R right
};

int find_command(vector<Q>base,string cond,char find){
    for (int i = 0; i < base.size(); ++i) {
        if(base.at(i).i==cond&&(find==(char)base.at(i).if_char))return i;
        //cout<<base.at(i).i+"-"+cond+"   "+find+"    "+base.at(i).if_char;
    }
    return -1;
}

int move(vector<Q> base, int tek_index, int tek_command) {
    switch (base.at(tek_command).position){
        case 'L': {
            tek_index--;
            break;}
        case 'l': {
            tek_index--;
            break;}
        case 'S':{
            break;
        }
        case '0':{
            break;
        }
        case 's':{
            break;
        }
        case 'R':{
            tek_index++;
            break;
        }
        case 'r':{
            tek_index++;
            break;
        }
        default:{
            cout<<"такой комманды нет,введите этот символ    ";
            cin>>base.at(tek_command).position;
        }
    }
    return tek_index;
}

string myMT(vector<Q>base,string input){
    int tek_index=0,tek_command;
    string tek_condition="0";
    while (tek_condition!="f") {

        if(true){
            tek_command=find_command(base,tek_condition,input[tek_index]);
            if(tek_command==-1){
                cout<<"программа определена неоднозначно,попробуйте еще раз ";
                exit(EXIT_FAILURE);
            }
        }
        //cout<<tek_command<<" com "<<move(base,tek_index,tek_command)<<" mov "<<tek_index<<" cond "<<tek_condition;
        input[tek_index]=base.at(tek_command).to_char;

        tek_index=move(base,tek_index,tek_command);

        tek_condition=base.at(tek_command).to_i;

    }


    cout<<"программа успешно завершилась,результат:"<<endl<<input;
}




