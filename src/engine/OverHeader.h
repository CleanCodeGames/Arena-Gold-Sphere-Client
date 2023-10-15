#ifndef OVER_HEADER_H
#define OVER_HEADER_H

#define DEV_MODE 1

#include <list>
#include <set>
#include <map>
#include <unordered_map>
#include <memory>
#include <iostream>
#include <fstream>
#include <filesystem>
#include <random>
#include <chrono>
#include <thread>
#include <atomic>

#include <entt/entt.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <SFML/Network.hpp>

static constexpr auto PI = 3.141592f;
static constexpr auto DEG = 57.29582f;
static constexpr auto RAD = 0.017453f;

using sf::UdpSocket;
using sf::TcpSocket;
using sf::Packet;
using sf::Clock;
using sf::Int16;
using sf::Int32;
using sf::Uint16;
using sf::IpAddress;
using sf::Socket;
using sf::Time;
using sf::seconds;
using std::string;
using std::wstring;
using std::vector;
using std::list;
using std::pair;
using std::set;
using std::map;
using std::unordered_map;
using std::unique_ptr;
using std::shared_ptr;
using std::thread;
using std::atomic;
using std::make_shared;
using std::make_unique;
using std::cout;
using std::cerr;
using std::wcout;
using std::endl;
using std::cosf;
using std::sinf;
using std::powf;
using std::sqrtf;
using std::clamp;
using std::to_string;
using std::abs;
using std::fabs;
using std::filesystem::directory_iterator;
namespace fs = std::filesystem;
typedef unsigned int uint;
typedef const uint cuint;
typedef const int cint;
typedef const bool cbool;
typedef const char cchar;
typedef const float cfloat;
typedef const string cstring;
typedef sf::Vector2f v2f;
typedef sf::Vector2i v2i;
typedef const v2f cv2f;
typedef const v2i cv2i;

#endif