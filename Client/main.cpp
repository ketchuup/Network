#include <iostream>
#include <SFML/Network.hpp>

int main()
{
	sf::IpAddress serverIp;
	unsigned short serverPort;

	std::cout << "Enter server IP: ";
	std::cin >> serverIp;
	std::cout << "Enter server port: ";
	std::cin >> serverPort;

	std::cout << "Connecting to " << serverIp << ':' << serverPort << std::endl;

	sf::TcpSocket socket;

	if (socket.connect(sf::IpAddress::LocalHost, 5000) != sf::Socket::Done)
	{
		std::cout << "Failed to connect." << std::endl;
	}

	// const char message[] = "Hello, World!";

	std::string message;

	std::cout << "Enter a message: ";
	std::cin >> message;

	std::cout << "Sending message to server..." << std::endl;

	if (socket.send(message.data(), message.size() + 1) != sf::Socket::Done)
	{
		std::cout << "Failed to send message." << std::endl;
	}

	char buffer[512];
	std::size_t received;

	std::cout << "Receiving message from server..." << std::endl;

	if (socket.receive(buffer, 512, received) != sf::Socket::Done)
	{
		std::cout << "Failed to receive message." << std::endl;
	}

	std::cout << "Received message: " << buffer << std::endl;

	return 0;
}