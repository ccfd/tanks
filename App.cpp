#include "App.h"
#include "LiveTank.h"
#include "Bullet.h"
#include "KeyboardPlayer.h"
#include "Obstacle.h"
#include <assert.h>

App::App() : back(resources.back) {
    sf::ContextSettings settings;
    settings.antialiasingLevel = 8;
    window = new sf::RenderWindow(sf::VideoMode(1120, 630), "Tanks", sf::Style::Default, settings);
    window->setFramerateLimit(24);
    window->setVerticalSyncEnabled(true);
    back.scale(gscale,gscale);
    tanks.push_back(new LiveTank(new KeyboardPlayer(), 350,300,0,0));
    tanks.push_back(new LiveTank(new Player(), 600,300,1,0));
    {
	    Polygon poly;
	    poly.push_back(Point(1510*gscale,    90*gscale));
	    poly.push_back(Point(1576*gscale,    46*gscale));
	    poly.push_back(Point(1719*gscale,   814*gscale));
	    poly.push_back(Point(1663*gscale,   817*gscale));
	    poly.push_back(Point(1573*gscale,   318*gscale));
	    poly.push_back(Point(1558*gscale,   319*gscale));
	    tanks.push_back(new Obstacle(poly));
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
	    tanks.push_back(new Obstacle(poly));
    }
}
	
	void App::Draw() {
		window->draw(back);
		for (Tanks::iterator t = tanks.begin(); t != tanks.end(); t++) (*t)->Draw(window);
	}
	
	void App::DrawExtents() {
		for (Tanks::iterator t = tanks.begin(); t != tanks.end(); t++) {
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
		tanks.push_back(obj);
	}
	
	std::vector<Object*> App::GetCollision(Object * obj) {
		std::vector<Object*> ret;
		Polygon me = obj->Extent();
		for (Tanks::iterator t = tanks.begin(); t != tanks.end(); t++) {
			Polygon ext = (*t)->Extent();
//			bool inside = me.intersect(ext);
			bool inside = ext.intersect(me);
			assert(me.intersect(ext) == ext.intersect(me));
			if ( (inside) && (obj != (*t)) ) {
				ret.push_back(*t);
			}
		}
		return ret;
	}
	
	void App::Tick() {
		for (Tanks::iterator t = tanks.begin(); t != tanks.end(); t++) (*t)->Tick(this);
		Tanks::iterator t = tanks.begin();
		while (t != tanks.end()) {
			if ((*t)->IsAlive()) {  // "Bring out your dead!"
				t++;
			} else {
				delete (*t);
				t = tanks.erase(t);
			}
		}
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
//			this->DrawExtents();
			window->display();
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Escape)) window->close();
		}
		return EXIT_SUCCESS;
	}
