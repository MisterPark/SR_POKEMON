#pragma once
#include "Character.h"
class Suicune :
    public Character
{
public:
    Suicune();
    Suicune(const Vector3& pos, const Vector3& dir,int lv = 1);
    virtual ~Suicune();

    virtual void Initialize() override;
    virtual void Update() override;
    virtual void Render() override;
    virtual void Release() override;
    virtual bool Attack(const Vector3& dir, const int& attackType) override;

public:
    static Suicune* Create(const Vector3& pos, const Vector3& dir,int lv = 1);

};

