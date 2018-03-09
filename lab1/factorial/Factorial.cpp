//
// Created by mwypych on 02.02.17.
//
#include "Factorial.h"

bool IsOutOfRange(int value);

int factorial(int value) {
  if(IsOutOfRange(value))return 0;
  if(value == 1 || value == 0)return 1;
  if(value == -1)return -1;
  if(value > 1){
    return factorial(value -1)*value;
  }
  if(value < -1){
    return factorial(value + 1)*value;
  }
}

bool IsOutOfRange(int value) { return value >= 13 || value <= -13; }
