#pragma once
#include "Module.h"
#include "Globals.h"

class ModuleRenderExercise : public Module
{
public:
	ModuleRenderExercise();
	~ModuleRenderExercise();

	bool Init();
	update_status Update();

	unsigned CreateTriangleVBO();
	void DestroyVBO(unsigned vbo);
};