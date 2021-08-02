#include "NPC.h"

void NPC::ChangeEnemyDefaultStats ()
{
    this->SetMaxHp ( this->GetMaxHp () * this->VectorDifficultModifier [EnemyDifficult] );
    this->SetDamage ( this->GetDamage () * this->VectorDifficultModifier [EnemyDifficult] );
    this->SetDelayAttacks ( int32_t ( this->GetDelayAttacks () / this->VectorDifficultModifier [EnemyDifficult] ) );
    this->RefreshHp ();
}

void NPC::LevelModifier ()
{
    this->SetMaxHp ( this->GetMaxHp () * this->GetLevelModify () );
    this->SetDamage ( this->GetDamage () * this->GetLevelModify () );
    this->SetDelayAttacks ( int32_t ( this->GetDelayAttacks () / this->GetLevelModify () ) );
}

void NPC::Kill ( Character& other )
{
    std::cout << std::endl << this->GetName () << " kill " << other.GetName () << std::endl << std::endl;
}