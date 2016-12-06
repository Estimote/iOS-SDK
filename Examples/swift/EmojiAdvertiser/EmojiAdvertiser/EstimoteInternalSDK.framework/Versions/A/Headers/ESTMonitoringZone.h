//
//   ______     _   _                 _          _____ _____  _  __
//  |  ____|   | | (_)               | |        / ____|  __ \| |/ /
//  | |__   ___| |_ _ _ __ ___   ___ | |_ ___  | (___ | |  | | ' /
//  |  __| / __| __| | '_ ` _ \ / _ \| __/ _ \  \___ \| |  | |  <
//  | |____\__ \ |_| | | | | | | (_) | ||  __/  ____) | |__| | . \
//  |______|___/\__|_|_| |_| |_|\___/ \__\___| |_____/|_____/|_|\_\
//
//
//  Copyright © 2016 Estimote. All rights reserved.


/**
 *  Monitoring proximity represents mental model of a beacon's range.
 */
typedef NS_ENUM(NSUInteger, ESTMonitoringProximity) {
    /**
     *  Unknown proximity. Placeholder for a nil value.
     */
    ESTMonitoringProximityUnknown,
    /**
     *  Phone hears a beacon in near distance (≤ 1.5m).
     */
    ESTMonitoringProximityNear,
    /**
     *  Phone hears a beacon in medium distance (≤ 7m).
     */
    ESTMonitoringProximityMedium,
    /**
     *  Phone hears a far beacon (≤ 15m).
     */
    ESTMonitoringProximityFar
};
