#include <iostream>
#include <vector>
using namespace std;

class esNegativo{
  public:
    bool operator() (int num) {
      return num < 0;
    }
};

class esPar{
  public:
    bool operator() (int num){
      return num % 2 == 0;
    }
};

template <typename comparacion>
int sumar_si(vector<int>::iterator primer, vector<int>::iterator ultimo, comparacion c){
  int cont = 0;
  for(; primer != ultimo; ++primer){
    if(c(*primer)){
      cont += *primer;
    }
  }
  return cont;
}

int main(){
  vector<int>numeros = {-1,-2,-3,-4,5,6,7,8,9}; //Vector de numeros
  esPar par; //Objeto de Functor
  esNegativo neg; //Objeto de Functor
  
  //Variable entera que almacena el valor de suma de los numeros negativos del vector.
  //Para indicarle que sume los numeros negativos se pasa como ultimo parametro de la
  //funcion sumar_si el objeto neg del functor esNegativo.
  int sumaNegativa = sumar_si(numeros.begin(), numeros.end(), neg);

  //Variable entera que almacena el valor de suma de los numeros pares del vector.
  //Para indicarle que sume los numeros pares se pasa como ultimo parametro de la
  //funcion sumar_si el objeto par del functor esPar.
  int sumaPar = sumar_si(numeros.begin(), numeros.end(), par);
  
  cout<<"Vector -> ";
  for(int n : numeros){
    cout<<n<<" ";
  }

  cout<<"\nSuma de los numeros Negativos -> "<<sumaNegativa<<endl;
  cout<<"Suma de los numeros Pares -> "<<sumaPar<<endl;

  return 0;
}
