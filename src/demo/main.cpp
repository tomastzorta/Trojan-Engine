#include <trojan_engine/trojanEngine.h>

using namespace trojan_engine;

struct Player : Component
{
	void onTick() override
	{
		m_count_++;
		if (m_count_ > 10)
		{
			//getEntity()->kill();
			//getCore()->stop();
		}
        getEntity()->getTransform()->setPosition(glm::vec3(0.0f, 0.0f, -10.0f));
        getEntity()->getTransform()->Rotate(glm::vec3(0.0f, 1.0f, 0.0f));
	}

    void initialize()
    {
        getEntity()->addComponent<TriangleRenderer>();
    }

private:
	int m_count_ = 0;
};

#undef main
int main()
{
	SDL_SetMainReady();
	std::shared_ptr<Core> core = Core::initialize();

	core->addEntity()->addComponent<Player>();
	//core->addEntity()->addComponent<TriangleRenderer>();
	core->start();

	return 0;
}