#pragma once

#include "model.hxx"

class View
{

private:
    Model const& model_;

    ge211::Rectangle_sprite const hole_rectangle;
    ge211::Rectangle_sprite const black_screen;
    ge211::Image_sprite const mole;

    ge211::Font sans30{"sans.ttf", 30};

    ge211::Text_sprite level_sprite {"Choose which multiple tables to learn", sans30};
    ge211::Text_sprite level_sprite_2 {"by pressing 5, 6 or 7 on your "
                                       "keyboard", sans30};
    ge211::Text_sprite level_sprite_3 {"Click 1, 2 or 3 to whack left, middle"
                                       " or right mole",
                                       sans30};

    ge211::Text_sprite game_over_sprite {"Game Over", sans30};

    ge211::Text_sprite score_sprite;
    ge211::Text_sprite question_sprite;
    ge211::Text_sprite timer_sprite;
    ge211::Text_sprite num_sprite_1;
    ge211::Text_sprite num_sprite_2;
    ge211::Text_sprite num_sprite_3;

    ge211::Mixer& mixer_;
    ge211::Sound_effect whack_sound_;
    ge211::Sound_effect wrong_sound_;

    void load_audio_();


public:
    explicit View(Model const& model,  ge211::Mixer& mixer);

    void draw(ge211::Sprite_set& set);

    void play_whack_effect() const;
    void play_wrong_effect() const;

};