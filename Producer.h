#pragma once
#include "AllClasses.h"
#include "Tower.h"
#include "Player.h"

/**
 * \brief Реализация интерфейса класса Producer
 * При помощи фабрики создает башню и делает все побочные действия
 *
 */

class CProducer : public IProducer {
public:
	CProducer();
	~CProducer() override = default;

	void SetFactoryAndPlayer(CPlayer* player, IFactory* factory) override;

	/**
	 * \brief Функция, проверяющая, можно ли создать башню
	 * Проверяет, достаточно ли у игрока средств и не находится ли она на перезарядке
	 */

	bool IsAbleToCreate() override ;

	CTower* Create(CPoint* point) override;

private:
	void ChangeMoney();
	void ChangeCD();
	IFactory* _factory;
	CPlayer* _player;
	double _cd;
};