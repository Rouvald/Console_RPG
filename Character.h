#pragma once
#include <iostream>
#include <algorithm>
#include <string>
#include <mutex>
#include <thread>

//#include <cmath>

class Character
{
public:
    Character () {}
    Character ( bool Is_Good)
    {
        this->Is_Good = Is_Good;
        this->Hp = MaxHp;
        this->Damage *= DamageModify;
        Is_Good ? this->SetName ( "Ally" ) : this->SetName ( "Enemy");
    }
    Character ( std::string Name, bool Is_Good)
    {
        this->Name = Name;
        this->Is_Good = Is_Good;
        this->Hp = MaxHp;
    }
    float GetHp () { return this->Hp; }
    float GetMaxHp () { return this->MaxHp; }
    float GetEX () { return this->Ex; }
    bool GetIs_Good () { return this->Is_Good; }
    bool GetIs_Dead () { return this->Is_Dead; }
    float GetDamage () { return this->Damage; }
    float GetDamageModify () { return this->DamageModify; }
    int32_t GetDelayAttacks () { return this->DelayAttacks; }
    std::string GetName () { return this->Name; }

    void virtual PrintStat ();

    void virtual Attack ( Character& other );
    void virtual Kill ( Character& other );

    bool CheckLife ();

protected:
    void SetHp ( float Hp ) { this->Hp = Hp; }
    void SetMaxHp ( float MaxHp ) { this->MaxHp = MaxHp; }
    void SetEx ( float Ex ) { this->Ex = Ex; }
    //void SetIs_Good ( bool Is_good ) { this->Is_Good = Is_Good; }
    void SetIs_Dead ( bool Is_Dead ) { this->Is_Dead = Is_Dead; }
    void SetDamage ( float Damage ) { this->Damage = Damage; }
    void SetDamageModify ( float DamageModify ) { this->DamageModify = DamageModify; }
    void SetDelayAttacks ( int32_t DelayAttacks ) { this->DelayAttacks = DelayAttacks; }
    void SetName ( std::string Name ) { this->Name = Name; }

    std::string Name;
    float Hp = 0;
    float MaxHp = 100;
    float Ex = 0;
    float Damage = 1;
    float DamageModify = 5;
    int32_t DelayAttacks = 20;

    bool Is_Good = false;
    bool Is_Dead = false;

};

