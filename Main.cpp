#pragma once
#include "Character.h"
#include "Hero.h"


int main ()
{
    Hero MainHero ( "Punisher228", true );
    MainHero.PrintStat ();
    Character Enemy ( false );
    Enemy.PrintStat ();

    std::cout << "================================" << std::endl;
    //while ( !MainHero.GetIs_Dead () || !Enemy.GetIs_Dead () )
    //{
    //    if ( MainHero.CheckLife() || Enemy.CheckLife()) { break; }
    //    MainHero.Attack ( Enemy );
    //    Enemy.Attack ( MainHero );
    //}
    std::thread ThreadHero ( &Hero::Attack, MainHero, std::ref ( Enemy ) );
    std::thread ThreadNPC ( &Character::Attack, Enemy, std::ref ( MainHero ) );
    ThreadHero.join ();
    ThreadNPC.join ();

    if ( Enemy.GetHp () == 0.0f )
    {
        MainHero.Kill ( Enemy );
    }
    else if ( MainHero.GetHp () == 0.0f )
    {
        Enemy.Kill ( MainHero );
    }
    std::cout << "================================" << std::endl;

    MainHero.PrintStat ();
    Enemy.PrintStat ();

    return 0;
}