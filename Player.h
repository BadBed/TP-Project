#pragma once
#include "AllClasses.h"
#include "Tower.h"
#include "IProducer.h"

/**
 * \brief Класс Player
 * Содержит сумму денежных единиц, которыми владеет игрок, ...
 *
 */

class CPlayer : public IComposite {
public:

    int money;

    void Update(double dtime) override;


private:
	std::vector<unique_ptr<IProducer> > buffer;

};