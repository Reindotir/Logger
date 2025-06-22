#include <unordered_map>
#include <vector>
#include <typeindex>
#include <functional>

class Event {
public:
    bool prevented = false;
    bool dispatched = false;

    virtual void prevent() { prevented = true; }
    virtual void dispatch() { dispatched = true; }
};

struct SubscribeOptions {
    bool once = true;
};

struct Listener {
    size_t id;
    std::function<void(Event&)> callback;
    SubscribeOptions options;
};

class EventBus {
public:
    std::unordered_map<std::type_index, std::vector<Listener>> map;
    size_t idCounter = 0;

    size_t generateUniqueID() {
        return ++idCounter;
    }

    template<typename T>
    std::function<void()> subscribe(std::function<void(T&)> callback, SubscribeOptions options = {});

    template<typename T>
    void unsubscribe(size_t id);

    template<typename T, typename... Args>
    T publish(Args&&... args);
};