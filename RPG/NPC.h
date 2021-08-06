#pragma once
#include "Character.h"
#include "Hero.h"

class Hero;

enum class Difficulty
{
    easy,
    normal,
    hard,
    error
};

class NPC :
    public Character
{
public:
    NPC () :Character () {}
    NPC ( bool Is_Good ) :Character ( Is_Good ) {}

    int32_t GetEnemyDifficulty () { return this->EnemyDifficulty; }

    void ChangeEnemyDefaultStats ( int32_t NewEnemyDifficulty );

    void LevelModifier () override;

    void Kill (Character& other);

private:
    void ChangeEnemyDefaultModification ( int32_t NewEnemyDifficulty );
    void ModificationUP ();
    void ModificationDOWN ();

    void NormalizeLevelModifierStatsUP ();
    void NormalizeLevelModifierStatsDOWN ();

    void SetEnemyDifficulty ( int32_t EnemyDifficulty ) { this->EnemyDifficulty = EnemyDifficulty; }
    int32_t EnemyDifficulty = 1;

    float DifficultyHealthModifier = 15.0f;
    float DifficultyDamageModifier = 1.5f;
    int32_t DifficultyDelayAttacksModifier = 3;

    float LevelHealthModification = 5.25f;
    float LevelDamageModification = 0.75f;
    int32_t LevelDelayAttacksModification = 2;

    const float HealthAndDamage_LEVEL_DIFFERENCE = 0.25f;
    const int32_t DelayAttacks_LEVEL_DIFFERENCE = 1;
};

