#include "App.h"
#include "LiveTank.h"
#include "Bullet.h"
#include "KeyboardPlayer.h"

App::App() : back(resources.back) {
		sf::ContextSettings settings;
	    settings.antialiasingLevel = 8;
	    window = new sf::RenderWindow(sf::VideoMode(1120, 630), "Tanks", sf::Style::Default, settings);
	    window->setFramerateLimit(24);
		window->setVerticalSyncEnabled(true);
		back.scale(gscale,gscale);
		tanks.push_back(new LiveTank(new KeyboardPlayer(), 350,300,0,0));
		tanks.push_back(new LiveTank(new Player(), 600,300,1,0));
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
			if (GetCollision(*t).size() > 0) {
				color = sf::Color(255,0,0);
			}
			for (Polygon::iterator p = ext.begin(); p != ext.end(); p++) {
				sfPoly.push_back(sf::Vertex(*p, color));
			}
			{
				Polygon::iterator p = ext.begin();
				sfPoly.push_back(sf::Vertex(*p, color));
			}
			window->draw(&sfPoly[0], sfPoly.size(), sf::LinesStrip);
			semiLineCut cut = ext.cut(semiLine(Point(100,300),Point(1.0,0.0)));
			if (cut.count > 0) {
				sf::Vertex ver(cut.cut, color);
				window->draw(&ver, 1, sf::Points);
			}
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
			bool inside = me.intersect(ext);
			if ( (inside) && (obj != *t) ) {
				ret.push_back(*t);
			}
		}
		Tanks::iterator t = tanks.begin();
		while (t != tanks.end()) if ((*t)->IsAlive()) t++; else t = tanks.erase(t); // "Bring out your dead!"
		return ret;
	}
	
	void App::Tick() {
		for (Tanks::iterator t = tanks.begin(); t != tanks.end(); t++) (*t)->Tick(this);
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
