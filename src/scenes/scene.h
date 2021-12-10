#ifndef SCENE_H
#define SCENE_H

#include "game_manager/game_manager.h"


class Scene
{
private:

public:
	Scene();
	virtual ~Scene();

	virtual void init() = 0;
	virtual void update(float deltaTime) = 0;
	virtual void draw() = 0;
	virtual void destroy() = 0;
	virtual void checkClicks(int x, int y) = 0;
	virtual void checkMouseCollision(int x, int y);
};

#endif // !SCENE_H
