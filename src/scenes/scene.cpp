#include "scene.h"

#include <iostream>

using std::cout;


Scene::Scene()
{
	cout << "Se ha creado un scene.\n";
}
Scene::~Scene()
{
	cout << "La scene ha sido eliminada de la memoria.\n";
}

void Scene::update(float deltaTime)
{

}

void Scene::checkMouseCollision(int x, int y)
{

}
