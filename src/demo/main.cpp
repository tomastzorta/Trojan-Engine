#include <trojan_engine/trojanEngine.h>

using namespace trojan_engine;

#undef main
int main()
{
	SDL_SetMainReady();
	const std::shared_ptr<Core> core = Core::Initialize();

	core->AddEntity()->AddComponent<Player>();
	const auto texture = core->GetResources()->Load<Texture>("trojan_engine/image.jpg");

	if (!texture) {
		std::cerr << "Failed to load texture" << std::endl;
		return -1;
	}

	core->Start();
	return 0;
}