#pragma once

#include <glfw/glfw3.h>

#define SECOND 1000000000L

class Time
{
public:
	inline static double GetTime(){ return glfwGetTime(); }
	inline static double GetDelta(){ return delta; };
	void static SetDelta(double newDelta){ Time::delta = newDelta; }

private:
	static double delta;
};