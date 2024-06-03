#include "model.hxx"


void
Model::choose_level(int n)
{
    if(n == 5)
    {
        int five_answers [12] = {1, 2, 2, 3, 3, 1, 2, 2, 1, 3, 3, 3};
        std::string five_questions [12] = {"5 x 20 = ?",
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

        int five_mole_one [12] = {100, 49, 39, 29, 48, 25, 57, 29, 40, 48,
                                  573, 39};
        int five_mole_two[12] = {34, 45, 50, 32, 49, 84, 59, 30, 2, 4, 93,
                                 58};
        int five_mole_three [12] = {94, 4, 9, 35, 15, 57, 5, 48, 9, 10, 20,
                                    55};

        for (int i = 0; i < 12 ; i++)
        {
            mole_one[i] = five_mole_one[i];
            mole_two[i] = five_mole_two[i];
            mole_three[i] = five_mole_three[i];
            answers[i] = five_answers[i];
            questions[i] = five_questions[i];
        }
    }

    else if(n == 6)
    {
        int six_answers [12] = {1,2,3,3,1,2,2,3,3,3,1,1};
        std::string six_questions [12] = {"6 x 6 = ?",
                                          "6 x 7 = ?",
                                          "6 x 1 = ?",
                                          "6 x 5 = ?",
                                          "6 x 8 = ?",
                                          "6 x 9 = ?",
                                          "6 x 4 = ?",
                                          "6 x 0 = ?",
                                          "6 x 2 = ?",
                                          "6 x 11 = ?",
                                          "6 x 12 = ?",
                                          "6 x 13 = ?"
        };

        int six_mole_one [12] = {36, 49, 39, 20, 48, 58, 57, 29, 490, 48,
                                 72, 78};
        int six_mole_two[12] = {34, 42, 50, 32, 49, 54, 24, 95, 2, 50, 93,
                                58};
        int six_mole_three [12] = {94, 4, 6, 30, 15, 57, 100, 0, 12, 66, 5,
                                   5};
        for (int i = 0; i < 12; i++)
        {
            mole_one[i] = six_mole_one[i];
            mole_two[i] = six_mole_two[i];
            mole_three[i] = six_mole_three[i];
            answers[i] = six_answers[i];
            questions[i] = six_questions[i];
        }
    }

    else if(n == 7)
    {
        int seven_answers [12] = {1,1,1,2,2,2,2,2,1,3,2,1};
        std::string seven_questions [12] = {"7 x 5 = ?",
                                            "7 x 7 = ?",
                                            "7 x 8 = ?",
                                            "7 x 2 = ?",
                                            "7 x 9 = ?",
                                            "7 x 12 = ?",
                                            "7 x 1 = ?",
                                            "7 x 14 = ?",
                                            "7 x 1 = ?",
                                            "7 x 6 = ?",
                                            "7 x 4 = ?",
                                            "7 x 3 = ?"};

        int seven_mole_one [12] = {35, 49, 56, 20, 48, 580, 57, 29, 7, 48,
                                   96, 21};
        int seven_mole_two[12] = {34, 43, 50, 14, 63, 84, 7, 98, 2, 50, 28,
                                  58};
        int seven_mole_three [12] = {94, 4, 6, 30, 15, 57, 100, 85, 24, 42, 5,
                                     150};

        for (int i = 0; i < 12; i++)
        {
            mole_one[i] = seven_mole_one[i];
            mole_two[i] = seven_mole_two[i];
            mole_three[i] = seven_mole_three[i];
            answers[i] = seven_answers[i];
            questions[i] = seven_questions[i];
        }
    }
}

void
Model::on_frame(double dt)
{
    if(!begin && !ending){
        game_seconds_ += dt;
        mole_appear1 += dt;
        mole_appear2 += dt;
        mole_appear3 += dt;
    }

    if (game_seconds_ >= 20){
        ending = true;
    }

}