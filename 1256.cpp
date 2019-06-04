#include<bits/stdc++.h>

using namespace std;

int main()
{
    int n;
    cin>>n; //recebe quantidade de casos de teste
    bool x=false;
    while(n--){
        if(x){
            cout<<endl;
        } else
            x=true;
        int a,b;
        cin>>a>>b; //recebe a quantidade de endereço base e quantidade de chaves
        int c[b],i=0;
        for(int j=0;j<b;j++)
            cin>>c[j]; //insere chaves no vetor
        for(i=0;i<a;i++){ //percorre todo o vetor
            cout<<i<<" -> "; //imprime i -> e em seguida imprime valores que possuem mod de i
            for(int j=0;j<b;j++){
                if(c[j]%a==i)
                    cout<<c[j]<<" -> ";
            }
            cout<<"\\\n";
        }
    }
    return 0;
}
