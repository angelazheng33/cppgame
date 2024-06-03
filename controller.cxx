#include "controller.hxx"
#include <iostream>

Controller::Controller()
        : view_(model_,
                mixer())
{ }

void
Controller::draw(ge211::Sprite_set& set)
{
    view_.draw(set);
}

void
Controller::on_key(ge211::Key key)
{
    if (key == ge211::Key::code('q')) {
        quit();
    }

    if (model_.ending){
        return;
    }

    if ((key == ge211::Key::code('5')) or (key == ge211::Key::code('6')) or
        (key == ge211::Key::code('7'))) {
        model_.begin = false;
        model_.game_seconds_ = 0;
    }

    if (model_.begin){
        return;
    }

    if (key == ge211::Key::code('5')) {
        model_.choose_level(5);
    }

    if (key == ge211::Key::code('6')) {
        model_.choose_level(6);
    }

    if (key == ge211::Key::code('7'))  {
        model_.choose_level(7);
    }


    if (key == ge211::Key::code('1')){
        model_.mole_appear1 = 0;
        if(model_.answers[model_.i] == 1){
            view_.play_whack_effect();
            model_.score++;
        }
        else{
            view_.play_wrong_effect();
            model_.score--;
        }
    }

    if (key == ge211::Key::code('2')){
        model_.mole_appear2 = 0;
        if(model_.answers[model_.i] == 2){
            view_.play_whack_effect();
            model_.score++;
        }
        else{
            view_.play_wrong_effect();
            model_.score--;
        }
    }

    if (key == ge211::Key::code('3')){
        model_.mole_appear3 = 0;
        if(model_.answers[model_.i] == 3){
            view_.play_whack_effect();
            model_.score++;
        }
        else{
            view_.play_wrong_effect();
            model_.score--;
        }
    }


    if ((key == ge211::Key::code('1')) or (key == ge211::Key::code('2')) or
        (key == ge211::Key::code('3'))) {

        model_.i++;

        if (model_.i >= 12)
        {
            model_.i = 0;
        }
    }

}

void
Controller::on_frame(double dt)
{
    model_.on_frame(dt);
}