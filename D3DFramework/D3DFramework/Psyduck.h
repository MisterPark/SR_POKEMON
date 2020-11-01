    #pragma once
    #include "Monster.h"
    class Psyduck :
        public Character
    {
    public:
        Psyduck();
        virtual ~Psyduck();

        virtual void Update() override;
        virtual void Render() override;

    private:
        //void Pattern();
        //void RandomMovePattern();
        //void Attack(Transform* PlayerT);
        //void CreateBullet(Transform* PlayerT);

        
        bool AttackDelay;
    };

