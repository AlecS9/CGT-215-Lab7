// CGT 215 Lab7.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <SFML/Graphics.hpp>
#include <SFPhysics.h>

using namespace std;
using namespace sf;
using namespace sfp;

int main()
{
	RenderWindow window(VideoMode(800, 600), "Bounce");
	World world(Vector2f(0, 1));

	PhysicsCircle ball;
	ball.setCenter(Vector2f(400, 30));
	ball.setRadius(20);
	world.AddPhysicsBody(ball);
	ball.applyImpulse(Vector2f(0.1,0.1));

	PhysicsRectangle floor;
	floor.setSize(Vector2f(740, 40));
	floor.setCenter(Vector2f(400, 550));
	floor.setStatic(true);
	world.AddPhysicsBody(floor);

	PhysicsRectangle ceiling;
	ceiling.setSize(Vector2f(800, 20));
	ceiling.setCenter(Vector2f(400, 10));
	ceiling.setStatic(true);
	world.AddPhysicsBody(ceiling);

	PhysicsRectangle sideL;
	sideL.setSize(Vector2f(20, 600));
	sideL.setCenter(Vector2f(10, 300));
	sideL.setStatic(true);
	world.AddPhysicsBody(sideL);

	PhysicsRectangle sideR;
	sideR.setSize(Vector2f(20, 600));
	sideR.setCenter(Vector2f(790, 300));
	sideR.setStatic(true);
	world.AddPhysicsBody(sideR);

	
	PhysicsRectangle center;
	center.setSize(Vector2f(100, 100));
	center.setCenter(Vector2f(400, 300));
	center.setStatic(true);
	world.AddPhysicsBody(center);
	
	/*
	int thudCount(0);
	floor.onCollision = [&thudCount](PhysicsBodyCollisionResult result)
	{
		cout << "thud " << thudCount << endl;
		thudCount++;
	};
	*/
	int bangCount(1);
	center.onCollision = [&bangCount](PhysicsBodyCollisionResult result)
	{
		cout << "bang " << bangCount << endl;
		bangCount++;
		if (bangCount == 4)
		{
			exit(0);
		}
	};
	
	Clock clock;
	Time lastTime(clock.getElapsedTime());
	while (true)
	{
		Time currentTime(clock.getElapsedTime());
		Time deltaTime(currentTime - lastTime);
		int deltaTimeMS(deltaTime.asMilliseconds());
		if (deltaTimeMS > 0)
		{
			world.UpdatePhysics(deltaTimeMS);
			lastTime = currentTime;
		}
		
		window.clear(Color(0, 0, 0));
		window.draw(ball);
		window.draw(floor);
		window.draw(ceiling);
		window.draw(sideL);
		window.draw(sideR);
		window.draw(center);
		window.display();
	}
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
