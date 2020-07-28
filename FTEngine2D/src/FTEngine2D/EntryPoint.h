#pragma once

#ifdef  FTE_PLATFORM_WINDOWS

extern FTE::Application* FTE::CreateApplication();

int main(int argc, char** argv)
{
	FTE::Log::Init();
	FTE_CORE_WARN("Initialized Log!");
	int a = 5;
	FTE_INFO("Hello! var={0}", a);

	auto app = FTE::CreateApplication();
	app->Run();
	delete app;
}
#endif //  FTE_PLATFORM_WINDOWS
