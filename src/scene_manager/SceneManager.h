#ifndef SCENE_MANAGER_H
#define SCENE_MANAGER_H

#include "scenes/scene.h"


class SceneManager
{
public:
	SceneManager(Scene* scene);
	~SceneManager();

	static Scene* getActualScene();
	static void chargeNewScene(Scene* newScene);

private:
	static Scene* scene;
};

#endif // !SCENE_MANAGER_H

