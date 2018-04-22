#pragma once
#include <memory>
#include "AllClasses.h"
#include "Composite.h"
#include "Point.h"
#include "TowerComponents.h"

using std::unique_ptr;

struct CMapEadge {
    int v1, v2;
};

class CMap : IComposite {
private:
    vector<unique_ptr<CPoint> > _points;
    vector<vector<CMapEadge> > _eadges;
public:

    ~CMap() = default;
    void Update(double dt) override;
};