#include <iostream>
#include <memory>

int main(){
  std::shared_ptr<int> num1 = std::make_shared<int>(100);
  // Creamos un puntero débil a partir de un puntero compartido
  std::weak_ptr<int> num2 = num1;
  
  // Este puntero no permite acceso ni modificación
  std::cout << num2 << std::endl; // Error
  
  // Necesitamos transformarlo a un shared_ptr bloqueándolo
  std::shared_ptr<int> num3 = num2.lock();
  
  // Podemos comprobar que son una copia
  std::cout << num1 << ", " << num3 << "\n"; // 0x22f5e6c12c0, 0x22f5e6c12c0
  return 0;
}
