#pragma once
#include "Character.h"
#include "Hero.h"


int main ()
{
    Hero MainHero ( "Punisher228", true );
    //MainHero.PrintStat ();
    NPC Enemy ( false );
    Enemy.ChangeEnemyDefaultStats ();
    //Enemy.PrintStat ();

    std::cout << "================================" << std::endl;
    //while ( !MainHero.GetIs_Dead () || !Enemy.GetIs_Dead () )
    //{
    //    if ( MainHero.CheckLife() || Enemy.CheckLife()) { break; }
    //    MainHero.Attack ( Enemy );
    //    Enemy.Attack ( MainHero );
    //}
    int qq = 0;
    while ( qq < 3 )
    {
        MainHero.PrintStat ();
        Enemy.PrintStat ();
        std::thread ThreadHero ( &Hero::Attack, MainHero, std::ref ( Enemy ) );
        std::thread ThreadNPC ( &NPC::Attack, Enemy, std::ref ( MainHero ) );
        ThreadHero.join ();
        ThreadNPC.join ();

        if ( Enemy.CheckDeath () )
        {
            MainHero.HeroKillEnemy ( Enemy );
            //MainHero.GainEx ();
        }
        else if ( MainHero.CheckDeath ())
        {
            Enemy.Kill ( MainHero );
            MainHero.EndGame ();
            break;
        }

        //MainHero.CheckDeath () ? MainHero.EndGame () : MainHero.GainEx ();

        if ( MainHero.GetLevel () > Enemy.GetLevel () )
        {
            Enemy.LevelUp ();
        }
        MainHero.RefreshHp ();
        Enemy.RefreshHp ();

        qq++;
    }
    std::cout << "================================" << std::endl;

    MainHero.PrintStat ();
    Enemy.PrintStat ();

    return 0;
}