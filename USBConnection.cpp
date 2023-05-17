#include "USBConnection.h"

std::stack<int> USBConnection::ids({3, 2, 1});  // Initialize static stack with IDs

USBConnection::USBConnection(int id) : ID(id) {}

USBConnection* USBConnection::CreateUsbConnection() {
    if (ids.empty()) {
        return nullptr;  // No available ports
    }
    
    int id = ids.top();
    ids.pop();
    
    return new USBConnection(id);
}

USBConnection::~USBConnection() {
    ids.push(ID);  // Return used ID to the stack
}
int USBConnection::get_id() const {
    return ID;
}