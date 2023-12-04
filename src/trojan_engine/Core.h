#pragma once
#include <vector>
#include <memory>
#include <SDL2/SDL.h>

namespace trojan_engine
{
	struct Entity;
    struct Resources;
	struct Keyboard;

	struct Core
	{
		static std::shared_ptr<Core> initialize();
		void start();
		void stop();
		std::shared_ptr<Entity> addEntity();
        std::shared_ptr<Resources> getResources();
		std::shared_ptr<Keyboard> getKeyboard();


	private:
		bool m_running = true;
		
		std::vector<std::shared_ptr<Entity> > m_entities_;
        std::shared_ptr<Resources> m_resource;
		std::shared_ptr<Keyboard> m_keyboard;


		std::weak_ptr<Core> m_self_;
		SDL_Window* m_window_ = nullptr;
		SDL_GLContext m_context_ = nullptr;
	};

}
