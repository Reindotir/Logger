#include "EventBus.h"
#include <functional>

template<typename T>
std::function<void()> EventBus::subscribe(std::function<void(T&)> callback, SubscribeOptions options = {}) {
    size_t id = generateUniqueID();

    auto wrapper = [callback](Event& e) {
        callback(static_cast<T&>(e));
    };

    map[typeid(T)].push_back({ id, wrapper, options });

    return [this, id]() { this->unsubscribe<T>(id); };
}

template<typename T>
void EventBus::unsubscribe(size_t id) {
    auto it = map.find(typeid(T));
    if (it == map.end()) return;

    auto& vec = it->second;
    vec.erase(
        std::remove_if(vec.begin(), vec.end(),
            [id](const Listener& l) { return l.id == id; }),
        vec.end()
    );
}


template<typename T, typename... Args>
T EventBus::publish(Args&&... args) {
    T event { std::forward<Args>(args)... };

    auto it = map.find(typeid(T));
    if (it == map.end()) return event;

    auto& vec = it->second;

    for (auto& listener : vec) {
        listener.callback(event);
        if (listener.options.once) {
            unsubscribe<T>(listener.id);
        }
    }

    return event;
}