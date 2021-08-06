#pragma once
#include "Character.h"
#include "NPC.h"

class NPC;

enum class LevelModification
{
    health,
    damage,
    delay,
    error
};

class Hero : public Character
{
public:
    Hero () : Character () {}
    Hero ( std::string Name, bool Is_Good ) : Character ( Name, Is_Good )
    {
        this->SetHp ( 100 );
        this->SetDamage ( this->GetDamage () * DefaultHeroDamage );
        //this->SetLevelModify ( DefaultHeroLevelModify );
        this->SetDelayAttacks ( DefaultHeroDelayAttacks );
    }
    //float GetStandartDamageMogify () { return StandartDamageHeroMogify; }
    float GetEX () { return this->Ex; }

    void PrintStat () override;

    void GainEx (int32_t ExForKillingEnemy);
    //void LevelUp () override;
    void LevelModifier () override;

    void HeroKillEnemy (NPC& other);
    void EndGame ();

private:
    LevelModification Convert (const std::string& str);

    float GetMaxEx () { return this->MaxEx; }

    void SetEx ( float Ex ) { this->Ex = Ex; }
    void SetMaxEx ( float MaxEx ) { this->MaxEx = MaxEx; }
    float DefaultHeroDamage = 7.0f;
    int32_t DefaultHeroDelayAttacks = 60;
    float LevelHealthModification = 22.0f;
    float LevelDamageModification = 3.0f;
    int32_t LevelDelayAttacksModification = 4;

    float MaxEx = 100.0f;

    std::vector<int32_t> ExUp = { 80, 100, 120 };
};

