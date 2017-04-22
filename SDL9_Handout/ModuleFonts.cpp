#include "Globals.h"
#include "Application.h"
#include "ModuleTextures.h"
#include "ModuleRender.h"
#include "ModuleFonts.h"

#include<string.h>

// Constructor
ModuleFonts::ModuleFonts() : Module()
{}

// Destructor
ModuleFonts::~ModuleFonts()
{}

// Load new texture from file path
int ModuleFonts::Load(const char* texture_path, const char* characters, uint rows)
{
	int id = -1;

	if(texture_path == nullptr || characters == nullptr || rows == 0)
	{
		LOG("Could not load font");
		return id;
	}

	SDL_Texture* tex = App->textures->Load(texture_path);

	if(tex == nullptr || strlen(characters) >= MAX_FONT_CHARS)
	{
		LOG("Could not load font at %s with characters '%s'", texture_path, characters);
		return id;
	}

	id = 0;
	for(; id < MAX_FONTS; ++id)
		if(fonts[id].graphic == nullptr)
			break;

	if(id == MAX_FONTS)
	{
		LOG("Cannot load font %s. Array is full (max %d).", texture_path, MAX_FONTS);
		return id;
	}

	fonts[id].graphic = tex; // graphic: pointer to the texture
	fonts[id].rows = rows; // rows: rows of characters in the texture
	fonts[id].len = strlen(characters); // len: length of the table

	// TODO 1: Finish storing font data
	
	// table: array of chars to have the list of characters
	strcpy_s(fonts[id].table, characters);
	// row_chars: amount of chars per row of the texture
	fonts[id].row_chars = fonts[id].len/rows;
	// char_w: width of each character
	App->textures->GetSize(fonts[id].graphic, fonts[id].char_w, fonts[id].char_h);
	fonts[id].char_w = fonts[id].char_w / fonts[id].row_chars;
	fonts[id].char_h = fonts[id].char_h / fonts[id].rows;

	
	
	// char_h: height of each character
	
	LOG("Successfully loaded BMP font from %s", texture_path);

	return id;
}

void ModuleFonts::UnLoad(int font_id)
{
	if(font_id >= 0 && font_id < MAX_FONTS && fonts[font_id].graphic != nullptr)
	{
		App->textures->Unload(fonts[font_id].graphic);
		fonts[font_id].graphic = nullptr;
		LOG("Successfully Unloaded BMP font_id %d", font_id);
	}
}

// Render text using a bitmap font
void ModuleFonts::BlitText(int x, int y, int font_id, const char* text) const
{
	if(text == nullptr || font_id < 0 || font_id >= MAX_FONTS || fonts[font_id].graphic == nullptr)
	{
		LOG("Unable to render text with bmp font id %d", font_id);
		return;
	}

	const Font* font = &fonts[font_id];
	SDL_Rect rect;
	uint len = strlen(text);

	rect.w = font->char_w;
	rect.h = font->char_h;
	int a = 0;
	// TODO 2: Find the character in the table and its position in the texture, then Blit

	for(uint i = 0; i < len; ++i)
	{
		for (int j = 0; j < MAX_FONT_CHARS; j++)
		{
			
			if (j != 0 && j%fonts[font_id].row_chars == 0)
			{
				a++;
			}
			if (text[i] == fonts[font_id].table[j])
			{
				rect.x = j*rect.w;
				rect.y = a*rect.h;
				App->render->Blit(fonts[font_id].graphic,x+(i*rect.w), y, &rect,1.0f,false);
				break;
			}
		}
	
	}
}
