#include <iostream>
#include <memory>

//class Persona{
//  private:
//    std::string nombre{"Sin nombre"};
//    std::shared_ptr<Persona> amigo; // nullptr compartido
//  public:
//    Persona() = default;
//    Persona(std::string nombre) : nombre(nombre){};
//    ~Persona() {
//        std::cout << nombre << " liberado de la memoria\n";
//    }
//    void set_amigo(std::shared_ptr<Persona> p) {
//        this->amigo = p;
//    }
//    void print_amigo() {
//        std::cout << "El amigo de " << nombre << " es "
//                  << amigo->nombre << std::endl;
//    }
//};
//
//int main(){
//    // Dependencia cíclica
//    std::shared_ptr<Persona> Persona1 = std::make_shared<Persona>("Leo");
//    std::shared_ptr<Persona> Persona2 = std::make_shared<Persona>("Messi");
//    
//    Persona1->set_amigo(Persona2);
//    Persona2->set_amigo(Persona1);
//    
//    Persona1->print_amigo();  
//    Persona2->print_amigo();  
//
//    std::cout<<std::endl;
//
//    return 0;
//}

class Persona{
  private:
    std::string nombre{""};
    std::weak_ptr<Persona> amigo; // nullptr débil
  public:
    Persona(std::string nombre) : nombre(nombre){};
    ~Persona(){
        std::cout << nombre << " liberado de la memoria\n";
    }
    void set_amigo(std::shared_ptr<Persona> p){
        // Conversión de shared a weak implícita
        this->amigo = p;
    }
    void print_amigo(){
        // Para utilizar el puntero débil lo bloqueamos
        std::shared_ptr<Persona> p_amigo = amigo.lock();
        std::cout << "El amigo de " << nombre << " es "<< p_amigo->nombre << std::endl;
    }
};

int main(){
    // Dependencia cíclica solucionado con puntero debil
    std::shared_ptr<Persona> Persona1 = std::make_shared<Persona>("Leo");
    std::shared_ptr<Persona> Persona2 = std::make_shared<Persona>("Messi");
    
    Persona1->set_amigo(Persona2);
    Persona2->set_amigo(Persona1);
    
    Persona1->print_amigo();  
    Persona2->print_amigo();  

    std::cout<<std::endl;

    return 0;
}
