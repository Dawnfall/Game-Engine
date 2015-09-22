#pragma once

#include "Game.h"

class RenderEngine
{
public:
	void Render(Game* object);
	void InitGraphics();
	void Clear() const;
	void SetClearColor(const glm::vec4& clearColor) const;

private:
	void RenderObject(const GameObject& object);
	
};