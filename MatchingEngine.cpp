#include "MatchingEngine.h"
#include <algorithm>
#include <map>

std::vector<Shipment> MatchAllPairs::match(const std::vector<freight>& F, const std::vector<Cargo>& C) 
{
    std::vector<Shipment> out;
    for (const auto& f : F) 
    {
        for (const auto& c : C) 
        {
            Shipment s(f, c);
            if (s.IsMatching()) out.push_back(s);
        }
    }
    return out;
}

std::vector<Shipment> SortedMinimalMatch::match(const std::vector<freight>& F, const std::vector<Cargo>& C) 
{
    // Sort cargo by arrival time (earliest first)
    std::vector<Cargo> sortedCargo = C;
    std::sort(sortedCargo.begin(), sortedCargo.end(), 
        [](const Cargo& a, const Cargo& b) {
            return a.getTime() < b.getTime();
        });
    
    // Sort freight by arrival time (earliest first)
    std::vector<freight> sortedFreight = F;
    std::sort(sortedFreight.begin(), sortedFreight.end(), 
        [](const freight& a, const freight& b) {
            return a.getTime() < b.getTime();
        });
    
    std::vector<Shipment> out;
    
    // Track remaining capacity for each freight
    std::map<int, int> freightRemainingCapacity;
    for (const auto& f : sortedFreight) {
        freightRemainingCapacity[f.getIndex()] = f.getCapacity();
    }
    
    // For each cargo (in time order), find the earliest compatible freight
    // that still has capacity
    for (const auto& cargo : sortedCargo) {
        int cargoNeed = cargo.getCapacity();
        
        // Try to find freight that can handle this cargo
        for (const auto& f : sortedFreight) {
            // Check if this freight matches the cargo (destination and time window)
            Shipment s(f, cargo);
            if (!s.IsMatching()) {
                continue;
            }
            
            // Check if freight has remaining capacity
            int remainingCap = freightRemainingCapacity[f.getIndex()];
            if (remainingCap <= 0) {
                continue;
            }
            
            // Allocate cargo to this freight
            int allocated = std::min(cargoNeed, remainingCap);
            Shipment shipment(f, cargo, 0, allocated);
            out.push_back(shipment);
            
            // Update remaining capacity
            freightRemainingCapacity[f.getIndex()] -= allocated;
            cargoNeed -= allocated;
            
            // If all cargo need is satisfied, move to next cargo
            if (cargoNeed <= 0) {
                break;
            }
        }
    }
    
    return out;
}
