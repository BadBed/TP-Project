#include <vector>

#include "AllClasses.h"
#include "Tower.h"
#include "TowerComponents.h"

void CTower::AddComponent(IComponent* comp) {
    components.push_back(unique_ptr<IComponent>(comp));
    comp->SetTower(this);
}

void CTower::Update(double dtime) {
    for(int i =0; i<components.size(); ++i){
        components[i]->Update(dtime);
    }
}

void CTower::Die(){
    for(int i =0; i<components.size(); ++i){
        components[i]->Die();
    }
}

//-----------------------------------------------------------------------



CTower* CFactoryNormal::Create(CPoint* point, CPlayer* player) {
    CTower* tower = new CTower;
    CComponentHealth* health = new CComponentHealth(HP);
    tower->AddComponent(health);
    tower->AddChild(health);
    CComponentAccessory* accessory = new CComponentAccessory(player);
    tower->AddComponent(accessory);
    tower->AddComponent(accessory);
    CComponentPosition* pos = new CComponentPosition(point);
    tower->AddComponent(pos);
    tower->AddChild(pos);
    CComponentGraphic* graphic = new CComponentGraphic();
    tower->AddComponent(graphic);
    tower->AddChild(graphic);
    CComponentPowerUsual* powerUsual = new CComponentPowerUsual();
    tower->AddComponent(powerUsual);
    tower->AddChild(powerUsual);
    CComponentTargetAttack* targetAttack = new CComponentTargetAttack(DMG, RADIUS, ATTACK_CD);
    tower->AddComponent(targetAttack);
    tower->AddChild(targetAttack);

    return tower;
}

int CFactoryNormal::GetCD() const{
    return CD;
}

int CFactoryNormal::GetCOST() const{
    return COST;
}

/////

CTower* CFactoryLongRange::Create(CPoint* point, CPlayer* player) {
    CTower* tower = new CTower;

    CComponentHealth* health = new CComponentHealth(HP);
    tower->AddComponent(health);
    tower->AddChild(health);
    CComponentAccessory* accessory = new CComponentAccessory(player);
    tower->AddComponent(accessory);
    tower->AddComponent(accessory);
    CComponentPosition* pos = new CComponentPosition(point);
    tower->AddComponent(pos);
    tower->AddChild(pos);
    CComponentGraphic* graphic = new CComponentGraphic();
    tower->AddComponent(graphic);
    tower->AddChild(graphic);
    CComponentPowerUsual* powerUsual = new CComponentPowerUsual();
    tower->AddComponent(powerUsual);
    tower->AddChild(powerUsual);
    CComponentTargetAttack* targetAttack = new CComponentTargetAttack(DMG, RADIUS, ATTACK_CD);
    tower->AddComponent(targetAttack);
    tower->AddChild(targetAttack);

    return tower;
}

int CFactoryLongRange::GetCD() const{
    return CD;
}

int CFactoryLongRange::GetCOST() const{
    return COST;
}

/////

CTower* CFactoryProtective::Create(CPoint* point, CPlayer* player) {
    CTower* tower = new CTower;

    CComponentHealth* health = new CComponentHealth(HP);
    tower->AddComponent(health);
    tower->AddChild(health);
    CComponentAccessory* accessory = new CComponentAccessory(player);
    tower->AddComponent(accessory);
    tower->AddComponent(accessory);
    CComponentPosition* pos = new CComponentPosition(point);
    tower->AddComponent(pos);
    tower->AddChild(pos);
    CComponentGraphic* graphic = new CComponentGraphic();
    tower->AddComponent(graphic);
    tower->AddChild(graphic);
    CComponentPowerUsual* powerUsual = new CComponentPowerUsual();
    tower->AddComponent(powerUsual);
    tower->AddChild(powerUsual);


    return tower;
}

int CFactoryProtective::GetCD() const{
    return CD;
}

int CFactoryProtective::GetCOST() const{
    return COST;
}

//////

