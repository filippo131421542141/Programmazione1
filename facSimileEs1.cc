#include <iostream>
#include <fstream>
#include <cstring>

using namespace std;

int main(int nArg,char * arg[]){
     if (nArg != 3)
    {
        cout << "Usage: ./a.out <fileInput> <fileOutput> \n";
        exit(1);
    }
    fstream in,out;
    in.open(arg[1],ios::in);
    out.open(arg[2],ios::out);

    if (in.fail() || out.fail())
    {
        cout << "Errore nell' apertura dei file \n";
        exit(2);
    }
    
    char str[256];
    while (in>> str)
    {
        
    }
    
    in.close();
    out.close();
}