#include <FTE.h>

class Sandbox : public FTE::Application
{
public:
	Sandbox()
	{

	}

	~Sandbox()
	{

	}
};

FTE::Application* FTE::CreateApplication()
{
	return new Sandbox();
}