CTower* CFactoryMissile::Create(CPoint* point, CPlayer* player) {
    CTower* tower = new CTower;

    CComponentHealth* health = new CComponentHealth(HP);
    tower->AddComponent(health);
    tower->AddChild(health);
    CComponentAccessory* accessory = new CComponentAccessory(player);
    tower->AddComponent(accessory);
    tower->AddComponent(accessory);
    CComponentPosition* pos = new CComponentPosition(point);
    tower->AddComponent(pos);
    tower->AddChild(pos);
    CComponentGraphic* graphic = new CComponentGraphic();
    tower->AddComponent(graphic);
    tower->AddChild(graphic);
    CComponentPowerUsual* powerUsual = new CComponentPowerUsual();
    tower->AddComponent(powerUsual);
    tower->AddChild(powerUsual);
    CComponentActiveSkillMissile* activeSkillMissile = new CComponentActiveSkillMissile(SKILL_CD);
    tower->AddComponent(activeSkillMissile);
    tower->AddChild(activeSkillMissile);

    return tower;
}

int CFactoryMissile::GetCD() const{
    return CD;
}

int CFactoryMissile::GetCOST() const{
    return COST;
}

/////

CTower* CFactorySupport::Create(CPoint* point, CPlayer* player) {
    CTower* tower = new CTower;

    CComponentHealth* health = new CComponentHealth(HP);
    tower->AddComponent(health);
    tower->AddChild(health);
    CComponentAccessory* accessory = new CComponentAccessory(player);
    tower->AddComponent(accessory);
    tower->AddComponent(accessory);
    CComponentPosition* pos = new CComponentPosition(point);
    tower->AddComponent(pos);
    tower->AddChild(pos);
    CComponentGraphic* graphic = new CComponentGraphic();
    tower->AddComponent(graphic);
    tower->AddChild(graphic);
    CComponentPowerUsual* powerUsual = new CComponentPowerUsual();
    tower->AddComponent(powerUsual);
    tower->AddChild(powerUsual);
    CComponentTargetSkillSupport* targetSkillSupport = new CComponentTargetSkillSupport(RADIUS, MULTIPLY);
    tower->AddComponent(targetSkillSupport);
    tower->AddChild(targetSkillSupport);

    return tower;
}

int CFactorySupport::GetCD() const{
    return CD;
}

int CFactorySupport::GetCOST() const{
    return COST;
}

//////

CTower* CFactoryMoving::Create(CPoint* point, CPlayer* player) {
    CTower* tower = new CTower;

    CComponentHealth* health = new CComponentHealth(HP);
    tower->AddComponent(health);
    tower->AddChild(health);
    CComponentAccessory* accessory = new CComponentAccessory(player);
    tower->AddComponent(accessory);
    tower->AddComponent(accessory);
    CComponentPosition* pos = new CComponentPosition(point);
    tower->AddComponent(pos);
    tower->AddChild(pos);
    CComponentGraphic* graphic = new CComponentGraphic();
    tower->AddComponent(graphic);
    tower->AddChild(graphic);
    CComponentPowerMoving* moving = new CComponentPowerMoving();
    tower->AddComponent(moving);
    tower->AddChild(moving);
    CComponentTargetAttack* targetAttack = new CComponentTargetAttack(DMG, RADIUS, ATTACK_CD);
    tower->AddComponent(targetAttack);
    tower->AddChild(targetAttack);
    CComponentActiveSkillMoving* activeSkillMoving = new CComponentActiveSkillMoving(SKILL_CD);
    tower->AddComponent(activeSkillMoving);
    tower->AddChild(activeSkillMoving);

    return tower;
}

int CFactoryMoving::GetCD() const{
    return CD;
}

int CFactoryMoving::GetCOST() const{
    return COST;
}

///////

CTower* CFactoryHealer::Create(CPoint* point, CPlayer* player) {
    CTower* tower = new CTower;

    CComponentHealth* health = new CComponentHealth(HP);
    tower->AddComponent(health);
    tower->AddChild(health);
    CComponentAccessory* accessory = new CComponentAccessory(player);
    tower->AddComponent(accessory);
    tower->AddComponent(accessory);
    CComponentPosition* pos = new CComponentPosition(point);
    tower->AddComponent(pos);
    tower->AddChild(pos);
    CComponentGraphic* graphic = new CComponentGraphic();
    tower->AddComponent(graphic);
    tower->AddChild(graphic);
    CComponentPowerUsual* powerUsual = new CComponentPowerUsual();
    tower->AddComponent(powerUsual);
    tower->AddChild(powerUsual);
    CComponentPassiveSkillHeal* skillHeal = new CComponentPassiveSkillHeal(RADIUS, HEAL_SPEED);
    tower->AddComponent(skillHeal);
    tower->AddChild(skillHeal);

    return tower;
}

