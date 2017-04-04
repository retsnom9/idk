#ifndef __MODULESCENESPACE_H__
#define __MODULESCENESPACE_H__

#include "Module.h"

struct SDL_Texture;

class ModuleSceneSpace : public Module
{
public:
	ModuleSceneSpace();
	~ModuleSceneSpace();

	bool Start();
	update_status Update();
	bool CleanUp();

public:
	
	Collider* collider1 = nullptr;
	Collider* collider2 = nullptr;
	Collider* collider3 = nullptr;
	Collider* collider4 = nullptr;
	SDL_Texture* background = nullptr;
	SDL_Texture* stars = nullptr;
};

#endif // __MODULESCENESPACE_H__