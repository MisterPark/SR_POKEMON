#pragma once
#include "Character.h"
class Darkrai :
    public Character
{
public:
    Darkrai();
    Darkrai(const Vector3& pos, const Vector3& dir, int lv = 1);
    virtual ~Darkrai();

    virtual void Initialize() override;
    virtual void Update() override;
    virtual void Render() override;
    virtual void Release() override;
    virtual bool Attack(const Vector3& dir, const int& attackType) override;

public:
    static Darkrai* Create(const Vector3& pos, const Vector3& dir, int lv = 1);

};

