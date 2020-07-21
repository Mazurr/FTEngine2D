#pragma once

#include "Core.h"

namespace FTE {
	class FTE_API Application
	{
	public:
		Application();
		virtual ~Application();
		void Run();
	};

	// To be defined in CLIENT
	Application* CreateApplication();
}
