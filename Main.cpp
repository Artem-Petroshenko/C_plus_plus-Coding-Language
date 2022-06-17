#include "Collisions.hpp"

int player_score{ 0 };
const float bonusWidth{ 6.f }, bonusHeight{ 6.f };

int main() {
    Time bonusTime = seconds(10.f);
    // Create the main window
    RenderWindow window(VideoMode(windowWidth, windowHeight), "Arkanoid game");
    Ball ball(windowWidth / 2.0, windowHeight / 2.0, ballRadius, Color::White);
    Paddle paddle(windowWidth / 2.0, windowHeight - 50.0, paddleWidth, paddleHeight, Color::White, false, false, false);
    vector<Block> blocks;
    vector<BonusBlock> bonusblocks;
    vector<SizePaddleBonus*> bonuses;
    SpeedPaddleBonus b1;

    Color blockColor{ 255, 242, 0, 255 };
    for (int i = 1; i <= countX; i++)
        for (int j = 1; j <= countY; j++) {
            /*int tmp = rand() % 10;
            Color blockColor{ 255, 242, 0, 255 };
            bool br = true;
            bool boo = false;
            bool bon = false;
            if (tmp > 8) {
                blockColor = { 255, 0, 0, 255 };
                br = false;
            }
            else if (tmp > 7) {
                blockColor = { 255, 0, 230, 255 };
                boo = true;
            }
            else if (tmp > 6) {
                blockColor = { 0, 0, 255, 255 };
                bon = true;
            }*/
            //blocks.emplace_back(22 + i * (blockWidth + 3), 22 + j * (blockHeight + 3), blockWidth, blockHeight, blockColor, br, boo, bon);
            blocks.emplace_back(22 + i * (blockWidth + 3), 22 + j * (blockHeight + 3), blockWidth, blockHeight, blockColor, true, false, true);
        }
    ostringstream s;
    s << player_score;

    Font font;
    font.loadFromFile("arial.ttf");
    Text plScore("", font, 20);

    // Start the game loop
    while (window.isOpen()) {
        ostringstream s;
        s << player_score;

        plScore.setString("Score: " + s.str());
        plScore.setFillColor(Color::White);
        plScore.setStyle(Text::Bold);
        plScore.setPosition(0, windowHeight - 25);

        //Clear the window
        window.clear(Color::Black);

        //exit the window
        if (Keyboard::isKeyPressed(Keyboard::Key::Escape))
            window.close();

        //show the window contents
        ball.update();
        paddle.update();
        testCollision(paddle, ball);
        for (auto& block : blocks)
            if (testCollision(block, ball)) {
                bonusblocks.emplace_back(block.getShape().getPosition().x, block.getShape().getPosition().y, bonusWidth, bonusHeight, Color::Green, true, false, false);
                SpeedPaddleBonus* ref = &b1;
                bonusblocks.back().setBonus(ref);
                bonusblocks.back().setVelocity(0.f, 0.1f);
            }
        for (auto& bonusblock : bonusblocks)
            bonusblock.update();
        for (auto& bonusblock : bonusblocks)
            if (testCapture(bonusblock, paddle))
                bonuses.push_back(bonusblock.getBonus());

        for (auto& bonus : bonuses)
            if (bonus->getTimer().getElapsedTime() >= bonusTime && bonus->getActive() == true) {
                bonus->rollback(paddle);
                bonus->setActive(false);
            }

        bonuses.erase(remove_if(begin(bonuses), end(bonuses), [](SizePaddleBonus* bonus) { return !bonus->getActive(); }), end(bonuses));
        bonusblocks.erase(remove_if(begin(bonusblocks), end(bonusblocks), [](BonusBlock& bonus) { return bonus.getFell(); }), end(bonusblocks));
        blocks.erase(remove_if(begin(blocks), end(blocks), [](Block& block) { return block.getHP() == 0; }), end(blocks));

        window.draw(ball.getShape());
        window.draw(paddle.getShape());
        for (auto& block : blocks)
            window.draw(block.getShape());
        for (auto& bonusblock : bonusblocks)
            window.draw(bonusblock.getShape());
        window.draw(plScore);
        window.display();
    }
    return 0;
}


//    // Process events
//    Event event;
//    while (window.pollEvent(event)) {
//        // Close window: exit
//        if (event.type == Event::Closed)
//            window.close();
//    }
//    // Clear screen
//    window.clear();
//    // Update the window
//    window.display();
//}
//return EXIT_SUCCESS;