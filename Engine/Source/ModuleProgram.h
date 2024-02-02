#pragma once
#include "Module.h"
#include "Globals.h"

class ModuleProgram : public Module
{
public:
	ModuleProgram();
	~ModuleProgram();

	bool Init();
	//update_status PreUpdate();
	update_status Update();
	//update_status PostUpdate();

	unsigned CreateProgram(unsigned vtx_shader, unsigned frg_shader);
	unsigned CompileShader(unsigned type, const char* source);
	char* LoadShaderSource(const char* shader_file_name);
	void RenderVBO(unsigned vbo, unsigned program);
};