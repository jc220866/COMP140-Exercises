#pragma once



class Character
{
public:
	Character();
	Character(const std::string& name, int age, int health, int score);
	~Character();

	void SetName(const std::string& name)
	{
		Name = name;
	};

	const std::string& GetName()
	{
		return Name;
	};

	void BuildTextureFromFont(TTF_Font* currentFont, SDL_Renderer* renderer);

	SDL_Texture * GetTexture()
	{
		return Texture;
	};

private:
	SDL_Texture *Texture;

	std::string Name;
	int Age;
	int Health;
	int Score;
};