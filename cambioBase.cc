#include <iostream>
using namespace std;
int dimNumber(int n){
    if (n/10 == 0) 
        return 1; 
    return 10 * dimNumber(n / 10); 
}

int pow(int n,int exp){
    int power=1;
    for (int i = 1; i <= exp; i++)
    {
        power*=n;
    }
return power;
}

int formBaseNto10(char str[], int baseParetenza){
    int temp=0;
    int dim=0;
    while (str[dim]!='\0')
    {
        dim++;
    }

    for (int i = dim-1; i>=0; i--)
    {
        if (str[i]>='0' && str[i]<='9')
        {
            temp+= (str[i]-'0')*pow(baseParetenza,(dim-1)-i);

        }else if (str[i]>='a' && str[i]<='z')
        {
            temp += ( str[i]-'a'+10 )* pow(baseParetenza,(dim-1)-i);
        }
    }
    return temp;
}

int fromDecimaltoNmin10(int n, int base){
    int temp=0;
    int potenza=1; 
    int t=n;
    while (n!=0)
    {
        temp+=(n%base)*potenza;
        n/=base; 
        potenza *=10;
    }
    return temp;
}

char * fromDecimaltoNsup10(int n, int base){
    int temp=0;
    int potenza=1;

    int dimensione=0;
    int t=n;
    while (t>0)
    {
        t/=10;
        dimensione++;
    }
    int dim=dimensione;
    char  *num= new char[dimensione];
    for (int i = 0; i < dimensione; i++)
    {
        num[i]='@';
    }
    
    while (n!=0)
    {
        int corrente  = n % base;
        temp+=(n%base)*potenza;
        n/=base;
        
        if (corrente >=0 && corrente <=9)
        {
            num[dimensione-1]=-'0'+corrente;
        }else if (corrente >9 && corrente <=36)
        {
            num[dimensione-1] = 'a'+corrente-10;
        
        }
        dimensione--;
        potenza *=10;
    }
    char * numOrdinato=new char[dim];
    int j=0;
    for (int i = 0; i < dim; i++)
    {
        
        if (num[i]!='@')
        {
            numOrdinato[j]=num[i];
            j++;
        }
        
    }
    numOrdinato[j]='\0';
    
    delete[] num;
    return numOrdinato;

}

int main(){
    int n;
    cout << "Inserisci il numero" << endl;
    cin >> n;
    const int len=10;
    char * esadecimale=fromDecimaltoNsup10(n,16,len);
    
    fromDecimaltoNsup10(n,16,len);
    cout << "Il numero in base 16: " << esadecimale<< endl;
    cout << "Il numero in base 8: "<< fromDecimaltoNmin10(n,8)<< endl ;
    cout << "Il numero in base 2: "<< fromDecimaltoNmin10(n,2)<<endl;


    // char str[256];
    // cout << "Inserisci il numero esadecimale" << endl;
    // cin >> str;

    // cout << formBaseNto10(str,16)<< endl;

}
