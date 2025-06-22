#include "App.h"
#include "../Context/Context.h"
#include "../EventBus/EventBus.h"
#include "../ServiceLocator/ServiceLocator.h"



void App::init() {
    EventBus bus;
    ServiceLocator services;
    
    Context* ctx = new Context(services, bus);
    context = ctx;

    initServices();
    initSystems();
}

void App::initServices() {
    // импортируешь все сервисы, иницализируешь их и отдаешь им контекст
}

void App::initSystems() {
    // импортируешь все системы, инициализируешь их и отаешь им контекст
}