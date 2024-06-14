#ifndef INPUT_H
#define INPUT_H

class Input
{
 public:
    Input(const int& horizontal, const int& vertical, bool exit);

    int getHorizontal() const;
    int getVertical() const;
    bool getExit() const;

 private:
    int horizontal;
    int vertical;
    bool exit;
};

#endif // INPUT_H
