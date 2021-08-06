#include "Character.h"

void Character::PrintStat ()
{
    std::cout << this->GetName () << " stat:    Hp: " << GetHp () << "\tDamage: " << GetDamage () << "\tDelay Attacks: " << this->GetDelayAttacks () << "\tLevel: " << this->GetLevel () << std::endl;
}

static bool Is_Character_Dead = false; // crunch for end second thread

void Character::Attack ( Character& other )
{
    if ( other.GetIs_Good () == this->GetIs_Good () )
    {
        std::cout << "\tU can't attack allies!" << std::endl;
        return;
    }
    if ( other.GetHp () <= 0.0f && !this->CheckDeath () ) { return; }

    while ( other.GetHp () > 0.0f/*this->GetDamage ()*/ && !Is_Character_Dead )
    {
        std::this_thread::sleep_for ( std::chrono::milliseconds ( this->GetDelayAttacks () ) );
        other.SetHp ( std::clamp ( other.GetHp () - this->GetDamage (), 0.0f, other.GetMaxHp () ) );
        //std::cout << GetName () << " attack " << other.GetName () << " Hp: " << other.GetHp () << std::endl;
    }
    Is_Character_Dead = true;
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

/*void Character::Kill (Character& other)
{
    std::cout << std::endl << this->GetName () << " kill " << other.GetName () << std::endl << std::endl;
}*/

//void Character::ChangeEnemyDefaultStats () {}//////////////////////////////////////////////////////////
//void Character::GainEx ( int32_t ExForKillEnemy ) {}//////////////////////////////////////////////////////////
//void Character::EndGame () {}//////////////////////////////////////////////////////////

void Character::LevelUp ()
{
    this->SetLevel ( this->GetLevel () + 1 );
    this->LevelModifier ();
}

void Character::RefreshHp ()
{
    this->SetHp ( this->GetMaxHp () );
    Is_Character_Dead = false;
}
