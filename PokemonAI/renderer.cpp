#include "renderer.h"

Renderer::Renderer() {
	screenWidth = int(float(1920) / 1.25); //this "/ 1.25" is specifically bc my screen is set to 125% zoom
	screenHeight = int(float(1080) / 1.25);

	SDL_Init(SDL_INIT_VIDEO);
	IMG_Init(IMG_INIT_PNG);
	TTF_Init();
}

Renderer::~Renderer() {
	IMG_Quit();
	SDL_Quit();
}

void Renderer::List(vector<pokemonSeed> vector) {
	SDL_Window* window = SDL_CreateWindow("PokeNNetwork", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, screenWidth, screenHeight, SDL_WINDOW_HIDDEN);
	SDL_Renderer* renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);

	std::vector<SDL_Surface*> surfaces;
	std::vector<SDL_Texture*> textures;
	std::vector<SDL_Rect> sizes;

	float ratio;
	if (vector.size() < 52)
		ratio = 1;
	else
		ratio = .75; //multiply width by this number to get height
	
	int h = 0;//these are the dimensions that the images will be arrayed with
	int w = 0;
	while (h * w < vector.size()) {
		if (float(w) > float(h) * float(16) / float(9)) {//16:9 aspect ratio is what we aim for
			h++;
		}
		else {
			w++;
		}
	}

	//allocate the positions for each img
	for (int i = 0; i < vector.size(); i++) {
		SDL_Rect size;
		size.w = min(screenHeight / h, screenWidth / w);
		size.h = min(screenHeight / h, screenWidth / w) * ratio;
		size.x = screenWidth / w * (i % int(w)) + (screenWidth - (size.w * w)) / w / 2;
		size.y = screenHeight / float(h) * int(i % int(pow(max(w, h), 2)) * (float(1) / float(max(w, h)))) + (screenHeight - (size.h * h)) / h / 2;
		sizes.push_back(size);
		if(vector.size() < 52)
			surfaces.push_back(IMG_Load(vector.at(i).GetPoke()->getImg().c_str()));
		else
			surfaces.push_back(IMG_Load(vector.at(i).GetPoke()->getIcon().c_str()));
	}

	//convert the imgs from a surface to a texture
	for (auto& element : surfaces) {
		textures.push_back(SDL_CreateTextureFromSurface(renderer, element));
		SDL_FreeSurface(element);
	}

	/*while (true) {
		SDL_Event e;
		if (SDL_WaitEvent(&e)) {
			if (e.type == SDL_QUIT) {//loop only ends when user closes the window
				break;
			}
		}
	}*/
	SDL_RenderClear(renderer);
	for (int i = 0; i < textures.size(); i++)
		SDL_RenderCopy(renderer, textures.at(i), NULL, &sizes.at(i));
	SDL_RenderPresent(renderer);


	SDL_Surface* surface = SDL_CreateRGBSurfaceWithFormat(0, screenWidth, screenHeight, 32, SDL_PIXELFORMAT_ARGB8888);
	SDL_RenderReadPixels(renderer, NULL, SDL_PIXELFORMAT_ARGB8888, surface->pixels, surface->pitch);
	IMG_SavePNG(surface, "imgOutput/strongest.jpg");
	SDL_FreeSurface(surface);

	for (auto& element : textures)
		SDL_DestroyTexture(element);

	SDL_DestroyRenderer(renderer);
	SDL_DestroyWindow(window);
}

void Renderer::ListLong(vector<pokemonSeed> vector) {
	std::vector<SDL_Surface*> surfaces;
	std::vector<SDL_Texture*> textures;
	std::vector<SDL_Rect> sizes;

	int w = 4;
	int imgEdge = 475;
	while (imgEdge * vector.size() / w > 16000) {//475 is image length, 16384 is max window length
		w *= 2;
		imgEdge /= 2;
	}

	int imgWidth;
	int imgHeight;

	imgWidth = imgEdge * w;
	imgHeight = vector.size() / w * imgEdge;
	if (vector.size() % w > 0)
		imgHeight += imgEdge;

	SDL_Window* imgwindow = SDL_CreateWindow("PokeNNetwork", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, imgWidth, imgHeight, SDL_WINDOW_HIDDEN);
	SDL_Renderer* imgrenderer = SDL_CreateRenderer(imgwindow, -1, SDL_RENDERER_ACCELERATED);

	//allocate the positions for each img
	for (int i = 0; i < vector.size(); i++) {
		SDL_Rect size;
		size.w = imgEdge;
		size.h = imgEdge;
		size.x = i % w * imgEdge;
		size.y = i / w * imgEdge;
		sizes.push_back(size);
		surfaces.push_back(IMG_Load(vector.at(i).GetPoke()->getImg().c_str()));
	}

	//convert the imgs from a surface to a texture
	for (auto& element : surfaces) {
		textures.push_back(SDL_CreateTextureFromSurface(imgrenderer, element));
		SDL_FreeSurface(element);
	}


	SDL_RenderClear(imgrenderer);
	for (int i = 0; i < textures.size(); i++)
		SDL_RenderCopy(imgrenderer, textures.at(i), NULL, &sizes.at(i));
	SDL_RenderPresent(imgrenderer);
	
	SDL_Surface* surface = SDL_CreateRGBSurfaceWithFormat(0, imgWidth, imgHeight, 32, SDL_PIXELFORMAT_ARGB8888);
	SDL_RenderReadPixels(imgrenderer, NULL, SDL_PIXELFORMAT_ARGB8888, surface->pixels, surface->pitch);
	IMG_SavePNG(surface, "imgOutput/strongestlong.jpg");
	SDL_FreeSurface(surface);

	for (auto& element : textures)
		SDL_DestroyTexture(element);

	SDL_DestroyRenderer(imgrenderer);
	SDL_DestroyWindow(imgwindow);
}

