#include <iostream>
#include <vector>
#include <fstream>
#define N 10
#include "prog.h"
using namespace std;
vector<string>variables;
/**
 * заполняет вектор и возвращает его
 * @return
 */
vector <Q> fillprog(){
    vector<Q> qbuff;Q buff;

    cout<<"заполните форму: i if_char to_i to_char position\n";
    int k=1;
    while(k!=0){
        cin>>buff.i>>buff.if_char>>buff.to_i>>buff.to_char>>buff.position;
        qbuff.push_back(buff);
        cout<<"еще одна? 0 нет\n";
        cin>>k;
    }
    return qbuff;
}

/**
 * показывает содержимое вектора
 * @param test
 */
void show(vector<Q> test){
    for (int var = 0; var < test.size(); ++var) {
        cout<<"Q"<<test[var].i<<" "<<test[var].if_char<<"-> Q"<<test[var].to_i;
        cout<<" "<<test[var].to_char<<" ,"<<test[var].position<<"\n";
    }
}

/**
 * заполнение вхоного слова
 * @return
 */
string fillinput(){
    cout<<"введите слово\n";
    string ci;
    cin>>ci;
    string begin="*";
    string end="______________";
    string ret=begin+ci+end;
    cout<<"слово="<<ret;
    return ret;
}

/**
 * проверка слова на корректность
 * @param input
 * @param buff
 * @param alpabet
 * @param variable
 * @return
 */
string check(string input,vector<Q>buff,char alpabet[N],vector <string> *variable ){

    bool is_correct= false;
    while(!is_correct) {
        for (int i = 0; i < input.length(); ++i) {
            is_correct = false;
            for (int j = 0; j < N; ++j) {
                if ((char) input[i] == alpabet[j]) {
                    is_correct = true;
                }
            }
            if (!is_correct) {
                cout << "вы ввели входное слово неверно,сделайте еще раз\n";
                cin >> input;
            }
        }
    }

    for (int i = 0; i < buff.size(); ++i) {
//        if buff[i].
    }

    cout<<"проверка проведена\n";
    return input;
}

/**
 * чтение фаила
 * @param f
 * @param buff
 */
vector <Q> read(){
    vector<Q> buff;
    ifstream fin("input");
    if(fin.fail()){
        cout<<"фаил не найден,идите учитсья\n";
        return buff;
    }
    while(!fin.eof()){
        Q test;
        fin>>test.i>>test.if_char>>test.to_i>>test.to_char>>test.position;
        buff.push_back(test);
    }
    buff.pop_back();
    return buff;
}

/**
 * запись программы,работающей в фаил
 * запись фаила
 * @param f
 * @param buff
 */
void out(vector<Q>buff){
    ofstream fout("output_to_read", ios_base::out | ios_base::trunc);
    for (int var = 0; var < buff.size(); ++var) {
        fout<<"Q"<<buff[var].i<<" "<<buff[var].if_char<<"-> Q"<<buff[var].to_i;
        fout<<" "<<buff[var].to_char<<" ,"<<buff[var].position<<"\n";
    }
    cout<<"фаил для чтения успешно записан\n";fout.close();
    fout.open("output_to_prog", ios_base::out | ios_base::trunc);
    if(fout.fail())cout<<"efwefewfwefb";
    for (int var = 0; var < buff.size(); ++var) {
        fout<<buff[var].i<<" "<<buff[var].if_char<<" "<<buff[var].to_i;
        fout<<" "<<buff[var].to_char<<" "<<buff[var].position<<"\n";
    }
    cout<<"фаил успешно записан\n";
    fout.close();
}

/**
 * диалог с порльзователем
 * @param base
 * @param input
 * @param alpabet
 */
void dialogue(vector<Q> *program,string *input,char alpabet[N],string *output){
    cout<<"выберите одно (a-read&start prog) (b-write&start prog):-  ";
    char a;cin>>a;
    switch (a){
        case 'a':{
            *program=fillprog();
            show(*program);
            *input=fillinput();
            *input=check(*input,*program,alpabet,&variables);
            *output=myMT(*program,*input);
            out(*program);
            break;
        }
        case 'b':{
            *program=read();
            show(*program);
            out(*program);
            break;
        }

    }
};

int main()
{
    string input,output;
    char alpabet[N]={'a','b','c','#','_',' ','*','l','r','s'};
    vector<Q> program;

    dialogue(&program,&input,alpabet,&output);




    return 0;
}
