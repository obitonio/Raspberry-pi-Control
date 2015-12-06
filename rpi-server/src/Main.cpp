#include "Main.h"
#include "Class.h"

int main (int argc, char **argv)
{
	// DECLARATION
	wiringPiSetup();
	Robot robot;
	sf::TcpSocket socket;
	sf::TcpListener listener;
/*	robot.forward(10000);
	robot.backward(10000);
*/

	 if (listener.listen(PORT) == sf::Socket::Done)
                std::cout << "Listen on port " << PORT << std::endl;
        else
                std::cout << "Can't listen on port " << PORT << std::endl;

        if (listener.accept(socket) == sf::Socket::Done)
        {
                std::cout << "Client connected" << std::endl;
        }
        else
                std::cout << "Error" << std::endl;

	int choice, time;
	sf::Packet packet;
	while (choice != 0)
	{
		packet.clear();
		socket.receive(packet);
		packet >> choice >> time;
		std::cout << "Choice: " << choice << " Time: " << time << std::endl;

		switch (choice)
		{
			case 1:
				robot.forward(time);
				// Forward
				break;
			case 2:
				robot.backward(time);
				// Backward
				break;
			case 3:
				robot.turnRight(time);
				// TurnRight
				break;
			case 4:
				robot.turnLeft(time);
				// TurnLeft
				break;
			default:
				choice = 0;
				break;
		}
	}

	return 0;
}
