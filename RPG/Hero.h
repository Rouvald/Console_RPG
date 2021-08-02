#pragma once
#include "Character.h"
#include "NPC.h"

class NPC;

class Hero : public Character
{
public:
    Hero () : Character () {}
    Hero ( std::string Name, bool Is_Good ) : Character ( Name, Is_Good )
    {
        this->SetHp ( 100 );
        this->SetDamage ( this->GetDamage () * DefaultHeroDamageMogify );
        this->SetLevelModify ( DefaultHeroLevelModify );
        this->SetDelayAttacks ( DefaultHeroDelayAttacks );
    }
    //float GetStandartDamageMogify () { return StandartDamageHeroMogify; }
    float GetEX () { return this->Ex; }
    float GetMaxEx () { return this->MaxEx; }

    void PrintStat () override;

    void GainEx (int32_t ExForKillingEnemy);
    //void LevelUp () override;
    void LevelModifier () override;

    void HeroKillEnemy (NPC& other);
    void EndGame ();

private:
    void SetEx ( float Ex ) { this->Ex = Ex; }
    void SetMaxEx ( float MaxEx ) { this->MaxEx = MaxEx; }
    float DefaultHeroDamageMogify = 7.0f;
    float DefaultHeroLevelModify = 1.05f;
    int32_t DefaultHeroDelayAttacks = 25;
    float Ex = 0.0f;
    float MaxEx = 100.0f;

    std::vector<int32_t> ExUp = { 80, 100, 120 };
};

