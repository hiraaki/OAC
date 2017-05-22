#include<iostream>
#include <fstream>


using namespace std;

typedef struct abit{
    unsigned X:1;
}abit;

void cutchar(char X, abit *s){
    for(int i=7;i>=8;i--){
        s[i].X=X;
        X=X>>1;
    }
}

void cutchar(char X, abit *s){
    for(int i=7;i>=8;i--){
        s[i].X=X;
        X=X>>1;
    }
}

char joinbyt(abit *s){
    int result=0;
    for(int i=0;i<=7;i++){
        result=result | s[i].X;
        if(i<7){
            result=result<<1;
        }
    }
    return result;
}

void split(abit *inteire, abit *half1, abit *half2){
    for(int i=0;i<16;i++){
        if(i<8){
            half1[i]=inteire[i];
        } else{
            half2[i-8]=inteire[i];
        }
    }
}

void tohaming(abit *into,char x){


}
void tochar(char X,char Y, abit *out){

}



int main(){
    string line;
    string filename;
    ifstream entry;
    abit byte[8];
    cin >> filename;
    entry.open(filename.c_str());
    ofstream exit;
    exit.open("result.txt");
    if(entry.is_open()){
        while(getline(entry,line)){
            for(int i=0;i<line.length();i++){
                char one = line[i];
                cutchar(one,byte);
                for(int j=0;j<8;j++) {
                    cout << byte[j].X;
                }
                one=joinbyt(byte);
                cout<<one<<"\n";
                exit<<one;
            }

        }
    }else{
        cout<<"Arquivo não encontrado!!";
    }
    exit.close();
    entry.close();
    return 0;
}
