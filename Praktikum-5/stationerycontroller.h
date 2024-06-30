#ifndef STATIONERYCONTROLLER_H
#define STATIONERYCONTROLLER_H

#include "abstractcontroller.h"

class StationeryController: public AbstractController
{
public:
    StationeryController();
    Input_gui move() override;
    ~StationeryController();
};

#endif // STATIONERYCONTROLLER_H
