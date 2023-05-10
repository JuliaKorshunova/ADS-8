// Copyright 2021 NNTU-CS
#include "train.h"
void Train::addCage(bool light) {
  Cage* cageWagon = new Cage;
  cageWagon->next = nullptr;
  cageWagon->light = light;
  cageWagon->prev = nullptr;
  if (first == nullptr) {
    first = cageWagon;
  } else if (first->next == nullptr) {
      cageWagon->next = first;
      first->next = cageWagon;
      cageWagon->prev = first;
      first->prev = cageWagon;
  } else {
    Cage* cg = first;
    while (cg->next != first) {
      cg = cg->next;
    }
    cg->next = cageWagon;
    cageWagon->prev = cg;
    cageWagon->next = first;
    first->prev  = cageWagon;
    }
  }
  countOp = 0;
}
Train::Train() {
  first = nullptr;
  countOp = 0;
}
int Train :: getLength() {
  Cage* items;
  int CageWa;
  countOp = 0;
  first->light = true;
  while (first->light == true) {
    items = first->next;
    while (items->light == false) {
      items = items->next;
      countOp++;
    }
    countOp++;
    items->light = false;
    CageWa = 1;
    while (items->prev != first) {
      items = items->prev;
      countOp++;
      CageWa++;
    }
    countOp++;
  }
  return CageWa;
}
int Train :: getOpCount() {
  if (countOp == 0)
    getLength();
  return countOp;
}
