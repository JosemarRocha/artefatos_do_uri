#include <iostream>
#include <cmath>
#include <iomanip>

using namespace std;

double areaT(double x, double h){ //formula simples pra tirar a area do triangulo isoceles
    double area;
    area = (x*h)/2;
    return area;
}

int main()
{
    double x, i, d, h, n,areaTotal, areaTI, aux;
    int j=0, k=0;
    double vetI[20]; //tres vetores pra armazenar os valores dos meus triangulos
    double vetD[20];
    double vetH[20];
    std::cout << std::setprecision(2) << std::fixed;

    while(cin >> n && n != -1){ //scan de quantos traingulos eu vou ter
        for(j=0;j<n;j++){
            cin >> i >> d >> h; //scan do triangulo
            vetI[j] = i; //armazenamento dos dados nos vetores
            vetD[j] = d;
            vetH[j] = h;
            x = d - i; //x eh a base do triangulo
            areaTI = areaT(x, h);
            areaTotal += areaTI; //ja soma todas as areas de tudo aqui
        }
        for(j=0;j<n;j++){ //parte da brincadeira top
            for(k=1;k<n;k++)
                if(vetI[j] > vetI[k] && vetD[j] < vetD[k] && vetH[j] < vetH[k]){ //SE o triangulo tiver contido em outro completamente, removo a area dele
                    x = vetD[j] - vetI[j];
                    areaTI = areaT(x, h);
                    areaTotal -= areaTI;
                }else if(vetI[j] > vetD[k] && vetD[j] > vetD[k]){ //SE um triangulo tiver com a parte esquerda contida em outro, tiro essa area da soma
                    aux = vetD[j] - vetI[k];
                    areaTI = areaT(aux, aux);
                    areaTotal -= areaTI;
                    if(vetI[j] < vetI[k] && vetD[j] > vetI[k]){ //SE um triangulo tiver com a parte direita contida em outro, tiro essa area da soma
                        aux = vetD[j] - vetI[k];
                        areaTI = areaT(aux, aux);
                        areaTotal -= areaTI;
                    }
                }else if(vetI[j] < vetI[k] && vetD[j] > vetI[k]){ //SE um triangulo tiver com a parte direita contida em outro, tiro essa area da soma
                    aux = vetD[j] - vetI[k];
                    areaTI = areaT(aux, aux);
                    areaTotal -= areaTI;
                    if(vetI[j] > vetD[k] && vetD[j] > vetD[k]){ //SE um triangulo tiver com a parte esquerda contida em outro, tiro essa area da soma
                        aux = vetD[j] - vetI[k];
                        areaTI = areaT(aux, aux);
                        areaTotal -= areaTI;
                    }
                }
        }
        cout << areaTotal << endl; //Imprime a porra toda, cansei, adeus, que se dane, ta dando errado pros testes mais complicados, os simples funfa
    }
}
