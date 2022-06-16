#include "Collisions.hpp"

int main() {
    int player_score = 0;
    // Create the main window
    RenderWindow window(VideoMode(windowWidth, windowHeight), "Arkanoid game");
    Ball ball(windowWidth / 2.0, windowHeight / 2.0, ballRadius, Color::White);
    Paddle paddle(windowWidth / 2.0, windowHeight - 50.0, paddleWidth, paddleHeight, Color::White, false, false);
    vector<Block> blocks;

    Color blockColor{ 255, 242, 0, 255 };
    for (int i = 1; i <= countX; i++)
        for (int j = 1; j <= countY; j++) {
            int tmp = rand() % 10;
            Color blockColor{ 255, 242, 0, 255 };
            bool br = true;
            bool boo = false;
            if (tmp > 8) {
                blockColor = { 255, 0, 0, 255 };
                br = false;
            }
            else if (tmp > 7) {
                blockColor = { 255, 0, 230, 255 };
                boo = true;
            }
            blocks.emplace_back(22 + i * (blockWidth + 3), 22 + j * (blockHeight + 3), blockWidth, blockHeight, blockColor, br, boo);
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
        if (!ball.update())
            player_score--;
        paddle.update();
        testCollision(paddle, ball);
        for (auto& block : blocks)
            if (testCollision(block, ball))
                player_score++;

        blocks.erase(remove_if(begin(blocks), end(blocks), [](Block& block) { return block.getHP() == 0; }), end(blocks));

        window.draw(ball.getShape());
        window.draw(paddle.getShape());
        for (auto& block : blocks)
            window.draw(block.getShape());
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