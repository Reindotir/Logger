#include "../ServiceLocator/ServiceLocator.h"
#include "../EventBus/EventBus.h"

class Context {
public:
    Context(ServiceLocator& services, EventBus& bus)
        : services(services), bus(bus) {};

    ServiceLocator& services;
    EventBus& bus;
};