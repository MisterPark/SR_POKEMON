#pragma once
#include "Mesh.h"

namespace PKH
{
    class Cube :
        public Mesh
    {
    public:
        Cube();
        virtual ~Cube();

        // Mesh��(��) ���� ��ӵ�

        virtual void Update() override;
        
        virtual IComponent* Clone() override;

    };
}
 