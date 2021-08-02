#pragma once
#include "Character.h"
#include "Hero.h"

class Hero;

class NPC :
    public Character
{
public:
    NPC () :Character () {}
    NPC ( bool Is_Good ) :Character ( Is_Good ) {}

    int32_t GetEnemyDifficult () { return this->EnemyDifficult; }

    void ChangeEnemyDefaultStats ();
    void LevelModifier () override;
    void Kill (Character& other);

private:
    void SetEnemyDifficult ( int32_t EnemyDifficult ) { this->EnemyDifficult = EnemyDifficult; }
    int32_t EnemyDifficult = 0;
    std::vector<float> VectorDifficultModifier = { 0.9f, 1.0f, 1.1f };
};

