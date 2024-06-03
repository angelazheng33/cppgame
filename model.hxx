#pragma once

#include <ge211.hxx>

class Model
{
public:
    bool begin = true;
    int score = 0;
    int i = 0;
    bool ending = false;


    double game_seconds_ = 0;

    double mole_appear1 = 2;
    double mole_appear2 = 2;
    double mole_appear3 = 2;

    int mole_one [12] = {0};
    int mole_two [12] = {0};
    int mole_three [12] = {0};
    int answers [12] = {0};
    std::string questions [12] = {"5 x 20 = ?",
                                  "5 x 9 = ?",
                                  "5 x 10 = ?",
                                  "5 x 7 = ?",
                                  "5 x 3 = ?",
                                  "5 x 5 = ?",
                                  "5 x 1 = ?",
                                  "5 x 6 = ?",
                                  "5 x 8 = ?",
                                  "5 x 2 = ?",
                                  "5 x 4 = ?",
                                  "5 x 11 = ?"
    };


    void choose_level(int n);
    void on_frame(double dt);

};