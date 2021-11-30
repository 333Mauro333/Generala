#include "scene_manager.h"

#include <iostream>

using std::cout;


Scene* SceneManager::scene = NULL;

Scene* SceneManager::getActualScene()
{
	return scene;
}
void SceneManager::chargeNewScene(Scene* newScene)
{
	if (scene != NULL)
	{
		scene->destroy();
	}

	scene = newScene;

	scene->init();
}
