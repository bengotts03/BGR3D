#pragma once

#include "Application.h"

extern BGAppCore::Application* BGAppCore::CreateApplication();

int main(int argc, char** argv) {
    auto application = BGAppCore::CreateApplication();

    application->Start();

    delete application;
}