int CFactoryHealer::GetCD() const{
    return CD;
}

int CFactoryHealer::GetCOST() const{
    return COST;
}

/////////

CTower* CFactoryEnlarger::Create(CPoint* point, CPlayer* player) {
    CTower* tower = new CTower;

    CComponentHealth* health = new CComponentHealth(HP);
    tower->AddComponent(health);
    tower->AddChild(health);
    CComponentAccessory* accessory = new CComponentAccessory(player);
    tower->AddComponent(accessory);
    tower->AddComponent(accessory);
    CComponentPosition* pos = new CComponentPosition(point);
    tower->AddComponent(pos);
    tower->AddChild(pos);
    CComponentGraphic* graphic = new CComponentGraphic();
    tower->AddComponent(graphic);
    tower->AddChild(graphic);
    CComponentPowerUsual* powerUsual = new CComponentPowerUsual();
    tower->AddComponent(powerUsual);
    tower->AddChild(powerUsual);
    CComponentPassiveSkillEnlarger* enlarger = new CComponentPassiveSkillEnlarger(ENLARGE_SPEED);
    tower->AddComponent(enlarger);
    tower->AddChild(enlarger);


    return tower;
}

int CFactoryEnlarger::GetCD() const{
    return CD;
}

int CFactoryEnlarger::GetCOST() const{
    return COST;
}

//////

CTower* CFactoryGenerator::Create(CPoint* point, CPlayer* player) {
    CTower* tower = new CTower;

    CComponentHealth* health = new CComponentHealth(HP);
    tower->AddComponent(health);
    tower->AddChild(health);
    CComponentAccessory* accessory = new CComponentAccessory(player);
    tower->AddComponent(accessory);
    tower->AddComponent(accessory);
    CComponentPosition* pos = new CComponentPosition(point);
    tower->AddComponent(pos);
    tower->AddChild(pos);
    CComponentGraphic* graphic = new CComponentGraphic();
    tower->AddComponent(graphic);
    tower->AddChild(graphic);
    CComponentPowerGenerate* powerGenerate = new CComponentPowerGenerate();
    tower->AddComponent(powerGenerate);
    tower->AddChild(powerGenerate);
    CComponentPassiveSkillEnlarger* skillEnlarger = new CComponentPassiveSkillEnlarger(ENLARGE_SPEED);
    tower->AddComponent(skillEnlarger);
    tower->AddChild(skillEnlarger);

    return tower;
}

int CFactoryGenerator::GetCD() const{
    return CD;
}

int CFactoryGenerator::GetCOST() const{
    return COST;
}

///////

CTower* CFactoryBase::Create(CPoint* point, CPlayer* player) {
    CTower* tower = new CTower;

    CComponentHealth* health = new CComponentHealth(HP);
    tower->AddComponent(health);
    tower->AddChild(health);
    CComponentAccessory* accessory = new CComponentAccessory(player);
    tower->AddComponent(accessory);
    tower->AddComponent(accessory);
    CComponentPosition* pos = new CComponentPosition(point);
    tower->AddComponent(pos);
    tower->AddChild(pos);
    CComponentGraphic* graphic = new CComponentGraphic();
    tower->AddComponent(graphic);
    tower->AddChild(graphic);
    CComponentPowerGenerate* powerGenerate = new CComponentPowerGenerate();
    tower->AddComponent(powerGenerate);
    tower->AddChild(powerGenerate);
    CComponentShoudNotDie* shoudNotDie = new CComponentShoudNotDie();
    tower->AddComponent(shoudNotDie);
    tower->AddChild(shoudNotDie);

    return tower;
}

int CFactoryBase::GetCD() const{
    return CD;
}

int CFactoryBase::GetCOST() const{
    return COST;
}

//*************************************************
