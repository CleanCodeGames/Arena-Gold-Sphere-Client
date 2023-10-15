// ▼
#include "Resources.h"

const size_t NumFilesInFolder(cchar* path)
{
	return std::distance(directory_iterator(path), directory_iterator{});
}

sf::Texture* Texture::get(const string& name)
{
	if (auto iter = all_textures_map.find(name); iter != all_textures_map.end()) 
		return iter->second.get();
	return nullptr;
}

sf::Font* Font::get(const string& name)
{
	if (auto iter = all_fonts_map.find(name); iter != all_fonts_map.end())
		return iter->second.get();
	return nullptr;
}

sf::Sound* Sound::get(const string& name)
{
	if (auto iter = all_sounds_map.find(name); iter != all_sounds_map.end())
		return iter->second.second.get();
	return nullptr;
}

sf::Music* Music::get(const string& name)
{
	if (auto iter = all_musics_map.find(name); iter != all_musics_map.end())
		return iter->second.get();
	return nullptr;
}

Shader::Shader()
{
	blink_and_wave.second.loadFromFile("Resources/Shader/blwafl.frag", sf::Shader::Fragment);
	blink_and_wave.first.shader = &blink_and_wave.second;
	blink_and_wave.first.blendMode = sf::BlendMode(sf::BlendMode::One, sf::BlendMode::OneMinusSrcAlpha);
}

Audio::~Audio() {}
Shader::~Shader() {}

Resources::Resources()
{
	auto Paths = serchPaths();
	for (size_t i = 0; i < Paths.size(); ++i) 
		addFile(Paths[i]);

	{
		int size = texture.all_textures_map.size();
		texture.all_textures_map.rehash(size);
	}

	{
		int size = font.all_fonts_map.size();
		font.all_fonts_map.rehash(size);
	}

	{
		int size = audio.sound.all_sounds_map.size();
		audio.sound.all_sounds_map.rehash(size);
	}

	{
		int size = audio.music.all_musics_map.size();
		audio.music.all_musics_map.rehash(size);
	}
}

std::vector<fs::path> Resources::serchPaths()
{
	const fs::path workdir = fs::current_path();
	const fs::path path = workdir / "resources";
	std::vector<fs::path> paths = scanDirectory(path.string());
	return paths;
}

std::vector<fs::path> Resources::scanDirectory(const std::string& pathDir)
{
	std::vector<fs::path> filesA;
	std::vector vec_extensions{ ".png", ".jpg", ".jpeg", ".wav", ".ogg", ".ttf", ".otf" };

	for (std::filesystem::directory_iterator it(pathDir); it != std::filesystem::end(it); it++)
	{
		if (it->is_directory()) 
		{
			std::vector<fs::path> filesB = scanDirectory(it->path().string());

			filesA.insert(std::end(filesA), std::begin(filesB), std::end(filesB));
		}

		for (auto& exp: vec_extensions)
			if (it->path().extension() == exp)
				filesA.push_back(it->path().string());
	}

	return filesA;
}

void Resources::addFile(fs::path path)
{
	std::string name;
	std::string type;
  
	std::string fullname = path.filename().string();
	bool isName = true;

	for (size_t i = 0; i < fullname.size(); ++i) {
		if (isName) {
			if (fullname[i] == '.') {
				isName = false;
				continue;
			}
			else {
				name += fullname[i];
				continue;
			}
		}

		type += fullname[i];
	}

	//texture
	if (type == "png" || type == "jpg" || type == "jpeg") {
		auto newTexture = make_unique<sf::Texture>();
		newTexture->loadFromFile(path.string());
		newTexture->setSmooth(false);
		texture.all_textures_map.insert({ name , move(newTexture) });
	}

	// sound
	if (type == "wav") {
		auto newBuffer = make_unique<sf::SoundBuffer>();
		newBuffer->loadFromFile(path.string());
		auto newSound = make_unique<sf::Sound>();
		newSound->setBuffer(*newBuffer.get());
		std::pair< unique_ptr < sf::SoundBuffer > , unique_ptr < sf::Sound > > x(move(newBuffer), move(newSound));
		audio.sound.all_sounds_map.insert({ name,  move(x) });
	}

	// music
	if (type == "ogg") {
		auto newMusic = make_unique<sf::Music>();
		newMusic->openFromFile(path.string());
		newMusic->setLoop(true);
		audio.music.all_musics_map.insert({ name,  move(newMusic) });
	}

	// font
	if (type == "ttf" || type == "otf") {
		auto newFont = make_unique<sf::Font>();
		newFont->loadFromFile(path.string());
		font.all_fonts_map.insert({ name , move(newFont) });
	}

}

