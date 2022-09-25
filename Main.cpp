#include "Collisions.hpp"

int playerScore{ 0 };

int main() {
	srand(time(0));
	RenderWindow window{ {windowWidth, windowHeight}, "Arkanoid - game" };
	window.setFramerateLimit(60);
	
	vector<Ball> balls;
	balls.emplace_back(windowWidth / 2, windowHeight - 50 - paddleHeight / 2.f);
	Paddle paddle(windowWidth / 2, windowHeight - 50, paddleWidth, paddleHeight, Color::White, false, false, false);
	vector<Block> bricks;
	vector<MovingBlock> movingBricks;
	vector<BonusBlock> bonusBlocks;
	vector<Bonus*> bonuses;

	for (int i = 0; i < blocksCountX; i++)
		for (int j = 0; j < blocksCountY; j++) {
			int blockType = rand() % 10;
			bool breakability = true, boosting = false, haveBonus = false;
			Color color = Color::Yellow;
			switch (blockType)
			{
			case 9:
				breakability = false;
				color = Color::Red;
				break;
			case 8:
				boosting = true;
				color = Color::Cyan;
				break;
			case 7:
				haveBonus = true;
				color = Color::Green;
				break;
			}
			bricks.emplace_back((i + 1) * (blockWidth + 3) + 22, (j + 2) * (blockHeight + 3), blockWidth, blockHeight, color, breakability, boosting, haveBonus);
		}

	ostringstream s;
	s << playerScore;

	Font font;
	font.loadFromFile("arial.ttf");
	Text plScore("", font, 20);

	while (true) {
		ostringstream s;
		s << playerScore;

		plScore.setString("Score: " + s.str());
		plScore.setFillColor(Color::White);
		plScore.setStyle(Text::Bold);
		plScore.setPosition(0, windowHeight - 25);

		window.clear(Color::Black);

		if (Keyboard::isKeyPressed(Keyboard::Key::Escape))
			break;		

		for(auto& ball : balls)
			TestCollision(paddle, ball);

		for (auto& brick : bricks)
			for(auto& ball : balls)
				if (TestCollision(brick, ball)) {
					bonusBlocks.emplace_back(brick.getShape()->getPosition().x, brick.getShape()->getPosition().y, bonusWidth, bonusHeight,
						Color::Green, true, false, false);
					int bonusType = rand() % 2;
					Bonus* bonus = new MovingBlockBonus(&bricks, &movingBricks);
					switch (bonusType)
					{
					case 1:
						bonus = new SecondBallBonus(&balls);
						break;
					}
					bonusBlocks.at(bonusBlocks.size() - 1).setBonus(bonus);
				}

		for (auto& brick1 : movingBricks)
			for (auto& brick2 : bricks)
				TestCollisionBlock(brick1, brick2);

		for (auto& brick : movingBricks)
			for(auto& ball : balls)
				TestCollision(brick, ball);

		for (auto& ball1 : balls)
			for (auto& ball2 : balls) {
				if (ball1.getShape()->getPosition().x == ball2.getShape()->getPosition().x && ball1.getShape()->getPosition().y == ball2.getShape()->getPosition().y)
					continue;
				TestCollisionBall(ball1, ball2);
			}

		for (auto& brick1 : movingBricks)
			for (auto& brick2 : movingBricks) {
				if (brick1.getShape()->getPosition().x == brick2.getShape()->getPosition().x && brick1.getShape()->getPosition().y == brick2.getShape()->getPosition().y)
					continue;
				TestCollisionBlock(brick1, brick2);
			}

		for (auto& bonusblock : bonusBlocks)
			if (TestCapture(bonusblock, paddle)) {
				bonusblock.getBonus()->doBonus();
				bonuses.emplace_back(bonusblock.getBonus());
			}

		movingBricks.erase(remove_if(begin(movingBricks), end(movingBricks), [](Block& brick) {return !brick.gethp(); }), end(movingBricks));
		bonusBlocks.erase(remove_if(begin(bonusBlocks), end(bonusBlocks), [](Block& bonusblock) {return !bonusblock.gethp(); }), end(bonusBlocks));
		bricks.erase(remove_if(begin(bricks), end(bricks), [](Block& brick) {return !brick.gethp(); }), end(bricks));

		for(auto& ball : balls)
			ball.update();
		paddle.update();
		for (auto& bonusblock : bonusBlocks)
			bonusblock.update();
		for (auto& brick : movingBricks)
			brick.update();

		for (auto& bonusblock : bonusBlocks)
			window.draw(*bonusblock.getShape());
		for (auto& brick : bricks)
			window.draw(*brick.getShape());
		for (auto& brick : movingBricks)
			window.draw(*brick.getShape());
		for(auto& ball : balls)
			window.draw(*ball.getShape());
		window.draw(*paddle.getShape());
		window.draw(plScore);
		window.display();
	}

	return 0;
}