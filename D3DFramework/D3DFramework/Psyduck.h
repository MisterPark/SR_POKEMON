    #pragma once
    #include "Monster.h"
    class Psyduck :
        public Character
    {
    public:
        Psyduck();
        Psyduck(const Vector3& pos, const Vector3& scale, const Vector3& dir);
        virtual ~Psyduck();

        virtual void Initialize() override;
        virtual void Update() override;
        virtual void Render() override;
        virtual void Release() override;

    public:
        virtual void Attack(const Vector3& dir, const int& attackType) override;
        static Psyduck* Create(const Vector3& pos, const Vector3& scale, const Vector3& dir);
    private:
        //void Pattern();
        //void RandomMovePattern();
        //void Attack(Transform* PlayerT);
        //void CreateBullet(Transform* PlayerT);

        bool isPlayer = false;
        bool AttackDelay;
    };

