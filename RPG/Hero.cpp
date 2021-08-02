#include "Hero.h"

void Hero::PrintStat ()
{
    std::cout << this->GetName () << " stat:    Hp: " << GetHp () << "\tDamage: " << GetDamage () << "\tDelay Attacks: " << this->GetDelayAttacks () << "\tEx: " << this->GetEX () << "\tLevel: " << this->GetLevel () << std::endl;
}

void Hero::GainEx ( int32_t ExForKillingEnemy )
{
    this->SetEx ( this->GetEX () + ExForKillingEnemy );////////////////////////////////////////////////
    if ( this->GetEX () >= this->GetMaxEx () )
    {
        this->SetEx ( this->GetEX () - this->GetMaxEx () );
        this->LevelUp ();
        std::cout << this->GetName () << " was able to survive. Now u can go on next level " << this->GetLevel () << std::endl << std::endl;
    }

}

/*void Hero::LevelUp ()
{
    this->SetLevel ( this->GetLevel () + 1 );
    this->LevelModifier ();
}*/

void Hero::LevelModifier ()
{
    this->SetMaxHp ( this->GetMaxHp () * this->GetLevelModify () );
    this->SetDamage ( this->GetDamage () * this->GetLevelModify () );
    this->SetDelayAttacks ( int32_t ( this->GetDelayAttacks () / this->GetLevelModify () ) );
}

void Hero::HeroKillEnemy ( NPC& other )
{
    std::cout << std::endl << this->GetName () << " kill " << other.GetName () << std::endl << std::endl;
    this->GainEx ( ExUp [other.GetEnemyDifficult ()] );
    //this->SetEnemyDifficult ( other.GetEnemyDifficult () );//////////////////////////////////////////////////////////////
}

void Hero::EndGame ()
{
    std::cout << "\n==========GAME OVER==========\n" << std::endl;
}
