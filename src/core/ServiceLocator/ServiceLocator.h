#include <unordered_map>
#include <typeindex>
#include <memory>
#include <stdexcept>

class ServiceLocator {
private:
    std::unordered_map<std::type_index, std::shared_ptr<void>> services;

public:
    template<typename T>
    void regist(std::shared_ptr<T> service) {
        services[typeid(T)] = service;
    }

    template<typename T>
    T& get() {
        auto it = services.find(typeid(T));
        if (it == services.end()) {
            throw std::runtime_error("Сервис не зарегистрирован!");
        }
        return *std::static_pointer_cast<T>(it->second);
    }

    template<typename T>
    bool has() {
        return services.find(typeid(T)) != services.end();
    }
};
