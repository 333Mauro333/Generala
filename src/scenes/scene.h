#ifndef SCENE_H
#define SCENE_H

#include "game_manager/game_manager.h"


class Scene
{
private:

public:
	Scene();
	~Scene();

	virtual void init() = 0;
	virtual void update(float deltaTime) = 0;
	virtual void draw(RenderWindow window) = 0;
	virtual void destroy() = 0;
};

#endif // !SCENE_H
