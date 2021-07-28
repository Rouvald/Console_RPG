#pragma once
#include "Character.h"

class NPC;

class Hero : public Character
{
public:
    Hero () : Character () {}
    Hero ( std::string Name, bool Is_Good) : Character ( Name, Is_Good) 
    {
        this->SetDamage ( this->GetDamage () * DefaultHeroDamageMogify );
        this->SetDelayAttacks ( DefaultHeroDelayAttacks );
    }
    //float GetStandartDamageMogify () { return StandartDamageHeroMogify; }

    int32_t& GetLevel () { return this->Level; }

    void PrintStat () override;

    void LevelUp () override;
    void EndGame () override;

private:
    void SetLevel ( int32_t Level ) { this->Level = Level; }
    int32_t Level = 1;
    float DefaultHeroDamageMogify = 7;
    int32_t DefaultHeroDelayAttacks = 25;

    std::vector<int32_t> ExUp = {80, 100, 120};
};

