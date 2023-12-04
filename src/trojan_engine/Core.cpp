#include "Core.h"
#include "Entity.h"
#include "Resources.h"
#include <SDL2/SDL.h>
#include <rend/rend.h>
#include <stdexcept>

namespace trojan_engine
{
	std::shared_ptr<Core> Core::initialize()
	{
		std::shared_ptr<Core> rtn = std::make_shared<Core>();

		rtn->m_resource = std::make_shared<Resources>();
		rtn->m_self_ = rtn;

		if (SDL_Init(SDL_INIT_VIDEO) < 0)
		{
			throw std::runtime_error("Failed to initialize SDL");
		}

		rtn->m_window_ = SDL_CreateWindow("Trojan Engine", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, 800, 600, SDL_WINDOW_RESIZABLE | SDL_WINDOW_REND);

		if (!rtn->m_window_)
		{
			throw std::runtime_error("Failed to create window");
		}

		rtn->m_context_ = SDL_Rend_CreateContext(rtn->m_window_);

		if (!rtn->m_context_)
		{
			throw std::runtime_error("Failed to create OpenGL context");
		}
		
		return rtn;
	}
	void trojan_engine::Core::start()
	{
		SDL_Event event = {0};

		while (m_running)
		{
			while (SDL_PollEvent(&event))
			{
				if (event.type == SDL_QUIT)
				{
					m_running = false;
				}
			}
			for (size_t ei = 0; ei < m_entities_.size(); ei++)
			{
				m_entities_[ei]->tick();
			}

			for (size_t ei = 0; ei < m_entities_.size(); ei++)
			{
				if (!m_entities_[ei]->alive())
				{
					m_entities_.erase(m_entities_.begin() +ei);
					--ei;
				}
			}
			SDL_Rend_ClearWindow(m_window_);
			// go through all entity call display
			for (size_t ei = 0; ei < m_entities_.size(); ei++)
			{
				m_entities_[ei]->display();
			}
			SDL_GL_SwapWindow(m_window_);
		}
			
	}
	void trojan_engine::Core::stop()
	{
		//SDL_DestroyWindow(m_window_);
		//SDL_Quit();
		m_running = false;
	}
	std::shared_ptr<Entity> Core::addEntity()
	{
		std::shared_ptr<Entity> rtn = std::make_shared<Entity>();

		rtn->m_core = m_self_;
		rtn->m_self = rtn;

		m_entities_.push_back(rtn);

		return rtn;
	}

    std::shared_ptr<Resources> Core::getResources()
    {
        return m_resource;
    }
}