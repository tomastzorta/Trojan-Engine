#pragma once
#include <vector>
#include <memory>
#include <SDL2/SDL.h>

namespace trojan_engine
{
	struct Entity;

	struct Core
	{
		static std::shared_ptr<Core> initialize();
		void start();
		void stop();
		std::shared_ptr<Entity> addEntity();

	private:
		bool m_running = true;
		
		std::vector<std::shared_ptr<Entity> > m_entities_;
		std::weak_ptr<Core> m_self_;
		SDL_Window* m_window_ = nullptr;
		SDL_GLContext m_context_ = nullptr;
	};

}