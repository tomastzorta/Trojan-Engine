#include <trojan_engine/trojanEngine.h>
#include "Player.h"
using namespace trojan_engine;

#undef main
int main()
{
	SDL_SetMainReady();
	const std::shared_ptr<Core> core = Core::Initialize();

	core->AddEntity()->AddComponent<Player>();

	core->Start();
	return 0;
}