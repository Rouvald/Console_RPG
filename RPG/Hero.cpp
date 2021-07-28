#include "Hero.h"

void Hero::PrintStat ()
{
    std::cout << this->GetName () << " stat:    Hp: " << GetHp () << "\tDamage: " << GetDamage () <<"\tEx: "<<this->GetEX() << "\tLevel: " << this->GetLevel () << std::endl;
}

void Hero::LevelUp ()
{
    this->SetEx ( this->GetEX () + ExUp [this->GetEnemyDifficult ()] );
    if ( this->GetEX () >= this->GetMaxEx() )
    {
        this->SetEx ( this->GetEX () - this->GetMaxEx() );
        this->SetLevel ( ++this->GetLevel () );
        std::cout << this->GetName () << " was able to survive. Now u can go on next level " << this->GetLevel () << std::endl << std::endl;
    }

}

void Hero::EndGame ()
{
    std::cout << "\n==========GAME OVER==========\n" << std::endl;
}
