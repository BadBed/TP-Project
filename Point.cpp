#include "AllClasses.h"
#include "Point.h"
#include "TowerComponents.h"

/**
 * \brief Реализация функций класса Point
 */

void CPoint::Update(double dtime) {}

void CPoint::SetTower(CTower* new_tower){
    tower.reset(new_tower);
    AddChild(new_tower);
}

CTower* CPoint::GetTower() {
    return tower.get();
}

void CPoint::RemoveTower() {
    RemoveChild(tower.get());
    tower.reset(nullptr);
}
