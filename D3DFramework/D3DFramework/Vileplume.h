#pragma once
#include "Character.h"
class Vileplume :
    public Character
{
public:
    Vileplume();
    Vileplume(const Vector3& pos, const Vector3& dir,int lv = 1);
    virtual ~Vileplume();

public:
    virtual void Initialize() override;
    virtual void Update() override;
    virtual void Render() override;
    virtual void Release() override;
    virtual bool Attack(const Vector3& dir, const int& attackType) override;

public:
    static Vileplume* Create(const Vector3& pos, const Vector3& dir,int lv = 1);


};


