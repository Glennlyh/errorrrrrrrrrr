#include "Shipment.h"
#include "functions.h"
#include <string>


Shipment::Shipment(const freight& f, const Cargo& c, int schedNo, int quantity)
    : Freight(f), cargo(c), scheduleNo(schedNo), cargoQuantity(quantity)
{
}


bool Shipment::IsMatching() const
{
    // Check if destinations match
    if (Freight.getDestination() != cargo.getDestination())
    {
        return false;
    }

    // Check if freight arrival time is within acceptable window
    // Window: [cargo deadline - 15 minutes, cargo deadline]
    return isWithinArrivalWindow(Freight.getTime(), cargo.getTime());
}


int Shipment::getFreightIndex() const
{
    return Freight.getIndex();
}


int Shipment::getCargoIndex() const
{
    return cargo.getIndex();
}


std::string Shipment::getFreightDes() const
{
    return Freight.getDestination();
}


std::string Shipment::getCargoDes() const
{
    return cargo.getDestination();
}


int Shipment::getFreightTime() const
{
    return Freight.getTime();
}


int Shipment::getCargoTime() const
{
    return cargo.getTime();
}