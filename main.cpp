//-----Mauricio Hiraaki Ishida-----
//-----G++ nome_do_arquivo.cpp------
//-----./a.out -R nome_do_aquivo_entrada-----
//-----./a.out -W nome_do_arquivo_saida-----
#include <iostream>
#include <fstream>
#include <unistd.h>

using namespace std;

void order66(){
    if(geteuid()!= 0){
        cout<<"YOU DON'T HAVE THE POWERS YET!!"<<endl;
    } else {
        cout<<"EXECUTING ORDER 66!!";
        system("  beep -l 350 -f 392 -D 100 --new -l 350 -f 392 -D 100 --new -l 350 -f 392 -D \\\n"
                   "  100 --new -l 250 -f 311.1 -D 100 --new -l 25 -f 466.2 -D 100 --new -l 350 \\\n"
                   "  -f 392 -D 100 --new -l 250 -f 311.1 -D 100 --new -l 25 -f 466.2 -D 100 --new \\\n"
                   "  -l 700 -f 392 -D 100 --new -l 350 -f 587.32 -D 100 --new -l 350 -f 587.32 -D \\\n"
                   "  100 --new -l 350 -f 587.32 -D 100 --new -l 250 -f 622.26 -D 100 --new -l 25 \\\n"
                   "  -f 466.2 -D 100 --new -l 350 -f 369.99 -D 100 --new -l 250 -f 311.1 -D 100 \\\n"
                   "  --new -l 25 -f 466.2 -D 100 --new -l 700 -f 392 -D 100 --new -l 350 -f 784 \\\n"
                   "  -D 100 --new -l 250 -f 392 -D 100 --new -l 25 -f 392 -D 100 --new -l 350 -f \\\n"
                   "  784 -D 100 --new -l 250 -f 739.98 -D 100 --new -l 25 -f 698.46 -D 100 --new \\\n"
                   "  -l 25 -f 659.26 -D 100 --new -l 25 -f 622.26 -D 100 --new -l 50 -f 659.26 \\\n"
                   "  -D 400 --new -l 25 -f 415.3 -D 200 --new -l 350 -f 554.36 -D 100 --new -l \\\n"
                   "  250 -f 523.25 -D 100 --new -l 25 -f 493.88 -D 100 --new -l 25 -f 466.16 -D \\\n"
                   "  100 --new -l 25 -f 440 -D 100 --new -l 50 -f 466.16 -D 400 --new -l 25 -f \\\n"
                   "  311.13 -D 200 --new -l 350 -f 369.99 -D 100 --new -l 250 -f 311.13 -D 100 \\\n"
                   "  --new -l 25 -f 392 -D 100 --new -l 350 -f 466.16 -D 100 --new -l 250 -f 392 \\\n"
                   "  -D 100 --new -l 25 -f 466.16 -D 100 --new -l 700 -f 587.32 -D 100 --new -l \\\n"
                   "  350 -f 784 -D 100 --new -l 250 -f 392 -D 100 --new -l 25 -f 392 -D 100 --new \\\n"
                   "  -l 350 -f 784 -D 100 --new -l 250 -f 739.98 -D 100 --new -l 25 -f 698.46 -D \\\n"
                   "  100 --new -l 25 -f 659.26 -D 100 --new -l 25 -f 622.26 -D 100 --new -l 50 \\\n"
                   "  -f 659.26 -D 400 --new -l 25 -f 415.3 -D 200 --new -l 350 -f 554.36 -D 100 \\\n"
                   "  --new -l 250 -f 523.25 -D 100 --new -l 25 -f 493.88 -D 100 --new -l 25 -f \\\n"
                   "  466.16 -D 100 --new -l 25 -f 440 -D 100 --new -l 50 -f 466.16 -D 400 --new \\\n"
                   "  -l 25 -f 311.13 -D 200 --new -l 350 -f 392 -D 100 --new -l 250 -f 311.13 -D \\\n"
                   "  100 --new -l 25 -f 466.16 -D 100 --new -l 300 -f 392.00 -D 150 --new -l 250 \\\n"
                   "  -f 311.13 -D 100 --new -l 25 -f 466.16 -D 100 --new -l 700 -f 392");
    }

}





