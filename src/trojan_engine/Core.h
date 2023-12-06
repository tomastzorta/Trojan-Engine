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
		static std::shared_ptr<Core> Initialize();
		void Start();
		void Stop();
		std::shared_ptr<Entity> AddEntity();
        std::shared_ptr<Resources> GetResources();
		std::shared_ptr<Keyboard> GetKeyboard();


	private:
		bool m_running = true;
		
		std::vector<std::shared_ptr<Entity> > m_entities;
        std::shared_ptr<Resources> m_resource;
		std::shared_ptr<Keyboard> m_keyboard;


		std::weak_ptr<Core> m_self;
		SDL_Window* m_window = nullptr;
		SDL_GLContext m_context = nullptr;
	};

}
