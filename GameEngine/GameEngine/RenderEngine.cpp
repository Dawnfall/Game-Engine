#include "RenderEngine.h"

#include <gl/glew.h>
#include <glm/glm.hpp>

#include "Game.h"
#include "GameObject.h"
#include "GameComponent.h"
#include "TestState.h"

void RenderEngine::InitGraphics()
{
	//glew initialization
	if (glewInit() != GLEW_OK)
		std::cerr << "Error! GLEW initialization failure! " << std::endl;

	glClearColor(0.2f, 0.3f, 0.8f, 1.0f);

	glFrontFace(GL_CCW);
	glCullFace(GL_BACK);
	glEnable(GL_CULL_FACE);

	glEnable(GL_DEPTH_TEST);
	//TODO: depth clamping

	glEnable(GL_FRAMEBUFFER_SRGB);
}

void RenderEngine::Render(Game* game)
{
	//***clearing
	Clear();

	if (game->GetState() == nullptr)
		return;

	




}


void RenderEngine::Clear() const
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
}

void RenderEngine::SetClearColor(const glm::vec4& clearColor) const
{
	glClearColor(clearColor.r, clearColor.g, clearColor.b, clearColor.a);
}