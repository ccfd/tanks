#include "App.h"
#include "Resources.h"
#include "LiveTank.h"
#include "Bullet.h"
#include "Obstacle.h"
#include "Factory.h"
#include <assert.h>
#include <stdio.h>

App::App(const Strings& arg) : back(resources.back) {
	fps = 24;
	fullScreen = false;
	mute = false;
	timeLimit = 86400.0;
	graphics = true;
	extents = false;
	int obstacles=0;
	for (Strings::const_iterator it = arg.begin(); it != arg.end(); it++) {
		if (*it == "-f") {
			fullScreen = true;
		} else if (*it == "-m") {
			mute = true;
		} else if (*it == "-e") {
			extents = true;
		} else if (*it == "-x") {
			extents = true;
			graphics = false;
		} else if (*it == "-t") {
			it++;
			if (it == arg.end()) throw "No time provided after -t";
			timeLimit = std::atof(it->c_str());
		} else if (*it == "-o") {
			it++;
			if (it == arg.end()) throw "No number provided after -o";
			obstacles = std::atoi(it->c_str());
		} else if (*it == "-fps") {
			it++;
			if (it == arg.end()) throw "No fps provided after -fps";
			fps = std::atof(it->c_str());
		} else {
			int number;
			std::string name;
			int pos = it->find_first_of(':');
			if (pos == std::string::npos) {
				name = *it;
				number = 1;
			} else {
				std::string first = it->substr(pos+1);
				number = std::atof(first.c_str());
				if (number <= 0) throw "Need at least one tank per player";
				if (number > 50) throw "Max 50 tanks per player";
				name = it->substr(0, pos);
			}
			printf("Requested %d tanks for %s player\n", number, name.c_str());
			playerNames.push_back(name);
			playerTanks.resize(number);
		}
	}
	sf::ContextSettings settings;
	settings.antialiasingLevel = 8;
	if (fullScreen) {
		window = new sf::RenderWindow(sf::VideoMode(1280, 720), "Objects", sf::Style::Fullscreen, settings);
	} else {
		window = new sf::RenderWindow(sf::VideoMode(1280, 720), "Objects", sf::Style::Default, settings);
	}		
	window->setFramerateLimit(fps);
	window->setVerticalSyncEnabled(true);
	if (mute) sf::Listener::setGlobalVolume(0.0);
	back.scale(gscale,gscale);
	hit.setBuffer(resources.hitbuffer);
	if (playerNames.size() < 2) playerNames.push_back("KeyboardPlayer");
	if (playerNames.size() < 2) playerNames.push_back("SimpleBot");
	Player * player;
	int tankNumber = 0;
	const double pi = atan(1.0)*4;
	double tankAngle = 2*pi/playerNames.size();
	for (Strings::iterator it = playerNames.begin(); it != playerNames.end(); it++) {
		player = PlayerFactory::Produce(*it);
		printf("Adding player: %s\n",it->c_str());
		if (player == NULL) err("Player not found");
		double a = tankAngle * tankNumber + 0.5*tankAngle*rand()/RAND_MAX;
		double rb = 2*pi*rand()/RAND_MAX;
		objects.push_back(new LiveTank(player, gscale*(960+cos(a)*400),gscale*(540+sin(a)*400),rb,rb, *it));
		tankNumber++;
	}
	{
		Polygon poly;
		poly.push_back(Point(1510*gscale,    90*gscale));
		poly.push_back(Point(1576*gscale,    46*gscale));
		poly.push_back(Point(1719*gscale,   814*gscale));
		poly.push_back(Point(1663*gscale,   817*gscale));
		poly.push_back(Point(1573*gscale,   318*gscale));
		poly.push_back(Point(1558*gscale,   319*gscale));
		poly.tag = TAG_OBSTACLE;
		objects.push_back(new Obstacle(poly));
	}
	{
		Polygon poly;
		poly.push_back(Point( 150*gscale,    96*gscale));
		poly.push_back(Point(1071*gscale,     0*gscale));
		poly.push_back(Point(1627*gscale,     0*gscale));
		poly.push_back(Point(1828*gscale,  1002*gscale));
		poly.push_back(Point(1204*gscale,  1080*gscale));
		poly.push_back(Point( 202*gscale,  1080*gscale));
		poly.tag = TAG_OBSTACLE;
		poly.insideout = true;
		objects.push_back(new Obstacle(poly));
	}
	for (int i=0; i<obstacles; i++) {
		Obstacle * obst;
		for (int i = 0; i < 20; i++) {
			Polygon poly;
			double x = (1100.0*rand()/RAND_MAX + 360)*gscale;
			double y = (800.0*rand()/RAND_MAX + 140)*gscale;
			double a = 3.14*rand()/RAND_MAX;
			poly.push_back(Point(x+20*cos(a),y+20*sin(a)));
			poly.push_back(Point(x+20*sin(a),y-20*cos(a)));
			poly.push_back(Point(x-20*cos(a),y-20*sin(a)));
			poly.push_back(Point(x-20*sin(a),y+20*cos(a)));
			poly.tag = TAG_OBSTACLE;
			obst = new Obstacle(poly,sf::Color(125, 32, 54));
			if (GetCollision(obst).size() == 0) {
				objects.push_back(obst);
				break;
			}
			delete obst; 
		}
	}		
	clockText.setFont(resources.regular);
	clockText.setCharacterSize(24*5); // in pixels, not points!
	clockText.setScale(0.2,0.2);
	clockText.setColor(sf::Color::Blue);
	clockText.setStyle(sf::Text::Bold);
	clockText.setPosition(sf::Vector2f(640,360));
}

