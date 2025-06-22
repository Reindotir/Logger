#include "../Context/Context.h"

class App {
protected:
    Context& context;
    
public:
    void init();

    void initServices();
    void initSystems();
};