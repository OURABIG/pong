#include <iostream>
#include <cmath>
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include "input.hpp"

const int WIN_WIDTH = 800;
const int WIN_HEIGHT = 600;

using namespace sf;
using namespace std;

void SetText(Text& txt, String str);
void CheckBtn();
void UpdateBall();
void Airaquet();