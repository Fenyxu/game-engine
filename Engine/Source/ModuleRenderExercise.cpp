#include "ModuleRenderExercise.h"
#include "ModuleProgram.h"
#include "Application.h"
#include "GL/glew.h"

unsigned vbo;
ModuleProgram* program;
unsigned programId;

ModuleRenderExercise::ModuleRenderExercise()
{
}

ModuleRenderExercise::~ModuleRenderExercise()
{
	DestroyVBO(vbo);
}

bool ModuleRenderExercise::Init()
{
	vbo = CreateTriangleVBO();
	program = App->GetProgram();

	char* vertexShaderSource = program->LoadShaderSource("./../Source/vertex_shader.glsl");
	char* fragmentShaderSource = program->LoadShaderSource("./../Source/fragment_shader.glsl");

	unsigned vertexShaderId = program->CompileShader(GL_VERTEX_SHADER, vertexShaderSource);
	unsigned fragmentShaderId = program->CompileShader(GL_FRAGMENT_SHADER, fragmentShaderSource);

	programId = program->CreateProgram(vertexShaderId, fragmentShaderId);
	return true;
}

update_status ModuleRenderExercise::Update()
{
	App->GetProgram()->RenderVBO(vbo, programId);
	return UPDATE_CONTINUE;
}

// This function must be called one time at creation of vertex buffer
unsigned ModuleRenderExercise::CreateTriangleVBO()
{
	float vtx_data[] = { -1.0f, -1.0f, 0.0f, 1.0f, -1.0f, 0.0f, 0.0f, 1.0f, 0.0f };
	unsigned vbo;
	glGenBuffers(1, &vbo);
	glBindBuffer(GL_ARRAY_BUFFER, vbo); // set vbo active
	glBufferData(GL_ARRAY_BUFFER, sizeof(vtx_data), vtx_data, GL_STATIC_DRAW);
	return vbo;
}
// This function must be called one time at destruction of vertex buffer
void ModuleRenderExercise::DestroyVBO(unsigned vbo)
{
	glDeleteBuffers(1, &vbo);
}
