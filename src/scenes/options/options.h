#ifndef OPTIONS_H
#define OPTIONS_H

#include "scenes/scene.h"


class Options : Scene
{
private:


public:
	Options();
	~Options();

	void init() override;
	void update(float deltaTime) override;
	void draw(RenderWindow window) override;
	void destroy() override;
};

#endif // !OPTIONS_H