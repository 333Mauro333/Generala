#include "SceneManager.h"

#include <iostream>

using std::cout;


SceneManager::SceneManager(Scene* scene)
{
	this->scene = scene;

	cout << "Se ha creado un SceneManager.\n";
}
SceneManager::~SceneManager()
{
	cout << "El SceneManager ha sido eliminado de la memoria.\n";
}

Scene* SceneManager::getActualScene()
{
	return scene;
}
void SceneManager::chargeNewScene(Scene* newScene)
{
	scene->destroy();

	scene = newScene;

	scene->init();
}
