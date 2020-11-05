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
#include <vector>

#include "set_calculator.h"


// Default constructor
Set::Set(void): long_size_(sizeof(ulong) * 8), 
limit_elements_size_(long_size_ - 1) {
  set_.push_back(0);
}

// Copy constructor
Set::Set(const ulong kSize): long_size_(sizeof(ulong) * 8), 
limit_elements_size_(kSize) {
  ulong array_size_ = (kSize / long_size_) + 1;
  for (ulong iterator = 0; iterator < array_size_; iterator++) {
    set_.push_back(0);
  }
}

// Default destructor
Set::~Set() {}

std::vector<ulong> Set::get_set(void) const { return set_; }
ulong Set::get_long_size_(void) const { return long_size_; }
ulong Set::get_limit_elements_size_(void) const { 
  return limit_elements_size_; 
}

void Set::set_set(std::vector<ulong> new_set) { set_ = new_set; }
void Set::set_limit_elements_size_(const ulong kNewLimit) { 
  limit_elements_size_ = kNewLimit; 
}

// 
void Set::InsertElement(const ulong element) {
  //std::cout << long_size_ << " " << element << "\n";
  CheckElement(element);
  ulong selectioner = element / long_size_;
  set_[selectioner] |= (ulong)1 << (element % long_size_);
}

// 
void Set::DeleteElement(const ulong element) {
  CheckElement(element);
  ulong selectioner = element / long_size_;
  if (set_[selectioner] & (1 << element)) {
     set_[selectioner] &= ~(1 << (element % long_size_));     
  } else {
    std::cerr << "This element does not exist in the set.\n";
  }                                            
}

// 
void Set::SetClear(void) {
  for (ulong i = 0; i < set_.size(); i++)
    for (ulong j = (i*long_size_); j < (i+1)*long_size_; j++) 
      if (set_[i] & (1 << j)) 
        set_[i] &= ~(1 << (j % long_size_));   
}

//
bool Set::SetIsEmpty(void) {
  for (ulong i = 0; i < set_.size(); i++)
    for (ulong j = (i*long_size_); j < (i+1)*long_size_; j++) 
      if (set_[i] & (1 << j)) 
        return false;
  return true;
}

// 
bool Set::ElementBelongsToSet(ulong element) {
  CheckElement(element);
  for (ulong i = 0; i < set_.size(); i++)
    for (ulong j = (i * long_size_); j < (i + 1) * long_size_; j++) 
      if (set_[i] & ((ulong)1 << j) && j == element) 
        return true;
  return false;
}

// 
Set& Set::operator=(std::initializer_list<ulong> operand_1) { 
  int divisor = 0;
  for (const ulong* prompter = std::begin(operand_1); 
                    prompter != std::end(operand_1); prompter++) {
    CheckElement(*prompter);
    divisor = *prompter / long_size_; 
    set_[divisor] = set_[divisor] | ((ulong)1) << (*prompter % long_size_); 
  }
  return *this; 
}  

//
bool Set::operator==(const Set& kOtherSet) const {

  return true;
}

// 
void Set::Write(void) {
  for (ulong i = 0; i < set_.size(); i++)
    for (ulong j = (i * long_size_); j < ((1 + i) * long_size_); j++)
      if (set_[i] & (ulong)1 << j)  // true si el numero 1 de set igual a j
        std::cout << j << " "; 
  std::cout << "\n";
}

//
void Set::CheckElement(ulong element) {
  if (limit_elements_size_ <= element) {
    std::cerr << "Element out of limit of the set.\n";
    exit(0);
  }
}  