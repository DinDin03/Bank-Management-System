#ifndef USBCONNECTION_H
#define USBCONNECTION_H

#include <stack>

class USBConnection {
private:
    int ID;
    
    USBConnection(int id);  // Private constructor
    
public:
    static USBConnection* CreateUsbConnection();  // Public static function to create new objects
    int get_id() const;
    ~USBConnection();  // Destructor
    
    static std::stack<int> ids;  // Static stack to keep track of IDs
};

#endif
