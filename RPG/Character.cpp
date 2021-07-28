#include "Character.h"

static bool Is_Last_Hit = false;

void Character::Attack ( Character& other )
{
    if ( other.GetIs_Good () == this->GetIs_Good () )
    {
        std::cout << "\tU can't attack allies!" << std::endl;
        return;
    }
    if ( other.GetHp () <= 0.0f && !this->CheckDeath () ) { return; }

    while ( other.GetHp () > 0.0f/*this->GetDamage ()*/ && !Is_Last_Hit )
    {
        std::this_thread::sleep_for ( std::chrono::milliseconds ( this->GetDelayAttacks () ) );
        other.SetHp ( std::clamp ( other.GetHp () - this->GetDamage (), 0.0f, other.GetMaxHp () ) );
        //std::cout << GetName () << " attack " << other.GetName () << " Hp: " << other.GetHp () << std::endl;
    }
    Is_Last_Hit = true;
}

void Character::Kill ( Character& other )
{
    this->SetEnemyDifficult ( other.GetEnemyDifficult () );
    std::cout << std::endl << this->GetName () << " kill " << other.GetName () << std::endl<<std::endl;
}

void Character::PrintStat ()
{
    std::cout << this->GetName () << " stat:    Hp: " << GetHp () << "\tDamage: " << GetDamage () <</* "\tLevel: " << this->GetLevel () <<*/ std::endl;
}

bool Character::CheckDeath ()
{
    this->GetHp () <= 0 ? this->SetIs_Dead ( true ) : this->SetIs_Dead ( false );
    if ( this->GetIs_Dead () )
    {
        std::cout << this->GetName () << "  is dead!" << std::endl;
    }
    return this->GetIs_Dead ();
}

void Character::StatsUp () 
{

}

void Character::LevelUp () {}

void Character::EndGame () {}