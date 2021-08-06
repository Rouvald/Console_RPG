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
        std::cout << this->GetName () << " was able to survive. Now u can go on next level " << this->GetLevel () << std::endl << std::endl;
        this->SetEx ( this->GetEX () - this->GetMaxEx () );
        this->LevelUp ();
    }

}

/*void Hero::LevelUp ()
{
    this->SetLevel ( this->GetLevel () + 1 );
    this->LevelModifier ();
}*/

void Hero::LevelModifier ()
{
    std::cout << "Choose level modification for Your Hero:" <<
        "\n1. +20 Maximum Health.(print 'health')" <<
        "\n2. +3 Damage.(print 'damage')" <<
        "\n3. -2 Delay Attacks. (print 'delay')" << std::endl;

    std::string tmpMofication;
    std::cin >> tmpMofication;

    std::cout << std::endl;

    LevelModification EnumLevelModification = Convert ( tmpMofication );
    do
    {
        switch ( EnumLevelModification )
        {
            case LevelModification::health:
            this->SetMaxHp ( this->GetMaxHp () + LevelHealthModification );
            break;

            case LevelModification::damage:
            this->SetDamage ( this->GetDamage () + LevelDamageModification );
            break;

            case LevelModification::delay:
            this->SetDelayAttacks ( this->GetDelayAttacks () - LevelDelayAttacksModification );
            break;

            case LevelModification::error:
            std::cout << "Wrong level modification's name! Write correct level modification: ";

            std::cin >> tmpMofication;
            std::cout << std::endl;
            EnumLevelModification = Convert ( tmpMofication );
            break;
        }
    } while ( EnumLevelModification == LevelModification::error );
}

LevelModification Hero::Convert ( const std::string& str )
{
    if ( str == "health" ) { return LevelModification::health; }
    else if ( str == "damage" ) { return LevelModification::damage; }
    else if ( str == "delay" ) { return LevelModification::delay; }
    return LevelModification::error;
}

void Hero::HeroKillEnemy ( NPC& other )
{
    std::cout << std::endl << this->GetName () << " kill " << other.GetName () << std::endl << std::endl;
    this->GainEx ( ExUp [other.GetEnemyDifficulty ()] );
    //this->SetEnemyDifficulty ( other.GetEnemyDifficulty () );//////////////////////////////////////////////////////////////
}

void Hero::EndGame ()
{
    std::cout << "\n==========GAME OVER==========\n" << std::endl;
}
