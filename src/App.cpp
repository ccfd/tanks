#include "App.h"
#include "LiveTank.h"
#include "Bullet.h"
#include "Obstacle.h"
#include "Factory.h"
#include <assert.h>

App::App() : back(resources.back) {
	sf::ContextSettings settings;
	settings.antialiasingLevel = 8;
	window = new sf::RenderWindow(sf::VideoMode(854, 480), "Objects", sf::Style::Default, settings);
	window->setFramerateLimit(24);
	window->setVerticalSyncEnabled(true);
	back.scale(gscale,gscale);
	hit.setBuffer(resources.hitbuffer);
	Player * player;
	player = PlayerFactory::Produce("KeyboardPlayer");
	if (player == NULL) err("KeyboardPlayer not found");
	objects.push_back(new LiveTank(player, 350,300,0,0));
	player = PlayerFactory::Produce("SimpleBot");
	if (player == NULL) err("SimpleBot not found");
	objects.push_back(new LiveTank(player, 600,300,1,0));
	{
		Polygon poly;
		poly.push_back(Point(1510*gscale,    90*gscale));
		poly.push_back(Point(1576*gscale,    46*gscale));
		poly.push_back(Point(1719*gscale,   814*gscale));
		poly.push_back(Point(1663*gscale,   817*gscale));
		poly.push_back(Point(1573*gscale,   318*gscale));
		poly.push_back(Point(1558*gscale,   319*gscale));
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
		poly.insideout = true;
		objects.push_back(new Obstacle(poly));
	}
}

void App::Draw() {
	window->draw(back);
	for (Objects::iterator t = objects.begin(); t != objects.end(); t++) (*t)->Draw(this,window);
	for (Objects::iterator t = bullets.begin(); t != bullets.end(); t++) (*t)->Draw(this,window);
}

void App::DrawExtents() {
	for (Objects::iterator t = objects.begin(); t != objects.end(); t++) {
		Polygon ext = (*t)->Extent();
		std::vector<sf::Vertex> sfPoly;
		sf::Color color(0, 255, 0);
		int count = GetCollision(*t).size();
		if (count == 1) {
			color = sf::Color(255, 0, 0);
		}
		if (count == 2) {
			color = sf::Color(255, 255, 0);
		}
		if (count == 3) {
			color = sf::Color(0, 255, 255);
		}
		if (count == 4) {
			color = sf::Color(0, 0, 255);
		}
		for (Polygon::iterator p = ext.begin(); p != ext.end(); p++) {
			sfPoly.push_back(sf::Vertex(*p, color));
		}
		{
			Polygon::iterator p = ext.begin();
			sfPoly.push_back(sf::Vertex(*p, color));
		}
		window->draw(&sfPoly[0], sfPoly.size(), sf::LinesStrip);
	}
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

semiLineCut App::GetCut(Object * obj, const semiLine &line) {
	semiLineCut ret;
	for (Objects::iterator t = objects.begin(); t != objects.end(); t++) if (obj != (*t)) {
		Polygon ext = (*t)->Extent();
		semiLineCut part = ext.cut(line);
		ret.add(part);
	}
	if (ret.count > 0) {
		std::vector<sf::Vertex> sfPoly;
		sf::Color color(255, 255, 255, 30);
		sfPoly.push_back(sf::Vertex(line.base+25.0f*line.direction, color));
		double err = 0.0;
		if (err > 0.0) {
			double gret = log(1+err);
	//		ret.distance = exp((ceil(log(ret.distance)/gret-0.5))*gret);
	//		ret.distance = exp((floor(log(ret.distance)/gret)+1.0*rand()/RAND_MAX)*gret);
			ret.distance = ret.distance*(1 + (1.0*rand()/RAND_MAX - 0.5)*err);
			ret.cut = line.base+((float)ret.distance)*line.direction;
		}
		sfPoly.push_back(sf::Vertex(ret.cut, color));
//		sfPoly.push_back(sf::Vertex(ret.cut, color));
		window->draw(&sfPoly[0], sfPoly.size(), sf::Lines);
		sf::CircleShape circ(2);
		circ.setOrigin(2,2);
		circ.setPosition(ret.cut.x,ret.cut.y);
		window->draw(circ);
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

		sf::Event event;
		while (window->pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window->close();
		}
		this->Tick();
		window->clear();
		this->Draw();
		this->DrawExtents();
		window->display();
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Escape)) window->close();
	}
	return EXIT_SUCCESS;
}
