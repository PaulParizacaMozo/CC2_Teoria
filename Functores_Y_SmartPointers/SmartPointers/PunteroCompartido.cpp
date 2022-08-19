#include <iostream>
#include <memory>

int main(){
  // Ejemplos de punteros inteligentes
  std::shared_ptr<int> num1 = std::make_shared<int>(100);
  std::shared_ptr<int> num2 = num1;
  
  // Son el mismo puntero
  std::cout << num1 << ", " << num2 << "\n";
  
  // Cantidad de veces que el puntero está en uso
  std::cout << num1.use_count() << "\n";  // 2
  
  // Liberamos la copia
  num2.reset();
  
  // Cantidad de veces que el puntero está en uso
  std::cout << num1.use_count() << "\n";  // 1
}

//int main(){
//  // De unique a shared se puede
//  //std::unique_ptr<int> num1 = std::make_unique<int>(100);
//  //std::shared_ptr<int> num2 = std::move(num1);
//  //std::cout << num1 << ", " << num2 << "\n"; // 0, 0x1cd3b9912b0
//  
//  // De shared a unique no se puede
//  std::shared_ptr<int> num1 = std::make_shared<int>(100);
//  std::unique_ptr<int> *num2 = std::move(num1);  // Error
//  return 0;
//}

