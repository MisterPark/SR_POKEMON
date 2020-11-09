#pragma once
#include "Character.h"
class Jynx :
    public Character
{
public:
    Jynx();
    Jynx(const Vector3& pos, const Vector3& dir);
    virtual ~Jynx();

    virtual void Initialize() override;
    virtual void Update() override;
    virtual void Render() override;
    virtual void Release() override;
    virtual bool Attack(const Vector3& dir, const int& attackType) override;

public:
    static Jynx* Create(const Vector3& pos, const Vector3& dir);
};

