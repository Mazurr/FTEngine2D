#pragma once

#ifdef  FTE_PLATFORM_WINDOWS

extern FTE::Application* FTE::CreateApplication();

int main(int argc, char** argv)
{
	auto app = FTE::CreateApplication();
	app->Run();
	delete app;
}
#endif //  FTE_PLATFORM_WINDOWS
