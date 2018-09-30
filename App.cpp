#include "App.h"
#include "LiveTank.h"
#include "Bullet.h"

App::App() : back(resources.back) {
		sf::ContextSettings settings;
	    settings.antialiasingLevel = 8;
	    window = new sf::RenderWindow(sf::VideoMode(1120, 630), "Tanks", sf::Style::Default, settings);
	    window->setFramerateLimit(24);
		window->setVerticalSyncEnabled(true);
		back.scale(gscale,gscale);
		tanks.push_back(new LiveTank(350,300,0,0));
		tanks.push_back(new LiveTank(600,300,1,0));
	}
	void App::Draw() {
		window->draw(back);
		for (Tanks::iterator t = tanks.begin(); t != tanks.end(); t++) (*t)->Draw(window);
	}
	void App::DrawExtents() {
		for (Tanks::iterator t = tanks.begin(); t != tanks.end(); t++) {
			Polygon ext = (*t)->Extent();
			std::vector<sf::Vertex> sfPoly;
			sf::Color color(255, 0, 0);
			for (Polygon::iterator p = ext.begin(); p != ext.end(); p++) {
				sfPoly.push_back(sf::Vertex(sf::Vector2f(p->x[0], p->x[1]), color));
			}
			{
				Polygon::iterator p = ext.begin();
				sfPoly.push_back(sf::Vertex(sf::Vector2f(p->x[0], p->x[1]), color));
			}
			window->draw(&sfPoly[0], sfPoly.size(), sf::LinesStrip);
		}
	}
	void App::AddObject(Object * obj) {
		tanks.push_back(obj);
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
//			this->DrawExtents();
			window->display();
		}
		return EXIT_SUCCESS;
	}
