#ifndef OPTIONS_H
#define OPTIONS_H

#include "scenes/scene.h"


class Options : Scene
{
private:
	RenderWindow* win;

public:
	Options(RenderWindow* window);
	~Options();

	void init() override;
	void update(float deltaTime) override;
	void draw() override;
	void destroy() override;
};

#endif // !OPTIONS_H
