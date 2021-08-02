#pragma once
#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <mutex>
#include <thread>


class Character
{
public:

    ////////    Constructors    ////////

    Character () {} // Without Params
    Character ( bool Is_Good) // With Params, for NPC
    {
        this->Is_Good = Is_Good;
        this->Hp = MaxHp;
        this->Damage *= DamageModify;
        Is_Good ? this->SetName ( "Ally" ) : this->SetName ( "Enemy" );
    }
    Character ( std::string Name, bool Is_Good ) // With PArams, for Hero
    {
        this->Name = Name;
        this->Is_Good = Is_Good;
        this->Hp = MaxHp;
    }
    ////////                    ////////

    ////////    Getters for all variables    ////////

    std::string GetName () { return this->Name; }
    float GetHp () { return this->Hp; }
    float GetMaxHp () { return this->MaxHp; }
    float GetDamage () { return this->Damage; }
    float GetDamageModify () { return this->DamageModify; }
    int32_t GetDelayAttacks () { return this->DelayAttacks; }
    float GetLevelModify () { return this->LevelModify; }       //  ????
    int32_t GetLevel () { return this->Level; }

    bool GetIs_Good () { return this->Is_Good; }
    bool GetIs_Dead () { return this->Is_Dead; }
    ////////                    ////////

    ////////    Methods in Character class  ////////
    
    void virtual PrintStat (); // Prints stats for NPC (for Hero override in Hero class)

    void virtual Attack ( Character& other ); // Duel logic
    bool CheckDeath (); // 
    //void virtual EndGame ();
    //void virtual Kill ( Character& other );

    //void virtual GainEx ( int32_t ExForKillEnemy );
    void virtual LevelModifier ()=0;
    void virtual LevelUp ();

    void virtual RefreshHp ();
    ////////                    ////////

protected:

    ////////    Setters for all variables   ////////

    void SetName ( std::string Name ) { this->Name = Name; }
    void SetHp ( float Hp ) { this->Hp = Hp; }
    void SetMaxHp ( float MaxHp ) { this->MaxHp = MaxHp; }
    void SetDamage ( float Damage ) { this->Damage = Damage; }
    void SetDamageModify ( float DamageModify ) { this->DamageModify = DamageModify; }
    void SetDelayAttacks ( int32_t DelayAttacks ) { this->DelayAttacks = DelayAttacks; }
    void SetLevelModify ( float LevelModify ) { this->LevelModify = LevelModify; }//    ????
    void SetLevel ( int32_t Level ) { this->Level = Level; }

    //void SetIs_Good ( bool Is_good ) { this->Is_Good = Is_Good; }
    void SetIs_Dead ( bool Is_Dead ) { this->Is_Dead = Is_Dead; }
    ////////                    ////////

    ////////    All variables   ////////

    std::string Name;
    float Hp = 0.0f;
    float MaxHp = 100.0f;
    float Damage = 1.0f;
    float DamageModify = 5.0f;
    int32_t DelayAttacks = 20;
    float LevelModify = 1.04f;//    ????
    int32_t Level = 1;

    bool Is_Good = false;
    bool Is_Dead = false;
    ////////                    ////////
};

