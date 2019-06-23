#include <bits/stdc++.h>
#define MAX 50005
using namespace std;

//Struct de um email
struct Atributos{
	int T1, T2;
	string p1,p2,p3;
};

vector < vector < int > > v; //Matriz de inteiros para armazenar a lista de amigos de cada pessoa
vector < vector < string > > s; //Matriz de strings para armazenar os nomes
vector < struct Atributos > att;    //Vetor da struct Atributos para armazenar os valores limitantes e os atributos
int n;

//função de busca em largura que ajuda a adicionar apartir do enviador o atributo de acordo a lista de amigos de cada um
void bfs(int enviador, struct Atributos E, int tam){
	int visitado[30]; //cria um vetor para armazenar os vértices visitados
	memset(visitado, 0, sizeof visitado);
	queue < int >  q; //cria uma fila para receber os vértices que serão visitados
	q.push(enviador); //pega o parametro enviador, que representa quem originou o spam
	int atual;

	while(!q.empty()){
		atual = q.front(); //representa o inicio da fila
		q.pop(); //libera da fila quem originou o spam
		if (!visitado[atual])
			if (v[atual].size() < E.T1){ //Se a quantidade de amigos dessa pessoa "atual" for menor que o valor limite T1
				s[atual].push_back(E.p1); //adiciona o atributo equivalente ao valor limite P1
			}else if (v[atual].size() < E.T2){ //Se a quantidade de amigos dessa pessoa "atual" for menor que o valor limite T2
				s[atual].push_back(E.p2); //adiciona o atributo equivalente ao valor limite P2
			}else{
				s[atual].push_back(E.p3);  //adiciona o atributo equivalente ao valor limite P3
			}
		visitado[atual] = 1;
		//Enquanto i for menor que o tamanho do vetor de lista de amigos da linha atual
		for (int i = 0; i < v[atual].size(); i++){
			if (!visitado[v[atual][i]]){
				q.push(v[atual][i]); //add o elemento na fila se ainda não foi visitado
			}
		}
	}
	//enquanto i for menor ou igual a n (numero de pessoas no grupo)
	for (int i = 1 ; i <= n ; i++){
		if (s[i].size() < tam + 1) //se o tamanho da lista de nomes for menor que o tam+1
			s[i].push_back(E.p1); //add no fim do vetor o atributo P1
	}
}

int main(){
	int caso = 0, x = 21, aux, a1, a2;
	string p1, p2, p3;

	while(x--){ //enfileira os elementos vazios dos vetores
		v.push_back({});
		s.push_back({});
	}
	//Recebe o valor de n (quantidade de pessoas no grupo)
	while(scanf("%d", &n) && n != 0){
		vector < int > VETOR; //cria o vetor para armazenar quem originou o spam
		for (int i = 1; i <= n; i++){
			while (scanf("%d", &aux) && aux != 0) //recebe a lista de amigos e armazena
				v[i].push_back(aux);
		}
        //Recebe quem deu origem ao spam
		while(scanf("%d", &aux) && aux != 0){
			VETOR.push_back(aux);
			cin >> a1 >> a2 >> p1 >> p2 >> p3;
			//recebe os valores limites e os atributos
			struct Atributos y;
			y.T1 = a1;
			y.T2 = a2;
			y.p1 = p1;
			y.p2 = p2;
			y.p3 = p3;
			//passa os valores para a struct e envia para o vetor de atributos
			att.push_back(y);
		}
        //Recebe o nome das pessoas e adiciona ":" junto ao nome
		for(int i = 1; i <= n; i++){
			cin >> p1;
			p1 = p1+":";
			s[i].push_back(p1); //envia o nome para o vetor de strings
		}

		//de acordo com a quantidade de emails ele executa a bfs para adicionar os atributos aos nomes
		for ( int i = 0 ; i < att.size() ; i++ ){
			bfs(VETOR[i], att[i], i+1);
		}
        //imprime o vetor de strings que após o bfs o nome já possui seus atributos
		for ( int i = 1 ; i <= n; i++ ){
			if ( i != 1 )
				cout << endl;
			for ( int j = 0 ; j < s[i].size() ; j++ ){
				cout << s[i][j] << " ";
			}
		}

		printf("\n");
		//limpa os vetores
		att.clear();
		for ( int i = 0 ; i < 21 ; i++ ){
			v[i].clear();
			s[i].clear();
		}
	}
	return 0;
}
