#pragma once

#include "Window.h"

#include "GLFW\glfw3.h"


namespace Hazel {

	class WindowsWindow : public Window	//window includes Event class
	{
	public:
		WindowsWindow(const WindowProps& props);
		~WindowsWindow();

		void OnUpdate() override;

		inline unsigned int GetWidth() const override { return m_Data.Width; }
		inline unsigned int GetHeight() const override { return m_Data.Height; }

		//Window attributes
		void SetEventCallback(const EventCallBackFn& callback) override { m_Data.EventCallBack = callback; }	//function object seems to contain call to OnEvent function
		void SetVSync(bool enabled) override;
		bool IsVSync() const override;
	private:
		virtual void Init(const WindowProps& props);
		virtual void Shutdown();
	private:
		GLFWwindow* m_Window;

		struct WindowData
		{
			std::string Title;
			unsigned int Width, Height;
			bool VSync;

			EventCallBackFn EventCallBack;
			//The structure probably looks as follows:
			//EventCallBack(Event& event)
			//{
			//	Application* app(this)->OnEvent(event); --might be any event such as windowresize or mousescroll--
			//}	-- event object is probably the placeholder in Application bind
			//void CallBack(WindowsWindow* wind, Event& event)
			//{
			//	wind->
			//}

		};

		WindowData m_Data;

	};

}