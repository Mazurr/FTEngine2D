#pragma once

#include "Core.h"
#include "FTEngine2D/Events/Event.h"
#include "FTEngine2D/Events/ApplicationEvent.h"
#include "FTEngine2D/LayerStack.h"
#include "FTEngine2D/Events/Event.h"
#include "FTEngine2D/Events/ApplicationEvent.h"
#include "Window.h"

namespace FTE {
	class FTE_API Application
	{
	public:
		Application();
		virtual ~Application();
		
		void Run();
		void OnEvent(Event& e);
		void PushLayer(Layer* layer);
		void PushOverlay(Layer* layer);
	private:
		bool OnWindowClose(WindowCloseEvent& e);

		std::unique_ptr<Window> m_Window;
		bool m_Running = true;
		LayerStack m_LayerStack;
	};

	// To be defined in CLIENT
	Application* CreateApplication();
}
