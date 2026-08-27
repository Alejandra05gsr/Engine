#pragma once
#include <unordered_map>
#include "raylib.h"
#include <string>

namespace kai
{
	class ResourcesManager
	{
	public:
		static ResourcesManager& get() {
			static ResourcesManager rm;
			return rm;
		}

		Texture2D& getTexture(const std::string& file)
		{
			//La ruta completa
			std::string fullPath = texturePath + file;


			//Busco que la fuente este cargada
			auto it = textures.find(fullPath); //Se llama desde el hashmap, devuelve un iterador y le paso el path completo a la textura que estoy buscando

			
			//Si no esta cargada
			if (it != textures.end())
			{
				return it->second;
			}



			//Si existe la cargo y devuelvo la fuente
			if (!FileExists(fullPath.c_str()))
			{
				std::string msg = "No se encontró textura: " + fullPath;
				TraceLog(LOG_WARNING, msg.c_str());
				Texture2D tex;
				return tex;
			}

			textures[fullPath] = LoadTexture(fullPath.c_str());

			return textures[fullPath];


		}


		//Ejemplo de cargar fuente: Font font = LoadFontEx("resources/KAISG.ttf", 96, 0, 0);
		//Ejemplo de dibujar fuente: DrawTextEx(font, msg, fontPosition, fontSize, 0, BLACK);

		Font& getFont(const std::string& file)
		{
			//La ruta completa
			std::string fullPath = fontPath + file;


			//Busco que la fuente este cargada
			auto it = fonts.find(fullPath);


			//Si no esta cargada
			if (it != fonts.end())
			{
				return it->second;
			}

			//Busco que exista el archivo
			if (!FileExists(fullPath.c_str()))
			{
				std::string msg = "No se encontró fuente: " + fullPath;
				TraceLog(LOG_WARNING, msg.c_str());
				Font font;
				return font;
			}

			//Si existe la cargo y devuelvo la fuente
			fonts[fullPath] = LoadFontEx(fullPath.c_str(), 16, 0, 0); //Nombre, tamaño
			return fonts[fullPath];

		}



		Sound& getSound(const std::string& file)
		{
			//La ruta completa
			std::string fullPath = soundPath + file;


			//Busco que la fuente este cargada
			auto it = sounds.find(fullPath);


			//Si no esta cargada
			if (it != sounds.end())
			{
				return it->second;
			}

			//Busco que exista el archivo
			if (!FileExists(fullPath.c_str()))
			{
				std::string msg = "No se encontró sonido: " + fullPath;
				TraceLog(LOG_WARNING, msg.c_str());
				Sound snd;
				return snd;
			}

			//Si existe la cargo y devuelvo la fuente
			sounds[fullPath] = LoadSound(fullPath.c_str());
			return sounds[fullPath];

		}

		Music& getMusic(const std::string& file)
		{
			//La ruta completa
			std::string fullPath = musicPath + file;


			//Busco que la fuente este cargada
			auto it = music.find(fullPath);


			//Si no esta cargada
			if (it != music.end())
			{
				return it->second;
			}

			//Busco que exista el archivo
			if (!FileExists(fullPath.c_str()))
			{
				std::string msg = "No se encontró la musica: " + fullPath;
				TraceLog(LOG_WARNING, msg.c_str());
				Music msc;
				return msc;
			}

			//Si existe la cargo y devuelvo la fuente
			music[fullPath] = LoadMusicStream(fullPath.c_str()); //Cargo la musica
			return music[fullPath];

		}


	private:
		//Texturas
		std::unordered_map <std::string, Texture2D> textures;
		std::string texturePath = "textures/";

		//Fuentes
		std::unordered_map <std::string, Font> fonts;
		std::string fontPath = "fonts/";

		//Sonidos
		std::unordered_map <std::string, Sound> sounds;
		std::string soundPath = "sounds/";

		//Musica (Se carga diferente)
		std::unordered_map <std::string, Music> music;
		std::string musicPath = "music/";


	};
}