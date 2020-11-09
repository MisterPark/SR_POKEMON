#pragma once
#include "Character.h"
class Slugma :
    public Character
{
public:
    Slugma();
    Slugma(const Vector3& pos, const Vector3& dir);
    virtual ~Slugma();

    virtual void Initialize() override;
    virtual void Update() override;
    virtual void Render() override;
    virtual void Release() override;
    virtual bool Attack(const Vector3& dir, const int& attackType) override;

public:
    static Slugma* Create(const Vector3& pos, const Vector3& dir);


};

