#include "Renderer.h"

void Renderer::AddDrawable(Drawable* drawable)
{
	drawables.push_back(drawable);
}

void Renderer::Render(RenderWindow* window)
{
	window->clear();
	for (auto* list : drawables) {
		window->draw(*list);
	}
	window->display();
}
