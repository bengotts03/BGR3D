#pragma once

namespace BGAppCore {
    class Performance {
    public:
        static float FPS;
        static float AverageFPS;

        static float MS;

        static void Update();
    private:
        static double _timeDifference;
        static unsigned int _fpsCount;
        static double _previousTime;
    };
}