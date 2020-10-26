#pragma once
#include "Character.h"

namespace PKH
{
	class CubeMan :
		public Character
	{
	public:

		CubeMan();
		virtual ~CubeMan();

		virtual void Update() override;
		virtual void Initialize() override;
		virtual void Release() override;
	};

}

