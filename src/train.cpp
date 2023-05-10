// Copyright 2021 NNTU-CS
#include "train.h"
Train::Train(): first(nullptr), countOp(0) {}
void Train::addCage(bool light) {
  Cage* CageWagon = new Cage;
  CageWagon->light = light;
  CageWagon->next = nullptr;
  CageWagon->prev = nullptr;
  if (first == nullptr) {
    first = CageWagon;
  } else {
    if (first->next == nullptr) {
      first->next = CageWagon;
      first->prev = CageWagon;
      CageWagon->prev = first;
      CageWagon->next = first;
    } else {
      Cage* cg = first;
      while (cg->next != first) {
        cg = cg->next;
      }
      cg->next = CageWagon;
      CageWagon->prev = cg;
      CageWagon->next = first;
      first->prev  = CageWagon;
    }
  }
  countOp = 0;
}
int Train::getLength() {
    Cage* CageWa = first;
    if (CageWa->light == false) {
        CageWa->light = true;
    }
    int rezult = 0;
    int countCageWagon = 0;
    while (true) {
        CageWa = CageWa->next;
        countOp += 1;
        countCageWagon += 1;
        while (CageWa->light == false) {
            CageWa = CageWa->next;
            countOp += 1;
            countCageWagon += 1;
        }
        CageWa->light = false;
        rezult = countCageWagon;
        while (countCageWagon != 0) {
            countOp += 1;
            countCageWagon -= 1;
            CageWa = CageWa->prev;
        }
        if (CageWa->light == false) {
            return rezult;
        }
    }
}
int Train::getOpCount() {
    return countOp;
}
