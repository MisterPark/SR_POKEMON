    #pragma once
    #include "Character.h"
    class Psyduck :
        public Character
    {
    public:
        Psyduck();
        Psyduck(const Vector3& pos, const Vector3& dir);
        virtual ~Psyduck();

        virtual void Initialize() override;
        virtual void Update() override;
        virtual void Render() override;
        virtual void Release() override;
        virtual bool Attack(const Vector3& dir, const int& attackType) override;

    public:
		static Psyduck* Create(const Vector3& pos, const Vector3& dir);

    };

