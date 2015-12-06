#include "Main.h"
#include "Class.h"

int main()
{
    sf::RenderWindow window(sf::VideoMode(WINDOW_X, WINDOW_Y), "RPi Remote");

    Panel panel;
	Network network("resource/connected.png", "resource/disconnected.png", sf::Vector2f(400, 400));

      while (window.isOpen())
    {

        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        panel.update(window);

        network.send(panel.getValue());

        window.clear(sf::Color::White);
        panel.draw(window);
		network.draw(window);
        window.display();
    }

    return 0;
}
/*
void Network()
{
    sf::TcpSocket socket;
    sf::Socket::Status status = socket.connect("192.168.1.84", 3000);

    if (status != sf::Socket::Done)
    {
        std::cout << "Error" << std::endl;
    }
    else
    {
        std::cout << "Connected" << std::endl;
    }

    int choice;
    sf::Packet packet;

    // DEMO
        packet << 1 << 2000;
        socket.send(packet);

        packet.clear();

        packet << 2 << 2000;
        socket.send(packet);

        packet.clear();

        packet << 3 << 1000;
        socket.send(packet);

        packet.clear();

        packet << 4 << 1000;
        socket.send(packet);
    //

    while (choice)
    {
        std::cout << std::endl;
        std::cout << "RPi Remote:" << std::endl;
        std::cout << "  1. Forward" << std::endl;
        std::cout << "  2. Backward" << std::endl;
        std::cout << "  3. TurnRight" << std::endl;
        std::cout << "  4. TurnLeft" << std::endl;

        std::cin >> choice;

        if (choice < 5 && choice > 0)
        {
            int time;
            std::cout << "Time (sec): ";
            std::cin >> time;

            time = time * 1000;

            std::cout << "Send; choice: " << choice << " time: " << time << std::endl;

            packet.clear();
            packet << choice << time;


            socket.send(packet);
        }
        else if (choice == 0)
        {
            packet.clear();
            packet << choice;


            socket.send(packet);
        }
        else
        {
            std::cout << "Error choice" << std::endl;
        }
    }
}*/
