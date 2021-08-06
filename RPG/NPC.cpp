#include "NPC.h"

void NPC::ChangeEnemyDefaultModification ( int32_t NewEnemyDifficulty )
{
    while ( this->EnemyDifficulty != NewEnemyDifficulty )
        this->EnemyDifficulty < NewEnemyDifficulty ? this->ModificationUP () : this->ModificationDOWN ();
}

void NPC::ModificationUP ()
{
    this->SetMaxHp ( this->GetMaxHp () + this->DifficultyHealthModifier );
    this->SetDamage ( this->GetDamage () + this->DifficultyDamageModifier );
    this->SetDelayAttacks ( this->GetDelayAttacks () - this->DifficultyDelayAttacksModifier );

    this->LevelHealthModification += this->HealthAndDamage_LEVEL_DIFFERENCE;
    this->LevelDamageModification += this->HealthAndDamage_LEVEL_DIFFERENCE;
    this->LevelDelayAttacksModification -= this->DelayAttacks_LEVEL_DIFFERENCE;

    this->NormalizeLevelModifierStatsUP ();

    ++this->EnemyDifficulty;
}
void NPC::ModificationDOWN ()
{
    this->SetMaxHp ( this->GetMaxHp () - this->DifficultyHealthModifier );
    this->SetDamage ( this->GetDamage () - this->DifficultyDamageModifier );
    this->SetDelayAttacks ( this->GetDelayAttacks () + this->DifficultyDelayAttacksModifier );

    this->LevelHealthModification -= this->HealthAndDamage_LEVEL_DIFFERENCE;
    this->LevelDamageModification -= this->HealthAndDamage_LEVEL_DIFFERENCE;
    this->LevelDelayAttacksModification += this->DelayAttacks_LEVEL_DIFFERENCE;

    this->NormalizeLevelModifierStatsDOWN ();

    --this->EnemyDifficulty;
}

void NPC::NormalizeLevelModifierStatsUP ()
{
    int32_t LevelDifference = this->GetLevel () - 1;

    this->SetMaxHp ( this->GetMaxHp () + this->HealthAndDamage_LEVEL_DIFFERENCE * LevelDifference );
    this->SetDamage ( this->GetDamage () + this->HealthAndDamage_LEVEL_DIFFERENCE * LevelDifference );
    this->SetDelayAttacks ( this->GetDelayAttacks () - this->DelayAttacks_LEVEL_DIFFERENCE * LevelDifference );
}

void NPC::NormalizeLevelModifierStatsDOWN ()
{
    int32_t LevelDifference = this->GetLevel () - 1;

    this->SetMaxHp ( this->GetMaxHp () - this->HealthAndDamage_LEVEL_DIFFERENCE * LevelDifference );
    this->SetDamage ( this->GetDamage () - this->HealthAndDamage_LEVEL_DIFFERENCE * LevelDifference );
    this->SetDelayAttacks ( this->GetDelayAttacks () + this->DelayAttacks_LEVEL_DIFFERENCE * LevelDifference );
}

void NPC::ChangeEnemyDefaultStats ( int32_t NewEnemyDifficulty )
{
    if ( NewEnemyDifficulty < 0 && NewEnemyDifficulty > 2 ) return;

    if ( this->EnemyDifficulty != NewEnemyDifficulty )
        this->ChangeEnemyDefaultModification ( NewEnemyDifficulty );

    this->RefreshHp ();
}

void NPC::LevelModifier ()
{
    this->SetMaxHp ( this->GetMaxHp () + this->LevelHealthModification );
    this->SetDamage ( this->GetDamage () + this->LevelDamageModification );
    this->SetDelayAttacks ( this->GetDelayAttacks () - this->LevelDelayAttacksModification );
}

void NPC::Kill ( Character& other )
{
    std::cout << std::endl << this->GetName () << " kill " << other.GetName () << std::endl << std::endl;
}