#include <iostream>
#include <fstream>


using namespace std;

typedef struct abit{
    unsigned X:1;
}abit;


void equals(abit *X,abit *Y){
    for(int i=0;i<16;i++)
        X[i].X=Y[i].X;
}

void printbyte(abit *byte,int n){
    for(int i=0;i<n;i++){
        if((i==3)&&(n==16))
            cout<<" ";
        cout<<byte[i].X;
    }
    cout<<endl;
}


void cutchar(char X, abit *s){
    for(int i=7;i>=0;i--){
        s[i].X=X;
        X=X>>1;
    }
}

char tochar(abit *s){
    char result;

    for(int i=0;i<8;i++){
        //result=result|s[i].X;

        result=result<<1;
        if(i==0)
            result=result<<8;

        if(s[i].X==0)
            result=result^0;
        else if(s[i].X==1)
            result=result^1;

        //cout<<(int)result<<"|"<<s[i].X<<" ";
    }

   // cout<<"\n";

    return result;
}



void split(abit *bits2, abit *half1, abit *half2){
    for(int i=0;i<16;i++){
        if(i<8){
            half1[i]=bits2[i];
        } else{
            half2[i-8]=bits2[i];
        }
    }
}

void joinbytes(abit *X,abit *Y,abit *Z){
    for(int i=0;i<16;i++){
        if(i<8){
            Z[i]=X[i];
        }else{
            Z[i]=Y[i-8];
        }
    }
}

void calcG(abit *bytes){
    bytes[3].X=0;
    for(int i=4;i<16;i++){
        bytes[3].X=bytes[i].X^bytes[3].X;
    }

}

void intohaming(abit *in,abit *out){
    for(int i=0;i<4;i++){
        out[i].X=out[i].X^out[i].X;
    }
    out[3].X=0;
    out[4].X=in[0].X; //m8
    out[5].X=in[1].X; //m7
    out[6].X=in[2].X; //m6
    out[7].X=in[3].X; //m5
    out[8].X=in[4].X ^ in[2].X ^ in[1].X ^ in[0].X; //c4
    out[9].X=in[4].X; //m4
    out[10].X=in[5].X; //m3
    out[11].X=in[6].X; //m2
    out[12].X=in[6].X ^ in[5].X ^ in[4].X ^ in[0].X; //c3
    out[13].X= in[7].X; //m1
    out[14].X= in[7].X ^ in[5].X ^ in[4].X ^ in[2].X ^ in[1].X; //c2
    out[15].X= in[7].X ^ in[6].X ^ in[4].X ^ in[3].X ^ in[1].X; //c1
    //out[3].X= out[4].X ^ out[5].X ^ out[6].X ^ out[7].X ^ out[8].X ^ out[9].X ^ out[10].X ^ out[11].X ^ out[12].X^ out[13].X ^ out[14].X ^ out[15].X;
    calcG(out);

}



void MakeHamingfile(string in,string out){
    streampos size;
    abit byte[8];
    byte[0].X=0;
    abit bytes[16];
    bytes[0].X=0;
    char *memblock;
    char *memblockOut;
    ifstream file (in, ios::in|ios::binary|ios::ate);
    ofstream fileout (out);
    if (file.is_open()&&fileout.is_open())
    {
        size = file.tellg();
        memblock = new char [size];
        memblockOut=new char [size*2];
        file.seekg (0, ios::beg);
        file.read (memblock, size);
        cout <<size<<"\n";
        int j=0;
        for(int i=0;i<size;i++){
            cutchar(memblock[i],byte);
            //printbyte(byte,8);
            intohaming(byte,bytes);
            //printbyte(bytes,16);
            abit half1[8];
            abit half2[8];
            split(bytes,half1,half2);
            //printbyte(half1,8);
            memblockOut[j]=tochar(half1);
            j++;
            //printbyte(half2,8);
            memblockOut[j]=tochar(half2);
            j++;
        }
        fileout.write(memblockOut,size*2);
        //cout<<endl;
        //cout.write(memblock,size);
        //cout<<endl;
        //cout.write(memblockOut,size*2);
        //cout<<endl;


        delete[] memblock;
        delete[] memblockOut;
        file.close();
        fileout.close();

    }
    else cout << "Unable to open file";
}

