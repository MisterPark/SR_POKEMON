#pragma once
#include "Character.h"
class Rapidash :
    public Character
{
public:
    Rapidash();
    Rapidash(const Vector3& pos, const Vector3& dir,int lv = 1);
    virtual ~Rapidash();

    virtual void Initialize() override;
    virtual void Update() override;
    virtual void Render() override;
    virtual void Release() override;
    virtual bool Attack(const Vector3& dir, const int& attackType) override;

public:
    static Rapidash* Create(const Vector3& pos, const Vector3& dir,int lv = 1);


};

