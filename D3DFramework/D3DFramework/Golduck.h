#pragma once
#include "Character.h"
class Golduck :
    public Character
{
public:
    Golduck();
    Golduck(const Vector3& pos, const Vector3& dir);
    virtual ~Golduck();

    virtual void Initialize() override;
    virtual void Update() override;
    virtual void Render() override;
    virtual void Release() override;
    virtual bool Attack(const Vector3& dir, const int& attackType) override;

public:
    static Golduck* Create(const Vector3& pos, const Vector3& dir);


};