void takebyte(abit *X,abit *Y){
    Y[7]=X[13];
    Y[6]=X[11];
    Y[5]=X[10];
    Y[4]=X[9];
    Y[3]=X[7];
    Y[2]=X[6];
    Y[1]=X[5];
    Y[0]=X[4];
}

char xorC(abit *X, abit *Y){
    abit out[8];
//    out[7].X=0;
    out[3].X=0;
    out[2].X=0;
    out[1].X=0;
    out[0].X=0;
    out[7].X=X[15].X^Y[15].X;
    out[6].X=X[14].X^Y[14].X;
    out[5].X=X[12].X^Y[12].X;
    out[4].X=X[8].X^Y[8].X;

    printbyte(out,8);
    return tochar(out);
}


void MakeBfile(string in,string out){
    streampos size;
    abit bytes1[16];
    bytes1[15].X=0;
    abit bytes2[16];
    bytes2[15].X=0;
    abit byte1[8];
    byte1[7].X=0;
    abit byte2[8];
    byte2[7].X=0;
    char *memblock;
    char *memblockOut;
    ifstream file (in, ios::in|ios::binary|ios::ate);
    ofstream fileout (out);
    if (file.is_open()&&fileout.is_open())
    {
        size = file.tellg();
        memblock = new char [size];
        memblockOut=new char [size/2];
        file.seekg (0, ios::beg);
        file.read (memblock, size);
        cout <<size<<"\n";
        int j=0;
        for(int i=0;i<size;i++){
            cutchar(memblock[i],byte1);
            printbyte(byte1,8);
            i++;
            cutchar(memblock[i],byte2);
            printbyte(byte2,8);
            joinbytes(byte1,byte2,bytes1);
            printbyte(bytes1,16);
            takebyte(bytes1,byte1);
            //printbyte(byte1,8);
            intohaming(byte1,bytes2);
            //printbyte(bytes2,16);
            char X=xorC(bytes1,bytes2);
            //cout<<(int)X<<endl;
            if(X==0){
                memblockOut[j]=tochar(byte1);
            } else{
                cout<<"ERRO ENCONTRADO!!"<<endl;
                printbyte(bytes1,16);
                equals(bytes2,bytes1);
                if(bytes1[16-X].X==0){
                    bytes2[16-X].X=1;
                    calcG(bytes2);
                    printbyte(bytes2,16);
                    if((bytes1[3].X^bytes2[3].X)!=0){
                        cout<<"ERRO NAO CORRIGIDO!!"<<endl;
                    } else {
                        cout<<"ERRO CORRIGIDO"<<endl;
                    }

                }else if(bytes1[16-X].X==1){
                    bytes2[16-X].X=0;
                    calcG(bytes2);
                    printbyte(bytes2,16);
                    if((bytes1[3].X^bytes2[3].X)!=0){
                        cout<<"ERRO NAO CORRIGIDO"<<endl;
                    } else {
                        cout<<"ERRO CORRIGIDO"<<endl;
                    }
                }
                takebyte(bytes2,byte1);
                memblockOut[j]=tochar(byte1);

            }
            j++;
        }
        //cout.write(memblock,size);
        //cout.write(memblockOut,size/2);
        fileout.write(memblockOut,size/2);

        delete[] memblock;
        delete[] memblockOut;
        file.close();
        fileout.close();

    }
    else cout << "Unable to open file"<<endl;
}


int main(int argc, char *argv[]){
    string op=argv[1];
    string entrada=argv[2];
    if(op=="-R"){
        MakeHamingfile(entrada,"out.haming");

    }else if(op=="-W"){
        MakeBfile("out.haming",entrada);
    }
    return 0;
}