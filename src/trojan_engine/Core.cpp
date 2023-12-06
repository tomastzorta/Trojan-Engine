#include "Core.h"
#include "Entity.h"
#include "Resources.h"
#include "Keyboard.h"
#include <SDL2/SDL.h>
#include <rend/rend.h>
#include <stdexcept>

namespace trojan_engine
{
	std::shared_ptr<Core> Core::Initialize()
	{
		auto coreInit = std::make_shared<Core>();
		coreInit->m_self = coreInit;

		coreInit->m_resource = std::make_shared<Resources>();
		coreInit->m_keyboard = std::make_shared<Keyboard>();

		std::cout << "Core initialized with address: " << coreInit.get() << std::endl;

		if (SDL_Init(SDL_INIT_VIDEO) < 0)
		{
			throw std::runtime_error("Failed to initialize SDL");
		}

		coreInit->m_window = SDL_CreateWindow("Trojan Engine", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, 800, 600, SDL_WINDOW_RESIZABLE | SDL_WINDOW_REND);

		if (!coreInit->m_window)
		{
			throw std::runtime_error("Failed to create window");
		}

		coreInit->m_context = SDL_Rend_CreateContext(coreInit->m_window);

		if (!coreInit->m_context)
		{
			throw std::runtime_error("Failed to create OpenGL context");
		}

		return coreInit;
	}
	void Core::Start()
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
				else if (event.type == SDL_KEYDOWN || event.type == SDL_KEYUP)
				{
					Event keyboardEvent{};
					keyboardEvent.key = event.key.keysym.sym;
					keyboardEvent.type = event.type == SDL_KEYDOWN ? Event::KEY_PRESSED : Event::KEY_RELEASED;
					m_keyboard->handleEvent(keyboardEvent);
				}
			}
			for (const auto &m_entity : m_entities)
			{
				m_entity->Tick();
			}

			for (size_t entityIndex = 0; entityIndex < m_entities.size(); entityIndex++)
			{
				if (!m_entities[entityIndex]->Alive())
				{
					m_entities.erase(m_entities.begin() + entityIndex);
					--entityIndex;
				}
			}
			SDL_Rend_ClearWindow(m_window);
			// go through all entity call display
			for (const auto &m_entity : m_entities)
			{
				m_entity->Display();
			}
			SDL_GL_SwapWindow(m_window);

			//clear all pressed and released keys
			m_keyboard->onTick();
		}
			
	}
	void Core::Stop()
	{
		//SDL_DestroyWindow(m_window_);
		//SDL_Quit();
		m_running = false;
	}
	std::shared_ptr<Entity> Core::AddEntity()
	{
		auto newEntity = std::make_shared<Entity>();
		newEntity->m_core = m_self;
		newEntity->m_self = newEntity;

		m_entities.push_back(newEntity);

		std::cout << "Entity added with Core reference: " << (newEntity->m_core.lock() ? "Valid" : "Null") << std::endl;
		return newEntity;
	}

    std::shared_ptr<Resources> Core::GetResources()
    {
        return m_resource;
    }

	std::shared_ptr<Keyboard> Core::GetKeyboard()
	{
		return m_keyboard;
	}
}