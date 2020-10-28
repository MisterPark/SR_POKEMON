#pragma once
#include "Character.h"
class Bullet : public Character
{
public:
	Bullet();
	Bullet(const Vector3& pos, const Vector3& scale, const Vector3& dir, const int& type, const bool& isPlayer);
	virtual ~Bullet();

public:
	virtual void Initialize() override;
	virtual void Update() override;
	virtual void Render() override;
	virtual void Release() override;

public:
	static Bullet* Create(
		const Vector3& pos,
		const Vector3& scale,
		const Vector3& dir,
		const int& type,
		const bool& isPlayer = true);

private:
	Vector3 dir;
	int type;
	bool isPlayer;
};

