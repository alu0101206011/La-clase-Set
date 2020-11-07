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
limit_elements_size_(long_size_) {
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

void Set::set_set(const std::vector<ulong> kNewSet) { set_ = kNewSet; }
void Set::set_limit_elements_size_(const ulong kNewLimit) { 
  limit_elements_size_ = kNewLimit; 
}

// Sets the bit at the position given by the parameter named element to 1
void Set::InsertElement(const ulong kElement) {
  CheckElement(kElement);
  ulong selectioner = kElement / long_size_;
  set_[selectioner] |= (ulong)1 << (kElement % long_size_);
}

// Sets the bit at the position given by the parameter named element to 0
void Set::DeleteElement(const ulong kElement) {
  CheckElement(kElement);
  ulong selectioner = kElement / long_size_;
  if (ElementBelongsToSet(kElement)) {
     set_[selectioner] &= ~((ulong)1 << (kElement % long_size_));
  } else {
    std::cerr << "Element cannot be deleted\n";
  }
}

// Change the positions of the long vector that were at 1 to 0
void Set::ClearSet(void) {
  for (ulong i = 0; i < set_.size(); i++)
    for (ulong j = 0; j < long_size_; j++)
      if (set_[i] & (ulong)1 << j)
        set_[i] &= ~((ulong)1 << (j % long_size_));
}

// Returns true if the long vector is empty
bool Set::SetIsEmpty(void) {
  for (ulong i = 0; i < set_.size(); i++)
    for (ulong j = 0; j < long_size_; j++) 
      if (set_[i] & (ulong)1 << j) 
        return false;
  return true;
}

// Returns true if the element position in the long vector is at 1
bool Set::ElementBelongsToSet(const ulong kElement) {
  CheckElement(kElement);
  ulong selectioner = kElement / long_size_;
  if (set_[selectioner] & (ulong)1 << kElement) {
     return true;
  } else {
    return false;
  }
}

// Equal operator overload having a initializer list as a parameter
void Set::operator=(const Set kOtherSet) { 
  set_ = kOtherSet.get_set();
  long_size_ = kOtherSet.get_long_size_();
  limit_elements_size_ = kOtherSet.get_limit_elements_size_();
}

// Equality operator overload returns true if two sets are equal
bool Set::operator==(Set kOtherSet) {
  ulong counter;
  if (kOtherSet.limit_elements_size_ > limit_elements_size_) {
    for (counter = 0; counter < limit_elements_size_; counter++) {
      if (ElementBelongsToSet(counter) ^ kOtherSet.ElementBelongsToSet(counter))
        return false;
    }
    while (counter != kOtherSet.get_limit_elements_size_()) {
      if (kOtherSet.ElementBelongsToSet(counter)) 
        return false;
      counter++;
    }
  } else {
    for (counter = 0; counter < kOtherSet.get_limit_elements_size_(); counter++) 
      if (ElementBelongsToSet(counter) ^ kOtherSet.ElementBelongsToSet(counter))
        return false;
    while (counter != get_limit_elements_size_()) {
      if (ElementBelongsToSet(counter)) 
        return false;
      counter++;
    }
  }
  return true;

}

// 
Set Set::operator+(Set kOtherSet) {
  Set Result(limit_elements_size_ + kOtherSet.limit_elements_size_);
  
} 

// Write the elements of the set
void Set::Write(void) {
  for (ulong i = 0; i < set_.size(); i++)
    for (ulong j = 0; j < long_size_; j++)
      if (set_[i] & (ulong)1 << j)  // true si el numero 1 de set igual a j
        std::cout << j + (i * long_size_) << " ";
  std::cout << "\n";
}

// Check if the element is out of limit
void Set::CheckElement(const ulong kElement) const {
  if (limit_elements_size_ <= kElement) {
    std::cerr << "Element out of limit of the set.\n";
    exit(0);
  }
}  