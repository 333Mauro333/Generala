#ifndef CREDITS_H
#define CREDITS_H

#include "scenes/scene.h"


class Credits : Scene
{
private:


public:
	Credits();
	~Credits();

	void init() override;
	void update(float deltaTime) override;
	void draw() override;
	void destroy() override;
};

#endif // !CREDITS_H
