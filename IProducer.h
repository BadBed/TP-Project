#pragma once
#include "AllClasses.h"
#include "Tower.h"

/**
 * \brief Интерфейс класса Producer
 */

class IProducer {
public:
    virtual ~IProducer() = default;
    /**
     * \brief Функция, задающая игрока и фабрику
     * @param player
     * @param factory
     */
    virtual void SetFactoryAndPlayer(CPlayer* player, IFactory* factory) = 0;
    /**
     * \brief Функция, проверяющая, можно ли создать башню
     */
    virtual bool IsAbleToCreate() = 0;
    /**
     * \brief Функция, непосредственно создающая башню
     * @param point - указатель на точку на поле
     * @return указатель на башню
     */
    virtual CTower* Create(CPoint*) = 0;
};