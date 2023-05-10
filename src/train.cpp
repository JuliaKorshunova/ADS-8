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
Train::Train(): {
  first = nullptr;
  countOp = 0;
}
int Train::getLength() {
    Cage* CageWa = first;
    if (CageWa->light == false) {
        CageWa->light = true;
    }
    int countCageWa = 0;
    int rezult = 0;
    while (true) {
        CageWa = CageWa->next;
        countOp += 1;
        countCageWa += 1;
        while (CageWa->light == false) {
            CageWa = CageWa->next;
            countCageWa += 1;
            countOp += 1;
        }
        CageWa->light = false;
        rezult = countCageWa;
        while (countCageWa != 0) {
            countOp += 1;
            countCageWa -= 1;
            CageWa = CageWa->prev;
        }
        if (CageWa->light == false) {
            return rezult;
        }
    }
}
int Train :: getOpCount() {
  if (countOp == 0)
    getLength();
  return countOp;
}
