// ▼
#ifndef RESOURCES_H
#define RESOURCES_H
#include "OverHeader.h"

class Texture
{
	unordered_map<string, unique_ptr<sf::Texture>> all_textures_map;
	friend class Resources;

public:

	sf::Texture* get(const string& name);
};

class Font
{
	unordered_map<string, unique_ptr<sf::Font>> all_fonts_map;
	friend class Resources;

public:

	sf::Font* get(const string& name);
};

class Sound
{
	unordered_map<string, pair< unique_ptr <sf::SoundBuffer>, unique_ptr <sf::Sound> >> all_sounds_map;

	friend class Resources;

public:

	sf::Sound* get(const string& name);
};

class Music
{
	unordered_map<string, unique_ptr<sf::Music>> all_musics_map;
	friend class Resources;

public:
	sf::Music* get(const string& name);
};

class Audio
{
public:

	Sound sound;
	Music music;

	Audio() = default;
	~Audio();
};

class Shader
{
public:

	pair<sf::RenderStates, sf::Shader> blink_and_wave;

	Shader();
	~Shader();
};


struct Resources
{
	Texture texture;
	Shader shader;
	Audio audio;
	Font font;

	Resources();

private:

	std::vector<fs::path> serchPaths();
	std::vector<fs::path> scanDirectory(const std::string& pathDir);
	void addFile(fs::path path);

};

typedef Resources Content;
typedef Resources Asset;

#endif