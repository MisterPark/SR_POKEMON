#pragma once
#include "Mesh.h"

namespace PKH
{
    class Triangle :
        public Mesh
    {
    public:
        Triangle();
        virtual ~Triangle();

        // Mesh��(��) ���� ��ӵ�

        virtual void Update() override;

		virtual IComponent* Clone() override;
    };


}