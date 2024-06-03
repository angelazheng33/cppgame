#include "view.hxx"

using Color = ge211::Color;
using Sprite_set = ge211::Sprite_set;

static ge211::Color const brown_color {139, 69, 19};
static const Color dark_screen = Color::black();
static const Color white = Color::white();

View::View(Model const& model, ge211::Mixer& mixer)
        : model_(model),
          hole_rectangle({150,40}, brown_color),
          black_screen({900,900}, dark_screen),
          mole("mole.png"),
          score_sprite(),
          num_sprite_1(),
          num_sprite_2(),
          num_sprite_3(),
          mixer_(mixer)
{
    load_audio_();
}

void
View::draw(ge211::Sprite_set& set)
{
    if (model_.begin){
        set.add_sprite(black_screen, {0,0}, 10);
        set.add_sprite(level_sprite, {0,0},11);
        set.add_sprite(level_sprite_2, {0,50},11);
    }

    if (model_.ending){

        set.add_sprite(black_screen, {0,0}, 10);
        set.add_sprite(game_over_sprite, {325,250},11);

        ge211::Text_sprite::Builder score_builder(sans30);
        score_builder.color(white) << "Score: " << model_.score;
        score_sprite.reconfigure(score_builder);
        set.add_sprite(score_sprite, {350,300}, 11);
    }

    //Timer
    ge211::Text_sprite::Builder timer_builder(sans30);
    timer_builder.color(white) << "Timer: " << (20 - model_.game_seconds_);
    timer_sprite.reconfigure(timer_builder);
    set.add_sprite(timer_sprite, {570,0});

    //Score board
    ge211::Text_sprite::Builder score_builder(sans30);
    score_builder.color(white) << "Score: " << model_.score;
    score_sprite.reconfigure(score_builder);
    set.add_sprite(score_sprite, {0,0});

    //Math question
    ge211::Text_sprite::Builder question_sprite_builder(sans30);
    question_sprite_builder.color(white) << model_.questions[model_.i];
    question_sprite.reconfigure(question_sprite_builder);
    set.add_sprite(question_sprite, {320,0},1);

    //Instructions
    set.add_sprite(level_sprite_3, {75,500},1);

    //Moles
    ge211::Text_sprite::Builder num_sprite_1_builder(sans30);
    num_sprite_1_builder.color(white) << model_.mole_one[model_.i];
    num_sprite_1.reconfigure(num_sprite_1_builder);
    set.add_sprite(num_sprite_1, {110,343},1);

    ge211::Text_sprite::Builder num_sprite_2_builder(sans30);
    num_sprite_2_builder.color(white) << model_.mole_two[model_.i];
    num_sprite_2.reconfigure(num_sprite_2_builder);
    set.add_sprite(num_sprite_2, {375,343},1);

    ge211::Text_sprite::Builder num_sprite_3_builder(sans30);
    num_sprite_3_builder.color(white) << model_.mole_three[model_.i];
    num_sprite_3.reconfigure(num_sprite_3_builder);
    set.add_sprite(num_sprite_3, {625,343},1);

    if (model_.mole_appear1 > 0.5){
        set.add_sprite(mole, {80, 225}, 0);
    }

    if (model_.mole_appear2 > 0.5){
        set.add_sprite(mole, {330,225},0);
    }

    if (model_.mole_appear3 > 0.5){
        set.add_sprite(mole, {580,225},0);
    }

    set.add_sprite(hole_rectangle, {65,350},0);
    set.add_sprite(hole_rectangle, {315,350},0);
    set.add_sprite(hole_rectangle, {565,350}, 0);
}


void
View::play_whack_effect() const
{
    mixer_.try_play_effect(whack_sound_, 1.0);
}

void
View::play_wrong_effect() const
{
    mixer_.try_play_effect(wrong_sound_, 0.5);
}

void
View::load_audio_()
{
    whack_sound_.try_load("whack.mp3", mixer_);
    wrong_sound_.try_load("wrong.mp3", mixer_);
}
