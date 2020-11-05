/// Universidad de La Laguna
/// Escuela Superior de Ingeniería y Tecnología
/// Grado en Ingeniería Informática
/// Computabilidad y algoritmia
///
/// @author Anabel Díaz Labrador <alu0101206011@ull.edu.es>
/// @date 2 Nov 2020
/// @brief 
/// 
/// @see 
/// 
/// To compile: make 
/// To clean files: make clean

#include <iostream>
#include <fstream>
#include <vector>

#include "set_calculator.h"


void ErrorMessage(const int);
void binary(unsigned int);


int main(int argc, char *argv[]) {
  if (argc != 3 && argc != 2) { ErrorMessage(1); }     
  if ((std::string)argv[1] == "--help" || (std::string)argv[1] == "-h")
    if (argv[2] == NULL) {
      ErrorMessage(2);
    }
  if (argv[2] == NULL) { ErrorMessage(1); }
  if ((std::string)argv[1] != "infile.txt") {
    ErrorMessage(3);
  }

  std::ifstream reader("infile.txt");
  if (!reader) ErrorMessage(4);
  char character;

   while (!reader.eof()) {
    //reader >> string;
    reader >> character;
    switch (character) {
    case '{':
      {
        std::vector<char> hola;
        hola.push_back(character);
        reader >> character;
        while (character != '}') {
          if (character != ',')
            hola.push_back(character);
          reader >> character;
        }
        hola.push_back(character);
        
        for (unsigned i = 0; i < hola.size(); i++) {
          std::cout << hola[i];
        }
        
        std::cout << "\nConjunto finalizado\n";      
        break;
      }
    case '+':
      std::cout << "soy un + \n";
      break;

    case '-':
      std::cout << "soy un - \n";
      break;

    case '!':
      std::cout << "soy un ! \n";
      break;

    case '*':
      std::cout << "soy un * \n";
      break;

    case '=':
      std::cout << "soy un = \n";
      break;

    default:
      break;
    }
  }
 
  Set set1; 
  set1.InsertElement(1); 
  set1.InsertElement(2); 
  set1.Write(); 
  set1.DeleteElement(2); 
  set1.Write(); 
  if (set1.ElementBelongsToSet(1)) { 
    std::cout << "The element '" << 1 << "' belongs to the set.\n";
  } else {
    std::cout << "The element '" << 1 << "' does not belong to the set.\n";
  }
  set1.SetClear();
  if (set1.SetIsEmpty()) {
    std::cout << "Yes está empty\n";
  } else {
    std::cout << "Nope, no está empty\n";
  }
  
  Set set2(240);
  set2 = {1, 80, 90, 32, 129, 127, 128, 239};
  set2.Write();
  if (set2.SetIsEmpty()) {
    std::cout << "Yes está empty\n";
  } else {
    std::cout << "Nope, no está empty\n";
  }
  if (set2.ElementBelongsToSet(32)) {
    std::cout << "The element '" << 32 << "' belongs to the set.\n";
  } else {
    std::cout << "The element '" << 32 << "' does not belong to the set.\n";
  }

  return 0;
}

// Show error messages in terminal
void ErrorMessage(const int kError) {
  if (kError == 1) {
    std::cerr << "Invalid arguments to function.\n" 
              << "Write ./set_calculator --help for more info\n";
    exit(1);
  } else if (kError == 2) {
    std::cerr << "Usage: ./set_calculator infile.txt outfile.txt" 
              << "\nFor OPTION:\n" 
              << "\t-h,--help\t\tShow this help message\n";
    exit(1);
  } else if (kError == 3) {
    std::cerr << "Invalid file names.\n" 
              << "Write ./set_calculator --help for more info\n";
    exit(1);
  } else if (kError == 4) {
    std::cerr << "Error: file could not be opened\n";
    exit(1);
  }
}