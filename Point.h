#pragma once
#include "AllClasses.h"
#include "Tower.h"

/**
 * \brief Класс Point
 */

class CPoint : public IComposite{
public:
    void Update(double dtime) override;

    /**
     * \brief Функция, устанавливающая башню на конкретную точку
     * @param new_tower
     */

    void SetTower(CTower* new_tower);

    /**
     * \brief Возврщает башню, находящуюся в точке
     * @return
     */

    CTower* GetTower();

    /**
     * \brief Удаляет башню из точки
     */

    void RemoveTower();

    int x, y;

private:
    unique_ptr<CTower> tower;
};