#ifndef PERSONA_H
#define PERSONA_H
#include <iostream>

class Persona{
  //Atributos
  private:
    std::string nombre;
    int edad;
  //Metodos
  public:
    void setNombre(std::string);
    std::string getNombre();
    void setEdad(int);
    int getEdad();
  //Sobrecarga de operadores para la clase Persona
    friend bool operator >(const Persona &, const Persona &);
    friend bool operator <(const Persona &, const Persona &);
    friend std::ostream& operator<<(std::ostream &, const Persona &p);
};

#endif
