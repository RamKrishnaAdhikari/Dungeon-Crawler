#ifndef ABSTRACTVIEW_H
#define ABSTRACTVIEW_H

class Level;

class AbstractView
{
public:
    AbstractView();
    virtual void draw() = 0;
    virtual ~AbstractView() = default;
};

#endif // ABSTRACTVIEW_H
