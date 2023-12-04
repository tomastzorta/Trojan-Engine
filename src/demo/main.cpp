#include <trojan_engine/trojanEngine.h>

using namespace trojan_engine;

#undef main
int main()
{
	SDL_SetMainReady();
	const std::shared_ptr<Core> core = Core::initialize();

	core->addEntity()->addComponent<Player>();
	core->getResources()->load<Texture>("trojan_engine/image.jpg");


	core->start();
	return 0;
}