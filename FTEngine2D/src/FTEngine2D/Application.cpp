#include "Application.h"
#include "Events/ApplicationEvent.h"
#include "Log.h"

namespace FTE {
	
	Application::Application()
	{
		WindowResizeEvent e(1280, 720);
		if (e.IsInCategory(EventCategoryApplication))
		{
			FTE_TRACE(e);
		}
		if (e.IsInCategory(EventCategoryInput))
		{
			FTE_TRACE(e);
		}
	}

	Application::~Application()
	{
	}

	void Application::Run()
	{
		while (true);
	}
}