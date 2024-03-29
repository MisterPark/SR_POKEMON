#pragma once
#include "Character.h"
class Poliwhirl :
    public Character
{
public:
    Poliwhirl();
    Poliwhirl(const Vector3& pos, const Vector3& dir,int lv = 1);
    virtual ~Poliwhirl();

    virtual void Initialize() override;
    virtual void Update() override;
    virtual void Render() override;
    virtual void Release() override;
    virtual bool Attack(const Vector3& dir, const int& attackType) override;

public:
    static Poliwhirl* Create(const Vector3& pos, const Vector3& dir,int lv = 1);

};

