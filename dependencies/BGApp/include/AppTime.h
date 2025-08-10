#pragma once

namespace BGAppCore {
    class Time {
    public:
        static double NormalTime;
        static double PreviousNormalTime;
        static double DeltaTime;

        static void Update();
    };
}