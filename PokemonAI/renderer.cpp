#include "renderer.h"

Renderer::Renderer() {

}

void Renderer::List(vector<pokemonSeed> vector) {
	SDL_Init(SDL_INIT_VIDEO);

	int screenWidth = int(float(1920) / 1.25); //this "/ 1.25" is specifically bc my screen is set to 125% zoom
	int screenHeight = int(float(1080) / 1.25);

	SDL_Window* window = SDL_CreateWindow("PokeNNetwork", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, screenWidth, screenHeight, SDL_WINDOW_OPENGL);
	SDL_Renderer* renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);

	std::vector<SDL_Surface*> surfaces;
	std::vector<SDL_Texture*> textures;
	std::vector<SDL_Rect> sizes;


	float ratio;
	if (vector.size() < 50)
		ratio = 1;
	else
		ratio = .75; //multiply width by this number to get height
	
	int h = 0;
	int w = 0;
	while (h * w < vector.size()) {
		if (float(w) > float(h) * float(16) / float(9)) {
			h++;
		}
		else {
			w++;
		}
	}

	for (int i = 0; i < vector.size(); i++) {
		SDL_Rect size;
		size.w = min(screenHeight / h, screenWidth / w);
		size.h = min(screenHeight / h, screenWidth / w) * ratio;
		size.x = screenWidth / w * (i % int(w)) + (screenWidth - (size.w * w)) / w / 2;
		size.y = screenHeight / float(h) * int(i % int(pow(max(w, h), 2)) * (float(1) / float(max(w, h)))) + (screenHeight - (size.h * h)) / h / 2;
		sizes.push_back(size);
		if(vector.size() < 50)
			surfaces.push_back(IMG_Load(vector.at(i).GetPoke()->getImg().c_str()));
		else
			surfaces.push_back(IMG_Load(vector.at(i).GetPoke()->getIcon().c_str()));
	}


	for (auto& element : surfaces) {
		textures.push_back(SDL_CreateTextureFromSurface(renderer, element));
		SDL_FreeSurface(element);
	}



	while (true) {
		SDL_Event e;
		if (SDL_WaitEvent(&e)) {
			if (e.type == SDL_QUIT) {
				break;
			}
		}

		SDL_RenderClear(renderer);
		//SDL_SetRenderDrawColor(renderer, 255, 0, 0, 255);
		for (int i = 0; i < textures.size(); i++) {
			SDL_RenderCopy(renderer, textures.at(i), NULL, &sizes.at(i));
			//SDL_RenderDrawRect(renderer, &sizes.at(i));
		}
		SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
		SDL_RenderPresent(renderer);
	}

	SDL_Surface* surface = SDL_CreateRGBSurfaceWithFormat(0, screenWidth, screenHeight, 32, SDL_PIXELFORMAT_ARGB8888);
	SDL_RenderReadPixels(renderer, NULL, SDL_PIXELFORMAT_ARGB8888, surface->pixels, surface->pitch);
	IMG_SavePNG(surface, "imgOutput/strongest.jpg");
	SDL_FreeSurface(surface);


	for (auto& element : textures)
		SDL_DestroyTexture(element);
	SDL_DestroyRenderer(renderer);
	SDL_DestroyWindow(window);
	IMG_Quit();
	SDL_Quit();
}