#include <iostream>
#include <SFML/Network.hpp>

int main()
{
	unsigned short port;

	std::cout << "Enter a port: ";
	std::cin >> port;

	std::cout << "Server runs at " << sf::IpAddress::getLocalAddress() << ':' << port << std::endl;

	sf::TcpListener listener;

	std::cout << "Listening..." << std::endl;

	if (listener.listen(port) != sf::Socket::Done)
	{
		std::cout << "Failed while listening." << std::endl;
	}

	sf::TcpSocket client;

	if (listener.accept(client) != sf::Socket::Done)
	{
		std::cout << "Failed while accepting." << std::endl;
	}

	std::cout << "New connection: " << client.getRemoteAddress() << ':' << client.getRemotePort() << std::endl;

	char buffer[512];
	std::size_t received;

	std::cout << "Receiving message from client..." << std::endl;

	if (client.receive(buffer, 512, received) != sf::Socket::Done)
	{
		std::cout << "Failed while receiving." << std::endl;
	}

	std::cout << "Received message: " << buffer << std::endl;

	std::cout << "Sending message to client..." << std::endl;

	if (client.send(buffer, received) != sf::Socket::Done)
	{
		std::cout << "Failed while sending." << std::endl;
	}

	return 0;
}