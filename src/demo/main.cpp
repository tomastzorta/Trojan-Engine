#include <trojan_engine/trojanEngine.h>

using namespace trojan_engine;

#undef main
int main()
{
	SDL_SetMainReady();
	std::shared_ptr<Core> core = Core::initialize();

	core->addEntity()->addComponent<Player>();
	core->start();

	return 0;
}