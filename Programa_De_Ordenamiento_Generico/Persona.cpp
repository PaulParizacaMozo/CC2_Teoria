#include "Persona.h"
using namespace std;

void Persona::setNombre(string nombre){
  this->nombre = nombre;
}

string Persona::getNombre(){
  return nombre;
}

void Persona::setEdad(int edad){
  this->edad = edad;
}

int Persona::getEdad(){
  return edad;
}

//Sobreacarga de operadores para la clase Persona.
//Sobrecarga de operadores(<,>) para que puedan ser usados en la funcion ascendente descendente.
bool operator >(const Persona &p1, const Persona &p2){
  return (p1.edad > p2.edad);
}
bool operator <(const Persona &p1, const Persona &p2){
  return (p1.edad < p2.edad);
}

//Se sobrecarga (<<) para que puede ser usados en la funcion MostrarArreglo.
ostream& operator<<(ostream &os, const Persona &p){
  os<<p.nombre<<":"<<p.edad;
  return os;
}
