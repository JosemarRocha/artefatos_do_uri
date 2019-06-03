#include <iostream>
#include <queue> //sera usado para filas de prioridade
#include <vector> //vetores...é
#include <utility> //sera usado para as tuplas

using namespace std;
typedef pair<int, int> PARES;

int main(){
    int n; //numero de casos
    int t; //tempo de execucao no sistema
    int c; //numero de ciclos do processo
    int i;
    long long int espera, execucao; //long long preservando a questao e pq pode n caber em 32 bits

    priority_queue<PARES, vector<PARES>, greater<PARES> > processos; //tipo, onde guardar os elemntos, comparacao
    priority_queue<PARES, vector<PARES>, greater<PARES> > f;
    PARES p;

    while(cin >> n){ //numero de casos
        espera = execucao = 0;

        for(i=0; i<n; i++){
            cin >> t >> c; //recebendo tempo de execucao e de ciclos
            processos.push(make_pair(t,c)); //criando uma tupla dos dois
        }
        execucao = processos.top().first; //pegando o elemento no topo de processos, pois é meu tempo de execucao

        while(!processos.empty()){
            p = processos.top(); //pega a tupla no topo do vetor de processos
            if(p.first > execucao){ //caso o primeiro valor da tupla for maior q exec
                if(f.top().second <= execucao){ //caso o segundo valor na tupla no topo de f for menor igual a exec
                    espera += execucao - f.top().second;
                }else{
                    execucao = f.top().second;
                }
                execucao += f.top().first;
                f.pop();
            }
            f.push(make_pair(p.second, p.first)); //insere a tupla de p em f
            processos.pop(); //remove a tupla no topo de processos
        }
        while(!f.empty()){ //repete quase o mesmo processo acima até q f esteja completamente vazio
            if(f.top().second <= execucao){
                espera += execucao - f.top().second;
            }else{
                execucao = f.top().second;
            }
            execucao += f.top().first;
            f.pop();
        }
        cout << espera<< endl;
    }
    return 0;
}
