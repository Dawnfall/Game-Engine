#pragma once

#include <vector>

#include "GameComponent.h"
#include "Transform.h"
//comented is scene graph

class GameObject
{
public:
	GameObject(){};

	virtual void AddChild(const GameObject& child)
	{
		m_children.push_back(child);
	}
	virtual void AddComponent(const GameComponent& component)
	{
		m_components.push_back(component);
	}
	virtual void Update()
	{

		for (GameComponent& gameComponent : m_components)
			gameComponent.Update();

		for (GameObject& gameObject : m_children)
			gameObject.Update();
	}
	virtual void Render()
	{
		for (GameComponent& gameComponent : m_components)
			gameComponent.Render();

		for (GameObject& gameObject : m_children)
			gameObject.Render();
	}

	~GameObject(){}
private:
	std::vector<GameObject> m_children;
	std::vector<GameComponent> m_components;

};