typedef struct abit{
    unsigned X:1;
}abit;

//---Copia de Y->X---
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

//---corta char---
//---shifts a direita---
void cutchar(char X, abit *s){
    for(int i=7;i>=0;i--){
        s[i].X=X;
        X=X>>1;
    }
}

//---converte para "char"---
//---shifts a esquerda---
char tochar(abit *s){
    char result;
    for(int i=0;i<8;i++){
        //result=result|s[i].X;

	//garantir 0 para result

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


//---Separa 1 array de 16bits para 2 de 8 bits---
void split(abit *bits2, abit *half1, abit *half2){
    for(int i=0;i<16;i++){
        if(i<8){
            half1[i]=bits2[i];
        } else{
            half2[i-8]=bits2[i];
        }
    }
}

//---Junta dois bytes em um array de 16bits
void joinbytes(abit *X,abit *Y,abit *Z){
    for(int i=0;i<16;i++){
        if(i<8){
            Z[i]=X[i];
        }else{
            Z[i]=Y[i-8];
        }
    }
}

//---Faz o calculo do bit G---
void calcG(abit *bytes){
    bytes[3].X=0;
    for(int i=4;i<16;i++){
        bytes[3].X=bytes[i].X^bytes[3].X;
    }

}

//---entra array 8bits sai um array 16bits
//---com o hamming feito e o bit G calculado---
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


//---Gera o arquivo out.hamming---
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
    if (file.is_open()&&fileout.is_open()){
		//---cria vetores de memoria com os tamanhos necessarios---
		//pega tamanho do arquivo
        size = file.tellg();
		//vetor com o tamanho do arquivo
        memblock = new char [size];
		//vetor com o dobro do tamanho
        memblockOut=new char [size*2];
        file.seekg (0, ios::beg);
        file.read (memblock, size);
        cout <<size<<"\n";
        int j=0;
		//---Leitura byte a byte---
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

//---retira o byte original da array de 16bits---
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

//---xor do c com c'
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


//---recupera arquivo gerado pelo haming----
//---out.haming gerado pelo MakeHamming---
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
    if (file.is_open()&&fileout.is_open()){
        size = file.tellg();
        memblock = new char [size];
        memblockOut=new char [size/2];
        file.seekg (0, ios::beg);
        file.read (memblock, size);
        cout <<size<<"\n";
        int j=0;
        for(int i=0;i<size;i++){
			//--pega o primeiro byte
            cutchar(memblock[i],byte1);
            printbyte(byte1,8);
            i++;
			//--pega o segundo byte
            cutchar(memblock[i],byte2);
            printbyte(byte2,8);
			//--junta os bytes
            joinbytes(byte1,byte2,bytes1);
            printbyte(bytes1,16);
			//--pega byte original
            takebyte(bytes1,byte1);
            //printbyte(byte1,8);
			//faz hamming com o G, mas é desconsiderado
            intohaming(byte1,bytes2);
            //printbyte(bytes2,16);
			//---xorC gera um X que convertido para int gera o numero requerido
            char X=xorC(bytes1,bytes2);
            //cout<<(int)X<<endl;
			//---se o xor dos cs é 0 então não há erros
            if(X==0){
                memblockOut[j]=tochar(byte1);
            } else{
                cout<<"ERRO ENCONTRADO!!"<<endl;
                printbyte(bytes1,16);
                equals(bytes2,bytes1);
				//---tentativa de recuperação
                if(bytes1[16-X].X==0){
					//--recupera o bit flipado					
                    bytes2[16-X].X=1;
                    calcG(bytes2);
					//calculo do novo G
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

    }else if(op=="Order"){
        if(entrada=="66"){
            order66();
        }

    }

    return 0;
}
