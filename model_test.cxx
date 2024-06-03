#include "model.hxx"
#include <catch.hxx>
#include <string>

TEST_CASE("example test (TODO: replace this)")
{
    CHECK(1 + 1 == 2);
}

//
// TODO: Write preliminary model tests.
//
// These tests should demonstrate at least six of the functional
// requirements.
//


TEST_CASE("timer during opening screen")
{
    Model m;
    m.begin = true;
    m.on_frame(20);
    CHECK(m.ending == false);
}

TEST_CASE("show three level (1)")
{
    Model m;
    m.choose_level(5);
    CHECK(m.questions[0].at(0) == '5');

    m.choose_level(6);
    CHECK(m.questions[0].at(0) == '6');

    m.choose_level(7);
    CHECK(m.questions[0].at(0) == '7');

    CHECK(m.questions[2].at(0) == '7');

    //should stay at the current level if chosen level doesn't exist
    m.choose_level(8);
    CHECK(m.questions[0].at(0) == '7');

}

TEST_CASE("check multiplication result")
{
    Model m;
    m.choose_level(5);
    int correct_mole = m.answers[0];
    if(correct_mole == 1)
    {
        CHECK(m.mole_one[0] % 5 == 0);
        CHECK(m.mole_two[0] % 5 != 0);
        CHECK(m.mole_three[0] % 5 != 0);
    }
    if(correct_mole == 2)
    {
        CHECK(m.mole_one[0] % 5 != 0);
        CHECK(m.mole_two[0] % 5 == 0);
        CHECK(m.mole_three[0] % 5 != 0);
    }
    if(correct_mole == 3)
    {
        CHECK(m.mole_one[0] % 5 != 0);
        CHECK(m.mole_two[0] % 5 != 0);
        CHECK(m.mole_three[0] % 5 == 0);
    }
}


TEST_CASE("a new number appears to be multiplied (2)")
{
    Model m;
    m.choose_level(5);
    int i = 0;
    CHECK(m.questions[i].at(4) != m.questions[i+1].at(4));
    i++;
    CHECK(m.questions[i].at(4) != m.questions[i+1].at(4));
}

TEST_CASE("timer changes (9)")
{
    //timer shouldn't change during opening screen
    Model m;
    CHECK(m.game_seconds_ == 0);
    m.on_frame(10);
    CHECK(m.game_seconds_ == 0);

    //timer changes when game starts
    m.begin = false;
    m.on_frame(1);
    CHECK(m.game_seconds_ == 1);

    m.on_frame(10);
    CHECK(m.game_seconds_ == 11);

}

TEST_CASE("Game stops when time runs out (10)")
{
    Model m;
    m.begin = false;
    m.on_frame(20);
    CHECK(m.game_seconds_ == 20);

    //timer stops after 20 seconds
    m.on_frame(5);
    CHECK(m.game_seconds_ == 20);
}

TEST_CASE("Game Over screen appears (11)")
{
    Model m;
    m.begin = false;
    m.on_frame(20);
    CHECK(m.ending == true);
}

TEST_CASE("popped up mole images appear (3)")
{
    Model m;

    m.begin = false;

    //when m.mole_appear variable is larger than 0.5, it indicates that the
    //respective mole sprite is being displayed

    //checks that mole sprites appear when the game is being played
    CHECK(m.mole_appear1 > 0.5);
    CHECK(m.mole_appear2 > 0.5);
    CHECK(m.mole_appear3 > 0.5);

    // this test is further supported through validation by playing

}




