#pragma once
#include "Character.h"
#include "Hero.h"


int main ()
{
    Hero MainHero ( "Punisher228", true );
    //MainHero.PrintStat ();
    NPC Enemy ( false );
    int32_t NewEnemyDifficulty;
    std::cout << "Choose enemy difficulty: ";
    std::cin >> NewEnemyDifficulty;
    Enemy.ChangeEnemyDefaultStats ( NewEnemyDifficulty );
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
        }
        else if ( MainHero.CheckDeath ())
        {
            Enemy.Kill ( MainHero );
            MainHero.EndGame ();
            break;
        }

        if ( MainHero.GetLevel () > Enemy.GetLevel () )
        {
            Enemy.LevelUp ();
        }

        std::cout << "Choose enemy difficulty: ";
        std::cin >> NewEnemyDifficulty;
        Enemy.ChangeEnemyDefaultStats ( NewEnemyDifficulty );

        MainHero.RefreshHp ();
        Enemy.RefreshHp ();

        qq++;
    }
    std::cout << "================================" << std::endl;

    MainHero.PrintStat ();
    Enemy.PrintStat ();

    return 0;
}