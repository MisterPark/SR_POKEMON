#pragma once
#include "Mesh.h"

namespace PKH
{
    class Rectangle :
        public Mesh
    {
    public:
        Rectangle();
        virtual ~Rectangle();

        // Mesh��(��) ���� ��ӵ�

        virtual void Update() override;

        virtual IComponent* Clone() override;
    };
}
