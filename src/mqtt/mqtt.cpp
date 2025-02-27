#include <iostream>
#include <mqtt/async_client.h>
#include <mqtt/exception.h>
#include <mqtt/token.h>
#include <mqtt/types.h>

/*const std::string SERVER_URL{"tcp://localhost:1883"};*/
const std::string SERVER_URL{"tcp://127.0.0.1:1883"};
const std::string TOPIC{"test1"};

const char* PAYLOADS[] = {
    "Hello world!", "Hi there!", "Is anyone listening?", "Someone is always listening.", nullptr
};

int main() {
    mqtt::async_client cli(SERVER_URL, "client");

    try {
        std::cout << "\nConnecting..." << std::endl;
        cli.connect() -> wait();
        std::cout << "...OK" << std::endl;

        mqtt::topic top(cli, "test", 1);
        mqtt::token_ptr tok;

        size_t i = 0;

        while (PAYLOADS[i]) {
            tok = top.publish(PAYLOADS[i++]);
        }

        tok->wait();
        std::cout << "OK" << std::endl;


        std::cout << "\nDisconnecting..." << std::endl;
        cli.disconnect()->wait();
        std::cout<< " ...OK" << std::endl;
    }
    catch (const mqtt::exception& exc){ 
        std::cerr << exc << std::endl;
        return 1;
    }
    std::cout << "Hello world!" << std::endl;

    return 0;
}
