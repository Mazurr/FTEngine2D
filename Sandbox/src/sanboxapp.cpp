#include <FTE.h>

class ExampleLayer : public FTE::Layer
{
public:
	ExampleLayer()
		: Layer("Example")
	{
	}

	void OnUpdate() override
	{
		FTE_INFO("ExampleLayer::Update");
	}

	void OnEvent(FTE::Event& event) override
	{
		FTE_TRACE("{0}", event);
	}

};

class Sandbox : public FTE::Application
{
public:
	Sandbox()
	{
		PushLayer(new ExampleLayer());
		PushOverlay(new FTE::ImGuiLayer());
	}

	~Sandbox()
	{

	}
};

FTE::Application* FTE::CreateApplication()
{
	return new Sandbox();
}