void App::Draw() {
	window->draw(back);
	for (Objects::iterator t = objects.begin(); t != objects.end(); t++) (*t)->Draw(this,window);
	for (Objects::iterator t = bullets.begin(); t != bullets.end(); t++) (*t)->Draw(this,window);
	if (Time < prepTime + 1) {
		char str[256];
		double t = prepTime + 1 - Time;
		double it = floor(t);
		double w = t - it;
		w = 1.0*(1-w) + 0.2*w;
		if (it > 0.0) {		
			sprintf(str, "%.0f", it);
			clockText.setString(str);
		} else {
			clockText.setString("START");
		}
		clockText.setScale(w,w);
		sf::FloatRect bounds = clockText.getLocalBounds();
		clockText.setOrigin(bounds.width/2,bounds.height);
		sf::Color color(0, 0, 128, 255*(1-w));
		clockText.setColor(color);
		window->draw(clockText);
	} else if (timeLimit - Time < 1200) {
		static bool first = true;
		if (first) {
			clockText.setCharacterSize(24);
			clockText.setScale(1,1);
			clockText.setOrigin(0,0);
			sf::Color color(0, 0, 128, 128);
			clockText.setColor(color);
			clockText.setPosition(160,670);
			first = false;
		}
		char str[256];
		double t = timeLimit - Time;
		double it = floor(t);
		double mt = floor(t/60);
		double st = it - mt*60;
		sprintf(str, "Time left: %.0f:%02.0f", mt, st);
		clockText.setString(str);
		window->draw(clockText);
	}
}

void App::DrawExtents() {
	for (Objects::iterator t = objects.begin(); t != objects.end(); t++) (*t)->DrawExtents(this,window);
	for (Objects::iterator t = bullets.begin(); t != bullets.end(); t++) (*t)->DrawExtents(this,window);
}

void App::DrawPoly(const Polygon& ext, const sf::Color& color) {
		std::vector<sf::Vertex> sfPoly;
		for (Polygon::const_iterator p = ext.begin(); p != ext.end(); p++) {
			sfPoly.push_back(sf::Vertex(*p, color));
		}
		{
			Polygon::const_iterator p = ext.begin();
			sfPoly.push_back(sf::Vertex(*p, color));
		}
		window->draw(&sfPoly[0], sfPoly.size(), sf::LinesStrip);
}


void App::AddObject(Object * obj) {
	objects.push_back(obj);
}

void App::AddBullet(Object * obj) {
	bullets.push_back(obj);
}

App::Objects App::GetCollision(Object * obj) {
	Objects ret;
	Polygon me = obj->Extent();
	for (Objects::iterator t = objects.begin(); t != objects.end(); t++) if (obj != (*t)) {
		Polygon ext = (*t)->Extent();
		//			bool inside = me.intersect(ext);
		bool inside = ext.intersect(me);
		assert(me.intersect(ext) == ext.intersect(me));
		if (inside) {
			ret.push_back(*t);
		}
	}
	return ret;
}

semiLineCut App::GetCut(Object * obj, const semiLine &line, bool draw) {
	semiLineCut ret;
	for (Objects::iterator t = objects.begin(); t != objects.end(); t++) if (obj != (*t)) {
		Polygon ext = (*t)->Extent();
		semiLineCut part = ext.cut(line);
		ret.add(part);
	}
	if (ret.count > 0) {
		double err = 0.0;
		if (err > 0.0) {
			double gret = log(1+err);
	//		ret.distance = exp((ceil(log(ret.distance)/gret-0.5))*gret);
	//		ret.distance = exp((floor(log(ret.distance)/gret)+1.0*rand()/RAND_MAX)*gret);
			ret.distance = ret.distance*(1 + (1.0*rand()/RAND_MAX - 0.5)*err);
			ret.cut = line.base+((float)ret.distance)*line.direction;
		}
		if (draw) {
			std::vector<sf::Vertex> sfPoly;
			sf::Color color(255, 255, 255, 30);
			sfPoly.push_back(sf::Vertex(line.base+25.0f*line.direction, color));
			sfPoly.push_back(sf::Vertex(ret.cut, color));
	//		sfPoly.push_back(sf::Vertex(ret.cut, color));
			window->draw(&sfPoly[0], sfPoly.size(), sf::Lines);
			sf::CircleShape circ(2);
			if (ret.tag == TAG_UNKNOWN) {
				circ.setFillColor(sf::Color(255,0,0,255));
			}
			circ.setOrigin(2,2);
			circ.setPosition(ret.cut.x,ret.cut.y);
			window->draw(circ);
		}
	}
	return ret;
}


void App::Hit(float pitch) {
	hit.setPitch(pitch);
	if (!mute) hit.play();
};

void Clear(App::Objects& objects) {
	App::Objects::iterator t = objects.begin();
	while (t != objects.end()) {
		if ((*t)->IsAlive()) {  // "Bring out your dead!"
			t++;
		} else {
			delete (*t);
			t = objects.erase(t);
		}
	}
}

void App::Tick() {
	for (Objects::iterator t = objects.begin(); t != objects.end(); t++) (*t)->Tick(this);
	for (Objects::iterator t = bullets.begin(); t != bullets.end(); t++) (*t)->Tick(this);
	Clear(objects);
	Clear(bullets);
}

int App::Run() {
	while (window->isOpen())
	{
		Time += dt;
		sf::Event event;
		while (window->pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window->close();
		}
		this->Tick();
		window->clear();
		if (graphics) this->Draw();
		if (extents) this->DrawExtents();
		window->display();
		if (Time > timeLimit) window->close();
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Escape)) window->close();
	}
	return EXIT_SUCCESS;
}
