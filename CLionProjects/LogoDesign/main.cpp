#include <SFML/Graphics.hpp>

#include "MouseEvents.cpp"
#include "GUIComponent.cpp"

int main()
{
    sf::RenderWindow window(sf::VideoMode(800, 600), "I'm a fraud");
    GUIComponent GUI;

    GUI.initiate();

    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
            GUI.addEventHandler(window, event);
        }

        window.clear(sf::Color::Black);
        GUI.update(window);
        window.draw(GUI);
        window.display();
    }

    return 0;
}