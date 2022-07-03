#include <iostream>
#include "Persona.h"
//Descomentar(linea 5) si solo se compilar el archivo programaTotal.cpp
//No descomentar si compilara los archivos programaTotal.cpp y Persona.cpp
//#include "Persona.cpp"
using namespace std;

//Funcion para mostrar el arreglo
template<typename T>
void MostrarArreglo(T* arreglo,int Nelementos,string nombre){
  cout<<nombre<<endl<<"-> "; 
  for (int i=0; i<Nelementos; i++){
    cout<<arreglo[i]<<"   ";
  }
  cout<<endl;
}

template <typename T>
bool ascendente(T x, T y) {
    return x < y;
}
template <typename T>
bool descendente(T x, T y) {
    return x > y;
}

//InsertionSort
template<typename T>
void insertionSort(T* arreglo, int inicio, int Nelementos,bool(*orden)(T,T)){
  for (int i=1; i<Nelementos+1; i++){
    int j=i;
    while (j>0 && orden(arreglo[j],arreglo[j-1])){
      T auxiliar = arreglo[j];
      arreglo[j] = arreglo[j-1];
      arreglo[j-1] = auxiliar;
      j--;
    }
  }
}

//quickSort
template<typename T>
int particion(T *arreglo, int inicio, int final,bool(*orden)(T,T)) {
    T pivote = arreglo[inicio];
    int i = (inicio + 1);
    
    for (int j = i; j <= final; j++) {
        if (orden(arreglo[j],pivote)) {
            swap(arreglo[i], arreglo[j]);
            i++;
        }
    }
    swap(arreglo[inicio], arreglo[i-1]); 
    return (i - 1);
}

template<typename T>
void quickSort(T *arreglo, int inicio, int final,bool(*orden)(T,T)) {
    if (inicio < final) {
        int pi = particion(arreglo, inicio, final,orden);
        quickSort(arreglo, inicio, pi - 1,orden); 
        quickSort(arreglo, pi + 1, final,orden); 
    }
}

//mergeSort
template <typename T>
void Construir(T arreglo[], int inicio, int mitad, int final,bool(*orden)(T,T)){
  int NelementosIzq = mitad - inicio + 1;
  int NelementosDer = final - mitad;
  T *Izq;
  T *Der;
  Izq = new T[NelementosIzq];
  Der = new T[NelementosDer];
  for (int i=0; i<NelementosIzq; i++){
    Izq[i]=arreglo[inicio+i];
  }
  for (int j=0; j<NelementosDer; j++){
    Der[j]=arreglo[mitad+1+j];
  }
  int i=0;
  int j=0;
  int k=inicio;
  while (i<NelementosIzq && j<NelementosDer){
    if(orden(Izq[i],Der[j])){
      arreglo[k]=Izq[i];
      i++;
    }
    else{
      arreglo[k]=Der[j];
      j++;
    }
    k++;
  }
  while (j<NelementosDer){
    arreglo[k]=Der[j];
    j++;
    k++;
  }
  while (i<NelementosIzq){
    arreglo[k]=Izq[i];
    i++;
    k++;
  }
}

template <typename T>
void mergeSort(T arreglo[], int inicio, int final,bool(*orden)(T,T)) {
  if (inicio < final) {
    int mitad = inicio + (final-inicio) / 2;
    mergeSort(arreglo, inicio, mitad,orden);    
    mergeSort(arreglo, mitad + 1, final,orden);  
    Construir(arreglo, inicio, mitad, final,orden);   
  }
}

//Funcion ordenar, que contiene punteros a funciones para la seleccion del tipo de ordenamiento y el algoritmo a usar.
template <typename T>
void ordenar(T* arreglo,int inicio, int final,bool(*orden)(T,T), void(*llamarOrdenamiento)(T*,int,int,bool(*ptr)(T,T))){
  MostrarArreglo(arreglo,final,"Arreglo inicial");//MostrarArreglo
  (*llamarOrdenamiento)(arreglo,inicio,final-1,orden);//Puntero a funcion
  MostrarArreglo(arreglo,final,"Arreglo final");//Mostrar Arreglo
  cout<<endl;
}

//MAIN
int main() {
  const int Nelementos = 6; //Cantidad de elementos del Arreglo.
  //Creamos arreglos de distinto tipo(int,float,char,string).
  int ArrEntero[Nelementos]={5,3,4,2,1,6};
  float ArrFlotante[Nelementos]={2.6,1.3,4.5,3.3,5.2,5.1};
  char ArrCaracter[Nelementos]={'f','c','a','d','h','b'};
  string ArrCadena[Nelementos]={"hola","arbol","de","barrio","larry","casa"};
  //Creamos una arreglo de objetos y llenamos sus atributos.(clase Persona).
  Persona ArrPersona[6];
  ArrPersona[0].setNombre("juan");
  ArrPersona[0].setEdad(30);
  ArrPersona[1].setNombre("pedro");
  ArrPersona[1].setEdad(18);
  ArrPersona[2].setNombre("luis");
  ArrPersona[2].setEdad(32);
  ArrPersona[3].setNombre("jose");
  ArrPersona[3].setEdad(30);
  ArrPersona[4].setNombre("paul");
  ArrPersona[4].setEdad(20);
  ArrPersona[5].setNombre("leo");
  ArrPersona[5].setEdad(23);
  
  //Al llamar a la funcion ordenar indicamos el arreglo,indice inicial, cantidad de elementos, el tipo de ordenamiento y el algoritmo de ordenamiento.
  cout<<"Enteros"<<endl;
  ordenar(ArrEntero,0,Nelementos,ascendente,insertionSort);
  ordenar(ArrEntero,0,Nelementos,descendente,quickSort);
  
  cout<<"Flotantes"<<endl;
  ordenar(ArrFlotante,0,Nelementos,descendente,mergeSort);
  ordenar(ArrFlotante,0,Nelementos,ascendente,insertionSort);
  
  cout<<"Cadenas"<<endl;
  ordenar(ArrCadena,0,Nelementos,descendente,quickSort);
  ordenar(ArrCadena,0,Nelementos,ascendente,insertionSort);
  
  //Para ordenar el arreglo de objeto, en este caso de personas se sobrecargo los operadores(<,>y<<) para que pueda ser usado en la funcion sin ningun problema.
  cout<<"Personas"<<endl;
  ordenar(ArrPersona,0,Nelementos,ascendente,quickSort);
  ordenar(ArrPersona,0,Nelementos,descendente,mergeSort);
  return 0;
}
