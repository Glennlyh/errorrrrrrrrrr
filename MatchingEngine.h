#pragma once
#include <vector>
#include "freight.h"
#include "Cargo.h"
#include "Shipment.h"

struct MatchStrategy 
{
    virtual ~MatchStrategy() = default;
    virtual std::vector<Shipment> match(const std::vector<freight>& F, const std::vector<Cargo>& C) = 0;
};

struct MatchAllPairs : MatchStrategy 
{
    std::vector<Shipment> match(const std::vector<freight>& F, const std::vector<Cargo>& C) override;
};

// Optimized matching strategy that sorts cargo and freight by arrival time
// and minimizes the number of freights used
struct SortedMinimalMatch : MatchStrategy 
{
    std::vector<Shipment> match(const std::vector<freight>& F, const std::vector<Cargo>& C) override;
};
