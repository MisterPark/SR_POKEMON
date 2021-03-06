#pragma once
#include "Character.h"
class Poliwag :
    public Character
{
public:
    Poliwag();
    Poliwag(const Vector3& pos, const Vector3& dir,int lv = 1);
    virtual ~Poliwag();

    virtual void Initialize() override;
    virtual void Update() override;
    virtual void Render() override;
    virtual void Release() override;
    virtual bool Attack(const Vector3& dir, const int& attackType) override;

public:
    static Poliwag* Create(const Vector3& pos, const Vector3& dir,int lv = 1);

};