void Renderer::ListExtinction(Pokemons* list, int generations) {
	std::vector<SDL_Surface*> surfaces;
	std::vector<SDL_Texture*> textures;
	std::vector<SDL_Rect> sizes;

	TTF_Font* font = TTF_OpenFont("fonts/Gidole-Regular.ttf", 36);

	//icons are 40 * 30; upsize twice for 160 * 120? 1920/160 = 12 icons per row
	int w = 12;
	int imgEdge = 160;
	while (imgEdge * list->numPokes() / w > 4000) {//475 is image length, 16384 is max window length
		w *= 2;
		imgEdge /= 2;
	}

	//allocate the positions for each img
	bool foundGen;
	int foundGenCounter = 0;
	int extinctFound;
	for (int i = 1; i < generations + 1; i++) {
		foundGen = false;
		extinctFound = 0;
		for (int j = 0; j < list->numPokes(); j++) {
			if (list->pokemonAtID(j + 1)->isExtinct() == i) {
				if (!foundGen) {
					foundGen = true;
					string text = "Pokemon that went extinct in gen " + to_string(i);
					SDL_Rect size;
					int width;
					int height;
					TTF_SizeText(font, text.c_str(), &width, &height);
					size.w = width;
					size.h = imgEdge / 4;
					size.x = 0;
					size.y = foundGenCounter * 160;
					sizes.push_back(size);
					surfaces.push_back(TTF_RenderText_Solid(font, text.c_str(), SDL_Color{255, 255, 255, 255}));
				}
				SDL_Rect size;
				size.w = imgEdge;
				size.h = imgEdge / 4 * 3;
				size.x = extinctFound % w * imgEdge;
				size.y = extinctFound / w * imgEdge + foundGenCounter * 160 + imgEdge / 4;
				sizes.push_back(size);
				surfaces.push_back(IMG_Load(list->pokemonAtID(j + 1)->getIcon().c_str()));
				extinctFound++;
				if (extinctFound == 12) {
					foundGenCounter++;
					extinctFound = 0;
				}
			}
		}	
		if (foundGen) {
			foundGenCounter++;
		}
	}

	int imgWidth;
	int imgHeight;

	imgWidth = imgEdge * w;
	imgHeight = foundGenCounter * imgEdge;

	SDL_Window* imgwindow = SDL_CreateWindow("PokeNNetwork", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, imgWidth, imgHeight, SDL_WINDOW_HIDDEN);
	SDL_Renderer* imgrenderer = SDL_CreateRenderer(imgwindow, -1, SDL_RENDERER_ACCELERATED);

	//convert the imgs from a surface to a texture
	for (auto& element : surfaces) {
		textures.push_back(SDL_CreateTextureFromSurface(imgrenderer, element));
		SDL_FreeSurface(element);
	}


	SDL_RenderClear(imgrenderer);
	for (int i = 0; i < textures.size(); i++)
		SDL_RenderCopy(imgrenderer, textures.at(i), NULL, &sizes.at(i));
	SDL_RenderPresent(imgrenderer);

	SDL_Surface* surface = SDL_CreateRGBSurfaceWithFormat(0, imgWidth, imgHeight, 32, SDL_PIXELFORMAT_ARGB8888);
	SDL_RenderReadPixels(imgrenderer, NULL, SDL_PIXELFORMAT_ARGB8888, surface->pixels, surface->pitch);
	IMG_SavePNG(surface, "imgOutput/extinction.jpg");
	SDL_FreeSurface(surface);

	for (auto& element : textures)
		SDL_DestroyTexture(element);

	SDL_DestroyRenderer(imgrenderer);
	SDL_DestroyWindow(imgwindow);
	TTF_CloseFont(font);
}