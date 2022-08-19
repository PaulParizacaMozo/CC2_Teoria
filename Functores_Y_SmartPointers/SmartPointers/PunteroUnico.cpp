#include <iostream>
#include <memory>
using namespace std;

class Punto{
  public:
    Punto(double x, double y) : x(x), y(y){};
    void print()    {
        std::cout << "(" << x << ", " << y << ")\n";
    }
  private:
    double x{}, y{};
};

int main(){
  //Ejemplos de punteros inteligentes
  std::unique_ptr<int> num{new int(200)};
  std::unique_ptr<std::string> cad{new std::string("Arbol")};
  std::unique_ptr<Punto> punto{new Punto(4, 9)};

  //200, Arbol
  std::cout << *num << ", " << *cad << "\n";           
  // Dir. Memoria, Dir. Memoria
  std::cout << num.get() << ", " << cad.get() << "\n"; 
  // (4, 9)
  punto->print();                                      

  return 0;
}

// Ejemplos de punteros inteligentes
//std::unique_ptr<int> num = std::make_unique<int>(200);
//std::unique_ptr<std::string> cad = std::make_unique<std::string>("Arbol");
//std::unique_ptr<Punto> punto = std::make_unique<Punto>(4, 9);
//
//std::unique_ptr<int> num1 = std::make_unique<int>(100);
//std::unique_ptr<int> num2 = num1; // Error
