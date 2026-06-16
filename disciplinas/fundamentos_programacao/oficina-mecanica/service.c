#include "types.h"

double service_price(Service s) {
    switch (s) {
        case SIMPLE_WASH:    return 30.0;
        case FULL_WASH:      return 80.0;
        case OIL_EXCHANGE:   return 120.0;
        case CALIBRATE_TIRE: return 15.0;
        case PAINTING:       return 500.0;
        default:             return 0.0;
    }
}

const char* service_to_string(Service s) {
    switch (s) {
        case SIMPLE_WASH:    return "Simple Wash";
        case FULL_WASH:      return "Full Wash";
        case OIL_EXCHANGE:   return "Oil Exchange";
        case CALIBRATE_TIRE: return "Calibrate Tire";
        case PAINTING:       return "Painting";
        default:             return "Unknown";
    }
}