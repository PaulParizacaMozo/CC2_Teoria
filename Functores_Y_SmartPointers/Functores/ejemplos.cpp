#include <iostream>
using namespace std;

class FunctorSinParSinRet { //Functor sin parametros y sin retorno
  public:
    void operator() () { //Sobrecarga del operador()
      cout<<"Hola mundo"<<endl; 
    }
};

class FunctorSinParConRet { //Functor sin parametros y con retorno
  public:
    int operator() () { //Sobrecarga del operador()
      return 10; 
    }
};

class FunctorConParSinRet { //Functor con parametros y sin retorno
  public:
    void operator() (int num1, int num2) { //Sobrecarga del operador()
      cout<<"\n El numero 1 es -> "<<num1; 
      cout<<"\n El numero 2 es -> "<<num2<<endl;
    }
};

class FunctorConParConRet { //Functor con parametros y con retorno
  public:
    int operator() (int num1, int num2) { //Sobrecarga del operador()
      return num1 + num2; 
    }
};

int main(){
  FunctorSinParSinRet f1;
  FunctorSinParConRet f2;
  FunctorConParSinRet f3;
  FunctorConParConRet f4;

  cout<<"Functor sin parametros y sin retorno -> "; f1();
  cout<<"Functor sin parametros y con retorno -> "<<f2()<<endl;
  cout<<"Functor con parametros y sin retorno -> "; f3(4,8);
  cout<<"Functor con parametros y con retorno -> "<<f4(8,10)<<endl;

  return 0;
}
